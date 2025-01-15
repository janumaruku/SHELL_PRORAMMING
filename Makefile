##
## EPITECH PROJECT, 2024
## MINISHELL 1
## File description:
## The project Makefile
##

SRCS	=	srcs/binary_tree_functions/clean_tree.c\
			srcs/binary_tree_functions/create_tree.c\
			srcs/binary_tree_functions/join_tree.c\
			srcs/binary_tree_functions/print_tree.c\
			srcs/binary_tree_functions/tree_from_cmd.c\
			srcs/linked_list/clear_list.c\
			srcs/linked_list/disp_list.c\
			srcs/linked_list/free_node.c\
			srcs/linked_list/linked_list_utils.c\
			srcs/linked_list/pop_back.c\
			srcs/linked_list/pop_element.c\
			srcs/linked_list/pop_front.c\
			srcs/linked_list/push_back.c\
			srcs/linked_list/search_node.c\
			srcs/linked_list/sort_list.c\
			srcs/linked_list/tab_to_list.c\
			srcs/shell_functions/command_parsing/and_parsing.c\
			srcs/shell_functions/command_parsing/or_parsing.c\
			srcs/shell_functions/command_parsing/parenthesis_parsing.c\
			srcs/shell_functions/command_parsing/pipe_parsing.c\
			srcs/shell_functions/command_parsing/rleft_parsing.c\
			srcs/shell_functions/command_parsing/rrighht_parsing.c\
			srcs/shell_functions/command_parsing/semicolon_parsing.c\
			srcs/shell_functions/builtins/builtin.c\
			srcs/shell_functions/builtins/fg.c\
			srcs/shell_functions/builtins/history.c\
			srcs/shell_functions/builtins/jobs.c\
			srcs/shell_functions/builtins/my_cd.c\
			srcs/shell_functions/builtins/my_env.c\
			srcs/shell_functions/builtins/my_exit.c\
			srcs/shell_functions/builtins/my_setenv.c\
			srcs/shell_functions/builtins/my_unsetenv.c\
			srcs/shell_functions/builtins/set.c\
			srcs/shell_functions/cli_execution/execute.c\
			srcs/shell_functions/cli_execution/interpretor.c\
			srcs/shell_functions/cli_execution/processing.c\
			srcs/shell_functions/job_control/job_control.c\
			srcs/shell_functions/job_control/jobs_utils.c\
			srcs/shell_functions/main_loop/main_loop.c\
			srcs/shell_functions/Others/list_str_funcs.c\
			srcs/shell_functions/Others/separator.c\
			srcs/shell_functions/prompt/delete_character.c\
			srcs/shell_functions/prompt/multi_char_binding.c\
			srcs/shell_functions/prompt/others.c\
			srcs/shell_functions/prompt/prompt.c\
			srcs/shell_functions/prompt/raw_mode.c\
			srcs/utils/count_word.c\
			srcs/utils/disp_2d_array.c\
			srcs/utils/err_putchar.c\
			srcs/utils/err_putstr.c\
			srcs/utils/free_2d_array.c\
			srcs/utils/int_to_str.c\
			srcs/utils/is_anum.c	\
			srcs/utils/is_char.c	\
			srcs/utils/is_digit.c\
			srcs/utils/is_empty_line.c\
			srcs/utils/jm_copy.c	\
			srcs/utils/my_getnbr.c\
			srcs/utils/my_perror.c\
			srcs/utils/my_putchar.c\
			srcs/utils/my_putnbr.c\
			srcs/utils/my_putstr.c\
			srcs/utils/my_strcat.c\
			srcs/utils/my_strcmp.c\
			srcs/utils/my_strcpy.c\
			srcs/utils/my_strdup.c\
			srcs/utils/my_strlen.c\
			srcs/utils/my_strncmp.c\
			srcs/utils/split.c\
			srcs/utils/swap.c\
			srcs/utils/tab_len.c\
			srcs/utils/split_semicolon.c\

OBJS = (patsubst %.c, %.o, $(SRCS))

BIN = 42sh

all: $(BIN)

$(BIN): $(SRCS)
	gcc -o $@ $^ srcs/main.c -lm -g3

unit_tests: fclean
	gcc -o unit_tests tests/unit_test.c $(SRCS) -lcriterion --coverage

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/ --branches
	gcovr --exclude tests/

clean:
	find . -type f -name "*.o" -delete
	find . -type f -name "*~" -delete
	find . -type f -name "#*#" -delete
	find . -type f -name "a.out" -delete
	find . -type f -name "vgcore*" -delete
	find . -type f -name "*.gcda" -delete
	find . -type f -name "*.gcno" -delete

fclean: clean
	rm -f $(BIN) unit_tests

re: fclean all

.PHONY: all clean fclean re
