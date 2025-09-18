 #include <stdio.h>
#include <unistd.h>
/*
    Exercise 1-9. Write a program to copy its input to its output, 
    replacing each string of one or more blanks by a single blank.
*/

int main(int ac, char **av)
{
    int i;

    if (ac != 2)
        return (-1);
    i = 0;
    while (av[1][i])
    {
        while (av[1][i] == ' ' && av[1][i + 1] == ' ')
            i++;
        write(1, &av[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}