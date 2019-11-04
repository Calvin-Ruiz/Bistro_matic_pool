/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** check_buffer.c
*/
#include "include/errors.h"

void check_buffer(uchar_t *buffer, int size, uchar_t **args, uchar_t *keys)
{
    int i = -1;
    int level = 0;
    while (++i < size) {
        if (keys[buffer[i]] == 0) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_USAGE);
        }
        if (buffer[i] == args[2][0])
            level++;
        if (buffer[i] == args[2][1])
            level--;
        if (level == -1) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_USAGE);
        }
    }
    if (level != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
}
