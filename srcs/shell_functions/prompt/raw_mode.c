/*
** EPITECH PROJECT, 2024
** SHELL PROGRAMMING
** File description:
** Functions to enable and desable raw mode
*/

#include <termios.h>
#include <unistd.h>

void disable_raw_mode(void)
{
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

void enable_raw_mode(void)
{
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}
