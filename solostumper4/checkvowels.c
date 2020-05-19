/*
** EPITECH PROJECT, 2019
** solostumper
** File description:
** check the vowels
*/

#include "my.h"

void checkvowelone(char *str, int i, int maj)
{
    if (maj == 0 &&  str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
    if (str[i] == 'o' || str[i] == 'O')
        str[i] = '0';
    if (str[i] == 'i' || str[i] == 'I')
        str[i] = '1';
}

void checkvoweltwo(char *str, int i)
{
    if (str[i] == 'u' || str[i] == 'U')
        str[i] = '2';
    if (str[i] == 'e' || str[i] == 'E')
        str[i] = '3';
    if (str[i] == 'a' || str[i] == 'A')
        str[i] = '4';
}

void checkvowelthree(char *str, int i, int maj)
{
    if (maj == 1 && str[i] >= 'A' && str[i] <= 'Z')
        str[i] = str[i] + 32;
    if (str[i] == 'y' || str[i] == 'Y')
        str[i] = '5';
}
