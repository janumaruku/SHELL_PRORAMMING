/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Separator functions
*/

#include "../../../include/shell.h"

int cmd_seg(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
        return 0;
    return 1;
}

int colon_seg(char c)
{
    if (c == ':')
        return 0;
    return 1;
}
