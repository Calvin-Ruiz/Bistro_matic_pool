/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** add.c
*/
#include <stdlib.h>
#include <unistd.h>
#include "include/infnbr.h"

static void my_addcpy(infnbr_t *from, int to_add)
{
    uint_t *nbr;
    long int len = from->len++;

    nbr = my_malloc((from->len) * (sizeof(uint_t)));
    nbr[len--] = to_add;
    nbr[len] = from->nbr[len] - from->lim_switch[to_add];
    while (len-- > 0)
        nbr[len] = from->nbr[len];
    free(from->nbr);
    from->nbr = nbr;
}

static void my_sub(infnbr_t *inbr1, infnbr_t *inbr2, uint_t temp)
{
    long int pos = -1;

    while (++pos < inbr2->len) {
        inbr1->nbr[pos] += temp + inbr1->limit - 1 - inbr2->nbr[pos];
        temp = inbr1->nbr[pos] / inbr1->limit;
        inbr1->nbr[pos] -= inbr1->lim_switch[temp];
    }
    while (pos < inbr1->len) {
        inbr1->nbr[pos] += temp + inbr1->limit - 1;
        temp = inbr1->nbr[pos] / inbr1->limit;
        inbr1->nbr[pos++] -= inbr1->lim_switch[temp];
    }
}

static void my_add(infnbr_t *inbr1, infnbr_t *inbr2, uint_t temp)
{
    long int pos = -1;

    while (++pos < inbr2->len) {
        inbr1->nbr[pos] += inbr2->nbr[pos] + temp;
        temp = inbr1->nbr[pos] / inbr1->limit;
        inbr1->nbr[pos] -= inbr1->lim_switch[temp];
    }
    while (pos < inbr1->len) {
        inbr1->nbr[pos] += temp;
        temp = inbr1->nbr[pos] / inbr1->limit;
        inbr1->nbr[pos++] -= inbr1->lim_switch[temp];
    }
}

static void my_adder(infnbr_t *inbr1, infnbr_t *inbr2)
{
    uint_t temp = 0;

    if ((inbr1->isneg + inbr2->isneg) & 1) {
        temp = 1;
        my_sub(inbr1, inbr2, temp);
    } else
        my_add(inbr1, inbr2, temp);
    free(inbr2->nbr);
    free(inbr2);
    fix_len(inbr1);
}

infnbr_t *my_infadd(infnbr_t *inb1, infnbr_t *inb2)
{
    if (inb1->len < inb2->len) {
        infnbr_t *tmp = inb1;
        inb1 = inb2;
        inb2 = tmp;
    }
    if ((inb1->nbr[inb1->len - 1] + inb2->nbr[inb2->len - 1]) >= inb1->limit) {
        if (!((inb1->isneg + inb2->isneg) & 1))
            my_addcpy(inb1, (inb1->nbr[inb1->len++ - 1] >= inb1->limit));
    }
    if (((inb1->isneg + inb2->isneg) & 1) && (inb1->len == inb2->len)) {
        long int i = inb1->len;
        while (i-- > 1 && (inb1->nbr[i] == inb2->nbr[i]));
        if (inb1->nbr[i] < inb2->nbr[i]) {
            infnbr_t *tmp2 = inb1;
            inb1 = inb2;
            inb2 = tmp2;
        }
    }
    my_adder(inb1, inb2);
    return (inb1);
}
