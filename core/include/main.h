/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** main.h
*/
#include "infnbr.h"

#ifndef MAIN_H_
#define MAIN_H_

uchar_t *check_args(int nargs, char **args);
void check_buffer(uchar_t *buffer, int size, char **args, uchar_t *keys);
void converter(uchar_t *convert, uchar_t *buffer, int size);
int my_getnbr(char *str);
void select_operator(uchar_t const *str, lint_t len, char **av);

#endif /* MAIN_H_ */
