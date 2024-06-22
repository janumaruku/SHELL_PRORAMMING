/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to search a character in a string
*/

#include "../../include/utils.h"

int is_char(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (c == str[i])
            return 1;
    }
    return 0;
}
