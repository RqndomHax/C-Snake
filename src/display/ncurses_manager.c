/*
** EPITECH PROJECT, 2021
** snake
** File description:
** ncurses manager
*/

#include "../../includes/game.h"
#include <unistd.h>

// Terminal display with ncurses
int init_ncurses()
{
    initscr();
    cbreak();
    timeout(0);
    curs_set(0);
    noecho();
    keypad(stdscr, true);
    return (1);
}

void ncurses_display(snake_t *snake)
{
    int c = getch();

    // Keyboard input management
    if (!snake->has_pressed && (c == KEY_UP && snake->head->direction != DOWN && snake->head->direction != UP)) {
        snake->has_pressed = 1;
        snake->head->direction = UP;
    }
    if (!snake->has_pressed && (c == KEY_DOWN && snake->head->direction != UP && snake->head->direction != DOWN)) {
        snake->has_pressed = 1;
        snake->head->direction = DOWN;
    }
    if (!snake->has_pressed && (c == KEY_RIGHT && snake->head->direction != LEFT && snake->head->direction != RIGHT)) {
        snake->has_pressed = 1;
        snake->head->direction = RIGHT;
    }
    if (!snake->has_pressed && (c == KEY_LEFT && snake->head->direction != RIGHT && snake->head->direction != LEFT)) {
        snake->has_pressed = 1;
        snake->head->direction = LEFT;
    }

    // tickrate system with ncurses
    usleep(1000000/snake->config.tickrate);
}