/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to display environment variables
*/

#include "../../../include/shell.h"
#include "../../../include/linked_list.h"
#include "../../../include/utils.h"

int my_env(char **cmd)
{
    if (cmd[1] != NULL) {
        printf("env: %s: No such file or directory.\n", cmd[1]);
        return 1;
    }
    disp_list(l_env, "\n", str_disp);
    my_putchar('\n');
    return 0;
}
