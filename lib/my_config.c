/*
** EPITECH PROJECT, 2021
** lib
** File description:
** basic config file
*/

#include <stdlib.h>

int read_file(char *filepath, char **content);

char **my_str_to_word_array(char *content, char *dlm);

int my_config_get_int(char *key)
{

}

char **get_config(char *filepath)
{
    char *content = NULL;
    char **config = NULL;

    if (!read_file(filepath, &content))
            return (NULL);
    config = my_str_to_word_array(content, "\n");
    free(content);
    if (config == NULL)
        return (NULL);
    return (config);
}