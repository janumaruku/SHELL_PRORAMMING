/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to free dynamicaly allocated memory
*/

#include "../../include/utils.h"

void my_free(void *data)
{
    if (data)
        free(data);
    data = NULL;
}
