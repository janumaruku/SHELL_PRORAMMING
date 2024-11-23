/*
** EPITECH PROJECT, 2024
** BINARY TREE
** File description:
** Function to join tree
*/

#include "../../include/binary_tree.h"

tree_t *join_tree(tree_t *left, tree_t *right, void *data)
{
    tree_t *tree = new_tree(data);

    tree->tleft = left;
    tree->tright = right;
    if (left != NULL)
        left->parent = tree;
    if (right != NULL)
        right->parent = tree;
    return tree;
}
