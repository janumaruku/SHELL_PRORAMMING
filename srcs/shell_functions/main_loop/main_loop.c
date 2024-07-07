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

    while (1) {
        cmd = prompt();
        if (!cmd)
            continue;
        interpretor(cmd);
        free_2d_array(cmd);
    }
}
