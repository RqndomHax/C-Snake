/*
** EPITECH PROJECT, 2021
** snake
** File description:
** ncurses print
*/

#include "../../includes/game.h"

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

void print_ncurses(snake_t *snake)
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

void print_debug(void)
{
    clear();
    addch('h');
    addch('e');
    addch('y');
    refresh();
}