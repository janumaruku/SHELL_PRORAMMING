/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to delete an environment variable
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/builtin.h"

int my_unsetenv(char **cmd)
{
    pnode_t node = NULL;

    if (!cmd[1]) {
        fprintf(stderr, "unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; cmd[i]; i++) {
        node = search_node(l_env, cmd[i], env_var_search);
        if (node)
            l_env = pop_element(l_env, node, str_pop);
    }
    return 1;
}
