/*
** EPITECH PROJECT, 2024
** push_back.c
** File description:
** push_back function
*/

#include "../../include/linked_list.h"
#include "../../include/utils.h"

node_t *fill_node(void *var)
{
    node_t *node = malloc(sizeof(node_t));

    node->data = var;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

linked_list_t *push_back(linked_list_t *list, void *var)
{
    node_t *node = fill_node(var);

    if (list == NULL || is_empty_list(list)) {
        list->begin = node;
        list->end = node;
        list->cursor = node;
        list->lenght += 1;
        return list;
    }
    list->end->next = node;
    node->prev = list->end;
    list->end = list->end->next;
    list->cursor = list->end;
    list->lenght += 1;
    return list;
}

linked_list_t *push_front(linked_list_t *list, void *var)
{
    node_t *node = fill_node(var);

    if (list == NULL || is_empty_list(list)) {
        list->begin = node;
        list->end = node;
        list->lenght += 1;
        return list;
    }
    node->next = list->begin;
    list->begin->prev = node;
    list->begin = list->begin->prev;
    list->lenght += 1;
    return list;
}
