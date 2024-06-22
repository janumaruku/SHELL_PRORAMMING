/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The interpretor function
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/linked_list.h"

int env_var_search(void *expected, void *data)
{
    char *e = (char *)expected;
    char *d = (char *)data;

    if (my_strncmp(e, d, my_strlen(e)) == 0 &&
        d[my_strlen(e)] == '=')
        return 1;
    return 0;
}

char *my_getenv(char *varname)
{
    pnode_t node = search_node(l_env, "PATH=", env_var_search);
}

int interpretor(char **cmd)
{

    if (access(cmd[0], X_OK) == 0) {
        runner(cmd[0], cmd);
        return 0;
    }
    return 0;
}