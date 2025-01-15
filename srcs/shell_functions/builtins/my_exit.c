/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The exit function
*/

#include "../../../include/shell.h"
#include "../../../include/builtin.h"
#include "../../../include/utils.h"
#include "../../../include/job_control.h"

extern char *current_command;
extern pnode_t top_reached;
extern pnode_t buttom_reached;
extern char *cli;
extern tree_t *command_tree;

int my_exit(char **cmd)
{
    if (isatty(0))
        my_putstr("exit\n");
    mem_free(past_dir);
    free_job(job_list);
    free_2d_array(cmd);
    free_2d_array(t_env);
    clear_list(&l_env, str_pop);
    clear_list(&l_shell_var, str_pop);
    clear_list(&history, del_history);
    if (cli)
        mem_free(cli);
    if (current_command != NULL)
        mem_free(current_command);
    if (command_tree)
        clean_tree(command_tree, str_pop);
    free_node(&top_reached, str_pop);
    free_node(&buttom_reached, str_pop);
    exit(0);
}
