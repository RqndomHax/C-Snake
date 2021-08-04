/*
** EPITECH PROJECT, 2021
** lib
** File description:
** create sprite
*/

#include <SFML/Graphics.h>

void generate_sprite(sfSprite **sprite, sfTexture *texture)
{
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, sfTrue);
}