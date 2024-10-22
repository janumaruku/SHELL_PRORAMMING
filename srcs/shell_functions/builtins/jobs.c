/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** jobs function to display all suspended jobs
*/

#include "../../../include/shell.h"
#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/builtin.h"
#include "../../../include/job_control.h"

int jobs(char **cmd)
{
    disp_list(job_list->jobs, "\n", print_job);
    if (job_list->jobs->lenght > 0)
        printf("\n");
}
