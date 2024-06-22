/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to compare n caracters in two strings
*/

#include "../../include/utils.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    for (i = 0; s1[i] && s2[i] && i < n; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return i == n ? 0 : s1[i] - s2[i];
}
