/*
** EPITECH PROJECT, 2019
** head.c
** File description:
** copy of the head function
*/

#include "include/my.h"

int per_line(int nb_line, int q_v, t_node *head)
{
    t_node *traveler = head;

    if (q_v == 0)
        q_v = (traveler->next) ? 2 : 1;
    if (traveler) {
        (q_v == 2) ? display_file_name(traveler->path) : 1;
        display_file_line(nb_line, traveler->path);
        while (traveler->next) {
            traveler = traveler->next;
            (q_v == 2) ? display_file_name(traveler->path) : 1;
            display_file_line(nb_line, traveler->path);
        }
    }
    return (0);   
}


int per_byte(int nb_byte, int q_v, t_node *head)
{
    t_node *traveler = head;

    if (q_v == 0)
        q_v = (traveler->next) ? 2 : 1;
    if (traveler) {
        (q_v == 2) ? display_file_name(traveler->path) : 1;
        display_file_byte(nb_byte, traveler->path);
        while (traveler->next) {
            traveler = traveler->next;
            (q_v == 2) ? display_file_name(traveler->path) : 1;
            display_file_byte(nb_byte, traveler->path);
        }
    }
    return (0);
}

int head_fct(t_parsing *data, t_node *head)
{
    if (data->flag_c_n == 1)
        return (per_byte(data->value, data->flag_q_v, head));
    else {
        return (per_line(data->value, data->flag_q_v, head));
    }
}

int main(int ac, char **av)
{
    t_parsing *data = malloc(sizeof(t_parsing));
    t_node *head = parse(data, ac, av);

    if (head == NULL)
        return (1);
    return (head_fct(data, head));
}