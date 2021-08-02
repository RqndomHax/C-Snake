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
    list_add(&snake->snake, snake->config.arena/2, snake->config.arena/2);
    if (snake->snake == NULL)
        return (0);
    snake->is_running = 1;
    set_default_value(&snake->config.fps, 60);
    set_default_value(&snake->config.tickrate, 10);
    set_default_value(&snake->config.speed, 2);
    set_default_value(&snake->config.size, 4);
    set_default_value(&snake->config.booster, 1);
    set_default_value(&snake->config.arena, 20);
    snake->direction = RIGHT;
    return (1);
}

static void print_infos(snake_t *snake)
{
    printf("----------\n");
    printf("\n--- snake head position ---\n");
    printf("--direction: %d\n--x: %d\n--y: %d\n", snake->direction, snake->snake->x, snake->snake->y);
    printf("\n--- snake size ---\n");
    printf("--size: %d\n", list_size(snake->snake));
    printf("----------\n");
}

int run_game(snake_t *snake)
{
    int delay = 0;

    while (snake->is_running) {
        if (delay++ < snake->config.speed)
            continue;
        delay = 0;
        if (!move_snake(snake))
            return (0);
        print_infos(snake);
        usleep(1000000/snake->config.tickrate);
    }
    return (1);
}