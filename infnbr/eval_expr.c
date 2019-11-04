/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** eval_expr.c
*/
#include <stdlib.h>
#include <unistd.h>
#include "include/eval_expr.h"

infnbr_t *my_operate(uchar_t const *str, long int len, infnbr_t *base);

static infnbr_t *unpack(uchar_t const *str, long int len, infnbr_t *base)
{
    int isneg = 0;
    int i = 0;

    while (str[i] == SUB || str[i] == ADD)
        isneg += str[i++] == SUB;
    if (i >= len)
        my_error(NO_DIGIT);
    if (str[i] == PAR_O) {
        str += i + 1;
        base = my_operate(str, len - 2 - i, base);
        base->isneg += isneg;
    } else
        base = get_infnbr(str, len, base);
    return (base);
}

static infnbr_t *calc(infnbr_t *res, uchar_t op, uchar_t const *s, lint_t len)
{
    switch (op) {
    case 0:
        res = unpack(s, len, res);
        return (res);
    case MUL:
        res = my_infmult(res, unpack(s, len, res));
        return (res);
    case DIV:
        res = my_infdiv(res, unpack(s, len, res));
        return (res);
    case MOD:
        res = my_infmod(res, unpack(s, len, res));
        return (res);
    }
}

static infnbr_t *prioritar_op(uchar_t const *str, lint_t len, infnbr_t *res)
{
    long int i = 0;
    uchar_t priop = 0;

    while (i < len) {
        if (str[i] == MUL || str[i] == DIV || str[i] == MOD) {
            res = calc(res, priop, str, i);
            priop = str[i];
            str += i + 1;
            len -= i + 1;
            i = -1;
        }
        i = get_next_out_of_parenthesis(str, i);
    }
    res = calc(res, priop, str, i);
    return (res);
}

infnbr_t *my_operate(uchar_t const *str, long int len, infnbr_t *base)
{
    long int i = 0;
    infnbr_t *result = get_infnbr(str, 0, base);
    while (str[i] == ADD || str[i] == SUB)
        i++;
    while (i <= len) {
        if (i == len) {
            result = my_infadd(result, prioritar_op(str, i, base));
            break;
        }
        if (str[i] == ADD || str[i] == SUB) {
            result = my_infadd(result, prioritar_op(str, i, base));
            str += i;
            len -= i;
            i = get_next_after_add_sub(str, 0, len);
        }
        if (str[i] == MUL || str[i] == DIV || str[i] == MOD)
            i = get_next_after_add_sub(str, i + 1, len);
        i = get_next_out_of_parenthesis(str, i);
    }
    return (result);
}
