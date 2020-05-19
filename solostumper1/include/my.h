/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** function prototypes
*/

#ifndef __MY_H__
#define __MY_H__

#include <stdio.h> //test

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE 10

typedef struct s_node
{
    char *path;
    struct s_node *next;
} t_node;

typedef struct s_parsing {
    int flag_c_n;
    int value;
    int flag_q_v;
} t_parsing;

int main(int argc, char **argv);
int head_fct(t_parsing *data, t_node *head);
int per_byte(int nb_byte, int q_v, t_node *head);
int per_line(int nb_byte, int q_v, t_node *head);

void init_data(t_parsing *data);
t_node *parse(t_parsing *data, int ac, char **av);
int store_flags(t_parsing *data, char **av, int *index);
char *store_complex_flags(
    t_parsing *data, char **av, int *index, char *which_case);

void my_putchar(char c);
void my_putstr_error(char const *str);
void my_putstr(char const *str);
void my_put_nbr(int nb);
int str_to_int(char *str);
int is_it_number(char *str);
char *str_dup(char *str);

t_node *linked_list_add(t_node *head, char *path);
void linked_list_print(t_node *head);

void display_file_name(char *name);
void display_error(char which_error, char *error);
int display_file_byte(int nb_byte, char *path);
int display_file_line(int nb_line, char *path);

char *get_next_line(int fd);
char *read_gnl(int fd, char **result, int totNb);
char *str_join_gnl(char *str1, char *str2);
char *str_dup_gnl(char *str);

#endif
