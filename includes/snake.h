/*
** EPITECH PROJECT, 2021
** snake
** File description:
** snake main header
*/

#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct snake_s
{
    int fps;
    int size;
    int booster;
    int arena;
    char *content;
    char *config_path;
    char **argv;
    int argc;
}snake_t;

int parse_config(snake_t *snake);

int parse_args(snake_t *snake);

#endif /* !SNAKE_H_ */