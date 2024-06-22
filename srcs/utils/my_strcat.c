/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to concatane two strings
*/

#include "../../include/utils.h"

char *my_strcat(char *dest, char const *src)
{
    int k = my_strlen(dest);
    int i = 0;

    for (; src[i]; i++) {
        dest[k] = src[i];
        k++;
    }
    dest[k] = '\0';
    return dest;
}
