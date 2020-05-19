/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** return the alphabetics char.
*/

#include <unistd.h>

int my_str_isalpha(char const *str)
{
    int i = 0;
    if (str[i] == '\0') {
        i++;
        return (1);
    }
    while (str[i] != '\0') {
        if ((str[i] >= 65 && str[i] <= 90) ||
            (str[i] >= 97 && str[i] <= 122))
            i++;
        else if ((str[i] >= 0 && str[i] <= 64) ||
                 (str[i] >= 91 && str[i] <= 96) ||
                 (str[i] >= 123 && str[i] <= 127))
            return (0);
    }
    return (1);
}
