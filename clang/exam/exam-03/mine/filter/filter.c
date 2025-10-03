#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

int ft_strncmp(char *s1, char *s2, size_t n)
{
	for (size_t i = 0; i < n && (s1[i] || s2[i]); i++)
	{
		if (s1[i] != s2[i])
			return (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return 0;
}

void	filter(char *line, char *target)
{
	size_t len = strlen(target);
	size_t i = 0;
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

char *gnl(int fd)
{
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    char *line = malloc(100000);
    if (!line)
        return (NULL);
    line[0] = '\0';
    char *buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    size_t b_read = 0;
    size_t len = 0;
    while ((b_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (b_read < 0)
        {
            free(line);
            free(buffer);
        }
        buffer[b_read] = '\0';
        ft_strncat(line, buffer, BUFFER_SIZE);
        len += b_read;
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
		return 1;
	char *line;
	while ((line = gnl(0)))
	{
		filter(line, av[1]);
		free(line);
	}
	return 0;
}