/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** div_mod.h
*/
#include "infnbr.h"

#ifndef DIV_MOD_H_
#define DIV_MOD_H_

void right_shift(uint_t *nb, lint_t len, infnbr_t *base);
void my_sub(infnbr_t *inbr1, uint_t *nbr2, lint_t len2);
uint_t find_level(infnbr_t *inbr1, uint_t *nbr2, lint_t len2);
uint_t *my_addcpy(infnbr_t *from);
void readjust_ptr(infnbr_t *inbr1, uint_t *nbr2, long int dec);

#endif /* DIV_MOD_H_ */
