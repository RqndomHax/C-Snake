/*
** EPITECH PROJECT, 2021
** snake
** File description:
** main
*/

#include "../includes/snake.h"
#include "../includes/lib.h"

int main(int argc, char **argv)
{
    snake_t snake;

    snake.argv = argv;
    snake.argc = argc;
    snake.content = NULL;
    snake.config_path = NULL;
    if (!parse_args(&snake))
        return (1);
    if (!read_file(argv[1], &snake.content))
        return (1);
    return (0);
}