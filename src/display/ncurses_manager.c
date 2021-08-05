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

    // Check if the arena is bigger than the terminal display
    if (snake->config.arena < COLS && snake->config.arena < LINES)
        return (1);

    // Set the arena to the size of the terminal -1 (include borders)
    if (COLS > LINES)
        snake->config.arena = LINES-1;
    else
        snake->config.arena = COLS-1;

    return (1);
}

// Keyboard management for ncurses
void ncurses_display(snake_t *snake)
{
    int c = getch();

    /* -- Directions -- */

    if (c == 27) {
        snake->is_running = 0;
        return;
    }

    // Snake up
    if (!snake->has_pressed && (c == KEY_UP && snake->head->direction != DOWN && snake->head->direction != UP)) {
        snake->has_pressed = 1;
        snake->head->direction = UP;
    }

    // Snake down
    if (!snake->has_pressed && (c == KEY_DOWN && snake->head->direction != UP && snake->head->direction != DOWN)) {
        snake->has_pressed = 1;
        snake->head->direction = DOWN;
    }

    // Snake right
    if (!snake->has_pressed && (c == KEY_RIGHT && snake->head->direction != LEFT && snake->head->direction != RIGHT)) {
        snake->has_pressed = 1;
        snake->head->direction = RIGHT;
    }

    // Snake left
    if (!snake->has_pressed && (c == KEY_LEFT && snake->head->direction != RIGHT && snake->head->direction != LEFT)) {
        snake->has_pressed = 1;
        snake->head->direction = LEFT;
    }

    // Recursive if a key is pressed to empty the key buffers while checking if it's a valid key
    if (c != ERR && !snake->has_pressed)
        return (ncurses_display(snake));
}