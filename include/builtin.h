/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Builtin command function's prototypes
*/

#include <time.h>

typedef struct history_s {
    int num;
    struct tm *time;
    char *command;
} history_t;

int builtin(char **cmd);

void del_history(void *data);

int history_cmd(char **cmd);

int my_cd(char **cmd);

int my_env(char **cmd);

int my_exit(char **cmd);

int my_setenv(char **cmd);

int my_unsetenv(char **cmd);

history_t *new_command(char *command);

void print_history(void *data, void *separator, int is_seperator);

extern plist_t history;

#pragma once
