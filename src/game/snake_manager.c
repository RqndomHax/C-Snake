/*
** EPITECH PROJECT, 2021
** snake
** File description:
** snake manager
*/

#include "../../includes/snake.h"

static void move_tail_snake(list_t *bit, list_t *destination)
{
    if (bit->x == destination->x && bit->y == destination->y)
        return;
    bit->x = destination->x;
    bit->y = destination->y;
}

int move_snake(snake_t *snake)
{
    list_t *tmp = snake->snake;
    list_t *old = snake->snake;
    int result = 0;

    result = auto_move(snake);
    if (result != 2)
        return (result);
    while (tmp->next != NULL) {
        old = tmp;
        tmp = tmp->next;
        move_tail_snake(tmp, old);
    }
    return (2);
}