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
    scale_sprite(snake->config.arena, &snake->sfml.corpse, &snake->sfml.corpset, "assets/corpse.png");
    scale_sprite(snake->config.arena, &snake->sfml.booster, &snake->sfml.boostert, "assets/booster.png");
    scale_sprite(snake->config.arena, &snake->sfml.wall, &snake->sfml.wallt, "assets/wall.png");
    snake->sfml.clock = sfClock_create();
    return (1);
}

void print_sfml(snake_t *snake)
{
    list_t *tail = snake->tail;
    double tmp;

    sfRenderWindow_clear(snake->sfml.window, sfBlack);
    tmp = sprite_get_scale(snake->config.arena, 800, sfTexture_getSize(snake->sfml.wallt).x);
    for (int y = 0; y <= snake->config.arena; y++) {
        for (int x = 0; x <= snake->config.arena; x++) {
            sfSprite_setPosition(snake->sfml.wall, (sfVector2f) {(x * sfTexture_getSize(snake->sfml.wallt).x)/tmp, (y * sfTexture_getSize(snake->sfml.wallt).y)/tmp});
            if ((x == 0 || x == snake->config.arena)) {
                sfRenderWindow_drawSprite(snake->sfml.window, snake->sfml.wall, NULL);
                continue;
            }
            if (y == 0 || y == snake->config.arena) {
                sfRenderWindow_drawSprite(snake->sfml.window, snake->sfml.wall, NULL);
                continue;
            }
        }
    }
    tmp = sprite_get_scale(snake->config.arena, 800, sfTexture_getSize(snake->sfml.tailt).x);
    sfSprite_setPosition(snake->sfml.tail, (sfVector2f) {(tail->x * sfTexture_getSize(snake->sfml.tailt).x)/tmp, (tail->y * sfTexture_getSize(snake->sfml.tailt).y)/tmp});
    sfRenderWindow_drawSprite(snake->sfml.window, snake->sfml.tail, NULL);
    tail = tail->next;
    tmp = sprite_get_scale(snake->config.arena, 800, sfTexture_getSize(snake->sfml.corpset).x);
    while (tail != NULL && tail->next != NULL && tail->next->next != NULL) {
        sfSprite_setPosition(snake->sfml.corpse, (sfVector2f) {(tail->x * sfTexture_getSize(snake->sfml.corpset).x)/tmp, (tail->y * sfTexture_getSize(snake->sfml.corpset).y)/tmp});
        sfRenderWindow_drawSprite(snake->sfml.window, snake->sfml.corpse, NULL);
        tail = tail->next;
    }
    sfSprite_setPosition(snake->sfml.head, (sfVector2f) {(tail->x * sfTexture_getSize(snake->sfml.headt).x)/tmp, (tail->y * sfTexture_getSize(snake->sfml.headt).y)/tmp});
    sfRenderWindow_drawSprite(snake->sfml.window, snake->sfml.head, NULL);
    tmp = sprite_get_scale(snake->config.arena, 800, sfTexture_getSize(snake->sfml.boostert).x);
    sfSprite_setPosition(snake->sfml.booster, (sfVector2f) {(snake->booster_x * sfTexture_getSize(snake->sfml.boostert).x)/tmp, (snake->booster_y * sfTexture_getSize(snake->sfml.boostert).y)/tmp});
    sfRenderWindow_drawSprite(snake->sfml.window, snake->sfml.booster, NULL);
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
}