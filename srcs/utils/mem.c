/*
** EPITECH PROJECT, 2025
** SHELL PROGRAMMING
** File description:
** Functions for memory management
*/

#include "../../include/utils.h"

void *mem_clean(void *p)
{
    if (p)
        free(p);
    return NULL;
}
