/*
** EPITECH PROJECT, 2024
** SECURED
** File description:
** Functioni to free a node in the linked list
*/

#include "../../include/linked_list.h"

void free_node(node_t **node, void (*func)(void *data))
{
    func((*node)->data);
    free(*node);
}
