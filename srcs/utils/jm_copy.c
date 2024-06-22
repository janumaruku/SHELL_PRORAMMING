/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to copy a string
*/

#include "../../include/utils.h"

char *jm_copy(char *dest, char const *src, int (*func)(char))
{
    int i = 0;

    while (src[i] && func(src[i])) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
