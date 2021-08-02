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

enum display_e
{
    DEFAULT,
    NCURSES,
    SFML
};

typedef struct snake_s
{
    enum display_e display;
    int fps;
    int size;
    int booster;
    int arena;
    char **config;
    char *config_path;
    char **argv;
}snake_t;

void init_setup(snake_t *snake, char **argv);

void init_config(snake_t *snake);

int parse_config(snake_t *snake);

int show_help(void);

int parse_args(snake_t *snake);

#endif /* !SNAKE_H_ */