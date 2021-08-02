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

int auto_move(snake_t *snake)
{
    switch (snake->direction) {
        case UP:
            snake->snake->y--;
            break;
        case DOWN:
            snake->snake->y++;
            break;
        case LEFT:
            snake->snake->x--;
            break;
        case RIGHT:
            snake->snake->x++;
            break;
    }
    if (snake->snake->x == snake->config.arena || snake->snake->y == snake->config.arena)
        return (0);
    return (1);
}