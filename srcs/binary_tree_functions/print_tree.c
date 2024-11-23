/*
** EPITECH PROJECT, 2024
** BINARY TREE
** File description:
** Functions to print the tree
*/

#include "../../include/utils.h"
#include "../../include/binary_tree.h"

// void print_tree_prefix(tree_t *tree, void (*func)(void *))
// {
//     if (tree == NULL)
//         return;
//     if (tree->parent != NULL){
//         func(tree->parent->data);
//         printf(" -> ");
//         func(tree->data);
//     }
//     else {
//         func(tree->data);
//         printf("\n");
//     }
//     print_tree_prefix(tree->tleft, func);
//     print_tree_prefix(tree->tright, func);
// }

void print_tree_prefix(tree_t *tree, void (*func)(void *))
{
    if (tree == NULL)
        return;
    print_tree_prefix(tree->tleft, func);
    func(tree->data);
    print_tree_prefix(tree->tright, func);
}
