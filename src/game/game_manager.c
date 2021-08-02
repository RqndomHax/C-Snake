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
    list_add(&snake->snake, snake->arena/2, snake->arena/2);
    if (snake->snake == NULL)
        return (0);
    snake->is_running = 1;
    set_default_value(&snake->fps, 60);
    set_default_value(&snake->tickrate, 10);
    set_default_value(&snake->speed, 2);
    set_default_value(&snake->size, 4);
    set_default_value(&snake->booster, 1);
    set_default_value(&snake->arena, 20);
    if (snake->display == DEFAULT)
        snake->display = NCURSES;
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
    int speed = 0;

    while (snake->is_running) {
        if (speed++ < snake->speed)
            continue;
        speed = 0;
        print_infos(snake);
        usleep(1000000/snake->tickrate);
    }
    return (1);
}