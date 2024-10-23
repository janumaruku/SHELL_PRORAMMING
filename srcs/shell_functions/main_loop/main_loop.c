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

int main_loop(void)
{
    char *cli = NULL;
    char **cmd = NULL;
    // char *cli = NULL;

    while (1) {
        cli = prompt2();
        // disp_2d_array(cmd);
        if (!cli)
            continue;
        // cmd = split(cli, cmd_seg);
        cmd = split(cli, cmd_seg);
        history = push_back(history, new_command(cli));
        if (builtin(cmd)) {
            // free(cli);
            free_2d_array(cmd);
            continue;
        }
        interpretor(cmd);
        // free(cli);
        free_2d_array(cmd);
    }
}
