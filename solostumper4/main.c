/*
** EPITECH PROJECT, 2019
** solostumper
** File description:
** main
*/

#include "my.h"

void my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

int name_formatter(char *str)
{
    int i = 0;
    int maj = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ')
            maj = 1;
        checkvowelone(str, i, maj);
        checkvoweltwo(str, i);
        checkvowelthree(str, i, maj);
        if (maj == 0)
            maj = 1;
        else
            maj = 0;
        i++;
    }
    my_putstr(str);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        my_putstr("Usage : geekNameFormatter string");
        my_putstr("\n");
        return (84);
    }
    name_formatter(av[1]);
    my_putstr("\n");
    return (0);
}
