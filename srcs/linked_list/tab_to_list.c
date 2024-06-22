/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to convert a 2d array to a linked list
*/

#include "../../include/utils.h"
#include "../../include/linked_list.h"

plist_t tab_to_list(char *env[])
{
    plist_t list = new_list();

    for (int i = 0; env[i]; i++)
        list = push_back(list, my_strdup(env[i]));
    return list;
}
