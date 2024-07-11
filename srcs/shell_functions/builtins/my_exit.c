/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The exit function
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"

int my_exit(char **cmd)
{
    my_putstr("exit\n");
    free(past_dir);
    free_2d_array(cmd);
    free_2d_array(t_env);
    clear_list(&l_env, str_pop);
    exit(0);
}
