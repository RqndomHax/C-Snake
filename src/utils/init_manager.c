/*
** EPITECH PROJECT, 2021
** snake
** File description:
** init manager
*/

#include <stdlib.h>
#include "../../includes/snake.h"

void init_setup(snake_t *snake, char **argv)
{
    snake->display = -1;
    snake->fps = -1;
    snake->size = -1;
    snake->booster = -1;
    snake->arena = -1;
    snake->content = NULL;
    snake->config_path = NULL;
    snake->argv = argv;
}