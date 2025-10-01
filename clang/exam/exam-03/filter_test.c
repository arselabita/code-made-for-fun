
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
# define BUFFER_SIZE 10

char *ft_strncat(char *dest, char *src, size_t n)
{
	size_t i = 0;
	size_t j = strlen(dest);
	while (i < n && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return dest;
}

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
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	char *line = malloc(100000);
	if (!line)
		return (NULL);
	line[0] = '\0';
	char *buffer = malloc(BUFFER_SIZE + 1);
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
		ft_strncat(line, buffer, read_bytes);
		len += read_bytes;
		if (line[len - 1] == '\n')
			break ;
	}
	free(buffer);
	if (len == 0)
		return (free(line), NULL);
	return line;
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
	