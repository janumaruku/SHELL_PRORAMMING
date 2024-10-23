/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** All linked list function prototypes
*/

#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next;
    struct node *prev;
} node_t, *pnode_t;

typedef struct linked_list {
    node_t *begin;
    node_t *end;
    node_t *cursor;
    int lenght;
    int last_id;
} linked_list_t, *plist_t;

void clear_list(linked_list_t **list, void (*func)(void *data));

void disp_list(linked_list_t *list, void *sep,
    void (*func)(void *, void *, int));

node_t *fill_node(void *var);

void free_node(node_t **node, void (*func)(void *data));

int is_empty_list(linked_list_t *list);

linked_list_t *new_list(void);

linked_list_t *pop_back(linked_list_t *li, void (*func)(void *data));

linked_list_t *pop_element(linked_list_t *list, node_t *node,
    void (*func)(void *data));

linked_list_t *pop_front(linked_list_t *list, void (*func)(void *data));

linked_list_t *push_back(linked_list_t *list, void *var);

linked_list_t *push_front(linked_list_t *list, void *var);

node_t *search_node(linked_list_t *li, void *name,
    int (*func)(void *expected, void *data));

void sort_list(plist_t *list, int (*func)(void *, void *));

plist_t tab_to_list(char *env[]);

#pragma once
