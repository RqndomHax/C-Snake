/*
** EPITECH PROJECT, 2021
** lib
** File description:
** return 0 if a string is not numeric else it returns 1
*/

static int is_num(char);

int my_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!is_num(str[i]))
            return (0);
    return (1);
}

static int is_num(char const c)
{
    if (c == '-' || c == '+')
        return (1);
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}
