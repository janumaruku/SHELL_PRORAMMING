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
    return res;
}

void free_job(jobs_t *jobs)
{
    clear_list(&(jobs->jobs), job_pop);
    free(jobs);
}

char *set_job_state(job_status_t state)
{
    char *c_states[4] = {RUNNING, SUSPENDED, DONE, TERMINATED};
    job_status_t states[4] = {RUNG, STP, DN, TRMTD};

    for (int i = 0; i < 4; i++)
        if (state == states[i])
            return my_strdup(c_states[i]);
    return NULL;
}
