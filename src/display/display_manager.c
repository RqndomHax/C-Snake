/*
** EPITECH PROJECT, 2021
** snake
** File description:
** display manager
*/

#include <unistd.h>
#include "../../includes/snake.h"

static int init_sfml(sfml_t *sfml)
{
    (void) sfml;
    return (0);
}

static int init_ncurses(snake_t *snake)
{
    initscr();
    cbreak();
    timeout(0);
    curs_set(0);
    noecho();
    (void) snake;
    return (1);
}

void manage_game(snake_t *snake)
{
    int c = 0;

    if (snake->config.display == SFML)
        return;
    c = getch();
    if (c == 65 && snake->head->direction != DOWN && snake->head->direction != UP)
        snake->head->direction = UP;
    if (c == 66 && snake->head->direction != UP && snake->head->direction != DOWN)
        snake->head->direction = DOWN;
    if (c == 67 && snake->head->direction != LEFT && snake->head->direction != RIGHT)
        snake->head->direction = RIGHT;
    if (c == 68 && snake->head->direction != RIGHT && snake->head->direction != LEFT)
        snake->head->direction = LEFT;
    usleep(1000000/snake->config.tickrate);
}

void print_ncurse(snake_t *snake)
{
    list_t *tail = snake->tail;

    clear();

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

int init_display(snake_t *snake)
{
    if (snake->config.display == SFML)
        return (init_sfml(snake->sfml));
    return (init_ncurses(snake));
}