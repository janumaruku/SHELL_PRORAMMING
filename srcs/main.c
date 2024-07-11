/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The main function
*/

#include "../include/linked_list.h"
#include "../include/shell.h"
#include "../include/utils.h"

plist_t l_env;
char **t_env;
char *past_dir;

int main(int argc, char *argv[], char *env[])
{
    l_env = tab_to_list(env);
    t_env = tab_dup(env);
    past_dir = NULL;
    main_loop();
    return 0;
}