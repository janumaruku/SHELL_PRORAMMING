/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to convert a string into string array
*/

#include "../../include/utils.h"

char **split(char const *str, int (*func)(char))
{
    int c = 0;
    int nb_w = count_word(str, func);
    int a = 0;
    int b = 0;
    int i = 0;
    char **w_array = malloc(sizeof(char *) * (nb_w + 1));

    for (c = 0; c < nb_w; c++) {
        for (; !func(str[i]); i++);
        a = 0;
        b = i;
        for (; str[i] && func(str[i]); i++)
            a++;
        w_array[c] = malloc(sizeof(char) * (a + 1));
        jm_copy(w_array[c], &str[b], func);
    }
    w_array[c] = NULL;
    return w_array;
}
