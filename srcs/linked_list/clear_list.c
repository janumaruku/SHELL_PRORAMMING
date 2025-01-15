/*
** EPITECH PROJECT, 2024
** clear_list.c
** File description:
** function to clear my linked list
*/

#include "../../include/linked_list.h"
#include "../../include/utils.h"

void clear_list(linked_list_t **list, void (*func)(void *data))
{
    if (*list == NULL || is_empty_list(*list)) {
        mem_free(*list);
        return;
    }
    *list = pop_front(*list, func);
    clear_list(list, func);
}
