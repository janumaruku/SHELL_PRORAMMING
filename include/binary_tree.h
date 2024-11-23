/*
** EPITECH PROJECT, 2024
** BINARY TREE
** File description:
** Binary tree function prototype
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
    void *data;
    struct tree *tleft;
    struct tree *tright;
    struct tree *parent;
} tree_t;

tree_t *clean_tree(tree_t *tree, void (*func)(void *));

tree_t *join_tree(tree_t *left, tree_t *right, void *str);

tree_t *new_tree(void *);

void print_tree_prefix(tree_t *tree, void (*func)(void *));

tree_t *tree_from_cmd(char *str);

#pragma once
