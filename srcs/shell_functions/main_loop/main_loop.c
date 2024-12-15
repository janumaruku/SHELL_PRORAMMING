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

void func1(void *data)
{
    char *d = (char *)data;

    free(d);
}

int main_loop(void)
{
    char *cli = NULL;
    char **cmd = NULL;
    tree_t *tree = NULL;
    // char *cli = NULL;

    while (1) {
        cli = prompt2();
        // disp_2d_array(cmd);
        if (!cli)
            continue;
        // cmd = split(cli, cmd_seg);
        cmd = split(cli, cmd_seg);
        history = push_back(history, new_command(my_strdup(cli)));
        if (builtin(cmd)) {
            // free(cli);
            free_2d_array(cmd);
            continue;
        }
        tree = semicolon_parsing(cli);
        processing(tree);
        // interpretor(cmd);
        free(cli);
        clean_tree(tree, func1);
        free_2d_array(cmd);
    }
}
