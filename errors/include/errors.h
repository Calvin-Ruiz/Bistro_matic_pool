/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** errors.h
*/
#include <stdlib.h>
#include "infnbr.h"

#ifndef ERRORS_H_
#define ERRORS_H_

#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

void my_putstr(const char *str);

#endif /* ERRORS_H_ */
