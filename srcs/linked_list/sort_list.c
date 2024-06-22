/*
** EPITECH PROJECT, 2024
** LINKED LIST
** File description:
** Function to sort the list
*/

#include "../../include/linked_list.h"
#include "../../include/utils.h"

void partition(pnode_t temp, pnode_t *a, pnode_t *b)
{
    pnode_t fast;
    pnode_t slow;

    if (temp == NULL || temp->next == NULL) {
        *a = temp;
        *b = NULL;
    } else {
        slow = temp;
        fast = temp->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        *a = temp;
        *b = slow->next;
        slow->next = NULL;
    }
}

pnode_t merge(pnode_t a, pnode_t b, int (*func)(void *, void *))
{
    pnode_t res = 0;

    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    if (func(a->data, b->data) <= 0) {
        res = a;
        res->next = merge(a->next, b, func);
    } else {
        res = b;
        res->next = merge(a, b->next, func);
    }
    return res;
}

pnode_t sort_inter(pnode_t list, int (*func)(void *, void *))
{
    pnode_t temp = list;
    pnode_t a = 0;
    pnode_t b = 0;

    if (temp == 0 || temp->next == 0)
        return list;
    partition(temp, &a, &b);
    a = sort_inter(a, func);
    b = sort_inter(b, func);
    return merge(a, b, func);
}

void sort_list(plist_t *list, int(*func)(void *, void *))
{
    pnode_t tmp = 0;

    (*list)->begin = sort_inter((*list)->begin, func);
    for (tmp = (*list)->begin; tmp->next != 0; tmp = tmp->next);
    (*list)->end = tmp;
}
