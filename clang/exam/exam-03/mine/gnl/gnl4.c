#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}
char *ft_strdup(char *s)
{
    char *copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!copy)
        return (NULL);
    int i = 0;
    while (s[i])
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char line[70000];
    static int b_pos;
    static int b_read = 0;
    int i;

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
}