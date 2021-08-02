/*
** EPITECH PROJECT, 2021
** snake
** File description:
** init manager
*/

#include <stdlib.h>
#include <string.h>
#include "../../includes/snake.h"
#include "../../includes/lib.h"

void init_setup(snake_t *snake, char **argv)
{
    snake->display = NCURSES;
    snake->fps = -1;
    snake->size = -1;
    snake->booster = -1;
    snake->arena = -1;
    snake->config_path = NULL;
    snake->argv = argv;
}

void init_config(snake_t *snake)
{
    char **config = NULL;
    char *tmp = NULL;

    config = get_config(snake->config_path);
    if (config == NULL)
        return;
    for (int i = 0; config[i]; printf("[%s]\n", config[i++]));
    snake->fps = my_config_get_int(config, "fps");
    snake->size = my_config_get_int(config, "size");
    snake->booster = my_config_get_int(config, "booster");
    snake->arena = my_config_get_int(config, "arena");
    tmp = my_config_get_string(config, "display");
    if (tmp != NULL) {
        if (strcmp(tmp, "sfml") == 0)
            snake->display = SFML;
        else
            snake->display = NCURSES;
        free(tmp);
    }
    free_array(config);
}