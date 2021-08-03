/*
** EPITECH PROJECT, 2021
** snake
** File description:
** snake main header
*/

#ifndef GAME_H_
#define GAME_H_

#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "lib.h"
#include "display.h"
#include "config.h"
#include "snake.h"

/* --- SETUP --- */
void init_setup(snake_t *snake, char **argv);
int parse_args(snake_t *snake);
int show_help(void);

/* --- CONFIG --- */
void init_config(snake_t *snake);
int parse_config(snake_t *snake);

/* --- GAME --- */
int init_game(snake_t *snake);
int run_game(snake_t *snake);
int auto_move(snake_t *snake);
int move_snake(snake_t *snake);
void manage_game(snake_t *snake);
void update_coordinates(list_t *snake);

/* --- DISPLAY --- */
int init_display(snake_t *snake);
int init_ncurses(snake_t *ncurses);
void print_ncurses(snake_t *snake);
void sfml_display(snake_t *snake);
void ncurses_display(snake_t *snake);
void print_display(snake_t *snake);

/* --- UTILS --- */
void config_priority(char **config, char *key, int *target);
void set_default_value(int *target, int value);

#endif /* !GAME_H_ */