#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int ft_strncmp(char *line, char *target, size_t n)
{
    for(size_t i = 0; i < n && (line[i] || target[i]); i++)
    {
        if (line[i] != target[i])
            return ((unsigned char)line[i] - (unsigned char)target[i]);
    }
    return (0);
}

void filter(char *line, char *target)
{
    size_t i;
    size_t len;

    i = 0;
    len = strlen(target);
    while (line[i])
    {
        if (ft_strncmp(&line[i], target, len) == 0)
        {
            for (size_t j = 0; j < len; j++)
                write(1, "*", 1);
            i += len;
        }
        else
        {
            write(1, &line[i], 1);
            i++;
        }
    }
}

char *ft_strncat(char *dest, char *src, size_t n)
{
    size_t i;
    size_t len;

    i = 0;
    len = strlen(dest);
    while (i < n && src[i])
    {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
char *gnl(int fd)
{
    char *line;
    char *buffer;
    size_t len;
    size_t read_bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = (char *)malloc(100000);
    if (!line)
        return (NULL);
    line[0] = '\0';
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (free(line), NULL);
    read_bytes = 0;
    len = 0;
    while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (read_bytes < 0)
        {
            free(line);
            free(buffer);
        }
        buffer[read_bytes] = '\0';
        ft_strncat(line, buffer, read_bytes);
        len += read_bytes;
        if (line[len - 1] == '\n')
            break ;
    }
    free(buffer);
    if (len == 0)
        return (free(line), NULL);
    return (line);
}

int main(int ac, char **av)
{
    char *line;

    if (ac != 2)
        return (1);
    while ((line = gnl(0)))
    {
        filter(line, av[1]);
        free(line);
    }
    return (0);
}