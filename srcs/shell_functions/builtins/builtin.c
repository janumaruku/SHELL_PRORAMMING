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

int builtin(char **cmd)
{
    char *builin_cmd[6] = {"exit", "env", "setenv", "unsetenv",
    "cd", NULL};
    int (*func[5])(char **) = {my_exit, my_env, my_setenv, my_unsetenv,
    my_cd};

    for (int i = 0; builin_cmd[i]; i++) {
        if (my_strcmp(cmd[0], builin_cmd[i]) == 0) {
            func[i](cmd);
            return 1;
        }
    }
    return 0;
}