#include <unistd.h>

/*
    Exercise 1-12. Write a program that prints its input one word per line.
*/

int main(int ac, char **av)
{
    int i;

    if (ac < 2)
        return (1);
    i = 0;
    while (av[1][i])
    {
        if (av[1][i] == ' ')
            write(1, "\n", 1);
        else
            write(1, &av[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}