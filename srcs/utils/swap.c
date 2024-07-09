/*
** EPITECH PROJECT, 2024
** UTILS FUNCTIONS
** File description:
** Function to swap two pointer value
*/

#include "../../include/utils.h"

void swap_char(char *a, char *b)
{
    char c = 0;

    c = *a;
    *a = *b;
    *b = c;
}
