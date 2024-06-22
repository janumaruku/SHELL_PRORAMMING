/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** program that displays characters of a string
*/

#include "../../include/utils.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
