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
    char **cmd = NULL;
    char *cli = NULL;

    while (1) {
        cmd = prompt2();
        // disp_2d_array(cmd);
        if (!cmd)
            continue;
        // cmd = split(cli, cmd_seg);
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
