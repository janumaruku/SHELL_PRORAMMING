/*
** EPITECH PROJECT, 2024
** linked list functions
** File description:
** fonctions for our linked lists
*/

#include "../../include/linked_list.h"

linked_list_t *new_list(void)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->begin = NULL;
    new->end = NULL;
    new->lenght = 0;
    return new;
}

int is_empty_list(linked_list_t *list)
{
    if (list->begin == NULL && list->end == NULL && list->lenght == 0)
        return 1;
    return 0;
}
