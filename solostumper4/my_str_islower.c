/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** my_str_islower
*/

int my_str_islower(char const *str)
{
    int i = 0;
    if (str[i] == '\0') {
        i++;
        return (1);
    }
    while (str[i] != '\0') {
            if (str[i] >= 97 && str[i] <= 122)
                i++;
            else if ((str[i] >= 0 && str[i] <= 96) ||
                     (str[i] >= 123 && str[i] <= 127))
                return(0);
    }
    return (1);
}
