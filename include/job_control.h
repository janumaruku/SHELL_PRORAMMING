/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Job control functions
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "linked_list.h"
#define RUNNING "Running"
#define SUSPENDED "Suspended"
#define DONE "Done"
#define TERMINATED "Terminated"
#define CURRENT 0
#define NEXT 1
#define NOTHING 2

typedef struct jobs_s jobs_t;

typedef struct job_s job_t;

extern job_t *_cur_process;

// extern int cur_process;

extern jobs_t *job_list;

typedef enum {
    RUNG,
    STP,
    DN,
    TRMTD
} job_status_t;

struct job_s {
    int num;
    int pid;
    int exit_status;
    int curr_or_next;
    job_status_t state;
    char *c_state;
    char *cmd;
};

struct jobs_s {
    plist_t jobs;
    pnode_t curr;
    pnode_t next;
    int last_id;
};

int fg(char **cmd);

void free_job(jobs_t *jobs);

jobs_t *init_job_list(void);

void job_control(int signum);

int job_search(void *expected, void *data);

int jobs(char **cmd);

void print_job(void *data, void *sep, int b);

job_t *set_job_state(job_status_t state, job_t *job);

void set_sigaction(struct sigaction *sa);

void SIGCHLD_handler(int signuum);

#pragma once
