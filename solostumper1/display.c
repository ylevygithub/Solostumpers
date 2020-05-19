/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display prompt
*/

#include "include/my.h"

void display_file_name(char *name)
{
    my_putstr("==> ");
    my_putstr(name);
    my_putstr(" <==\n");
}

int display_file_line(int nb_line, char *path)
{
    int fd = open(path, O_RDONLY);

    for (int index = 0; index < nb_line; index++) {
        if (fd < 0) {
            display_error('f', path);
            return (0);
        }
        my_putstr(get_next_line(fd));
        my_putchar('\n');
    }
}


int display_file_byte(int nb_byte, char *path)
{
    int fd = open(path, O_RDONLY);
    int readed = 0;
    char *tmpFile = malloc(nb_byte + 1);

    tmpFile[nb_byte] = '\0';
    if (fd < 0) {
        display_error('f', path);
        return (0);
    }
    readed = read(fd, tmpFile, nb_byte);
    if (readed < 0) {
        display_error('f', path);
        return (0);
    }
    for (int index = 0; index < readed; index++)
        my_putchar(tmpFile[index]);
    close(fd);
    return (0);
}

void display_error(char which_error, char *error)
{
    switch (which_error) {
        case 'c' : my_putstr_error("head: invalud number of bytes: '");
        my_putstr_error(error);
        my_putstr_error("'\n");
        break;
        case 'n' : my_putstr_error("head: invalud number of lines: '");
        my_putstr_error(error);
        my_putstr_error("'\n");
        break;
        case 'f' : my_putstr_error("head: cannot open '");
        my_putstr_error(error);
        my_putstr_error("' for reading: No such file or directory\n");
        break;
    }
}