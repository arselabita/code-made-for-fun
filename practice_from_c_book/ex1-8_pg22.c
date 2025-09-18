#include <stdio.h>

/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

int main(int ac, char **av)
{
    int i;
    int count;

    if (ac != 2)
        return (-1);
    i = 0;
    count = 0;
    while (av[1][i])
    {
        if (av[1][i] == '\n' || av[1][i] == ' ' || av[1][i] == '\t')
            count++;
        i++;
    }
        printf("spaces: %i\n", count);
    
    return (0);
}
