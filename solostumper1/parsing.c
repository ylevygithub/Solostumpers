/*
** EPITECH PROJECT, 2019
** parsing.c
** File description:
** parserer
*/

#include "include/my.h"

t_node *parse(t_parsing *data, int ac, char **av)
{
    t_node *head = NULL;
    int index = 1;
    int error = 0;

    init_data(data);
    while (index < ac && !error) {
        if (av[index][0] == '-' && av[index][1]) {
            error = store_flags(data, av, &index);
        }
        else
            head = linked_list_add(head, str_dup(av[index]));
        index++;
    }
    return ((error) ? NULL : head);
}

int store_flags(t_parsing *data, char **av, int *index)
{
    char *error = NULL;
    char which_case = av[*index][1];

    if (which_case == 'c' || which_case == 'n') {
        data->flag_c_n = (which_case == 'c') ? 1 : 2;
        data->value = (av[*index][2]) ? (is_it_number(av[*index] + 2)) ?
        str_to_int(av[*index] + 2) : !(error = str_dup(av[*index] + 2)) :
        (is_it_number(av[++*index])) ? str_to_int(av[*index]) :
        !(error = str_dup(av[*index]));
    }
    switch (av[*index][1]) {
        case 'q': data->flag_q_v = 1;
        break;
        case 'v': data->flag_q_v = 2;
        break;
        case '-': error = store_complex_flags(data, av, index, &which_case);
        break;
    }
    (error) ? display_error(which_case, error) : 1;
    return ((error) ? 1 : 0);
}

char *store_complex_flags(
    t_parsing *data, char **av, int *index, char *which_case)
{
    char *error = NULL;

    *which_case = av[*index][2];
    if (*which_case == 'c' || *which_case == 'n') {
        data->flag_c_n = (*which_case == 'c') ? 1 : 2;
        data->value = (av[*index][2]) ? (is_it_number(av[*index] + 2)) ?
        str_to_int(av[*index] + 2) : !(error = str_dup(av[*index] + 2)) :
        (is_it_number(av[++*index])) ? str_to_int(av[*index]) :
        !(error = str_dup(av[*index]));
    }
    switch (av[*index][2]) {
        case 'q': data->flag_q_v = 1;
        break;
        case 'v': data->flag_q_v = 2;
        break;
        default: error++;
        break;
    }

    return (error);
}

void init_data(t_parsing *data)
{
    data->flag_c_n = 2;
    data->value = 10;
    data->flag_q_v = 0;
}