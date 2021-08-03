/*
** EPITECH PROJECT, 2021
** lib
** File description:
** linked lists
*/

#include "../includes/list.h"

void list_destroy(list_t **list)
{
    list_t *current = *list;
    list_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}

list_t *list_add(list_t **list, int x, int y)
{
    list_t *new;
    list_t *to_last = *list;

    new = malloc(sizeof(list_t));
    if (!new)
        return (0);
    new->x = x;
    new->y = y;
    new->next = NULL;
    if (*list == NULL)
        *list = new;
    else {
        while (to_last->next != NULL)
            to_last = to_last->next;
        to_last->next = new;
    }
    return (new);
}


int list_size(list_t *list)
{
    list_t *tmp = list;
    int size = 0;

    if (list == NULL)
        return (size);
    while (tmp != NULL) {
        tmp = tmp->next;
        size++;
    }
    return (size);
}