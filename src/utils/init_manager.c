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
    config_priority(config, "fps", &snake->fps);
    config_priority(config, "size", &snake->size);
    config_priority(config, "booster", &snake->booster);
    config_priority(config, "arena", &snake->arena);
    if (snake->display == DEFAULT) {
        tmp = my_config_get_string(config, "display");
        if (tmp != NULL) {
            if (strcmp(tmp, "sfml") == 0)
                snake->display = SFML;
            free(tmp);
        }
    }
    free_array(config);
}