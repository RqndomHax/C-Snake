/*
** EPITECH PROJECT, 2021
** snake
** File description:
** game movements
*/

#include "../../includes/snake.h"

void move_left(snake_t *snake)
{
    if (snake->direction == RIGHT)
        return;
    snake->direction = LEFT;
}

void move_right(snake_t *snake)
{
    if (snake->direction == LEFT)
        return;
    snake->direction = RIGHT;
}

void move_up(snake_t *snake)
{
    if (snake->direction == DOWN)
        return;
    snake->direction = UP;
}

void move_down(snake_t *snake)
{
    if (snake->direction == UP)
        return;
    snake->direction = DOWN;
}