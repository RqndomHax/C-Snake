/*
** EPITECH PROJECT, 2021
** snake
** File description:
** ncurses manager
*/

#include "../../includes/snake.h"
#include <unistd.h>

// Terminal display with ncurses
int init_ncurses(snake_t *snake)
{
    (void) snake;
    initscr();
    cbreak();
    timeout(0);
    curs_set(0);
    noecho();
    return (1);
}

static void print_borders(snake_t *snake)
{
    for (int y = 0; y <= snake->config.arena; y++) {
        for (int x = 0; x <= snake->config.arena; x++) {
            move(y, x);
            if ((x == 0 || x == snake->config.arena)) {
                addch('|');
                continue;
            }
            if (y == 0 || y == snake->config.arena) {
                addch('-');
                continue;
            }
            addch('.');
        }
    }
}

void print_ncurse(snake_t *snake)
{
    list_t *tail = snake->tail;

    clear();

    print_borders(snake);
    while (tail->next != NULL) {
        move(tail->y, tail->x);
        addch('+');
        tail = tail->next;
    }

    move(snake->booster_y, snake->booster_x);
    addch('%');
    move(snake->head->y, snake->head->x);
    if (!snake->is_running)
        addch('$');
    else
        addch('?');
    refresh();
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