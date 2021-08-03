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
        return (init_sfml(snake->sfml));
    return (init_ncurses(snake));
}

void print_display(snake_t *snake)
{
    if (snake->config.display == SFML)
        return;
    return (print_ncurses(snake));
}