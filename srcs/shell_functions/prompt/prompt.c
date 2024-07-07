/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to display the prompt
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/prompt.h"

char **prompt(void)
{
    char *line = NULL;
    size_t l = 0;
    int g = 0;
    char **exit_cmd = NULL;
    char **cmd = NULL;

    my_putstr("[janumaruku] user> ");
    g = getline(&line, &l, stdin);
    if (g == -1) {
        exit_cmd = malloc(sizeof(char *) * 2);
        exit_cmd[0] = my_strdup("exit");
        exit_cmd[1] = NULL;
        free(line);
        my_exit(exit_cmd);
    }
    if (is_empty_line(line))
        return NULL;
    cmd = split(line, cmd_seg);
    free(line);
    return cmd;
}

int arrow_key_handling(line_edition_t *p)
{
    char c = getchar();

    if (c == 'C') {
        
    }
}

int multi_char_binding(line_edition_t *p)
{
    char c = 0;
    char *bindkey = "ABCD";
    line_edition_t * (*func)(line_edition_t *)[4] =
    {up_history, down_history, forward_char, backward_char};

    getchar();
    for (int i = 0; bindkey[i]; i++) {
        if (c == bindkey[i]) {
            p = func(p);
            return 1;
        }
    }
    return 0;
}

char *prompt2(void)
{
    char c = 0;
    line_edition_t *p = malloc(sizeof(line_edition_t));

    enable_raw_mode();
    my_putstr("[janumaruku] user> ");
    while (1) {
        c = getchar();
        if (c == 27) {
            multi_char_binding(p);
            continue;
        }
    }
}