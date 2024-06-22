/*
** EPITECH PROJECT, 2024
** pop_element.c
** File description:
** deleting any element of my linked_list
*/

#include "../../include/linked_list.h"

linked_list_t *pop_element(linked_list_t *list, node_t *node,
    void (*func)(void *data))
{
    node_t *tp = node->prev;

    if (list->begin == node) {
        list = pop_front(list, func);
        return list;
    }
    if (list->end == node) {
        list = pop_back(list, func);
        return list;
    }
    tp->next = node->next;
    node->next->prev = tp;
    free_node(&node, func);
    list->lenght -= 1;
    return list;
}
