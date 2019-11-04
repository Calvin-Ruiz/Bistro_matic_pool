/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** my_error.c
*/
#include "include/errors.h"

void my_error(int errtype)
{
    switch (errtype) {
    case DIV0:
        my_putstr(ERROR_MSG);
        exit(EXIT_OPS);
    case MOD0:
        my_putstr(ERROR_MSG);
        exit(EXIT_OPS);
    case MISS_OP:
        my_putstr(ERROR_MSG);
        exit(EXIT_USAGE);
    case NO_DIGIT:
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
}
