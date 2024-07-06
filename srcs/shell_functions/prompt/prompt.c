/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to display the prompt
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"

char **prompt(void)
{
    char *line = NULL;
    size_t l = 0;
    int g = 0;
    char **exit_cmd = NULL;
    char **cmd = NULL;

    my_putstr("[janumaruku] user>");
    g = getline(&line, &l, stdin);
    if (g == -1) {
        exit_cmd = malloc(sizeof(char *) * 2);
        exit_cmd[0] = my_strdup("exit");
        exit_cmd[1] = NULL;
        free(line);
        my_exit(exit_cmd);
    }
    if (is_empty_line(line))
        return NULL;
    cmd = split(line, cmd_seg);
    free(line);
    return cmd;
}