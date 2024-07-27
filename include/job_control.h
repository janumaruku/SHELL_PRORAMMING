/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Job control functions
*/

#include "linked_list.h"

typedef enum {
    RUNNING,
    STOPPED,
    DONE,
    TERMINATED
} job_status_t;

typedef struct job_s {
    int num;
    int pid;
    job_status_t state;
    char *cmd;
} job_t;

typedef struct jobs_s {
    plist_t jobs;
    pnode_t curr;
    pnode_t next;
} jobs_t;

#pragma once
