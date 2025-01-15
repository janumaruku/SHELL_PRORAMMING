/*
** EPITECH PROJECT, 2024
** BINARY TREE
** File description:
** Function to clean a binary tree
*/

#include "../../include/binary_tree.h"
#include "../../include/utils.h"

tree_t *clean_tree(tree_t *tree, void (*func)(void *))
{
    if (tree == NULL)
        return NULL;
    clean_tree(tree->tleft, func);
    clean_tree(tree->tright, func);
    // printf("Deleting %s\n", tree->data);
    func(tree->data);
    mem_free(tree);
    return NULL;
}