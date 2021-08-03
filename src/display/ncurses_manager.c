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
    return (1);
}

void ncurses_display(snake_t *snake)
{
    int c = getch();

    // Keyboard input management
    if (c == 65 && snake->head->direction != DOWN && snake->head->direction != UP)
        snake->head->direction = UP;
    if (c == 66 && snake->head->direction != UP && snake->head->direction != DOWN)
        snake->head->direction = DOWN;
    if (c == 67 && snake->head->direction != LEFT && snake->head->direction != RIGHT)
        snake->head->direction = RIGHT;
    if (c == 68 && snake->head->direction != RIGHT && snake->head->direction != LEFT)
        snake->head->direction = LEFT;

    // tickrate system with ncurses
    usleep(1000000/snake->config.tickrate);
}