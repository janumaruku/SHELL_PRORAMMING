/*
** EPITECH PROJECT, 2024
** ANAGRAM
** File description:
** All functions prototypes
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <math.h>

int count_word(char const *str, int (*func)(char));

void disp_2d_array(char **tab);

int err_putchar(char c);

int err_putstr(char const *str);

void free_2d_array(char **map);

char *int_to_str(int n);

int is_anum(char const c);

int is_alpha(char const c);

int is_char(char *str, char c);

int is_digit(char c);

int is_empty_line(char *str);

char *jm_copy(char *dest, char const *src, int (*func)(char));

int my_getnbr(char const *str);

void my_perror(char const *str);

int my_putchar(char c);

int my_putnbr(int nb);

int my_putstr(char const *str);

char *my_strcat(char *dest, char const *src);

char *my_strcat2(char *str1, char const *str2);

int my_strcmp(char *s1, char *s2);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *str);

int my_strlen(const char *str);

int my_strncmp(char *s1, char *s2, int n);

int number_len(int n);

char **split(char const *str, int (*func)(char));

char **split_colons(char *str);

void swap_char(char *a, char *b);

char **tab_dup(char **tab);

int tab_len(char **tab);

char *tab_to_str(char **tab);

bool my_str_isnum(char const *str);

#pragma once
