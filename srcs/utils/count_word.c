/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to count number of word in a function
*/

#include "../../include/utils.h"

int count_word(char const *str, int (*func)(char))
{
    int i = 0;
    int c = 0;

    while (str[i]) {
        while (str[i] && !func(str[i]))
            i++;
        if (func(str[i]))
            c++;
        while (str[i] && func(str[i]))
            i++;
    }
    return c;
}
