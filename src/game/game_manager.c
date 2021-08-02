/*
** EPITECH PROJECT, 2021
** snake
** File description:
** game manager
*/

#include "../../includes/snake.h"
#include "../../includes/list.h"
#include <unistd.h>
#include <time.h>

void set_default_value(int *target, int value)
{
    if (*target == -1)
        *target = value;
}

int init_game(snake_t *snake)
{
    snake->snake = NULL;
    snake->is_running = 1;
    set_default_value(&snake->config.fps, 60);
    set_default_value(&snake->config.tickrate, 10);
    set_default_value(&snake->config.speed, 2);
    set_default_value(&snake->config.size, 4);
    set_default_value(&snake->config.booster, 1);
    set_default_value(&snake->config.arena, 20);
    snake->direction = RIGHT;
    for (int i = 0; i < snake->config.size; i++)
        list_add(&snake->snake, snake->config.arena/2, snake->config.arena/2);
    return (1);
}

int run_game(snake_t *snake)
{
    int delay = 0;
    int result = 0;

    while (snake->is_running) {
        if (delay++ < snake->config.speed)
            continue;
        delay = 0;
        snake->moves++;
        result = move_snake(snake);
        if (result != 2)
            return (result);
        usleep(1000000/snake->config.tickrate);
    }
    return (1);
}