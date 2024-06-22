/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** my_strcpy
*/

#include "../../include/utils.h"

char **split_colons(char *str)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * strlen(str));
    char *token = strtok(str, ";");

    while (token != NULL) {
        tab[i] = token;
        i++;
        token = strtok(NULL, ";");
    }
    tab[i] = NULL;
    return tab;
}
