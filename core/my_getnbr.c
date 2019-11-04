/*
** EPITECH PROJECT, 2019
** C Pool Day 04
** File description:
** my_getnbr.c
*/

static int add_char(int value, int add, int is_neg)
{
    if (value > 214748364) {
        return (0);
    } else if (value == 214748364) {
        if (add == '8' && is_neg) {
            return (-2147483648);
        } else if (add > '7') {
            return (0);
        }
    }
    value *= 10;
    value += (add - 48);
    return (value);
}

static int verify_limit(int after)
{
    if (after >= '9' || after <= '0') {
        return (-2147483648);
    } else {
        return (0);
    }
}

int my_getnbr(char const *str)
{
    int i = -1;
    int is_neg = 0;
    int value = 0;
    while (str[++i] > '9' || str[i] < '1') {
        is_neg = (is_neg + (str[i] == '-')) & 1;
        if (str[i] != '-' && str[i] != '+' && str[i] != '0')
            return (0);
    }
    while (str[i] <= '9' && str[i] >= '0') {
        value = add_char(value, str[i], is_neg);
        if (value == 0) {
            return (0);
        } else if (value < 1) {
            value = verify_limit(str[i + 1]);
            return (value);
        }
        i++;
    }
    value = (is_neg) ? -value : value;
    return (value);
}
