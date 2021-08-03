/*
** EPITECH PROJECT, 2021
** snake
** File description:
** better functions utils
*/

#include "../../includes/lib.h"

// Used to let the command args overwrite the config
void config_priority(char **config, char *key, int *target)
{
    if (*target == -1)
        *target = my_config_get_int(config, key);
}

// Used to set a default value if nothing is passed in commands or config
void set_default_value(int *target, int value)
{
    if (*target == -1)
        *target = value;
}