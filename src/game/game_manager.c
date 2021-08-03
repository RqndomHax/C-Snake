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
    snake->tail = NULL;
    snake->is_running = 1;
    set_default_value(&snake->config.fps, 60);
    set_default_value(&snake->config.tickrate, 10);
    set_default_value(&snake->config.speed, 2);
    set_default_value(&snake->config.size, 4);
    set_default_value(&snake->config.booster, 1);
    set_default_value(&snake->config.arena, 20);
    snake->head = list_add(&snake->tail, snake->config.arena/2, snake->config.arena/2);
    if (!snake->head)
        return (0);
    for (int i = 0; i < snake->config.size; i++) {
        snake->head->direction = RIGHT;
        snake->head = list_add(&snake->tail, snake->config.arena/2, snake->config.arena/2);
        if (!snake->head) {
            list_destroy(&snake->tail);
            return (0);
        }
    }
    return (1);
}

int run_game(snake_t *snake)
{
    int delay = 0;
    int result = 0;

    print_ncurse(snake);
    while (snake->is_running) {
        manage_game(snake);
        if (delay++ < snake->config.speed)
            continue;
        delay = 0;
        snake->moves++;
        result = move_snake(snake);
        if (result != 2) {
            snake->is_running = 0;
            return (result);
        }
        print_ncurse(snake);
    }
    snake->is_running = 0;
    return (1);
}