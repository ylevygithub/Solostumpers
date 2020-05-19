/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>

int my_strlen(char *str)
{
    int nb;

    nb = 0;
    while (str[nb] != '\0')
        nb++;
    return (nb);
}

int main(int ac, char **av)
{
    char *str = my_malloc(ac, av);
    int i = 0;
    str = av[i];
    if (ac > 1)
        palindrome(str);
    if (ac == 1) {
        my_putstr("Error : missing arguments.\n");
        return (84);
    }
    return (0);
}
