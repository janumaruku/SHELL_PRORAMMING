/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to check if a character is alpha numeric
*/

#include "../../include/utils.h"

int is_anum(char const c)
{
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

int is_alpha(char const c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

bool my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}
