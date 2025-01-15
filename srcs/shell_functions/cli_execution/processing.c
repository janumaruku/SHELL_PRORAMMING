/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Functions to execute a command line
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"
#include "../../../include/binary_tree.h"
#include "../../../include/command_parsing.h"

extern char *cli;
extern char *current_command;
extern pnode_t top_reached;
extern pnode_t buttom_reached;
extern tree_t *command_tree;

void func3(void *data)
{
    char *d = (char *)data;

    mem_free(d);
}

int comma_handling(tree_t *tree)
{
    if (my_strcmp(tree->data, ";") == 0) {
        processing(tree->tleft);
        processing(tree->tright);
        return 1;
    }
    return 0;
}

int or_handling(tree_t *tree)
{
    if (my_strcmp(tree->data, "||") == 0) {
        processing(tree->tleft);
        if (exit_status != 0)
            processing(tree->tright);
        return 1;
    }
    return 0;
}

int and_handling(tree_t *tree)
{
    if (my_strcmp(tree->data, "&&") == 0) {
        processing(tree->tleft);
        if (exit_status == 0)
            processing(tree->tright);
        return 1;
    }
    return 0;
}

int right_redirection_handling(tree_t *tree)
{
    int fd = 0;
    int pid = 0;

    if (my_strcmp(tree->data, ">") == 0 || my_strcmp(tree->data, ">>") == 0) {
        if (my_strcmp(tree->data, ">>") == 0)
            fd = open(tree->tright->data, O_WRONLY | O_CREAT | O_APPEND, 0777);
        else
            fd = open(tree->tright->data, O_WRONLY | O_CREAT | O_TRUNC, 0777);
        pid = fork();
        if (pid == 0) {
            dup2(fd, STDOUT_FILENO);
            close(fd);
            processing(tree->tleft);
            mem_free(past_dir);
            free_job(job_list);
            free_2d_array(t_env);
            clear_list(&l_env, str_pop);
            clear_list(&history, del_history);
            free_node(&top_reached, str_pop);
            free_node(&buttom_reached, str_pop);
            clean_tree(tree, func3);
            mem_free(cli);
            exit(0);
        }
        waitpid(pid, NULL, WUNTRACED);
        return 1;
    }
    return 0;
}

void simple_left(tree_t *tree)
{
    int fd = 0;
    int pid = 0;

    fd = open(tree->tright->data, O_RDONLY);
    if (fd < 0) {
        my_perror(tree->tright->data);
        return;
    }
    pid = fork();
    if (pid == 0) {
        dup2(fd, STDIN_FILENO);
        close(fd);
        processing(tree->tleft);
        mem_free(past_dir);
        free_job(job_list);
        free_2d_array(t_env);
        clear_list(&l_env, str_pop);
        clear_list(&history, del_history);
        free_node(&top_reached, str_pop);
        free_node(&buttom_reached, str_pop);
        clean_tree(tree, func3);
        mem_free(cli);
        exit(0);
    }
    waitpid(pid, NULL, WUNTRACED);
    close(fd);
    return;
}

void post_execution_intruction(int fds[])
{
    mem_free(past_dir);
    free_job(job_list);
    free_2d_array(t_env);
    clear_list(&l_env, str_pop);
    clear_list(&history, del_history);
    free_node(&top_reached, str_pop);
    free_node(&buttom_reached, str_pop);
    clean_tree(command_tree, str_pop);
    mem_free(cli);
    close(fds[0]);
    close(fds[1]);
}

void double_left(tree_t *tree)
{
    int pid = 0;
    int pid2 = 0;
    int fds[2] = {0};
    size_t k;
    char *line = NULL;
    char *temp = NULL;

    pipe(fds);
    temp = my_strcat2(tree->tright->data, "\n");
    mem_free(tree->tright->data);
    tree->tright->data = temp;
    pid = fork();
    if (pid == 0) {
        my_putstr("? ");
        while (getline(&line, &k, stdin) != -1 && my_strcmp(line, tree->tright->data) != 0) {
            write(fds[1], line, my_strlen(line));
            my_putstr("? ");
        }
        mem_free(line);
        post_execution_intruction(fds);
        exit(0);
    }
    close(fds[1]);
    waitpid(pid, NULL, WUNTRACED);
    pid2 = fork();
    if (pid2 == 0) {
        dup2(fds[0], STDIN_FILENO);
        processing(tree->tleft);
        post_execution_intruction(fds);
        exit(0);
    }
    close(fds[0]);
    waitpid(pid2, NULL, WUNTRACED);
}

int left_redirection_handling(tree_t *tree)
{
    int fd = 0;
    int pid = 0;
    int pid2 = 0;
    int fds[2] = {0};
    size_t k;
    char *line = NULL;
    char *temp = NULL;

    if (my_strcmp(tree->data, "<") == 0 || my_strcmp(tree->data, "<<") == 0) {
        if (my_strcmp(tree->data, "<") == 0) {
            simple_left(tree);
        } else if (my_strcmp(tree->data, "<<") == 0) {
            double_left(tree);
        }
        return 1;
    }
    return 0;
}

int pipe_handling(tree_t *tree)
{
    int fds[2] = {0};
    int pid1 = 0;
    int pid2 = 0;

    if (my_strcmp(tree->data, "|") == 0) {
        pipe(fds);
        pid1 = fork();
        if (pid1 == 0) {
            dup2(fds[1], STDOUT_FILENO);
            processing(tree->tleft);
            post_execution_intruction(fds);
            exit(0);
        }
        close(fds[1]);
        pid2 = fork();
        if (pid2 == 0) {
            dup2(fds[0], STDIN_FILENO);
            processing(tree->tright);
            post_execution_intruction(fds);
            exit(0);
        }
        close(fds[0]);
        waitpid(pid1, NULL, WUNTRACED);
        waitpid(pid2, NULL, WUNTRACED);
        return 1;
    }
    return 0;
}

int parentheses_handling(tree_t *tree)
{
    if (my_strcmp(tree->data, "()") == 0) {
        processing(tree->tleft);
        return 1;
    }
    return 0;
}

int processing(tree_t *tree)
{
    char **cmd = NULL;
    int fd = 0;
    int pid = 0;

    if (tree == NULL)
        return 0;
    if (comma_handling(tree))
        return 0;
    if (or_handling(tree))
        return 0;
    if (and_handling(tree))
        return 0;
    if (right_redirection_handling(tree))
        return 0;
    if (left_redirection_handling(tree))
        return 0;
    if (pipe_handling(tree))
        return 0;
    if (parentheses_handling(tree))
        return 0;
    cmd = split(tree->data, cmd_seg);
    interpretor(cmd);
    free_2d_array(cmd);
    return 0;
}
