/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** infnbr.h
*/

#ifndef INFNBR_H_
#define INFNBR_H_

enum {
    PAR_O = 249,
    PAR_C,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
};

enum {
    DIV0,
    MOD0,
    MISS_OP,
    NO_DIGIT,
    MALLOC_FAIL,
};

typedef unsigned long int uint8_t;
typedef unsigned int uint_t;
typedef unsigned char uchar_t;
typedef long int lint_t;

typedef struct infnbr
{
    uint_t *nbr;
    long int len;
    int isneg;
    uchar_t baselen;
    uchar_t ndigits;
    uint_t limit;
    uint_t lim_div_base;
    uint_t mid_limit;
    uint_t *lim_switch;
    uint_t *mid_lim_switch;
} infnbr_t;

void my_error(int errtype);
void *my_malloc(long int length);
long int get_next_out_of_parenthesis(uchar_t const *str, long int i);
long int get_next_after_add_sub(uchar_t const *str, long int i, long int len);
void my_putchar(char c);
void fix_len(infnbr_t *inbr);

#endif /* INFNBR_H_ */
