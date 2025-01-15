/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** history command implementation
*/

#include "../../../include/shell.h"
#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/builtin.h"
#include "../../../include/job_control.h"

plist_t history;

history_t *new_command(char *command)
{
    history_t *new_command = malloc(sizeof(history_t));
    time_t data = 0;

    if (history->lenght == 0)
        new_command->num = 1;
    else
        new_command->num = ((history_t *)(history->end->data))->num + 1;
    data = time(NULL);
    new_command->time = gmtime(&data);
    new_command->command = command;
    return new_command;
}

void print_history(void *data, void *separator, int is_seperator)
{
    history_t *d = (history_t *)data;
    char *s = (char *)separator;
    history_t *temp = (history_t *)(history->end->data);
    int len = history->lenght == 0 ? 1 : number_len(((history_t *)(history->end->data))->num);

    printf("    %*d  ", len, d->num);
    int strlen = printf("%d:%d", d->time->tm_hour, d->time->tm_min);
    printf("%*s%s", 5 - strlen + 3, "", d->command);
    if (is_seperator)
        printf("%s", s);
    fflush(stdout);
}

void del_history(void *data)
{
    history_t *d = (history_t *)data;

    mem_free(d->command);
    mem_free(d);
}

int history_cmd(char **cmd)
{
    disp_list(history, "\n", print_history);
    my_putchar('\n');
    return 0;
}
