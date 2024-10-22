/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** fg function to move a job to foreground
*/

#include "../../../include/shell.h"
#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/builtin.h"
#include "../../../include/job_control.h"

int fg(char **cmd)
{
    struct sigaction sa;
    int tmp = 0;
    pnode_t node = NULL;

    if (!cmd[1]) {
        node = job_list->curr;
        _cur_process = node->data;
    } else {
        if (cmd[1][0] != '%') {
            fprintf(stderr, "fg: No such job.\n");
            return 0;
        }
        if (cmd[1][1] == 0 || cmd[1][1] == ' ') {
            cmd[1] = NULL;
            fg(cmd);
            return 0;
        }
        if (!is_digit(cmd[1][1])) {
            fprintf(stderr, "fg: No such job.\n");
            return 0;
        }
        tmp = my_getnbr(&cmd[1][1]);
        node = search_node(job_list->jobs, &tmp, job_search);
        _cur_process = node->data;
    }
    free(_cur_process->c_state);
    _cur_process = set_job_state(RUNG, _cur_process);
    set_sigaction(&sa);
    kill(_cur_process->pid, SIGCONT);
    print_job(_cur_process, "\n", 1);
    waitpid(_cur_process->pid, &_cur_process->exit_status, WUNTRACED);
    if (WIFSIGNALED(_cur_process->exit_status)) {
        if (WTERMSIG(_cur_process->exit_status) == SIGSEGV)
            printf("Segmentation fault");
        if (_cur_process == job_list->curr->data) {
            job_list->jobs = pop_element(job_list->jobs, node, job_pop);
            job_list->curr = job_list->next;
            job_list->next = job_list->curr == job_list->jobs->end ? job_list->jobs->end->prev : job_list->jobs->end;
        } else
            job_list->jobs = pop_element(job_list->jobs, node, job_pop);
    } else if (WIFEXITED(_cur_process->exit_status)) {
        if (_cur_process == job_list->curr->data) {
            job_list->jobs = pop_element(job_list->jobs, node, job_pop);
            job_list->curr = job_list->next;
            job_list->next = job_list->curr == job_list->jobs->end ? job_list->jobs->end->prev : job_list->jobs->end;
        } else
            job_list->jobs = pop_element(job_list->jobs, node, job_pop);
    }
    _cur_process = NULL;
}