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

    if (snake->has_pressed)
        return (1);
    if (snake->config.display != SFML) {
        if ((*delay)++ == snake->config.speed)
            return (1);
        usleep(1000000/snake->config.tickrate);
        return (0);
    }
    seconds = sfTime_asSeconds(sfClock_getElapsedTime(snake->sfml.clock));
    if (seconds * snake->config.tickrate < 1)
        return (0);
    sfClock_restart(snake->sfml.clock);
    return (1);
}

int run_game(snake_t *snake)
{
    int delay = 0;
    int result = 0;

    print_display(snake);
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