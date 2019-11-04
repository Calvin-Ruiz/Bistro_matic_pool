/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** inftools.c
*/
#include "include/infnbr.h"

long int get_next_out_of_parenthesis(uchar_t const *str, long int i)
{
    int level = (str[i++] == PAR_O);

    while (level > 0)
        level = level + (str[i] == PAR_O) - (str[i++] == PAR_C);
    return (i);
}

void fix_len(infnbr_t *inbr)
{
    while (inbr->nbr[inbr->len - 1] == 0 && inbr->len > 1)
        inbr->len--;
}

long int get_next_after_add_sub(uchar_t const *str, long int i, long int len)
{
    if (len == 0)
        return (i);
    while (str[i] == ADD || str[i] == SUB)
        i++;
    if (i >= len)
        my_error(NO_DIGIT);
    return (i);
}
