/*
** EPITECH PROJECT, 2021
** snake
** File description:
** help
*/

#include <stdio.h>
#include <string.h>
#include "../../includes/game.h"

int show_help(void)
{
    printf("%s",
        "Snake game made in C\n"
        "Author: RqndomHax (https://github.com/RqndomHax)\n"

        "\n[Config File]\n"
        "  fps:         60 # This is the fps cap\n"
        "  tickrate:    12 # This is the tick rate of the game, tickrate: 12 means 12 ticks per second\n"
        "  speed:       1 # The amount of tick it takes to move the snake"
        "  size:        4 # This is the default snake size\n"
        "  booster:     1 # This is the size gained by the snake when it eats\n"
        "  arena:       20 # This is the size of the arena (20 = 20x20)\n"
        "  display:     ncurses # This is the type of display of the game (ncurses / sfml))\n"
        "  does_tp:     1 # If set to 1 the snake is tped to the other side of the map when going through a wall, else (0) it dies."
        "  force_move:  1 # If set to 1 when a movement key is pressed the snake will move next turn."
    
        "\n[Commands]\n"
        "  --fps        n   # sets the fps cap\n"
        "  --tickrate   n   # sets the game's tickrate\n"
        "  --speed      n   # sets the amount of ticks it takes to move the snake\n"
        "  --size       n   # sets the snake's size\n"
        "  --booster    n   # sets the size multiplier\n"
        "  --arena      n   # sets the arena's size\n"
        "  --ncurses        # sets the display's type to ncurse\n"
        "  --sfml           # sets the display's type to sfml\n"
        "  --does_tp    n   # if set to 1 the snake is tped to the other side of the map when going through a wall, else (0) it dies."        
        "  --force_move n   # if set to 1 when a movement key is pressed the snake will move next turn."

        "\nCommands overwrite the parameters of the config !\n");
    return (0);
}

static int replace_value(char **value, int *target)
{
    if (!(*value))
        return (-1);
    if (!my_isnum(*value)) {
        fprintf(stderr, "Value of '%s' is not numeric !\n", *(value - 1));
        return (-2);
    }
    *target = atoi((*value));
    if (*target <= 0) {
        fprintf(stderr, "Value of '%s' must be greater than 0.\n", *(value - 1));
        return (-2);
    }
    return (1);
}

int is_command(snake_t *snake, int *index)
{
    if (strcmp(snake->argv[(*index)], "--fps") == 0)
        return (replace_value(&snake->argv[++(*index)], &snake->config.fps));
    if (strcmp(snake->argv[(*index)], "--tickrate") == 0)
        return (replace_value(&snake->argv[++(*index)], &snake->config.tickrate));
    if (strcmp(snake->argv[(*index)], "--speed") == 0)
        return (replace_value(&snake->argv[++(*index)], &snake->config.speed));
    if (strcmp(snake->argv[(*index)], "--size") == 0)
        return (replace_value(&snake->argv[++(*index)], &snake->config.size));
    if (strcmp(snake->argv[(*index)], "--booster") == 0)
        return (replace_value(&snake->argv[++(*index)], &snake->config.booster));
    if (strcmp(snake->argv[(*index)], "--arena") == 0)
        return (replace_value(&snake->argv[++(*index)], &snake->config.arena));
    if (strcmp(snake->argv[(*index)], "--does_tp") == 0)
        return (replace_value(&snake->argv[++(*index)], &snake->config.does_tp));
    if (strcmp(snake->argv[(*index)], "--force_move") == 0)
        return (replace_value(&snake->argv[++(*index)], &snake->config.force_move));
    if (strcmp(snake->argv[(*index)], "--ncurses") == 0) {
        snake->config.display = NCURSES;
        return (1);
    }
    if (strcmp(snake->argv[(*index)], "--sfml") == 0) {
        snake->config.display = SFML;
        return (1);
    }
    if (strncmp("--", snake->argv[(*index)], 2) == 0) {
        fprintf(stderr, "Invalid command '%s' !\n", snake->argv[(*index)]);
        return (-2);
    }
    return (0);
}

int parse_args(snake_t *snake)
{
    int result = 0;

    for (int i = 1; snake->argv[i]; i++)
        if (strcmp(snake->argv[i], "--help") == 0)
            return (show_help());
    for (int i = 1; snake->argv[i]; i++) {
        result = is_command(snake, &i);
        if (result == 0) {
            if (snake->config_path != NULL) {
                fprintf(stderr, "Too many config files argument !\n");
                return (0);
            }
            snake->config_path = snake->argv[i];
        }
        if (result == -1 || result == -2) {
            if (result == -1)
                fprintf(stderr, "Missing argument !\n");
            return (0);
        }
    }
    if (snake->config_path == NULL)
        snake->config_path = "snake.cfg";
    return (1);
}