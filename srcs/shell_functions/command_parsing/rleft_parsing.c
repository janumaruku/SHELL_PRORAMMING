/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Functions for left redirection parsing
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"
#include"../../../include/binary_tree.h"
#include"../../../include/command_parsing.h"

tree_t *rleft_parsing(char *str)
{
    tree_t *tr;
    int i = my_strlen(str) - 1;
    int a[3] = {0, 0, 0};
    char **command = NULL;

    for (; i >= 0; i--) {
        a[0] = str[i] == ')' ? a[0] + 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 0 ? a[1] + 1 : a[1];
        if (str[i] == '<' && a[0] == 0 && a[1] == 0) {
            a[2] = 1;
            command = operands(str, str[i]);
            tr = join_tree(pipe_parsing(command[0]), new_tree(command[2]), command[1]);
        }
        a[0] = str[i] == '(' ? a[0] - 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 1 ? a[1] - 1 : a[1];
    }
    if (a[2] == 0)
        return pipe_parsing(str);
    return tr;
}
