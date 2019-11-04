/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** mult.c
*/
#include <stdlib.h>
#include <unistd.h>
#include "include/infnbr.h"

static void my_free(infnbr_t *inbr1, infnbr_t *inbr2)
{
    free(inbr1->nbr);
    free(inbr2->nbr);
    free(inbr2);
}

static void my_imult(uint_t *nbr, infnbr_t *inbr1, uint_t inbr2)
{
    lint_t i = 0;
    lint_t temp = 0;

    while (i < inbr1->len) {
        temp += ((uint8_t)inbr1->nbr[i]) * inbr2 + nbr[i];
        nbr[i++] = temp % inbr1->limit;
        temp /= inbr1->limit;
    }
    nbr[i] += temp;
}

infnbr_t *my_infmult(infnbr_t *inbr1, infnbr_t *inbr2)
{
    uint_t *nbr;
    lint_t i = -1;
    lint_t n = -1;
    lint_t len = inbr1->len + inbr2->len;
    if (inbr1->len < inbr2->len) {
        infnbr_t *tmp = inbr1;
        inbr1 = inbr2;
        inbr2 = tmp;
    }
    nbr = my_malloc(sizeof(uint_t) * len);
    while (++i < len)
        nbr[i] = 0;
    while (++n < inbr2->len)
        my_imult(nbr + n, inbr1, inbr2->nbr[n]);
    inbr1->isneg += inbr2->isneg;
    my_free(inbr1, inbr2);
    inbr1->nbr = nbr;
    inbr1->len = len;
    fix_len(inbr1);
    return (inbr1);
}
