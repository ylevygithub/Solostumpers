/*
** EPITECH PROJECT, 2019
** palindrome
** File description:
** a palindrome is a string wich reads backward as forward
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int nb = 0;
    
    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb = nb + 1;
    }
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[i] != '\0') {
        i++;
    }
    while (j < i) {
        i--;
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j++;
    }
    return (str);
}

int my_malloc(int argc, char **argv)
{
    int a = 0;
    int b = 0;

    while (argv[a]) {
        b = b + my_strlen(argv[a]);
    a = a + 1;
    }
    b = b + argc;
    return (b);
}

void palindrome(char *str)
{
    if (my_revstr(str) != str) {
        my_putstr("not a palindrome.\n");
    }
    if (my_revstr(str) == str) {
        my_putstr("palindrome!\n");
    }
}
