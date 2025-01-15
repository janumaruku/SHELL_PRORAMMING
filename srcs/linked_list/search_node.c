/*
** EPITECH PROJECT, 2024
** SECURED
** File description:
** Function to seach a node in the linked list with the key
*/

#include "../../include/linked_list.h"
#include "../../include/utils.h"

node_t *search_node(linked_list_t *li, void *name,
    int (*func)(void *expected, void *data))
{
    node_t *tmp = NULL;

    if (li == NULL || is_empty_list(li))
        return NULL;
    if (func(name, li->begin->data))
        return li->begin;
    if (func(name, li->end->data))
        return li->end;
    tmp = li->begin->next;
    while (tmp != NULL) {
        if (func(name, tmp->data))
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
