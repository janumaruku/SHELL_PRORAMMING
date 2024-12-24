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

extern char *current_command;
extern pnode_t top_reached;
extern pnode_t buttom_reached;

void func3(void *data)
{
    char *d = (char *)data;

    free(d);
}

int processing(tree_t *tree)
{
    char **cmd = NULL;
    int fd = 0;
    int pid = 0;

    if (tree == NULL)
        return 0;
    if (my_strcmp(tree->data, ";") == 0) {
        processing(tree->tleft);
        processing(tree->tright);
        return 0;
    }
    if (my_strcmp(tree->data, "||") == 0) {
        processing(tree->tleft);
        if (exit_status != 0)
            processing(tree->tright);
        return 0;
    }
    if (my_strcmp(tree->data, "&&") == 0) {
        processing(tree->tleft);
        if (exit_status == 0)
            processing(tree->tright);
        return 0;
    }
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
            free(past_dir);
            free_job(job_list);
            // // free_2d_array(cmd);
            free_2d_array(t_env);
            clear_list(&l_env, str_pop);
            clear_list(&history, del_history);
            // if (current_command != NULL)
            //     free(current_command);
            // // free(current_command);
            free_node(&top_reached, str_pop);
            free_node(&buttom_reached, str_pop);
            clean_tree(tree, func3);
            exit(0);
        }
        waitpid(pid, NULL, WUNTRACED);
        return 0;
    }
    if (my_strcmp(tree->data, "<") == 0 || my_strcmp(tree->data, "<<") == 0) {
        if (my_strcmp(tree->data, "<") == 0) {
            fd = open(tree->tright->data, O_RDONLY);
            if (fd < 0) {
                my_perror(tree->tright->data);
                return 0;
            }
            pid = fork();
            if (pid == 0) {
                dup2(fd, STDIN_FILENO);
                close(fd);
                processing(tree->tleft);
                free(past_dir);
                free_job(job_list);
                // // free_2d_array(cmd);
                free_2d_array(t_env);
                clear_list(&l_env, str_pop);
                clear_list(&history, del_history);
                // if (current_command != NULL)
                //     free(current_command);
                // // free(current_command);
                free_node(&top_reached, str_pop);
                free_node(&buttom_reached, str_pop);
                clean_tree(tree, func3);
                exit(0);
            }
            waitpid(pid, NULL, WUNTRACED);
        }
        close(fd);
        return 0;
    }
    cmd = split(tree->data, cmd_seg);
    interpretor(cmd);
    free_2d_array(cmd);
    return 0;
}
