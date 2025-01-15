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
extern pnode_t top_reached;
extern pnode_t buttom_reached;

line_edition_t *up_history(line_edition_t *p)
{
    if (history->lenght == 0)
        return p;
    if (history->cursor == top_reached)
        return p;
    if (history->cursor == buttom_reached)
        history->cursor = history->end;
    else
        history->cursor = history->cursor->prev;
    if (history->cursor == history->end)
        my_strcpy(current_command, p->cmd);
    kill_whole_line(p);
    my_strcpy(p->cmd, ((history_t *)(history->cursor->data))->command);
    p->len = my_strlen(p->cmd);
    p->pos = p->len;
    printf("%s", p->cmd);
    fflush(stdout);
    if (history->cursor == history->begin)
        history->cursor = top_reached;
    return p;
}

line_edition_t *down_history(line_edition_t *p)
{
    if (history->lenght == 0)
        return p;
    if (history->cursor == top_reached)
        history->cursor = history->begin->next;
    else if (history->cursor == history->end || history->cursor == buttom_reached)
        history->cursor = buttom_reached;
    else
        history->cursor = history->cursor->next;
    kill_whole_line(p);
    if (history->cursor == buttom_reached)
        my_strcpy(p->cmd, current_command);
    else
        my_strcpy(p->cmd, ((history_t *)(history->cursor->data))->command);
    p->len = my_strlen(p->cmd);
    p->pos = p->len;
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
