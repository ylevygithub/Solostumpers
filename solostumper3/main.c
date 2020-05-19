/*
** EPITECH PROJECT, 2019
** fizzbuzz
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void fizzbuzz(int ac, char **av)
{
    int a = atoi(av[1]);
    int b = atoi(av[2]);
    int i = a;

    while (i <= b) {
        if (i % 3 == 0)
            printf("Fizz");
        if (i % 5 == 0)
            printf("Buzz");
        else if (i % 5 != 0 && i % 3 != 0)
            printf("%d", i);
        printf("\n");
        i++;
    }
}

int main(int ac, char **av)
{
    char *str;
    int a;
    int b;

    if (ac != 3) {
        printf("Exit status:\t84\n");
        return (84);
    }
    a = atoi(av[1]);
    b = atoi(av[2]);
    if (ac == 3 && a > b) {
        printf("Error:\tthe second parameter must be greater than the first one.\n");
        return (84);
    }
    if (ac == 3 && a <= b)
        fizzbuzz(ac, av);
    return (0);
}
