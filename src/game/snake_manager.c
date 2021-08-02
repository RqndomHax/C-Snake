/*
** EPITECH PROJECT, 2021
** snake
** File description:
** snake manager
*/

#include "../../includes/snake.h"

static int move_tail_snake(list_t *bit, list_t *destination)
{
    if (bit->x == destination->x && bit->y == destination->y)
        return (0);
    bit->x = destination->x;
    bit->y = destination->y;
    return (1);
}

int move_snake(snake_t *snake)
{
    list_t *tmp = snake->snake;
    list_t *old = snake->snake;

    if (!auto_move(snake))
        return (0);
    while (tmp->next != NULL) {
        old = tmp;
        tmp = tmp->next;
        if (!move_tail_snake(tmp, old))
            return (0);
    }
    return (1);
}