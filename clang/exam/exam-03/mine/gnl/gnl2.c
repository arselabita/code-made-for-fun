#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static size_t ft_strlen(const char *s)
{
    size_t i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}
static char *ft_strcpy(char * dst, const char * src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
static char *ft_strjoin(char *s1, const char *s2)
{
    int s1_lenght = ft_strlen(s1);
    int s2_lenght = ft_strlen(s2);
    char *new_str = (char *)malloc(sizeof(char) * (s1_lenght + s2_lenght + 1));
    if (!new_str)
        return (NULL);
    ft_strcpy(new_str, s1);
    ft_strcpy(new_str + s1_lenght, s2);
    free(s1);
    return(new_str);
}

char *get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    char *line = malloc(10000);
    if (!line)
        return (NULL);
    line[0] = '\0';
    char *buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    size_t read_bytes;
    size_t length = 0;
    while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[read_bytes] = '\0';
        line = ft_strjoin(line, buffer);
        length = ft_strlen(line);
        if (buffer[length - 1] == '\n')
            break ;
    }
    free(buffer);
    if(read_bytes == 0 || length == 0)
        return (free(line), NULL);
    return (line);
}

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *result = get_next_line(fd);
    printf("%s\n", result);
    free(result);
}