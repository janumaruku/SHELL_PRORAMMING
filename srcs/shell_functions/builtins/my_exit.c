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
    exit(0);
}
