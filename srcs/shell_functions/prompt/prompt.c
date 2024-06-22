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
    char **e_cmd = NULL;
    char **cmd = NULL;

    my_putstr("[janumaruku] user>");
    g = getline(&line, &l, stdin);
    if (g == -1) {
        e_cmd = malloc(sizeof(char *) * 2);
        e_cmd[0] = my_strdup("exit");
        e_cmd[1] = NULL;
        my_exit(e_cmd);
    }
    if (is_empty_line(line))
        return NULL;
    cmd = split(line, cmd_seg);
    free(line);
    return cmd;
}