/*
** EPITECH PROJECT, 2019
** tools_sec.c
** File description:
** toolbox second part
*/

#include "include/my.h"

char *str_dup(char *str)
{
    char *result;
    int index = -1;

    while (str[++index]);
    result = malloc(index + 1);
    if (!result)
        return (NULL);
    result[index] = '\0';
    index = -1;
    while (str[++index])
        result[index] = str[index];
    return (result);
}

int is_it_number(char *str)
{
    for (int index = 0; str[index]; index++)
        if (str[index] > '9' || str[index] < '0')
            return (0);
    return (1);
}