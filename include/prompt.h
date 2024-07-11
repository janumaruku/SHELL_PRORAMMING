/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Prompt functions
*/

#include <termios.h>
#include <unistd.h>

#define COMMAND_MAX_LENGTH 2048

typedef struct line_edition {
    char *cmd;
    int pos;
    int len;
    int done;
} line_edition_t;

line_edition_t *backspace(line_edition_t *p);

line_edition_t *backward_char(line_edition_t *p);

int del_char(line_edition_t *p, char c);

void disable_raw_mode(void);

line_edition_t *down_history(line_edition_t *p);

void enable_raw_mode(void);

line_edition_t *enter(line_edition_t *p);

line_edition_t *forspace(line_edition_t *p);

line_edition_t *forward_char(line_edition_t *p);

void m_prompt(void);

int multi_char_binding(line_edition_t *p);

int others(line_edition_t *p, char c);

char **prompt(void);

char **prompt2(void);

line_edition_t *up_history(line_edition_t *p);

#pragma once
