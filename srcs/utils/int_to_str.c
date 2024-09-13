/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to convert an integer to character string
*/

#include "../../include/utils.h"

int number_len(int n)
{
    int res = 0;

    if (n == 0)
        return 0;
    if (n < 0) {
        res += 1;
        n *= -1;
    }
    while (n != 0) {
        res += 1;
        n /= 10;
    }
    return res;
}

int power(int n, int p)
{
    int res = 1;

    if (p == 0)
        return 1;
    while (p > 0) {
        res *= n;
        p--;
    }
    return res;
}

char *int_to_str(int n)
{
    int len = number_len(n);
    int i = 0;
    char *res = malloc(sizeof(char) * (len + 1));

    if (n < 0) {
        res[i] = '-';
        i++;
        n *= -1;
    }
    if (n < 10) {
        res[i] = n + 48;
        res[i + 1] = 0;
        return res;
    }
    while (i < len) {
        res[i] = ((int)(n / power(10, len - i - 1)) % 10) + 48;
        i++;
    }
    res[i] = 0;
    return res;
}
