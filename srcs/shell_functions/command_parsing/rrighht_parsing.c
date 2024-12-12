/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Function to parse command according to right redirection signs (> and >>)
*/

#include "../../../include/linked_list.h"
#include "../../../include/utils.h"
#include "../../../include/shell.h"
#include "../../../include/prompt.h"
#include "../../../include/builtin.h"
#include"../../../include/binary_tree.h"
#include"../../../include/command_parsing.h"

char **operands(char *str, char sign)
{
    char **result = malloc(sizeof(char *) * 4);
    int i = 0;
    int j = 0;
    int k = 0;
    int len = my_strlen(str);

    for (; str[i] == ' '; i++);
    if (str[i] == sign) {
        if (str[i + 1] == sign) {
            result[1] = my_strdup(sign == '>' ? ">>" : "<<");
            i += 1;
        } else
            result[1] = my_strdup(sign == '>' ? ">" : "<");
        i += 1;
        for (; str[i] == ' '; i++);
        for (j = i; str[j] != ' ' && str[j]; j++);
        str[j] = 0;
        result[2] = my_strdup(&str[i]);
        result[0] = my_strdup(&str[j + 1]);
        result[3] = NULL;
    } else {
        for (j = i; str[j] != sign; j++);
        str[j] = 0;
        if (str[j + 1] == sign) {
            result[1] = my_strdup(sign == '>' ? ">>" : "<<");
            j += 1;
        } else
            result[1] = my_strdup(sign == '>' ? ">" : "<");
        j +=1;
        for (; str[j] == ' '; j++);
        for (k = j; str[k] != ' ' && str[k] != 0; k++);
        if (str[k] != 0) {
            str[k] = 0;
            k += 1;
        } else
            str[k] = 0;
        result[2] = my_strdup(&str[j]);
        result[0] = malloc(sizeof(char) * (len + 1));
        my_strcpy(result[0], str);
        for (i = my_strlen(result[0]); str[k]; i++) {
            result[0][i] = str[k];
            k +=1;
        }
        result[0][i] = 0;
        result[3] = NULL;
    }
    return result;
}

tree_t *rright_parsing(char *str)
{
    tree_t *tr;
    int i = my_strlen(str) - 1;
    int a[3] = {0, 0, 0};
    char **command = NULL;

    for (; i >= 0; i--) {
        a[0] = str[i] == ')' ? a[0] + 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 0 ? a[1] + 1 : a[1];
        if (str[i] == '>' && a[0] == 0 && a[1] == 0) {
            a[2] = 1;
            command = operands(str, str[i]);
            tr = join_tree(rleft_parsing(command[0]), new_tree(command[2]), command[1]);
        }
        a[0] = str[i] == '(' ? a[0] - 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 1 ? a[1] - 1 : a[1];
    }
    if (a[2] == 0)
        return rleft_parsing(str);
    free(command[0]);
    free(command);
    return tr;
}
