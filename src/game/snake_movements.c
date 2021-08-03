/*
** EPITECH PROJECT, 2021
** snake
** File description:
** game movements
*/

#include "../../includes/snake.h"

// Creates a new booster
static int new_booster(snake_t *snake)
{
    list_t *tmp = snake->snake;
    int x = (rand() % snake->config.arena-1) + 1;
    int y = (rand() % snake->config.arena-1) + 1;

    while (tmp != NULL) {
        if (tmp->x == x && tmp->y == y)
            return (new_booster(snake));
        tmp = tmp->next;
    }
    snake->booster_x = x;
    snake->booster_y = y;
    printf("new booster at x = %d | y = %d\n", x, y);
    return (1);
}

// Checks if the snake is on a booster
static int check_boosters(snake_t *snake)
{
    if (snake->booster_x == -1 || snake->booster_y == -1)
        return (new_booster(snake));
    if (snake->snake->x == snake->booster_x && snake->snake->y == snake->booster_y) {
            for (int i = 0; i < snake->config.booster; i++)
                list_add(&snake->snake, snake->snake->x, snake->snake->y);
            return (new_booster(snake));
        }
    return (1);
}

// Checks if the snake is touching its tail
static int check_tail(snake_t *snake)
{
    list_t *tail = snake->snake->next;

    while (tail != NULL) {
        if (snake->snake->x == tail->x && snake->snake->x == tail->y)
            return (0);
        tail = tail->next;
    }
    return (1);
}

// Update the snake's coordinates
static void update_coordinates(snake_t *snake)
{
    switch (snake->direction) {
        case UP:
            snake->snake->y--;
            break;
        case DOWN:
            snake->snake->y++;
            break;
        case LEFT:
            snake->snake->x--;
            break;
        case RIGHT:
            snake->snake->x++;
            break;
    }
}

int auto_move(snake_t *snake)
{
    update_coordinates(snake);
    // Check if snake's head is touching an arena border
    if (snake->snake->x == snake->config.arena || snake->snake->y == snake->config.arena)
        return (0);
    if (snake->snake->x == 0 || snake->snake->y == 0)
        return (0);
    if (!check_tail(snake))
        return (0);
    if (!check_boosters(snake))
        return (1);
    return (2);
}