/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Prompt functions
*/

#include <termios.h>
#include <unistd.h>

typedef struct line_edition {
    char *cmd;
    int pos;
    int len;
} line_edition_t;

line_edition_t *backward_char(line_edition_t *p);

void disable_raw_mode(void);

line_edition_t *down_history(line_edition_t *p);

void enable_raw_mode(void);

line_edition_t *forward_char(line_edition_t *p);

char **prompt(void);

line_edition_t *up_history(line_edition_t *p);

#pragma once
