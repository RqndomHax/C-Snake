/*
** EPITECH PROJECT, 2021
** snake
** File description:
** sfml manager
*/

#include "../../includes/game.h"

// Graphical display with sfml
int init_sfml(snake_t *snake)
{
    sfVideoMode mode = {1920, 1080, 8};

    snake->sfml.window = sfRenderWindow_create(mode, "Snake by RqndomHax", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(snake->sfml.window, snake->config.fps);
    return (1);
}

void sfml_display(snake_t *snake)
{
    (void) snake;
}