/*
** EPITECH PROJECT, 2021
** snake
** File description:
** main
*/

#include "../includes/snake.h"

#include <stdio.h>

void show_stats(int has_won, snake_t *snake)
{
    if (!has_won)
        printf("\n\nYou have lost the game !\n");
    else
        printf("\n\nGreat job, you won !\n");
    printf("--------------------\n");
    printf("\n------ Stats -------\n");
    printf("\nsize ->\t\t%d\n", list_size(snake->snake));
    printf("\nmoves ->\t%d\n", snake->moves);
    printf("\n--- by RqndomHax ---\n");
    printf("--------------------\n");
}

int main(int argc, char **argv)
{
    snake_t snake;

    if (argc == 1)
        return (show_help());
    init_setup(&snake, argv);
    if (!parse_args(&snake))
        return (1);
    if (snake.config_path != NULL)
        init_config(&snake);
    if (!(init_game(&snake)))
        return (1);
    show_stats(run_game(&snake), &snake);
    list_destroy(&snake.snake);
    return (0);
}