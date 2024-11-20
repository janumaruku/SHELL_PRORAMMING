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

int my_exit(char **cmd)
{
    my_putstr("exit\n");
    free(past_dir);
    free_job(job_list);
    free_2d_array(cmd);
    free_2d_array(t_env);
    clear_list(&l_env, str_pop);
    clear_list(&history, del_history);
    if (current_command != NULL)
        free(current_command);
    // free(current_command);
    exit(0);
}
