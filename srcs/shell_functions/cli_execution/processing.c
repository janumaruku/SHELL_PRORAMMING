/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Functions to execute a command line
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"
#include "../../../include/binary_tree.h"
#include "../../../include/command_parsing.h"

int processing(tree_t *tree)
{
    char **cmd = NULL;
    if (tree == NULL)
        return 0;
    if (my_strcmp(tree->data, ";") == 0) {
        processing(tree->tleft);
        processing(tree->tright);
        return 0;
    }
    if (my_strcmp(tree->data, "||") == 0) {
        processing(tree->tleft);
        if (exit_status != 0)
            processing(tree->tright);
        return 0;
    }
    if (my_strcmp(tree->data, "&&") == 0) {
        processing(tree->tleft);
        if (exit_status == 0)
            processing(tree->tright);
        return 0;
    }
    cmd = split(tree->data, cmd_seg);
    interpretor(cmd);
    free_2d_array(cmd);
    return 0;
}
