/*
** EPITECH PROJECT, 2021
** snake
** File description:
** ncurses manager
*/

#include "../../includes/game.h"
#include <unistd.h>

// Terminal display with ncurses
int init_ncurses(snake_t *snake)
{
    initscr();
    cbreak();
    timeout(0);
    curs_set(0);
    noecho();
    keypad(stdscr, true);
    if (snake->config.arena < COLS && snake->config.arena < LINES)
        return (1);
    if (COLS > LINES)
        snake->config.arena = LINES-1;
    else
        snake->config.arena = COLS-1;
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
    if (c != ERR && !snake->has_pressed)
        return (ncurses_display(snake));

    // tickrate system with ncurses
    if (!snake->has_pressed)
        usleep(1000000/snake->config.tickrate);
}