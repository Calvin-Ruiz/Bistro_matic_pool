/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** left_shift.c
*/
#include <stdlib.h>
#include <unistd.h>
#include "include/infnbr.h"

void left_shift(uint_t *nb, long int len, infnbr_t *b)
{
    long int i = -1;
    uint_t tmp[2];

    tmp[1] = 0;
    while (++i < len) {
        tmp[1 & i] = nb[i] / b->mid_limit;
        nb[i] = ((nb[i] - b->mid_lim_switch[tmp[1 & i]]) << 1) | tmp[!(1 & i)];
    }
}
