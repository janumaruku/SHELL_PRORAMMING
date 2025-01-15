/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The main loop function
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"
#include "../../../include/binary_tree.h"
#include "../../../include/command_parsing.h"

char *cli;
tree_t *command_tree;

void func1(void *data)
{
    char *d = (char *)data;

    mem_free(d);
}

int ctrl_d(int g, char *line)
{
    char **cmd = malloc(sizeof(char *) * 2);
    int i = 0;

    cmd[0] = my_strdup("exit");
    cmd[1] = 0;
    if (g == -1) {
        mem_free(line);
        my_exit(cmd);
    }
    free_2d_array(cmd);
    for (; (line[i] == ' ' || line[i] == '\t'); i++);
    if (line[i] == '\n')
        return 1;
    return g;
}

char *esssai(void)
{
    int g = 0;
    size_t k = 0;
    char *line = NULL;

    if (isatty(0) == 1)
    my_putstr("$> ");
    g = getline(&line, &k, stdin);
    g = ctrl_d(g, line);
    if (g == 1) {
        mem_free(line);
        return NULL;
    }
    line[g - 1] = '\0';
    return line;
}

int main_loop(void)
{
    char **cmd = NULL;

    command_tree = NULL;
    cli = NULL;
    while (1) {
        if (!isatty(0))
            cli = esssai();
        else
            cli = prompt2();
        if (!cli)
            continue;
        command_tree = semicolon_parsing(cli);
        processing(command_tree);
        history = push_back(history, new_command(my_strdup(cli)));
        mem_free(cli);
        cli = NULL;
        clean_tree(command_tree, str_pop);
        command_tree = NULL;
    }
    return 0;
}
