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
        snake.config = get_config(snake.config_path);
        if (snake.config != NULL) {
            for (int i = 0; snake.config[i]; printf("[%s]\n", snake.config[i++]));
            free_array(snake.config);
        }
    }
    return (0);
}