/*
** EPITECH PROJECT, 2021
** snake
** File description:
** init manager
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../includes/game.h"

void init_setup(snake_t *snake, char **argv)
{
    time_t t;

    snake->sfml = NULL;
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
    snake->booster_x = -1;
    snake->booster_y = -1;

    // initialize the random number generator used to generate boosters
    srand((unsigned) time(&t));
}

void init_config(snake_t *snake)
{
    char **config = NULL;
    char *tmp = NULL;

    config = get_config(snake->config_path);
    if (config == NULL)
        return;
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

int init_game(snake_t *snake)
{
    snake->tail = NULL;
    snake->is_running = 1;
    set_default_value(&snake->config.fps, 60);
    set_default_value(&snake->config.tickrate, 10);
    set_default_value(&snake->config.speed, 2);
    set_default_value(&snake->config.size, 4);
    set_default_value(&snake->config.booster, 1);
    set_default_value(&snake->config.arena, 20);
    snake->head = list_add(&snake->tail, snake->config.arena/2, snake->config.arena/2);
    if (!snake->head)
        return (0);
    for (int i = 0; i < snake->config.size; i++) {
        snake->head->direction = RIGHT;
        snake->head = list_add(&snake->tail, snake->config.arena/2, snake->config.arena/2);
        if (!snake->head) {
            list_destroy(&snake->tail);
            return (0);
        }
    }
    return (1);
}

// Graphical display with sfml
int init_sfml(sfml_t *sfml)
{
    (void) sfml;
    return (0);
}