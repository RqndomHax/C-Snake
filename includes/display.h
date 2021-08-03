/*
** EPITECH PROJECT, 2021
** snake
** File description:
** display
*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <ncurses.h>

enum display_e
{
    DEFAULT,
    NCURSES,
    SFML
};

typedef struct sfml_s
{

}sfml_t;

int init_sfml(sfml_t *sfml);

#endif /* !DISPLAY_H_ */