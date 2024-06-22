/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Linked list funtion for strings
*/

#include "../../../include/utils.h"

void str_disp(void *data, void *sep, int b)
{
    char *d = (char *)data;
    char *s = (char *)sep;

    my_putstr(d);
    if (b)
        my_putstr(s);
}

void str_pop (void *data)
{
    char *d = (char *)data;

    free(d);
}