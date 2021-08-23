/*
** EPITECH PROJECT, 2021
** snake
** File description:
** game manager
*/

#include "../../includes/game.h"
#include "../../includes/list.h"
#include <unistd.h>
#include <time.h>

static int can_move(int *delay, snake_t *snake)
{
    float seconds;

    if (*delay >= snake->config.speed)
        return (1);
    if (snake->config.force_move && snake->has_pressed)
        return (1);
    if (snake->config.display != SFML) {
        clock_t current = clock();
        if (((double) (current - snake->start) / CLOCKS_PER_SEC) * snake->config.tickrate >= 1) {
            snake->start = current;
            (*delay)++;
        }
        return (*delay >= snake->config.speed);
    }
    seconds = sfTime_asSeconds(sfClock_getElapsedTime(snake->sfml.clock));
    if (seconds * snake->config.tickrate >= 1) {
        (*delay)++;
        sfClock_restart(snake->sfml.clock);
    }
    return (*delay >= snake->config.speed);
}

int run_game(snake_t *snake)
{
    int delay = 0;
    int result = 0;

    print_display(snake);
    snake->start = clock();
    while (snake->is_running) {
        manage_game(snake);
        if (snake->config.display == SFML)
            print_sfml(snake);
        if (!can_move(&delay, snake))
            continue;
        snake->has_pressed = 0;
        delay = 0;
        snake->moves++;
        result = move_snake(snake);
        if (result != 2) {
            snake->is_running = 0;
            return (result);
        }
        print_display(snake);
    }
    snake->is_running = 0;
    return (1);
}