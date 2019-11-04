/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** main_tools.c
*/
#include <stdlib.h>
#include "include/infnbr.h"
#include "include/main_tools.h"

void converter(uchar_t *convert, uchar_t *buffer, int size)
{
    int i = -1;

    while (++i < size)
        buffer[i] = convert[buffer[i]];
}

void *my_malloc(long int length)
{
    void *ptr = malloc(length);

    if (ptr == NULL) {
        ptr = malloc(length);
        if (ptr == NULL)
            my_error(MALLOC_FAIL);
    }
    return (ptr);
}

static infnbr_t *init_base(char **av)
{
    infnbr_t *base = my_malloc(sizeof(infnbr_t));
    long int max_value = 2147483648;
    base->baselen = -1;
    while (av[1][++base->baselen] != '\0');
    long int value = base->baselen;
    base->ndigits = 0;
    while (value < max_value) {
        value *= base->baselen;
        base->ndigits++;
    }
    base->limit = value / base->baselen;
    base->mid_limit = base->limit >> 1;
    base->lim_div_base = base->limit / base->baselen;
    base->lim_switch = my_malloc(sizeof(uint_t) * 2);
    base->lim_switch[0] = 0;
    base->lim_switch[1] = base->limit;
    base->mid_lim_switch = my_malloc(sizeof(uint_t) * 2);
    base->mid_lim_switch[0] = 0;
    base->mid_lim_switch[1] = base->mid_limit;
    return (base);
}

void select_operator(uchar_t const *str, lint_t len, char **av)
{
    infnbr_t *base = init_base(av);
    infnbr_t *result = my_operate(str, len, base);
    my_infnbr_printer(result, av[1], av[2][3]);
    free(base->lim_switch);
    free(base->mid_lim_switch);
    free(base);
    free(result->nbr);
    free(result);
}
