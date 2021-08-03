/*
** EPITECH PROJECT, 2021
** list
** File description:
** linked lists
*/

#include <stdlib.h>
#include <assert.h>

#ifndef LIST_H_
#define LIST_H_

enum direction_e
{
    RIGHT,
    LEFT,
    UP,
    DOWN
};

typedef struct list_s
{
    int y;
    int x;
    enum direction_e direction;
    struct list_s *next;
}list_t;

void list_destroy(list_t **);

list_t *list_add(list_t **, int, int);

int list_size(list_t *);

#endif /* !LIST_H_ */
