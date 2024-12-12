/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** The main function
*/

#include "../include/linked_list.h"
#include "../include/shell.h"
#include "../include/builtin.h"
#include "../include/utils.h"
#include "../include/job_control.h"
#include "../include/binary_tree.h"
#include "../include/command_parsing.h"

plist_t l_env;
char **t_env;
char *past_dir;
jobs_t *job_list;
extern pnode_t top_reached;
extern pnode_t buttom_reached;

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct trienode {
//     bool terminal;
//     struct trienode *children[255];
// } trienode;

// trienode *create_trienode(void) {
//     trienode *node = malloc(sizeof(*node));

//     node->terminal = false;
//     for (int i = 0; i < 255; i++) {
//         node->children[i] = NULL;
//     }
//     return node;
// }

// bool insert_word(trienode **root, char *word) {
//     trienode *tmp = NULL;
//     if (*root == NULL) {
//         *root = create_trienode();
//     }
//     tmp = *root;

//     for (int i = 0; word[i]; i++) {
//         if (tmp->children[word[i]] == NULL) {
//             tmp->children[word[i]] = create_trienode();
//         }
//         tmp = tmp->children[word[i]];
//     }
//     tmp->terminal = true;
// }

// void print_trienode_rec(trienode *node, char *str, int len) {
//     char new_str[201];
//     memcpy(new_str, str, len);
//     new_str[len + 1] = 0;

//     if (node->terminal)
//         printf("word: %s\n", str);
//     for (int i = 0; i < 255; i++) {
//         if (node->children[i] != NULL) {
//             new_str[len] = i;
//             print_trienode_rec(node->children[i], new_str, len + 1);
//         }
//     }
// }

// void print_trie(trienode *root) {
//     trienode *tmp = root;
//     if (root == NULL)
//         return;
    
//     for (int i = 0; i < 255; i++) {
//         if (tmp->children[i] != NULL)
//             print_trienode_rec(tmp, NULL, 0);
//     }
// }

// void clear_trie(trienode **root) {
    
// }

void func1(void *data)
{
    char *d = (char *)data;

    free(d);
}

void func2(void *data)
{
    char *d = (char *)data;

    my_putstr(d);
}

int main(int argc, char *argv[], char *env[])
{
    // l_env = tab_to_list(env);
    // t_env = tab_dup(env);
    // job_list = init_job_list();
    // past_dir = NULL;
    // history = new_list();
    // top_reached = fill_node(my_strdup("top"));
    // buttom_reached = fill_node(my_strdup("buttom"));
    // main_loop();
    // trienode *root = create_trienode();

    // insert_word(&root, "macaco");
    // insert_word(&root, "macaroon");
    // insert_word(&root, "machine");
    // insert_word(&root, "flower");
    // insert_word(&root, "flow");
    // insert_word(&root, "flight");
    // print_trie(root);
    char *str = my_strdup("ls ; ls -l | cat > data ; cat < test -l");
    printf("%s\n\n", str);
    tree_t *tr = semicolon_parsing(str);
    print_tree_prefix(tr, func2); my_putchar('\n');
    clean_tree(tr, func1);
    free(str);
    return 0;
}

// FRA1CT20247019486