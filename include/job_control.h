/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Job control functions
*/

#include "linked_list.h"
#define RUNNING "Running"
#define SUSPENDED "Suspended"
#define DONE "Done"
#define TERMINATED "Terminated"

typedef struct jobs_s jobs_t;

extern jobs_t *job_list;

typedef enum {
    RUNG,
    STP,
    DN,
    TRMTD
} job_status_t;

typedef struct job_s {
    int num;
    int pid;
    job_status_t state;
    char *c_state;
    char *cmd;
} job_t;

struct jobs_s {
    plist_t jobs;
    pnode_t curr;
    pnode_t next;
};

void free_job(jobs_t *jobs);

jobs_t *init_job_list(void);

char *set_job_state(job_status_t state);

#pragma once
