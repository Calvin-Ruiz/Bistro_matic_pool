/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** div.c
*/
#include <stdlib.h>
#include "include/div_mod.h"

static uint_t begin_div(lint_t len2, infnbr_t *inbr1, uint_t *nbr2, uint_t lvl)
{
    if ((len2 > inbr1->len) && nbr2[len2 - 1]) {
        right_shift(nbr2, len2, inbr1);
        return (lvl >> 1);
    }
    return (lvl);
}

static void my_div(uint_t *nbr, lint_t dec, infnbr_t *inbr1, infnbr_t *inbr2)
{
    long int i;
    uint_t *nbr2 = my_addcpy(inbr2);
    lint_t len2 = inbr2->len + 1;

    inbr1->nbr += dec;
    inbr1->len -= dec;
    uint_t level = find_level(inbr1, nbr2, len2);
    while (level > 0) {
        i = inbr1->len;
        level = begin_div(len2, inbr1, nbr2, level);
        while (i-- > 1 && inbr1->nbr[i] == nbr2[i]);
        if (inbr1->nbr[i] < nbr2[i]) {
            level = level >> 1;
            right_shift(nbr2, len2, inbr1);
        } else {
            my_sub(inbr1, nbr2, len2);
            nbr[dec] += level;
        }
    }
    readjust_ptr(inbr1, nbr2, dec);
}

infnbr_t *my_infdiv(infnbr_t *inbr1, infnbr_t *inbr2)
{
    lint_t len = inbr1->len - inbr2->len + 1;
    if (len <= 0) {
        inbr1->nbr[0] = 0;
        inbr1->len = 1;
        len = 0;
    }
    uint_t *nbr = my_malloc(sizeof(uint_t) * len);
    lint_t i = len;
    while (i-- > 0) {
        nbr[i] = 0;
        my_div(nbr, i, inbr1, inbr2);
    }
    free(inbr1->nbr);
    inbr1->nbr = nbr;
    inbr1->len = len;
    inbr1->isneg += inbr2->isneg;
    free(inbr2->nbr);
    free(inbr2);
    fix_len(inbr1);
    return (inbr1);
}
