/*
** EPITECH PROJECT, 2021
** snake
** File description:
** config
*/

#ifndef CONFIG_H_
#define CONFIG_H_

typedef struct config_s
{
    enum display_e display;
    int fps;
    int tickrate;
    int speed;
    int size;
    int booster;
    int arena;
}config_t;

#endif /* !CONFIG_H_ */