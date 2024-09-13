/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Functions to handle job control
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/job_control.h"

void SIGINT_handler(int signum)
{
    if (_cur_process == NULL)
        return;
    kill(_cur_process->pid, SIGINT);
    printf("\n");
}

void SIGTSTP_handler(int signum)
{
    pnode_t node = job_list->curr;

    free(_cur_process->c_state);
    _cur_process = set_job_state(STP, _cur_process);
    if (job_list->curr == NULL || _cur_process->num == 0) {
        _cur_process->num = job_list->last_id + 1;
        job_list->last_id++;
        job_list->jobs = push_back(job_list->jobs, _cur_process);
        job_list->curr = job_list->jobs->end;
        job_list->next = node;
    }
    if (job_list->curr->data != _cur_process) {
        job_list->curr = search_node(job_list->jobs, &_cur_process->num, job_search);
        job_list->next = node;
    }
    printf("\nSuspended\n");
}

void SIGCHLD_handler(int signuum)
{
    pnode_t node = NULL;

    printf("=============> Job ended\n");
    if (_cur_process->num == 0)
        return;
    if (_cur_process->num == job_list->last_id) {
        printf("Deleting backgroud job.\n");
        job_list->jobs = pop_back(job_list->jobs, job_pop);
        job_list->last_id -= 1;
        return;
    }
    node = search_node(job_list->jobs, &(_cur_process->num), job_search);
    job_list->jobs = pop_element(job_list->jobs, node, job_pop);
}

void job_control(int signum)
{
    if (signum == SIGINT) {
        // kill(_cur_process->pid, SIGINT);
        // printf("\n");
        SIGINT_handler(signum);
    }
    if (signum == SIGTSTP) {
        // kill(_cur_process->pid, SIGSTOP);
        // if (job_list->jobs->lenght == 0) {
        //     _cur_process->num = 1;
        //     job_list->last_id = 1;
        // } else {
        //     _cur_process->num = job_list->last_id + 1;
        //     job_list->last_id++;
        // }
        // _cur_process = set_job_state(RUNG, _cur_process);
        // job_list->jobs = push_back(job_list->jobs, _cur_process);
        // // if (job_list->jobs->lenght == 0)
        // //     job_list->curr = job_list->jobs->begin;
        // // else {
        // //     job_list->curr = job_list->jobs->end;
        // //     job_list->next = job_list->curr->prev;
        // // }
        // node = job_list->curr;
        // job_list->curr = job_list->jobs->end;
        // job_list->next = node;
        // _cur_process = NULL;
        // printf("\nSuspended\n");
        SIGTSTP_handler(signum);
    }
}