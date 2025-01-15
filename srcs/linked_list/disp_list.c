/*
** EPITECH PROJECT, 2024
** disp_list.c
** File description:
** function to display my linked_list
*/

#include "../../include/linked_list.h"
#include "../../include/utils.h"

void disp_list(linked_list_t *list, void *sep,
    void (*func)(void *, void *, int))
{
    node_t *actuel = list->begin;

    if (list == NULL || is_empty_list(list))
        return;
    while (actuel->next != NULL) {
        func(actuel->data, sep, 1);
        actuel = actuel->next;
    }
    func(actuel->data, sep, 0);
}
