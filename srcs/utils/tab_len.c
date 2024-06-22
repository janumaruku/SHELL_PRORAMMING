/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to count number of line of an array
*/

#include "../../include/utils.h"

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

char **tab_dup(char **tab)
{
    char **res = malloc(sizeof(char *) * (tab_len(tab) + 1));

    for (int i = 0; tab[i]; i++)
        res[i] = my_strdup(tab[i]);
    return res;
}
