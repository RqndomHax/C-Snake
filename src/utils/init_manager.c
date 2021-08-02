/*
** EPITECH PROJECT, 2021
** snake
** File description:
** init manager
*/

#include <stdlib.h>
#include <string.h>
#include "../../includes/snake.h"

void init_setup(snake_t *snake, char **argv)
{
    snake->config.display = NCURSES;
    snake->config.fps = -1;
    snake->config.tickrate = -1;
    snake->config.speed = -1;
    snake->config.size = -1;
    snake->config.booster = -1;
    snake->config.arena = -1;
    snake->config_path = NULL;
    snake->argv = argv;
    snake->moves = 0;
}

static void config_priority(char **config, char *key, int *target)
{
    if (*target == -1)
        *target = my_config_get_int(config, key);
}

void init_config(snake_t *snake)
{
    char **config = NULL;
    char *tmp = NULL;

    config = get_config(snake->config_path);
    if (config == NULL)
        return;
    for (int i = 0; config[i]; printf("[%s]\n", config[i++]));
    config_priority(config, "fps", &snake->config.fps);
    config_priority(config, "tickrate", &snake->config.tickrate);
    config_priority(config, "speed", &snake->config.speed);
    config_priority(config, "size", &snake->config.size);
    config_priority(config, "booster", &snake->config.booster);
    config_priority(config, "arena", &snake->config.arena);
    if (snake->config.display == DEFAULT) {
        tmp = my_config_get_string(config, "display");
        if (tmp != NULL) {
            if (strcmp(tmp, "sfml") == 0)
                snake->config.display = SFML;
            free(tmp);
        }
    }
    free_array(config);
}