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

int main_loop(void)
{
    char **cmd = NULL;
    char *cli = NULL;

    while (1) {
        cli = prompt2();
        if (!cli)
            continue;
        cmd = split(cli, cmd_seg);
        interpretor(cmd);
        free(cli);
        free_2d_array(cmd);
    }
}
