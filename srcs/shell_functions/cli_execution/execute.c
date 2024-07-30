/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to execute a command line
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/job_control.h"

int cur_process;
job_t *_cur_process;

void job_control(int signum)
{
    if (signum == SIGINT) {
        kill(cur_process, SIGINT);
        printf("\n");
    }
    if (signum == SIGTSTP) {
        kill(cur_process, SIGSTOP);
        printf("\nSuspended\n");
    }
}

void set_sigaction(struct sigaction *sa)
{
    sa->sa_handler = job_control;
    sigemptyset(&sa->sa_mask);
    sa->sa_flags = SA_RESTART;
    sigaction(SIGTSTP, sa, NULL);
    sigaction(SIGINT, sa, NULL);
}

int runner(char *path, char **cmd)
{
    struct sigaction sa;

    cur_process = fork();
    _cur_process = malloc(sizeof(job_t));
    _cur_process->num = 0;
    _cur_process->pid = cur_process;
    _cur_process->state = RUNG;
    _cur_process->c_state = set_job_state(_cur_process->state);
    _cur_process->cmd = tab_to_str(cmd);
    set_sigaction(&sa);
    if (cur_process == 0) {
        if (!execve(path, cmd, t_env)) {
            perror(cmd[0]);
            free_2d_array(t_env);
            clear_list(&l_env, str_pop);
        }        
    }
    waitpid(cur_process, 0, WUNTRACED);
    job_pop(_cur_process);
    return 0;
}
