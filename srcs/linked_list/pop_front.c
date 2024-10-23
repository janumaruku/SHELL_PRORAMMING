/*
** EPITECH PROJECT, 2024
** pop_front.c
** File description:
** removing the first element of my linked list
*/

#include "../../include/linked_list.h"

linked_list_t *pop_front(linked_list_t *list, void (*func)(void *data))
{
    node_t *actuel = list->begin;

    if (is_empty_list(list))
        return list;
    if (list->lenght == 1) {
        list->begin = NULL;
        list->end = NULL;
        list->cursor = NULL;
        free_node(&actuel, func);
        list->lenght -= 1;
        return list;
    }
    list->begin = list->begin->next;
    list->begin->prev = NULL;
    free_node(&actuel, func);
    list->lenght -= 1;
    return list;
}
