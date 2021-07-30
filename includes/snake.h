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
    int display;
    int fps;
    int size;
    int booster;
    int arena;
    char *content;
    char *config_path;
    char **argv;
}snake_t;

void init_setup(snake_t *snake, char **argv);

int parse_config(snake_t *snake);

int show_help(void);

int parse_args(snake_t *snake);

#endif /* !SNAKE_H_ */