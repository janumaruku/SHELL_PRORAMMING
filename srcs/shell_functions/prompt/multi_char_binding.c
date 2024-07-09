/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function for multi character binding
*/

#include "../../../include/prompt.h"
#include "../../../include/shell.h"
#include "../../../include/utils.h"

line_edition_t *up_history(line_edition_t *p)
{
    return p;
}

line_edition_t *down_history(line_edition_t *p)
{
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
