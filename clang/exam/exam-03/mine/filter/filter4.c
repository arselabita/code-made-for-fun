#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int ft_strncmp(char *s1, char *s2, size_t n)
{
    for (size_t i = 0; i < n && (s1[i] || s2[i]); i++)
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    }
    return (0);
}

void filter(char *line, char *target)
{
    size_t i = 0;
    size_t len = strlen(target);

    while (line[i])
    {
        if ((ft_strncmp(&line[i], target, len)) == 0)
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
    size_t i = 0;
    size_t len = strlen(dest);

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
    size_t len = 0;
    size_t read_bytes = 0;
    char *line;
    char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = (char *)malloc(100000);
    if (!line)
        return (NULL);
    line[0] = '\0';
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (free(line), NULL);
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
    if (ac != 2)
        return (1);
    char *line;
    while ((line = gnl(0)))
    {
        filter(line, av[1]);
        free(line);
    }
    return (0);
}

