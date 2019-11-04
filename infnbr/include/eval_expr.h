/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** eval_expr.h
*/
#include "infnbr.h"

#ifndef EVAL_EXPR_H_
#define EVAL_EXPR_H_

infnbr_t *get_infnbr(uchar_t const *buffer, lint_t bufflen, infnbr_t *base);
infnbr_t *my_infadd(infnbr_t *infnbr1, infnbr_t *infnbr2);
infnbr_t *my_infmult(infnbr_t *inbr1, infnbr_t *inbr2);
infnbr_t *my_infdiv(infnbr_t *inbr1, infnbr_t *inbr2);
infnbr_t *my_infmod(infnbr_t *inbr1, infnbr_t *inbr2);

#endif /* EVAL_EXPR_H_ */
