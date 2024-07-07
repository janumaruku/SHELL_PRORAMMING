/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The interpretor function
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/linked_list.h"

char *my_getenv(char *varname)
{
    pnode_t node = search_node(l_env, varname, env_var_search);
    int i = 0;
    char *str = (char *)node->data;

    for (; str[i] != '='; i++);
    return my_strdup(&str[i + 1]);
}

char *find_path(char *var, char *cmd)
{
    char **var_tab = split(var, colon_seg);
    int i = 0;
    int len = my_strlen(cmd) + 2;
    char *str;

    for (; var_tab[i]; i++) {
        str = malloc(sizeof(char) * (my_strlen(var_tab[i]) + len));
        str[0] = 0;
        my_strcat(str, var_tab[i]);
        my_strcat(str, "/");
        my_strcat(str, cmd);
        if (access(str, X_OK) == 0) {
            free_2d_array(var_tab);
            return str;
        }
        free(str);
    }
    free_2d_array(var_tab);
    return NULL;
}

int interpretor(char **cmd)
{
    char *var = my_getenv("PATH");
    char *path = find_path(var, cmd[0]);
    if (access(cmd[0], X_OK) == 0) {
        runner(cmd[0], cmd);
        free(var);
        free(path);
        return 0;
    }
    if (path) {
        runner(path, cmd);
        free(var);
        free(path);
        return 0;
    }
    fprintf(stderr, "%s: command not found.\n", cmd[0]);
    free(var);
    free(path);
    return 0;
}
