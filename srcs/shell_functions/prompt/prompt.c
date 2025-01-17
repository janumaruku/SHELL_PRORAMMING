/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to display the prompt
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"

line_edition_t *p;
char *current_command;
pnode_t top_reached;
pnode_t buttom_reached;

line_edition_t *init_line_edition(void)
{
    line_edition_t *p = malloc(sizeof(line_edition_t));

    p->cmd = malloc(sizeof(char) * (COMMAND_MAX_LENGTH + 1));
    p->pos = 0;
    p->len = 0;
    p->done = 0;
    return p;
}

line_edition_t *normal_characters(line_edition_t *p, char c)
{
    if (p->pos < p->len) {
        memmove(&p->cmd[p->pos + 1], &p->cmd[p->pos], p->len - p->pos + 1);
        p->cmd[p->pos] = c;
        p->cmd[p->len + 2] = 0;
        printf("%s", &p->cmd[p->pos]);
        for (int i = p->pos; i < p->len; i++)
            printf("\b");
    } else {
        p->cmd[p->pos] = c;
        p->cmd[p->pos + 1] = 0;
        putchar(c);
    }
    p->pos += 1;
    p->len += 1;
    return p;
}

int is_empty_str(char *str)
{
    int i = 0;

    for (; (str[i] == ' ' || str[i] == '\t') && str[i]; i++);
    if (str[i] == 0)
        return 1;
    return 0;
}

line_edition_t *enter(line_edition_t *p)
{
    p->done = 1;
    printf("\n");
    p->cmd[p->len] = '\0';
    if (is_empty_str(p->cmd) || my_strlen(p->cmd) == 0) {
        disable_raw_mode();
        mem_free(p->cmd);
        p->cmd = NULL;
        return p;
    }
    disable_raw_mode();
    return p;
}

void m_prompt(void)
{
    my_putstr("[janumaruku] user> ");
}

void while_prompting(int signum)
{
    if (signum == SIGTSTP)
        return;
    if (signum == SIGINT) {
        printf("\n");
        m_prompt();
        mem_free(p->cmd);
        p->cmd = malloc(sizeof(char) * (COMMAND_MAX_LENGTH + 1));
        p->pos = 0;
        p->len = 0;
        p->done = 0;
        return;
    }
}

void prompt_sig_handler(struct sigaction *sa)
{
    sa->sa_handler = while_prompting;
    sigemptyset(&sa->sa_mask);
    sa->sa_flags = SA_RESTART;
    sigaction(SIGTSTP, sa, NULL);
    sigaction(SIGINT, sa, NULL);
}

char *prompt2(void)
{
    char c = 0;
    char *res = NULL;
    p = init_line_edition();
    current_command = malloc(sizeof(char) * (COMMAND_MAX_LENGTH + 1));
    struct sigaction sa;

    history->cursor = buttom_reached;
    prompt_sig_handler(&sa);
    enable_raw_mode();
    m_prompt();
    p->cmd[0] = 0;
    while (1) {
        c = getchar();
        if (c == '\n') {
            p = enter(p);
            if (!p->cmd) {
                mem_free(p);
                if (current_command != NULL) {
                    mem_free(current_command);
                    current_command = NULL;
                }
                return NULL;
            }
            res = my_strdup(p->cmd);
            mem_free(p->cmd);
            mem_free(p);
            if (current_command != NULL) {
                mem_free(current_command);
                current_command = NULL;
            }
            return res;
        }
        if (c == 27) {
            multi_char_binding(p);
            continue;
        }
        if (c >= 0 && c <= 31) {
            others(p, c);
            if (p->done) {
                if (!p->cmd) {
                    mem_free(p);
                    if (current_command != NULL) {
                        mem_free(current_command);
                        current_command = NULL;
                    }
                    return NULL;
                }
                res = my_strdup(p->cmd);
                mem_free(p->cmd);
                mem_free(p);
                if (current_command != NULL) {
                    mem_free(current_command);
                    current_command = NULL;
                }
                return res;
            }
            continue;
        }
        if (c == 8 || c == 127) {
            del_char(p, c);
            continue;
        }
        if (c >= 32 && c <= 126 && p->len < COMMAND_MAX_LENGTH) {
            p = normal_characters(p, c);
            continue;
        }
    }
}
