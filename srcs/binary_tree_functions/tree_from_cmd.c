/*
** EPITECH PROJECT, 2024
** MINISHELL 2
** File description:
** Function to convert a command line into a binary tree
*/

#include "../../include/binary_tree.h"
#include "../../include/command_parsing.h"
#include "../../include/utils.h"
#include <dirent.h>
#include <string.h>

// char *red_dup(char *str)
// {
//     int i = 0;
//     char *res;

//     for (; str[i] != ' ' && str[i]; i++);
//     res = malloc(sizeof(char) * (i + 2));
//     i = 0;
//     for (; str[i] && str[i] != ' '; i++)
//         res[i] = str[i];
//     res[i] = 0;
//     return res;
// }

// char *red_remain(char *str, char c)
// {
//     int i = 0;
//     int a = 0;
//     char *res = malloc(sizeof(char) * (strlen(str) + 1));

//     for (; str[i] != c && str[i]; i++)
//         res[i] = str[i];
//     a = i;
//     i++;
//     if (str[i] == c)
//         i++;
//     for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
//     for (; str[i] && str[i] != ' ' && str[i] != '\t'; i++);
//     for (; str[i]; i++) {
//         res[a] = str[i];
//         a++;
//     }
//     res[a] = 0;
//     return res;
// }

// char *red_str(char *str, char c)
// {
//     int i = 0;
//     int a = 0;
//     int b = 0;

//     for (; str[i] && str[i] != c; i++);
//     i++;
//     if (str[i] == c)
//         i++;
//     for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
//     a = i;
//     for (; str[i] && str[i] != ' ' && str[i] != '\t'; i++)
//         b++;
//     return red_dup(&str[a]);
// }

// tree_t *tree_from_cmd_pp(char *str)
// {
//     tree_t *tr;
//     int i = my_strlen(str) - 1;
//     int j = 0;
//     char a = 0;
//     int b = 0;

//     for (; i >= 0; i--) {
//         if (str[i] == '|') {
//             b = 1;
//             str[i] = 0;
//             tr = join_tree(tree_from_cmd_pp(str),
//             tree_from_cmd_pp(&str[i + 1]), my_strdup("|"));
//         }
//     }
//     if (b == 0)
//         return new_tree(my_strdup(str));
//     return tr;
// }

// tree_t *tree_from_cmd_lrd(char *str)
// {
//     tree_t *tr;
//     int i = my_strlen(str) - 1;
//     int b = 0;
//     char *str1;
//     char *str2;

//     for (; i > 0; i--) {
//         if (str[i] == '<') {
//             b = 1;
//             str1 = red_str(str, '<');
//             str2 = red_remain(str, '<');
//             tr = join_tree(new_tree(str2),
//             new_tree(str1), str[i + 1] == '<' ?
//             my_strdup("<<") : my_strdup("<"));
//         }
//     }
//     if (b == 0)
//         return tree_from_cmd_pp(str);
//     return tr;
// }

// tree_t *tree_from_cmd_rrd(char *str)
// {
//     tree_t *tr;
//     int i = my_strlen(str) - 1;
//     int b = 0;
//     char *str1;
//     char *str2;

//     for (; i > 0; i--) {
//         if (str[i] == '>') {
//             b = 1;
//             str1 = red_str(str, '>');
//             str2 = red_remain(str, '>');
//             tr = join_tree(tree_from_cmd_lrd(str2),
//             new_tree(my_strdup(str1)), str[i + 1] == '>' ?
//             my_strdup(">>") : my_strdup(">"));
//             free(str1);
//             free(str2);
//         }
//     }
//     if (b == 0)
//         return tree_from_cmd_lrd(str);
//     return tr;
// }

// tree_t *tree_from_cmd(char *str)
// {
//     tree_t *tr;
//     int i = my_strlen(str) - 1;
//     int j = 0;
//     char a = 0;
//     int b = 0;

//     for (; i >= 0; i--) {
//         if (str[i] == ';') {
//             b = 1;
//             str[i] = 0;
//             tr = join_tree(tree_from_cmd(str),
//             tree_from_cmd_rrd(&str[i + 1]), my_strdup(";"));
//         }
//     }
//     if (b == 0)
//         return tree_from_cmd_rrd(str);
//     return tr;
// }

// char **operands(char *str, char sign)
// {
//     char **result = malloc(sizeof(char *) * 4);
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int len = my_strlen(str);

//     for (; str[i] == ' '; i++);
//     if (str[i] == sign) {
//         if (str[i + 1] == sign) {
//             result[1] = my_strdup(sign == '>' ? ">>" : "<<");
//             i += 1;
//         } else
//             result[1] = my_strdup(sign == '>' ? ">" : "<");
//         i += 1;
//         for (; str[i] == ' ' || !str[i]; i++);
//         for (j = i; str[j] != ' ' || !str[j]; j++);
//         str[j] = 0;
//         result[2] = my_strdup(&str[i]);
//         result[0] = my_strdup(&str[j + 1]);
//         result[3] = NULL;
//     } else {
//         for (j = i; str[j] != sign; j++);
//         str[j] = 0;
//         if (str[j + 1] == sign) {
//             result[1] = my_strdup(sign == '>' ? ">>" : "<<");
//             j += 1;
//         } else
//             result[1] = my_strdup(sign == '>' ? ">" : "<");
//         j +=1;
//         for (; str[j] == ' ' || !str[j]; j++);
//         for (k = j; str[k] != ' ' || !str[k]; k++);
//         str[k] = 0;
//         result[2] = my_strdup(&str[j]);
//         result[0] = malloc(sizeof(char) * (len + 1));
//         my_strcpy(result[0], str);
//         k += 1;
//         for (i = my_strlen(result[0]); str[k]; i++) {
//             result[0][i] = str[k];
//             k +=1;
//         }
//         result[0][i] = 0;
//         result[3] = NULL;
//     }
//     return result;
// }

tree_t *tree_from_cmd(char *str)
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
            tr = join_tree(new_tree(command[0]), new_tree(command[2]), command[1]);
        }
        a[0] = str[i] == '(' ? a[0] - 1 : a[0];
        // a[1] = str[i] == '`' && a[1] == 1 ? a[1] - 1 : a[1];
    }
    if (a[2] == 0)
        return new_tree(str);
    return tr;
}

// char **get_cmd(char *str)
// {
//     int i = 0;
//     char **cmd;

//     for (; str[i] == ' ' || str[i] == '\t'; i++);
//     cmd = split(&str[i], )
// }

// int is_empty_str(char *str)
// {
//     int i = 0;

//     for (; (str[i] == ' ' || str[i] == '\t') && str[i]; i++);
//     if (str[i] == 0)
//         return 1;
//     return 0;
// }

// void cmd_exec2(char *path, char **cmd)
// {
//     int child = 0;
//     int ex = 0;
//     int status = 0;

//     child = fork();
//     if (child == 0) {
//         ex = execve(path, cmd, var_tab);
//         if (ex != 0) {
//             my_perror(path);
//             exit(ex);
//         }
//         free(path);
//         clear_list(&var);
//         free_2d_array(var_tab);
//         free_2d_array(cmd);
//     }
//     waitpid(child, &status, WUNTRACED);
//     if (status == 11)
//         my_putstr("Segmentation fault\n");
// }

// int cmd_exec(tree_t *tree)
// {
//     char **cmd;

//     if (tree->parent != NULL && my_strcmp(tree->parent->data, ";") &&
//         is_empty(tree->data))
//         return 0;
//     cmd = split(tree->data, seg_arg);
// }

// int processing(tree_t *tree, int file)
// {
//     int fd[2];

//     if (my_strcmp(tree->data, ";") == 0) {
//         processing(tree->tleft, -1);
//         processing(tree->tright, -1);
//         return 0;
//     }
//     if (my_strcmp(tree->data, ">") == 0 || my_strcmp(tree->data, ">>") == 0) {
//         file = cmd_redright(tree->tright);
//         processing(tree->tleft, file);
//         return 0;
//     }
//     if (my_strcmp(tree->data, "<") == 0 || my_strcmp(tree->data, "<<") == 0) {
//         cmd_redleft(tree->tright);
//         cmd_exec(tree->tleft);
//         return 0;
//     }
//     if (my_strcmp(tree->data, "|") == 0) {
//         pipe(fd);
//         cmd_pipe(tree, fd, file);
//         return 0;
//     }
//     cmd_exec(tree);
//     return 0;
// }

// int exe(char *hhh)
// {
//     // char *str = strdup(hhh);
//     char *str = malloc(sizeof(char) * (my_strlen(hhh) + 1));
//     char *ccc;
//     int i = 0;
//     int j  = 0;
//     int a  = 0;

//     for (; hhh[i] != '>'; i++)
//         str[i] = hhh[i];
//     j = i++;
//     for (; hhh[i] == ' ' || hhh[i] == '\t'; i++);
//     a = i;
//     ccc = malloc(sizeof(char) * strlen(&str[a]));
//     a = 0;
//     for (; hhh[i] != ' ' && hhh[i] != '\t'; i++) {
//         str[j] = hhh[i];
//     }
// }

// int **multiply(int **mat1, int **mat2, int r, int c)
// {
//     int **res = malloc(sizeof(int *) * r);

//     for (int i = 0; i < r; i++) {
//         res[i] = malloc(sizeof(int) * c);
//         // for (int j = 0; j < c; j++)
//         //     res[i][j] = 0;
//         for (int j = 0; j < c; j++) {
//             for (int k = 0; k < c; k++)
//                 res[i][j] += mat1[i][k] * mat2[k][j];
//         }
//     }
//     return res;
// }

// int **identity(int s)
// {
//     int **res = malloc(sizeof(int *) * s);

//     for (int i = 0; i < s; i++) {
//         res[i] = malloc(sizeof(int) * s);
//         for (int j = 0; j < s; j++)
//             res[i][j] = 1;
//     }
//     return res;
// }

// int power(int **mat, int s, int p)
// {
//     int **res = mat;

//     if (p == 0)
//         return identity(s);
//     if (p == 1)
//         return mat;
//     for (int i = 0; i < p; i++) {
//         res = multiply(res, mat, s, s);
//     }
//     return res;
// }

// int main(void)
// {
//     // if (prefnotation("ls  << data ls -l", 5))
//     //     printf("It's a prefix notation.\n");
//     // else
//     //     printf("It's not a prefix notation.\n");
//     // char *str = "ls -l > data";
//     // exe(str);
//     int size = 3;
//     int **mat1 = malloc(sizeof(int *) * size);
//     int **mat2 = malloc(sizeof(int *) * size);
//     for (int i = 0; i < size; i++) {
//         mat1[i] = malloc(sizeof(int) * size);
//         mat2[i] = malloc(sizeof(int) * size);
//     }
//     int coeff1[] = {2,5,3,6,2,9,6,2,6};
//     int coeff2[] = {5,9,1,4,3,9,1,0,5};
//     int x = 0, y = 0;
//     for (int a = 0; a < size*size; ) {
//         if (a != 0 && a % size == 0) {
//             y++, x = 0;
//             mat1[y][x] = coeff1[a];
//             mat2[y][x] = coeff2[a];
//             a++;
//             x++;
//             continue;
//         }
//         mat1[y][x] = coeff1[a];
//         mat2[y][x] = coeff2[a];
//         a++;
//         x++;
//     }
//     int **res = multiply(mat1, mat1, size, size);
//     for (int i = 0; i < size; i++) {
//         for (int j = 0; j < size; j++)
//             printf("%d ", res[i][j]);
//         printf("\n");
//     }
//     return 0;
// }
