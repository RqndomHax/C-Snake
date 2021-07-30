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

    if (argc == 1)
        return (show_help());
    init_setup(&snake, argv);
    if (!parse_args(&snake))
        return (1);
    if (snake.config_path != NULL) {
        if (!read_file(argv[1], &snake.content))
            return (1);
        printf("[%s]\n", snake.content);
        free(snake.content);
    }
    return (0);
}