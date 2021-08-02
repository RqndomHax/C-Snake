/*
** EPITECH PROJECT, 2021
** lib
** File description:
** basic config file
*/

#include <stdlib.h>
#include <string.h>

int read_file(char *filepath, char **content);

char **my_str_to_word_array(char *content, char *dlm);

static int get_keysize(char *key)
{
    int size = 0;

    for (; key[size] && key[size] != ':'; size++);
    return (size);
}

static int get_line(char **config, char *key, int *key_index)
{
    int line = -1;
    int tmp_size = strlen(key);

    for (int i = 0; config[i] && line == -1; i++) {
        *key_index = get_keysize(config[i]);
        if (tmp_size != *key_index)
            continue;
        if (strncmp(config[i], key, *key_index) == 0) {
            line = i;
            (*key_index)++;
            for (; config[i][(*key_index)] == ' ' && config[i][(*key_index)++];);
        }
    }
    return (line);
}

void parse_value(char *old, char **old_ptr)
{
    for(; **old_ptr && **old_ptr != '#' && **old_ptr != ' '; (*old_ptr)++, *old = **old_ptr);
}

int my_config_get_int(char **config, char *key)
{
    int key_index = -1;
    int value = 0;
    char old;
    char *old_ptr;

    int line = get_line(config, key, &key_index);
    if (line == -1)
        return (0);
    old_ptr = &config[line][key_index];
    parse_value(&old, &old_ptr);
    *old_ptr = 0;
    value = atoi(&config[line][key_index]);
    *old_ptr = old;
    return (value);
}

char *my_config_get_string(char **config, char *key)
{
    int key_index = -1;
    char *value = NULL;
    char old;
    char *old_ptr;

    int line = get_line(config, key, &key_index);
    if (line == -1)
        return (0);
    old_ptr = &config[line][key_index];
    parse_value(&old, &old_ptr);
    *old_ptr = 0;
    value = strdup(&config[line][key_index]);
    *old_ptr = old;
    return (value);
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