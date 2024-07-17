/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to execute a command line
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"

int cur_process;

void job_control(int signum)
{
    if (signum == SIGINT) {
        printf("\n");
        kill(cur_process, SIGINT);
    }
    if (signum == SIGTSTP) {
        printf("\n===> Suspended\n");
        kill(cur_process, SIGSTOP);
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
    int child = fork();
    struct sigaction sa;

    set_sigaction(&sa);
    cur_process = child;
    if (child == 0) {
        if (!execve(path, cmd, t_env)) {
            perror(cmd[0]);
            free_2d_array(t_env);
            clear_list(&l_env, str_pop);
        }        
    }
    waitpid(child, 0, WUNTRACED);
    return 0;
}
