/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The functions prototypes
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "linked_list.h"
#include "job_control.h"
#include "binary_tree.h"

extern int exit_status;

extern plist_t l_env;

extern char *past_dir;

extern char **t_env;

int cmd_seg(char c);

int colon_seg(char c);

int env_var_search(void *expected, void *data);

int interpretor(char **cmd);

void job_pop(void *data);

int main_loop(void);

char *my_getenv(char *varname);

int processing(tree_t *tree);

int runner(char *path, char **cmd);

void str_disp(void *data, void *sep, int b);

void str_pop (void *data);

#pragma once
