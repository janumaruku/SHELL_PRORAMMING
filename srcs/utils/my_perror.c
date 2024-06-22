/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to print error message on error output using errno
*/

#include "../../include/utils.h"

void my_perror(char const *str)
{
    err_putstr(str);
    err_putstr(": ");
    if (errno == ENOEXEC)
        err_putstr("Exec format error. Wrong Architecture");
    else
        err_putstr(strerror(errno));
    err_putstr(".\n");
}
