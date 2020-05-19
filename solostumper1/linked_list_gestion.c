/*
** EPITECH PROJECT, 2019
** linked_list_gestion.c
** File description:
** linked list gestion
*/

#include "include/my.h"

void linked_list_print(t_node *head)
{
    t_node *traveler = head;

    if (traveler) {
        my_putstr(traveler->path);
        my_putchar('\n');
        while (traveler->next) {
            traveler = traveler->next;
            my_putstr(traveler->path);
            my_putchar('\n');
        }
    }
}

t_node *linked_list_add(t_node *head, char *path)
{
    t_node *tmp = malloc(sizeof(t_node));
    tmp->path = path;
    tmp->next = NULL;
    t_node *traveler;

    if (head == NULL)
        head = tmp;
    else {
        traveler = head;
        while (traveler->next != NULL)
            traveler = traveler->next;
        traveler->next = tmp;
    }
    return (head);
}