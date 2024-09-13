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

int tab_weight(char **tab)
{
    int i = 0;

    for (int j = 0; tab[j]; j++)
        for (int k = 0; tab[j][k]; k++)
            i++;
    return i;
}

char **tab_dup(char **tab)
{
    char **res = malloc(sizeof(char *) * (tab_len(tab) + 1));
    int i = 0;

    for (; tab[i]; i++)
        res[i] = my_strdup(tab[i]);
    res[i] = 0;
    return res;
}

char *tab_to_str(char **tab)
{
    int len = tab_weight(tab) + tab_len(tab);
    char *str = malloc(sizeof(char) * len);
    int k = 0;
    int i = 0;

    for (i = 0; tab[i + 1]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            str[k] = tab[i][j];
            k++;
        }
        str[k] = ' ';
        k++;
    }
    for (int j = 0; tab[i][j]; j++) {
        str[k] = tab[i][j];
        k++;
    }
    str[k] = 0;
    return str;
}
