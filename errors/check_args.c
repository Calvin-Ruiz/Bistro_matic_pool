/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** check_args.c
*/
#include "include/errors.h"
#include "include/check_args.h"

static void check_base(int b)
{
    if (b < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

static uchar_t *check_double(char **args)
{
    int a = -1;
    int b = -1;
    uchar_t *counter = my_malloc(256);

    while (++a < 256)
        counter[a] = 0;
    a = -1;
    while (args[1][++a] != '\0') {
        if (counter[args[1][a]]++ == 1) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_USAGE);
        }
    }
    while (args[2][++b] != '\0') {
        if (counter[args[2][b]]++ == 1) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_USAGE);
        }
    }
    return (counter);
}

static void check_empty(char **args)
{
    int i = my_getnbr(args[3]);

    if (i < 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    if (i == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
}

uchar_t *check_args(int nargs, char **args)
{
    int i = -1;
    int j = -1;

    check_help(args);
    if (nargs != 4) {
        my_putstr("Usage: ");
        my_putstr(args[0]);
        my_putstr(" base ops\"()+-*/%\" exp_len\n");
        exit(EXIT_USAGE);
    }
    while (args[1][++j] != '\0');
    while (args[2][++i] != '\0');
    if (i != 7){
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    check_base(j);
    check_empty(args);
    uchar_t *keys = check_double(args);
    return (keys);
}
