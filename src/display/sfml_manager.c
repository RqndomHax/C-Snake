/*
** EPITECH PROJECT, 2021
** snake
** File description:
** sfml manager
*/

#include "../../includes/game.h"

static double sprite_get_scale(int arena, double screen, double size)
{
    return ((arena / screen) * size);
}

static void scale_sprite(int arena, sfSprite **sprite, sfTexture **texture, char *path)
{
    double tmp;

    *texture = sfTexture_createFromFile(path, NULL);
    generate_sprite(sprite, *texture);
    tmp = sprite_get_scale(arena, 800, sfTexture_getSize(*texture).x);
    sfSprite_setScale(*sprite, (sfVector2f) {1 / tmp, 1 / tmp});
}

// Graphical display with sfml
int init_sfml(snake_t *snake)
{
    sfVideoMode mode = {1920, 1080, 8};

    snake->sfml.window = sfRenderWindow_create(mode, "Snake by RqndomHax", sfResize | sfClose, NULL);
    if (snake->sfml.window == NULL)
        return (0);
    sfRenderWindow_setFramerateLimit(snake->sfml.window, snake->config.fps);
    snake->sfml.icon = sfImage_createFromFile("assets/icon.png");
    if (snake->sfml.icon == NULL)
        return (0);
    sfRenderWindow_setIcon(snake->sfml.window, 16, 16, sfImage_getPixelsPtr(snake->sfml.icon));
    sfRenderWindow_setMouseCursorVisible(snake->sfml.window, sfFalse);
    scale_sprite(snake->config.arena, &snake->sfml.head, &snake->sfml.headt, "assets/head.png");
    scale_sprite(snake->config.arena, &snake->sfml.tail, &snake->sfml.tailt, "assets/tail.png");
    return (1);
}

void print_sfml(snake_t *snake)
{
    list_t *tail = snake->tail;
    double tmp;

    sfRenderWindow_clear(snake->sfml.window, sfBlack);
    tmp = sprite_get_scale(snake->config.arena, 800, sfTexture_getSize(snake->sfml.tailt).x);
    while (tail->next != NULL) {
        sfSprite_setPosition(snake->sfml.tail, (sfVector2f) {(tail->x * sfTexture_getSize(snake->sfml.tailt).x)/tmp, (tail->y * sfTexture_getSize(snake->sfml.tailt).y)/tmp});
        sfRenderWindow_drawSprite(snake->sfml.window, snake->sfml.tail, NULL);
        tail = tail->next;
    }
    sfSprite_setPosition(snake->sfml.head, (sfVector2f) {(tail->x * sfTexture_getSize(snake->sfml.headt).x)/tmp, (tail->y * sfTexture_getSize(snake->sfml.headt).y)/tmp});
    sfRenderWindow_drawSprite(snake->sfml.window, snake->sfml.head, NULL);
    sfRenderWindow_display(snake->sfml.window);
}

void sfml_display(snake_t *snake)
{
    sfEvent event;

    if (!sfRenderWindow_isOpen(snake->sfml.window)) {
        snake->is_running = 0;
        return;
    }
    while (sfRenderWindow_pollEvent(snake->sfml.window, &event)) {
        if ((event.type == sfEvtClosed) || (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(snake->sfml.window);
            snake->is_running = 0;
            return;
        }
        if (!snake->has_pressed && (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) && snake->head->direction != UP && snake->head->direction != DOWN) {
            snake->head->direction = UP;
            snake->has_pressed = 1;
        }
        if (!snake->has_pressed && (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) && snake->head->direction != DOWN && snake->head->direction != UP) {
            snake->head->direction = DOWN;
            snake->has_pressed = 1;
        }
        if (!snake->has_pressed && (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) && snake->head->direction != LEFT && snake->head->direction != RIGHT) {
            snake->head->direction = LEFT;
            snake->has_pressed = 1;
        }
        if (!snake->has_pressed && (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) && snake->head->direction != RIGHT && snake->head->direction != LEFT) {
            snake->head->direction = RIGHT;
            snake->has_pressed = 1;
        }
    }
    // tickrate system with sfml
    usleep(1000000/snake->config.tickrate);
    (void) snake;
}