/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to execute a command line
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/job_control.h"

// int cur_process;
job_t *_cur_process;
int exit_status;

void set_sigaction(struct sigaction *sa)
{
    sa->sa_handler = job_control;
    sigemptyset(&sa->sa_mask);
    sa->sa_flags = SA_RESTART;
    sigaction(SIGTSTP, sa, NULL);
    sigaction(SIGINT, sa, NULL);
    // sigaction(SIGCHLD, sa, NULL);
}

int runner(char *path, char **cmd)
{
    struct sigaction sa;

    _cur_process = malloc(sizeof(job_t));
    _cur_process->num = 0;
    _cur_process->curr_or_next = NOTHING;
    _cur_process->exit_status = 0;
    _cur_process->pid = fork();
    _cur_process = set_job_state(RUNG, _cur_process);
    _cur_process->cmd = tab_to_str(cmd);
    set_sigaction(&sa);
    if (_cur_process->pid == 0) {
        if (!execve(path, cmd, t_env)) {
            perror(cmd[0]);
            free_2d_array(t_env);
            clear_list(&l_env, str_pop);
        }
    }
    waitpid(_cur_process->pid, &_cur_process->exit_status, WUNTRACED);
    exit_status = _cur_process->exit_status;
    if (_cur_process->num == 0)
        job_pop(_cur_process);
    _cur_process = NULL;
    return 0;
}
