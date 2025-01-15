/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The main function
*/

#include "../include/linked_list.h"
#include "../include/shell.h"
#include "../include/builtin.h"
#include "../include/utils.h"
#include "../include/job_control.h"
#include "../include/binary_tree.h"
#include "../include/command_parsing.h"

plist_t l_env;
plist_t l_shell_var;
char **t_env;
char *past_dir;
jobs_t *job_list;
extern pnode_t top_reached;
extern pnode_t buttom_reached;

void func2(void *data)
{
    char *d = (char *)data;

    my_putstr(d);
}

int main(int argc, char *argv[], char *env[])
{
    l_env = tab_to_list(env);
    l_shell_var = new_list();
    t_env = tab_dup(env);
    job_list = init_job_list();
    past_dir = NULL;
    history = new_list();
    top_reached = fill_node(my_strdup("top"));
    buttom_reached = fill_node(my_strdup("buttom"));
    main_loop();
    return 0;
}

// FRA1CT20247019486