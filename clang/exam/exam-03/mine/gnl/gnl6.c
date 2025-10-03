#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t ft_strlen(char *dest)
{
    size_t i;

    i = 0;
    while (dest[i])
        i++;
    return (i);
}

char *ft_strncat(char *dest, char *src, size_t n)
{
    size_t i;
    size_t len;

    i = 0;
    len = ft_strlen(dest);
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
    size_t len;
    size_t read_bytes;
    static char *line;
    static char *buffer;

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
    while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        len = 0;
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

int main(void)
{
    int fd = open("file.txt", O_RDWR);
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
    printf("%s", gnl(fd));
}