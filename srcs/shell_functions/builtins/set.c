/*
** EPITECH PROJECT, 2025
** SHELL PROGRAMMING
** File description:
** Function to set shell variable
*/

#include "../../../include/shell.h"
#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/builtin.h"
#include "../../../include/job_control.h"

extern plist_t history;
extern plist_t l_shell_var;

int set_cmd(char **cmd)
{
    history_t *temp = NULL;

    printf("_");
    fflush(stdout);
    if (history->lenght == 0)
        printf("\n");
    else {
        temp = (history_t *)history->end->data;
        printf("\t%s\n", temp->command);
    }
    printf("\n");
    disp_list(l_shell_var, "\n", str_disp);
    return 0;
}
