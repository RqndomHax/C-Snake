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
    if (!has_won) {
        print_lose(snake);
        printf("\n\nYou have lost the game !\n");
    }
    else {
        print_win(snake);
        printf("\n\nGreat job, you won !\n");
    }
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
    init_game(&snake);
    if (!init_display(&snake))
        return (1);
    if (!init_snake(&snake)) {
        destroy_display(&snake);
        return (1);
    }
    show_stats(run_game(&snake), &snake);
    list_destroy(&snake.tail);
    destroy_display(&snake);
    return (0);
}