/*
** EPITECH PROJECT, 2021
** snake
** File description:
** help
*/

#include "includes/snake.h"

int parse_args(int argc, char **argv)
{
    if (argc > 2) {
        fprintf(stderr, "Too many arguments.");
        return (0);
    }
}