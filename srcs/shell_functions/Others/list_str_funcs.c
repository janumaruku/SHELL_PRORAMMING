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

int job_search(void *expected, void *data)
{
    int *e = (int *)expected;
    job_t *d = (job_t *)data;

    if (*e == d->num)
        return 1;
    return 0;
}

char *get_job_num_str(int n)
{
    char *res = malloc(sizeof(char) * 6);
    char *str = int_to_str(n);

    res[0] = 0;
    my_strcat(res, "[");
    my_strcat(res, str);
    my_strcat(res, "]");
    free(str);
    return res;
}

void print_job(void *data, void *sep, int b)
{
    job_t *d = (job_t *)data;
    char *s = (char *)sep;
    char *job_num_str = get_job_num_str(d->num);

    printf("%-4s ", job_num_str);
    if (data == job_list->curr->data)
        printf("+ ");
    else if (data == job_list->next->data)
        printf("- ");
    else
        printf("  ");
    printf("%-29s %s", d->c_state, d->cmd);
    if (b)
        printf("%s", s);
    free(job_num_str);
}
