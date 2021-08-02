/*
** EPITECH PROJECT, 2021
** snake
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

void free_array(char **array);

int read_file(char *filepath, char **content);

int my_isnum(char *);

char **my_str_to_word_array(char *str, char *dlm);

char **get_config(char *filepath);

int my_config_get_int(char **config, char *key);

char *my_config_get_string(char **config, char *key);

#endif /* !LIB_H_ */