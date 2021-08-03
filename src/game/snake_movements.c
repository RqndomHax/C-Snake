/*
** EPITECH PROJECT, 2021
** snake
** File description:
** game movements
*/

#include "../../includes/game.h"

// Creates a new booster
static int new_booster(snake_t *snake)
{
    list_t *tail = snake->tail;
    int x = (rand() % snake->config.arena-1) + 1;
    int y = (rand() % snake->config.arena-1) + 1;

    while (tail != NULL) {
        if (tail->x == x && tail->y == y)
            return (new_booster(snake));
        tail = tail->next;
    }
    snake->booster_x = x;
    snake->booster_y = y;
    return (1);
}

// Checks if the snake is on a booster
static int check_boosters(snake_t *snake)
{
    if (snake->booster_x == -1 || snake->booster_y == -1)
        return (new_booster(snake));
    if (snake->head->x == snake->booster_x && snake->head->y == snake->booster_y) {
            for (int i = 0; i < snake->config.booster; i++)
                snake->head = list_add(&snake->head, snake->head->x, snake->head->y);
            return (new_booster(snake));
        }
    return (1);
}

// Checks if the snake is touching its tail
static int check_tail(snake_t *snake)
{
    list_t *tail = snake->tail;

    while (tail->next != NULL) {
        if (snake->head->x == tail->x && snake->head->y == tail->y)
            return (0);
        tail = tail->next;
    }
    return (1);
}

// Update the snake's coordinates
void update_coordinates(list_t *snake)
{
    switch (snake->direction) {
        case UP:
            snake->y--;
            break;
        case DOWN:
            snake->y++;
            break;
        case LEFT:
            snake->x--;
            break;
        case RIGHT:
            snake->x++;
            break;
    }
}

int auto_move(snake_t *snake)
{
    update_coordinates(snake->head);
    // Check if snake's head is touching an arena border
    if (snake->head->x == snake->config.arena || snake->head->y == snake->config.arena)
        return (0);
    if (snake->head->x == 0 || snake->head->y == 0)
        return (0);
    if (!check_tail(snake))
        return (0);
    if (!check_boosters(snake))
        return (0);
    return (2);
}