/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to display a 2d array
*/

#include "../../include/utils.h"

void disp_2d_array(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
