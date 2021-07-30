/*
** EPITECH PROJECT, 2021
** lib
** File description:
** returns the content of a file
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int exit_file(int fd, char **content)
{
    close(fd);
    if (*content != NULL)
        free(*content);
    return (0);
}

int read_file(char *filepath, char **content)
{
    int fd = -1;
    struct stat sb;

    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (0);
    if (stat(filepath, &sb) || !S_ISREG(sb.st_mode))
        return (exit_file(fd, content));
    *content = malloc(sb.st_size + 1);
    if (!(*content) || read(fd, *content, sb.st_size) == -1)
        return (exit_file(fd, content));
    (*content)[sb.st_size] = 0;
    close(fd);
    return (1);
}