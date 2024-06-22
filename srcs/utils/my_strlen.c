/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** lenght of a string
*/

#include "../../include/utils.h"

int my_strlen(const char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
