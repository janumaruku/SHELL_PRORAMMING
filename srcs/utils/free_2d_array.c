/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to free a 2D array
*/

#include "../../include/utils.h"

void free_2d_array(char **map)
{
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}
