/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to duplicate a string
*/

#include "../../include/utils.h"

char *my_strdup(char const *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(dest, str);
    return dest;
}
