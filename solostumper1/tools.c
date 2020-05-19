/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** basic functions
*/

#include "include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr_error(char const *str)
{
    int index = -1;

    while (str[++index]);
    write(2, str, index);
}

void my_putstr(char const *str)
{
    int index = -1;

    while (str[++index]);
    write(1, str, index);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}

int str_to_int(char *str)
{
    int number = 0;
    int index = 0;
    int isNeg = 0;

    if (str[0] == '-')
        isNeg = 1;
    while (str[index] >=  '0' && str[index] <= '9') {
        number += str[index] - 48;
        if (str[++index])
            number *= 10;
    }
    return (isNeg == 1 ? number *= -1 : number);
}