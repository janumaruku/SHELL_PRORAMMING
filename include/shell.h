/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The functions prototypes
*/

#include "linked_list.h"

extern plist_t l_env;

extern char **t_env;

int cmd_seg(char c);

int colon_seg(char c);

int env_var_search(void *expected, void *data);

int interpretor(char **cmd);

int main_loop(void);

int my_exit(char **cmd);

char **prompt(void);

int runner(char *path, char **cmd);

void str_disp(void *data, void *sep, int b);

void str_pop (void *data);

#pragma once
