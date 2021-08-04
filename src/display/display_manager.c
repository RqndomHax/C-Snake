/*
** EPITECH PROJECT, 2021
** snake
** File description:
** display manager
*/

#include <unistd.h>
#include "../../includes/game.h"

void manage_game(snake_t *snake)
{
    if (snake->config.display == SFML)
        return (sfml_display(snake));
    return (ncurses_display(snake));
}

int init_display(snake_t *snake)
{
    if (snake->config.display == SFML)
        return (init_sfml(snake));
    return (init_ncurses(snake));
}

void print_display(snake_t *snake)
{
    if (snake->config.display == SFML)
        return;
    return (print_ncurses(snake));
}

void print_win(snake_t *snake) {
    if (snake->config.display == SFML)
        return;
    timeout(10000);
    print_ncurses(snake);
    getch();
}

void print_lose(snake_t *snake)
{
    if (snake->config.display == SFML)
        return;
    timeout(10000);
    print_ncurses(snake);
    getch();
}

void destroy_display(snake_t *snake)
{
    if (snake->config.display == SFML) {
        sfRenderWindow_destroy(snake->sfml.window);
        return;
    }
    endwin();
}