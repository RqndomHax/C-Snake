/*
** EPITECH PROJECT, 2021
** snake
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

int read_file(char *filepath, char **content);

int my_isnum(char *);

char **my_str_to_word_array(char *str, char *dlm);

#endif /* !LIB_H_ */