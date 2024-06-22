/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to compare two strings
*/

#include "../../include/utils.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return s1[i] - s2[i];
}
