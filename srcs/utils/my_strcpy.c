/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** my_strcpy
*/

#include "../../include/utils.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
