/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to execute a command line
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"

int runner(char *path, char **cmd)
{
    int child = fork();

    if (child == 0) {
        if (!execve(path, cmd, t_env)) {
            perror(cmd[0]);
            free_2d_array(t_env);
            clear_list(&l_env, str_pop);
        }        
    }
    wait(NULL);
    return 0;
}
