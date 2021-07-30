/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** returns word array from char array
*/

#include <stdlib.h>

typedef struct word_array_s
{
    char *str;
    char **result;
}word_array_t;

static int compare_str(word_array_t info, int index);

static int get_word_array_size(word_array_t info);

static int translate_to_word(word_array_t *info, int re, int *index);

char **my_str_to_word_array(char *str)
{
    word_array_t info;
    int index = 0;
    int total_size = 0;

    info.str = str;
    total_size = get_word_array_size(info);
    info.result = malloc(sizeof(char * ) * (total_size + 1));
    for (int i = 0 ; i <= total_size ; info.result[i++] = NULL);
    for (int i = 0 ; i < total_size ; )
        if (translate_to_word(&info, i, &index))
            i++;
    return (info.result);
}

static int compare_str(word_array_t info, int index)
{
    if (info.str[index] != '\n')
        return (0);
    return (1);
}

static int get_word_array_size(word_array_t info)
{
    int size = 1;

    for (int i = 0; info.str[i]; i++)
        if (compare_str(info, i))
            size++;
    return (size);
}

static int translate_to_word(word_array_t *info, int re, int *index)
{
    int size = 0;
    char **r = info->result;
    char *str = info->str;

    for (int i = *index ; !compare_str(*info, i) && str[i] ; i++, size++);
    if (str[*index] == 0)
        return (1);
    r[re] = malloc(size + 1);
    for (int i = 0 ; i < size ; r[re][i] = 0, i++);
    for (int i = 0 ; i < size ; r[re][i] = str[*index], i++, *index += 1);
    if (str[*index] != '\0')
        *index += 1;
    r[re][size] = '\0';
    return (1);
}