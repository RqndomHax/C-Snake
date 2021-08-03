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

#include "list.h"
#include "lib.h"
#include "display.h"

typedef struct config_s
{
    enum display_e display;
    int fps;
    int tickrate;
    int speed;
    int size;
    int booster;
    int arena;
}config_t;

typedef struct snake_s
{
    char **argv;
    char *config_path;
    config_t config;
    int moves;
    int is_running;
    list_t *head;
    list_t *tail;
    int booster_x;
    int booster_y;
    sfml_t *sfml;
}snake_t;

/* --- SETUP --- */
void init_setup(snake_t *snake, char **argv);
void init_config(snake_t *snake);
int parse_config(snake_t *snake);
int parse_args(snake_t *snake);
int show_help(void);

/* --- GAME --- */
int init_game(snake_t *snake);
int run_game(snake_t *snake);
int auto_move(snake_t *snake);
int move_snake(snake_t *snake);
void manage_game(snake_t *snake);
void update_coordinates(list_t *snake);

/* --- DISPLAY --- */
int init_display(snake_t *snake);
int init_sfml(sfml_t *sfml);
int init_ncurses(snake_t *ncurses);
void print_ncurse(snake_t *snake);
void sfml_display(snake_t *snake);
void ncurses_display(snake_t *snake);

/* --- UTILS --- */
void config_priority(char **config, char *key, int *target);
void set_default_value(int *target, int value);

#endif /* !SNAKE_H_ */