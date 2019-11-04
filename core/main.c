/*
** EPITECH PROJECT, 2019
** C Pool bistro-matic
** File description:
** main.c
*/
#include <stdlib.h>
#include <unistd.h>
#include "include/infnbr.h"
#include "include/main.h"

int main(int nargs, char **args)
{
    uchar_t *keys = check_args(nargs, args);
    int size = my_getnbr(args[3]);
    uchar_t buffer[size];
    int i = -1;
    uchar_t *convert = my_malloc(256);

    while (args[1][++i] != '\0')
        convert[args[1][i]] = i;
    i = -1;
    while (args[2][++i] != '\0')
        convert[args[2][i]] = PAR_O + i;
    size = read(0, buffer, size);
    check_buffer(buffer, size, args, keys);
    free(keys);
    converter(convert, buffer, size);
    free(convert);
    select_operator(buffer, size, args);
    return (0);
}
