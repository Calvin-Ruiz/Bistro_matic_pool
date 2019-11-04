/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** io_bases.c
*/
#include "include/infnbr.h"

void my_infnbr_printer(infnbr_t *infnbr, char const *base, char const minus)
{
    long int len = infnbr->len;
    uint_t selector = infnbr->limit;
    int digit = 0;

    while (infnbr->nbr[len - 1] == 0 && --len > 1);
    while (selector > (infnbr->nbr[len - 1] | 1))
        selector /= infnbr->baselen;
    if ((infnbr->isneg & 1) && infnbr->nbr[len - 1])
        my_putchar(minus);
    if (len < 1)
        my_putchar(base[0]);
    while (len-- > 0) {
        while (selector > 0) {
            digit = infnbr->nbr[len] / selector;
            my_putchar(base[digit]);
            infnbr->nbr[len] -= digit * selector;
            selector /= infnbr->baselen;
        }
        selector = infnbr->lim_div_base;
    }
}

infnbr_t *init_base(infnbr_t *base)
{
    infnbr_t *new_inf;

    new_inf = my_malloc(sizeof(*new_inf));
    new_inf->baselen = base->baselen;
    new_inf->ndigits = base->ndigits;
    new_inf->limit = base->limit;
    new_inf->lim_div_base = base->lim_div_base;
    new_inf->mid_limit = base->mid_limit;
    new_inf->lim_switch = base->lim_switch;
    new_inf->mid_lim_switch = base->mid_lim_switch;
    new_inf->isneg = 0;
    return (new_inf);
}

static uint_t *get_uint_array(uchar_t const *buff, lint_t len, infnbr_t *base)
{
    uint_t *nbr;
    uint_t mult = base->limit;
    long int pos = -1;
    long int loop = (len - 1) / base->ndigits + 1;

    nbr = my_malloc(loop * (sizeof(uint_t)));
    while (len-- > 0) {
        if (mult == base->limit) {
            mult = 1;
            nbr[++pos] = 0;
        }
        nbr[pos] += mult * buff[len];
        mult *= base->baselen;
    }
    return (nbr);
}

infnbr_t *get_infnbr(uchar_t const *buffer, long int bufflen, infnbr_t *base)
{
    infnbr_t *new_inf = init_base(base);

    if (bufflen == 0) {
        new_inf->nbr = my_malloc(sizeof(int));
        new_inf->nbr[0] = 0;
        new_inf->len = 1;
        return (new_inf);
    }
    while (buffer[0] == ADD || buffer[0] == SUB) {
        new_inf->isneg += buffer++[0] == SUB;
        bufflen--;
    }
    while (buffer++[0] == 0)
        bufflen--;
    new_inf->nbr = get_uint_array(--buffer, bufflen, base);
    new_inf->len = (bufflen - 1) / base->ndigits + 1;
    return (new_inf);
}
