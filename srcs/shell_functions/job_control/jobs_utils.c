/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Job control utils functions
*/

#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/job_control.h"

jobs_t *init_job_list(void)
{
    jobs_t *res = malloc(sizeof(jobs_t));

    res->jobs = new_list();
    res->curr = NULL;
    res->next = NULL;
    res->last_id = 0;
    return res;
}

void free_job(jobs_t *jobs)
{
    clear_list(&(jobs->jobs), job_pop);
    free(jobs);
}

job_t *set_job_state(job_status_t state, job_t *job)
{
    char *c_states[4] = {RUNNING, SUSPENDED, DONE, TERMINATED};
    job_status_t states[4] = {RUNG, STP, DN, TRMTD};

    for (int i = 0; i < 4; i++)
        if (state == states[i]) {
            job->state = state;
            job->c_state = my_strdup(c_states[i]);
            return job;
        }
    return NULL;
}
