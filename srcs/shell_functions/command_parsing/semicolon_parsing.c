/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Functions for semicolons parsing
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"
#include"../../../include/binary_tree.h"

tree_t *semicolon_parsing(char *str)
{
    tree_t *tr;
    int i = my_strlen(str) - 1;
    int a[3] = {0, 0, 0};

    for (; i >= 0; i--) {
        a[0] = str[i] == ')' ? a[0] + 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 0 ? a[1] + 1 : a[1];
        if (str[i] == ';' && a[0] == 0 && a[1] == 0) {
            a[2] = 1;
            str[i] = 0;
            tr = join_tree(semicolon_parsing(str),
            or_parsing(&str[i + 1]), my_strdup(";"));
        }
        a[0] = str[i] == '(' ? a[0] - 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 1 ? a[1] - 1 : a[1];
    }
    if (a[2] == 0)
        return or_parsing(str);
    return tr;
}

tree_t *tree_from_cmd(char *str)
{
    tree_t *tr;
    int i = my_strlen(str) - 1;
    int a[3] = {0, 0, 0};

    for (; i >= 0; i--) {
        a[0] = str[i] == ')' && a[0] == 0 ? a[0] + 1 : a[0];
        a[1] = str[i] == '`' && a[1] == 0 ? a[1] + 1 : a[1];
        if (str[i] == ';' && a[0] == 0 && a[1] == 0) {
            a[2] = 1;
            str[i] = 0;
            tr = join_tree(tree_from_cmd(str),
            tree_from_cmd_or(&str[i + 1]), my_strdup(";"));
        }
        a[0] = str[i] == '(' && a[0] == 1 ? a[0] - 1 : a[0];
        a[1] = str[i] == '`' && a[1] == 1 ? a[1] - 1 : a[1];
    }
    if (a[2] == 0)
        return tree_from_cmd_or(str);
    return tr;
}
