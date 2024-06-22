/*
** EPITECH PROJECT, 2023
** getnbr
** File description:
** prendre le nombre uniquement
*/

#include "../../include/utils.h"

int my_getnbr(char const *str)
{
    int a = 1;
    int n = 0;
    int t;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        t = str[i] - 48;
        n = (n * 10) + t;
        i++;
    }
    return n;
}
