
#define BUFFER_SIZE 10
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char    *gnl(int fd)
{
    if (fd < 0  || BUFFER_SIZE <= 0)
        return (NULL);
    char    *line = malloc(100000);
    if (!line)
        return (NULL);
    line[0] = '\0';
    char    *buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (free(line), NULL);
    size_t read_bytes = 0;
    size_t len = 0;
    while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (read_bytes < 0)
        {
            free(line);
            free(buffer);
        }
        buffer[read_bytes] = '\0';
        strncat(line, buffer, read_bytes);
        len += read_bytes;
        if (buffer[len -1] == '\n')
            break;
    }
    free(buffer);
    if (len == 0)
    {
        free(line);
        return (NULL);
    }
    return line;
}
int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *result = gnl(fd);
    printf("%s\n", result);
    free(result);
    return 0;
}