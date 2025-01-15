/*
** EPITECH PROJECT, 2024
** SECURED
** File description:
** Function to delete an element at the end of the linked list
*/

#include "../../include/linked_list.h"

linked_list_t *pop_back(linked_list_t *li, void (*func)(void *data))
{
    node_t *tp = li->end;

    if (li == NULL || is_empty_list(li))
        return li;
    if (li->lenght == 1) {
        li->begin = NULL;
        li->end = NULL;
        li->cursor = NULL;
        free_node(&tp, func);
        li->lenght -= 1;
        return li;
    }
    li->end = li->end->prev;
    li->end->next = NULL;
    li->cursor = li->end;
    li->lenght -= 1;
    free_node(&tp, func);
    return li;
}
