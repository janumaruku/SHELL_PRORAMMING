/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Job control utils functions
*/

#include "../../../include/utils.h"
#include "../../../include/job_control.h"

jobs_t *init_job_list(void)
{
    jobs_t *res = malloc(sizeof(jobs_t));

    res->jobs = new_list();
    res->curr = NULL;
    res->next = NULL;
    return res;
}
