/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to change directory
*/

#include "../../../include/shell.h"
#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/builtin.h"

char *get_current_dir(void)
{
    int size = 1024;
    char *buf = malloc(sizeof(char) * size);

    getcwd(buf, size);
    return buf;
}

int proccess_cd(char **cmd, char *dir)
{
    char *str = get_current_dir();

    if (chdir(dir) != 0) {
        perror(cmd[1]);
        free(str);
        return 1;
    } else if (!past_dir)
        past_dir = str;
    else {
        free(past_dir);
        past_dir = str;
    }
    return 1;
}

// int cd_home(char **cmd)
// {
//     char *str = my_getenv("HOME");

//     return perform_cd(cmd, str);
// }

int cd_dash(char **cmd)
{
    int cd = 0;

    if (past_dir == NULL) {
        err_putstr(": No such file or directory.\n");
        return 1;
    }
    return proccess_cd(cmd, past_dir);
}

int my_cd(char **cmd)
{
    char *str = NULL;

    if (tab_len(cmd) > 3) {
        fprintf(stderr, "cd: Too many arguments.\n");
        return 1;
    }
    if (!cmd[1] ||
        (tab_len(cmd) == 2 && my_strcmp("~", cmd[1]) == 0) ||
        (tab_len(cmd) == 2 && my_strcmp("~/", cmd[1]) == 0)) {
        str = my_getenv("HOME");
        proccess_cd(cmd, str);
        free(str);
        return 1;
    }
    if (my_strcmp(cmd[1], "-") == 0) {
        cd_dash(cmd);
        return 1;
    }
    return proccess_cd(cmd, cmd[1]);
}