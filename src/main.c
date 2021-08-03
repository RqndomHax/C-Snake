/*
** EPITECH PROJECT, 2021
** snake
** File description:
** main
*/

#include "../includes/game.h"

#include <stdio.h>

void show_stats(int has_won, snake_t *snake)
{
    if (snake->config.display == NCURSES) {
        timeout(10000);
        print_ncurses(snake);
        getch();
        endwin();
    }
    else {
        sfRenderWindow_destroy(snake->sfml.window);
    }
    if (!has_won)
        printf("\n\nYou have lost the game !\n");
    else
        printf("\n\nGreat job, you won !\n");
    printf("--------------------\n");
    printf("\n------ Stats -------\n");
    printf("\nsize ->\t\t%d\n", list_size(snake->tail));
    printf("\nmoves ->\t%d\n", snake->moves);
    printf("\n--- by RqndomHax ---\n");
    printf("--------------------\n");
}

int main(int argc, char **argv)
{
    snake_t snake;

    (void) argc;
    init_setup(&snake, argv);
    if (!parse_args(&snake))
        return (1);
    init_config(&snake);
    if (!(init_game(&snake)))
        return (1);
    if (!init_display(&snake)) {
        list_destroy(&snake.tail);
        return (1);
    }
    show_stats(run_game(&snake), &snake);
    list_destroy(&snake.tail);
    return (0);
}