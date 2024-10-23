/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function for multi character binding
*/

#include "../../../include/prompt.h"
#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/builtin.h"

extern char *current_command;

line_edition_t *up_history(line_edition_t *p)
{
    // my_putstr("I'm here.\n");
    if (history->lenght == 0) {
        printf("The list is empty.\n");
        return p;
    }
    if (history->cursor == NULL) {
        if (history->cursor == history->begin->prev) {
            printf("The cursor is at top.\n");
            return p;
        }
        history->cursor = history->end;
    }
    if (history->cursor == history->end) {
        printf("The cursor is on last node.\n");
        my_strcpy(current_command, p->cmd);
    }
    my_strcpy(p->cmd, ((history_t *)(history->cursor->data))->command);
    p->len = my_strlen(p->cmd);
    p->pos = p->len;
    history->cursor = history->cursor->prev;
    kill_whole_line(p);
    printf("%s==>", p->cmd);
    // fflush(stdout);
    return p;
}

line_edition_t *down_history(line_edition_t *p)
{
    // my_putstr("I'm here.\n");
    if (history->lenght == 0)
        return p;
    if (history->cursor == NULL) {
        if (history->cursor == history->end->next) {
            if (my_strcmp(p->cmd, current_command) == 0)
                return p;
            my_strcpy(p->cmd, current_command);
            p->len = my_strlen(p->cmd);
            p->pos = p->len;
            return p;
        }
        history->cursor = history->begin;
    }
    // if (history->cursor == history->end)
    //     my_strcpy(current_command, p->cmd);
    my_strcpy(p->cmd, ((history_t *)(history->cursor->data))->command);
    p->len = my_strlen(p->cmd);
    p->pos = p->len;
    history->cursor = history->cursor->next;
    kill_whole_line(p);
    printf("%s", p->cmd);
    fflush(stdout);
    return p;
}

line_edition_t *forward_char(line_edition_t *p)
{
    if (p->pos >= 0 && p->pos < p->len) {
        printf("%c", p->cmd[p->pos]);
        p->pos += 1;
    }
    return p;
}

line_edition_t *backward_char(line_edition_t *p)
{
    if (p->pos > 0 && p->pos <= p->len) {
        printf("\b");
        p->pos -= 1;
    }
    return p;
}

int multi_char_binding(line_edition_t *p)
{
    char c = 0;
    char *bindkey = "ABCD";
    line_edition_t * (*func[4])(line_edition_t *) =
    {up_history, down_history, forward_char, backward_char};

    getchar();
    c = getchar();
    for (int i = 0; bindkey[i]; i++) {
        if (c == bindkey[i]) {
            p = func[i](p);
            return 1;
        }
    }
    return 0;
}
