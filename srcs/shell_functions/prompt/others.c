/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function for character key from 0 to 31
*/

#include "../../../include/shell.h"
#include "../../../include/utils.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"

line_edition_t *nullable(line_edition_t *p)
{
    return p;
}

line_edition_t *line_begin(line_edition_t *p)
{
    if (p->pos == 0)
        return p;
    if (p->pos > 0) {
        p = backward_char(p);
        return line_begin(p);
    }
    return p;
}

void ctrl_c_handler(int signum)
{
    printf("SIGINT received.\n");
    return;
}

line_edition_t *tty_sigintr(line_edition_t *p)
{
    return p;
}

line_edition_t *end_of_file(line_edition_t *p)
{
    char **exit_cmd = NULL;

    if (p->len == 0) {
        exit_cmd = malloc(sizeof(char *) * 2);
        exit_cmd[0] = my_strdup("exit");
        exit_cmd[1] = NULL;
        mem_free(p->cmd);
        mem_free(p);
        disable_raw_mode();
        my_exit(exit_cmd);
    }
    if (p->len == p->pos) {
    m_prompt();
        printf("\n[janumaruku] user> %s", p->cmd);
        return p;
    }
    if (p->pos < p->len) {
        p = forspace(p);
        return p;
    }
    return p;
}

line_edition_t *end_of_line(line_edition_t *p)
{
    if (p->pos == p->len)
        return p;
    if (p->pos < p->len) {
        p = forward_char(p);
        return end_of_line(p);
    }
    return p;
}

line_edition_t *undefined(line_edition_t *p)
{
    return p;
}

line_edition_t *autocomplete(line_edition_t *p)
{
    return p;
}

line_edition_t *kill_line(line_edition_t *p)
{
    if (p->pos == p->len)
        return p;
    p = forspace(p);
    return kill_line(p);
}

line_edition_t *clear_screen(line_edition_t *p)
{
    system("clear");
    m_prompt();
    printf("%s", p->cmd);
    for (int i = p->pos; i < p->len; i++)
        printf("\b");
    return p;
}

line_edition_t *transpose_chars(line_edition_t *p)
{
    if (p->pos == 0)
        return p;
    if (p->pos == p->len) {
        swap_char(&p->cmd[p->pos - 2], &p->cmd[p->pos - 1]);
        printf("\b\b%s", &p->cmd[p->pos - 2]);
        return p;
    }
    swap_char(&p->cmd[p->pos - 1], &p->cmd[p->pos]);
    printf("\b%s", &p->cmd[p->pos - 1]);
    p->pos += 1;
    for (int i = p->pos; i < p->len; i++)
        printf("\b");
    return p;
}

line_edition_t *kill_region(line_edition_t *p)
{
    if (p->pos == 0)
        return p;
    p = backspace(p);
    return kill_region(p);
}

line_edition_t *kill_whole_line(line_edition_t *p)
{
    p = kill_line(p);
    p = kill_region(p);
    return p;
}

void ctrl_z_handler(int signum)
{
    return;
}

line_edition_t *control_z(line_edition_t *p)
{
    return p;
}

int others(line_edition_t *p, char c)
{
    line_edition_t *(*func[32])(line_edition_t *) = {
        nullable, line_begin, backward_char, tty_sigintr, end_of_file,
        end_of_line, forward_char, undefined, backspace, autocomplete,
        enter, kill_line, clear_screen, enter, down_history, nullable,
        up_history, nullable, nullable, nullable, transpose_chars,
        kill_whole_line, nullable, kill_region, nullable, nullable,
        nullable, nullable, nullable, nullable, nullable, control_z
    };

    for (int i = 0; i <= 31; i++) {
        if (c == i) {
            p = func[i](p);
            return 1;
        }
    }
    return 0;
}
