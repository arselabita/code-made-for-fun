#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

size_t ft_strlen(const char *s)
{
    size_t i = 0;

    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(const char *s1)
{
    int i;
    char *copy;

    copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
    if (!copy)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        copy[i] = s1[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
char *get_next_line(int fd)
{
    static char    buffer[BUFFER_SIZE];
    char        line[70000];
    static int    b_read;
    static int    b_pos;
    int            i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    while (1337)
    {
        if (b_pos >= b_read)
        {
            b_read = read(fd, buffer, BUFFER_SIZE);
            b_pos = 0;
            if (b_read <= 0)
                break ;
        }
        line[i++] = buffer[b_pos++];
        if (buffer[b_pos - 1] == '\n')
            break ;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}

int main(void)
{
    int fd = open("file.txt", O_RDWR);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}
