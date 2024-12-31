/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The main loop function
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"
#include "../../../include/binary_tree.h"
#include "../../../include/command_parsing.h"

char *cli;
tree_t *command_tree;

void func1(void *data)
{
    char *d = (char *)data;

    free(d);
}

int main_loop(void)
{
    char **cmd = NULL;

    command_tree = NULL;
    cli = NULL;
    while (1) {
        cli = prompt2();
        if (!cli)
            continue;
        history = push_back(history, new_command(my_strdup(cli)));
        command_tree = semicolon_parsing(cli);
        processing(command_tree);
        free(cli);
        cli = NULL;
        clean_tree(command_tree, str_pop);
        command_tree = NULL;
    }
    return 0;
}
