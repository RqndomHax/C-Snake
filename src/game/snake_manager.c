/*
** EPITECH PROJECT, 2021
** snake
** File description:
** snake manager
*/

#include "../../includes/game.h"

int move_snake(snake_t *snake)
{
    list_t *tail = snake->tail;
    int result = 0;

    result = auto_move(snake);
    if (result != 2)
        return (result);
    while (tail->next != NULL) {
        tail->direction = tail->next->direction;
        if (tail->next->x != tail->x || tail->next->y != tail->y)
            update_coordinates(tail, &snake->config);
        tail = tail->next;
    }
    return (2);
}