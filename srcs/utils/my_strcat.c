/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to concatane two strings
*/

#include "../../include/utils.h"

char *my_strcat(char *dest, char const *src)
{
    int k = my_strlen(dest);
    int i = 0;

    for (; src[i]; i++) {
        dest[k] = src[i];
        k++;
    }
    dest[k] = '\0';
    return dest;
}

char *my_strcat2(char *str1, char const *str2)
{
    int k = my_strlen(str1) + my_strlen(str2) + 1;
    char *result = malloc(sizeof(char) * k);
    int i = 0;
    int j = 0;

    for (; str1[i]; i++) {
        result[i] = str1[i];
    }
    for (; str2[j]; j++) {
        result[i] = str2[j];
        i++;
    }
    result[i] = '\0';
    return result;
}
