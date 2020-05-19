/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** my function getline
*/

#include "include/my.h"

char *str_dup_gnl(char *str)
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

char *str_join_gnl(char *str1, char *str2)
{
    char *result;
    int indexStr1 = 0;
    int indexStr2 = 0;

    while (str2[indexStr2] || str1[indexStr1]) {
        if (str1[indexStr1])
            indexStr1++;
        if (str2[indexStr2])
            indexStr2++;
    }
    result = malloc(indexStr1 + indexStr2 + 1);
    result[indexStr1 + indexStr2] = '\0';
    indexStr1 = -1;
    while (str1[++indexStr1])
        result[indexStr1] = str1[indexStr1];
    for (int index = 0; index < indexStr2; index++)
        result[indexStr1 + index] = str2[index];
    free(str1);
    free(str2);
    return (result);
}

char *read_gnl(int fd, char **result, int totNb)
{
    char *buff = malloc(READ_SIZE + 1);
    char *prev = NULL;
    int charNb = read(fd, buff, READ_SIZE);
    int index = -1;

    buff[charNb] = '\0';
    for (int i = 0; i < charNb && !*result; i++)
        if (buff[i] == '\n') {
            *result = malloc(totNb + i + 1);
            (*result)[totNb + i] = '\0';
            prev = (buff[i + 1] != '\0') ? str_dup_gnl(buff + i + 1) : NULL;
        }
    (!charNb && totNb) ? *result = malloc(totNb + 1) : NULL;
    (!charNb && totNb) ? (*result)[totNb] = '\0' : 1;
    if (*result == NULL && charNb)
        prev = read_gnl(fd, result, totNb + charNb);
    while (buff[++index] != '\n' && buff[index] && *result)
        (*result)[totNb + index] = buff[index];
    free(buff);
    return (prev);
}

char *get_next_line(int fd)
{
    static char *prev = NULL;
    char *result = NULL;
    char *prevTmp = NULL;
    int index = -1;

    while (prev && prev[++index])
        if (prev[index] == '\n') {
            prev[index] = '\0';
            result = str_dup_gnl(prev);
            prevTmp = prev;
            prev = str_dup_gnl(prev + index + 1);
            free(prevTmp);
            return (result);
        }
    prevTmp = (fd > 0 && read(fd, prevTmp, 0) == 0) ?
        read_gnl(fd, &result, 0) : NULL;
    if (prev)
        result = (result) ? str_join_gnl(prev, result) : prev;
    prev = prevTmp;
    return (result);
}