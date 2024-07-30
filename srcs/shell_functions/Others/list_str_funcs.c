/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Linked list funtion for strings
*/

#include "../../../include/utils.h"
#include "../../../include/job_control.h"

void str_disp(void *data, void *sep, int b)
{
    char *d = (char *)data;
    char *s = (char *)sep;

    my_putstr(d);
    if (b)
        my_putstr(s);
}

void str_pop (void *data)
{
    char *d = (char *)data;

    free(d);
}

int env_var_search(void *expected, void *data)
{
    char *e = (char *)expected;
    char *d = (char *)data;

    if (my_strncmp(e, d, my_strlen(e)) == 0 &&
        d[my_strlen(e)] == '=')
        return 1;
    return 0;
}

void job_pop(void *data)
{
    job_t *d = (job_t *)data;

    free(d->cmd);
    free(d->c_state);
    free(d);
}
