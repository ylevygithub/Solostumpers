/*
** EPITECH PROJECT, 2019
** fuzzbozz
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void fuzzbozz(int ac, char **av)
{
    int a = atoi(av[1]);
    int b = atoi(av[2]);
    int i = a;

    while (i <= b) {
        if (i % 2 == 0)
            printf("Fuzz");
        if (i % 3 == 0)
            printf("Bozz");
        else if (i % 2 != 0 && i % 3 != 0)
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
        printf("Exit status: 84\n");
        return (84);
    }
    a = atoi(av[1]);
    b = atoi(av[2]);
    if (ac == 3 && a > b) {
        write(2, "Error: the second ", 18);
        write(2, "parameter must be greater ", 26);
        write(2, "than the first one.\n", 20);
        return (84);
    }
    if (ac == 3 && a <= b)
        fuzzbozz(ac, av);
    return (0);
}
