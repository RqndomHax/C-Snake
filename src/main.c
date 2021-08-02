/*
** EPITECH PROJECT, 2021
** snake
** File description:
** main
*/

#include "../includes/snake.h"
#include "../includes/lib.h"

#include <stdio.h>

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
    printf("fps = [%d]\n", snake.fps);
    printf("size = [%d]\n", snake.size);
    printf("booster = [%d]\n", snake.booster);
    printf("arena = [%d]\n", snake.arena);
    printf("display = [%d]\n", snake.display);
    return (0);
}