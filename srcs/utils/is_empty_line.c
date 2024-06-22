/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to check if a line is empty or not
*/

#include "../../include/utils.h"

int is_empty_line(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
            return 0;
    return 1;
}
