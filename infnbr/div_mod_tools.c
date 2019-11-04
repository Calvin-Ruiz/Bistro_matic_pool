/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** div_mod_tools.c
*/
#include <stdlib.h>
#include "include/div_mod_tools.h"

uint_t *my_addcpy(infnbr_t *from)
{
    uint_t *nbr;
    lint_t len = from->len + 1;

    nbr = my_malloc(len * (sizeof(uint_t)));
    nbr[--len] = 0;
    while (len-- > 0)
        nbr[len] = from->nbr[len];
    return (nbr);
}

void my_sub(infnbr_t *inbr1, uint_t *nbr2, long int len2)
{
    lint_t pos = -1;
    uint_t temp = 1;

    while (++pos < len2 && pos < inbr1->len) {
        inbr1->nbr[pos] += temp + inbr1->limit - 1 - nbr2[pos];
        temp = inbr1->nbr[pos] / inbr1->limit;
        inbr1->nbr[pos] -= inbr1->lim_switch[temp];
    }
    while (pos < inbr1->len) {
        inbr1->nbr[pos] += temp - 1 + inbr1->limit;
        temp = inbr1->nbr[pos] / inbr1->limit;
        inbr1->nbr[pos++] -= inbr1->lim_switch[temp];
    }
}

uint_t find_level(infnbr_t *inbr1, uint_t *nbr2, lint_t len2)
{
    lint_t i;
    uint_t level = 1;

    while (level > 0) {
        i = inbr1->len;
        while (i-- > 1 && inbr1->nbr[i] == nbr2[i]);
        if (inbr1->nbr[i] < nbr2[i] || (inbr1->len < len2 && nbr2[len2 - 1]))
            return (level);
        level = level << 1;
        left_shift(nbr2, len2, inbr1);
    }
    free(nbr2);
    free(inbr1->lim_switch);
    free(inbr1->mid_lim_switch);
    free(inbr1);
    my_error(DIV0);
}

void readjust_ptr(infnbr_t *inbr1, uint_t *nbr2, long int dec)
{
    inbr1->nbr -= dec;
    inbr1->len += dec;
    inbr1->len -= (inbr1->nbr[inbr1->len - 1] == 0) && (inbr1->len > 1);
    free(nbr2);
}
