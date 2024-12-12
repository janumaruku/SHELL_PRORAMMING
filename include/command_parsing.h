/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Command parsing functions prototype
*/

#include"../../../include/binary_tree.h"

tree_t *and_parsing(char *str);

char **operands(char *str, char sign);

tree_t *or_parsing(char *str);

tree_t *pipe_parsing(char *str);

tree_t *rleft_parsing(char *str);

tree_t *rright_parsing(char *str);

tree_t *semicolon_parsing(char *str);

#pragma once
