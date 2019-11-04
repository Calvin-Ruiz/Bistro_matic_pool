/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** mod.c
*/
#include <stdlib.h>
#include "include/div_mod.h"

static void my_mod(long int dec, infnbr_t *inbr1, infnbr_t *inbr2)
{
    long int i;
    uint_t *nbr2 = my_addcpy(inbr2);
    lint_t len2 = inbr2->len + 1;
    inbr1->nbr += dec;
    inbr1->len -= dec;
    uint_t level = find_level(inbr1, nbr2, len2);
    while (level > 0) {
        i = inbr1->len;
        if ((len2 > inbr1->len) && nbr2[len2 - 1]) {
            level = level >> 1;
            right_shift(nbr2, len2, inbr1);
        }
        while (i-- > 1 && inbr1->nbr[i] == nbr2[i]);
        if (inbr1->nbr[i] < nbr2[i]) {
            level = level >> 1;
            right_shift(nbr2, len2, inbr1);
        } else
            my_sub(inbr1, nbr2, len2);
    }
    readjust_ptr(inbr1, nbr2, dec);
}

infnbr_t *my_infmod(infnbr_t *inbr1, infnbr_t *inbr2)
{
    lint_t len = inbr1->len - inbr2->len + 1;
    lint_t i = len;

    while (i-- > 0)
        my_mod(i, inbr1, inbr2);
    free(inbr2->nbr);
    free(inbr2);
    fix_len(inbr1);
    return (inbr1);
}
