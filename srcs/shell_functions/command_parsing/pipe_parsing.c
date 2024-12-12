/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Funtions for pipe parsing
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"
#include"../../../include/binary_tree.h"
#include"../../../include/command_parsing.h"

tree_t *pipe_parsing(char *str)
{
    tree_t *tr;
    int i = my_strlen(str) - 1;
    int a[3] = {0, 0, 0};

    for (; i >= 0; i--) {
        a[0] = str[i] == ')' ? a[0] + 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 0 ? a[1] + 1 : a[1];
        if (my_strncmp("||", &str[i] ,2) == 0 && a[0] == 0 && a[1] == 0) {
            a[2] = 1;
            str[i] = 0;
            tr = join_tree(pipe_parsing(str),
            new_tree(my_strdup(&str[i + 2])), my_strdup("|"));
        }
        a[0] = str[i] == '(' ? a[0] - 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 1 ? a[1] - 1 : a[1];
    }
    if (a[2] == 0)
        return new_tree(my_strdup(str));
    return tr;
}
