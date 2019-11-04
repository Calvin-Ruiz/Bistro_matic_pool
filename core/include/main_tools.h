/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** main_tools.h
*/
#include "infnbr.h"

#ifndef MAIN_TOOLS_H_
#define MAIN_TOOLS_H_

infnbr_t *my_operate(uchar_t const *buffer, lint_t bufflen, infnbr_t *base);
void my_infnbr_printer(infnbr_t *inbr, char const *base, char const minus);

#endif /* MAIN_TOOLS_H_ */
