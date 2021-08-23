/*
** EPITECH PROJECT, 2021
** snake
** File description:
** snake structure
*/

#ifndef SNAKE_H_
#define SNAKE_H_

#include "list.h"
#include "config.h"
#include "display.h"

typedef struct snake_s
{
    char **argv;
    char *config_path;
    struct config_s config;
    int moves;
    int is_running;
    list_t *head;
    list_t *tail;
    int booster_x;
    int booster_y;
    int has_pressed;
    clock_t start;
    sfml_t sfml;
}snake_t;

#endif /* !SNAKE_H_ */