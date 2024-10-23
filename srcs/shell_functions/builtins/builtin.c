/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to manage builtins
*/

#include "../../../include/shell.h"
#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/builtin.h"
#include "../../../include/job_control.h"

int builtin(char **cmd)
{
    char *builin_cmd[9] = {"exit", "env", "setenv", "unsetenv",
    "cd", "fg", "jobs", "history", NULL};
    int (*func[8])(char **) = {my_exit, my_env, my_setenv, my_unsetenv,
    my_cd, fg, jobs, history_cmd};

    for (int i = 0; builin_cmd[i]; i++) {
        if (my_strcmp(cmd[0], builin_cmd[i]) == 0) {
            func[i](cmd);
            return 1;
        }
    }
    return 0;
}

// [16] + Suspended                     cat