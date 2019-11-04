/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** printers.c
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb *(-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb +'0');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}

void my_putstr(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        my_putchar(str[i]);
}
