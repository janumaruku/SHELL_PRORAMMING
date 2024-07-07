/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function for multi character binding
*/

#include "../../../include/prompt.h"

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
