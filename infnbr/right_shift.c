/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** right_shift.c
*/
#include <stdlib.h>
#include <unistd.h>
#include "include/infnbr.h"

void right_shift(uint_t *nb, lint_t i, infnbr_t *base)
{
    uint_t tmp[2];

    tmp[1 & i] = 0;
    while (i-- > 0) {
        tmp[1 & i] = nb[i] & 1;
        nb[i] = (nb[i] >> 1) + base->mid_lim_switch[tmp[!(1 & i)]];
    }
}
