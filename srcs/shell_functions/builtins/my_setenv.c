/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to set a new environment variable
*/

#include "../../../include/shell.h"
#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/builtin.h"

int update_env(char **cmd)
{
    char *str = NULL;
    pnode_t node = NULL;

    node = search_node(l_env, cmd[1], env_var_search);
    if (node) {
        if (cmd[2])
            str = malloc(sizeof(char) * (my_strlen(cmd[1]) + my_strlen(cmd[2]) + 2));
        else
            str = malloc(sizeof(char) * (my_strlen(cmd[1]) + 2));
        str[0] = 0;
        my_strcat(str, cmd[1]);
        my_strcat(str, "=");
        if (cmd[2])
            my_strcat(str, cmd[2]);
        mem_free(node->data);
        node->data = str;
        return 1;
    }
    return 0;
}

int my_setenv_error(char **cmd)
{
    if (tab_len(cmd) > 3) {
        fprintf(stderr, "setenv: Too many arguments.\n");
        return 1;
    }
    if (is_digit(cmd[1][0])) {
        fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; cmd[1][i]; i++)
        if (!is_alpha(cmd[1][i])) {
            fprintf(stderr, "setenv: Variable name must contain alphanumeric characters.\n");
            return 1;
        }
    return 0;
}

int add_env_var(char **cmd)
{
    char *str = NULL;

    if (tab_len(cmd) == 2)
        str = malloc(sizeof(char) * (my_strlen(cmd[1]) + 2));
    else
        str = malloc(sizeof(char) * (my_strlen(cmd[1]) + my_strlen(cmd[2]) + 2));
    str[0] = 0;
    my_strcat(str, cmd[1]);
    my_strcat(str, "=");
    if (tab_len(cmd) == 3)
        my_strcat(str, cmd[2]);
    l_env = push_back(l_env, str);
    return 1;
}

int my_setenv(char **cmd)
{
    char *str = NULL;
    pnode_t node = NULL;

    if (!cmd[1]) {
        my_env(cmd);
        return 1;
    }
    if (my_setenv_error(cmd))
        return 1;
    if (update_env(cmd))
        return 1;
    add_env_var(cmd);
    return 1;
}
