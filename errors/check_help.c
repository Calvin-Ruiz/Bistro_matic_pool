/*
** EPITECH PROJECT, 2019
** CPool_bistro_2019
** File description:
** check_help.c
*/
#include <stdlib.h>
#include <unistd.h>

void check_help(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0'){
        write(1, "USAGE\n./calc base operators size_read\n", 38);
        write(1, "\nDESCRIPTION\n- base: all the symbols of the base\n", 49);
        write(1, "- operators: the symbols for the parentheses and", 48);
        write(1, " the 5 operators\n", 17);
        write(1, "- size_read: number of characters to be read\n", 45);
        exit(0);
    }
}
