/*
** EPITECH PROJECT, 2024
** BINARY
** File description:
** TREE
*/

#include "../../include/binary_tree.h"
#include "../../include/utils.h"

tree_t *new_tree(void *data)
{
    tree_t *tree = malloc(sizeof(tree_t));

    tree->data = data;
    tree->parent = NULL;
    tree->tleft = NULL;
    tree->tright = NULL;
    return tree;
}
