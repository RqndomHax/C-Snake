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