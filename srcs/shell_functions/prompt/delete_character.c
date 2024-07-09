/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to manage character deleting
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/prompt.h"

line_edition_t *backspace(line_edition_t *p)
{
    if (p->pos == 0)
        return p;
    printf("\b");
    if (p->pos == p->len) {
        p->cmd[p->len - 1] = 0;
        printf(" ");
    } else {
        printf("%s ", &p->cmd[p->pos]);
        memmove(&p->cmd[p->pos - 1], &p->cmd[p->pos], p->len - p->pos + 1);
        p->cmd[p->len - 1] = 0;
    }
    printf("\b");
    for (int i = p->pos; i < p->len; i++) {
        printf("\b");
    }
    p->pos -= 1;
    p->len -= 1;
    return p;
}

line_edition_t *forspace(line_edition_t *p)
{
    if (p->len == 0 || p->len == p->pos)
        return p;
    if (p->pos < p->len) {
        printf("%s ", &p->cmd[p->pos + 1]);
        memmove(&p->cmd[p->pos], &p->cmd[p->pos + 1], p->len - p->pos + 1);
        p->cmd[p->len - 1] = 0;
        for (int i = p->pos; i < p->len; i++) {
            printf("\b");
        }
        p->len -= 1;
        return p;
    }
    return p;
}

int del_char(line_edition_t *p, char c)
{
    if (c == 127) {
        p = backspace(p);
        return 1;
    }
    else {
        p = forspace(p);
        return 1;
    }
    return 0;
}
