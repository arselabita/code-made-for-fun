#include <unistd.h>

/*
    Exercise 1-10. Write a program to copy its input to its output, 
    replacing each tab by \t, each backspace by \b, and each backslash by \\. 
    This makes tabs and backspaces visible in an unambiguous way.
*/

int main (int ac, char **av)
{
    int i;

    i = 0;
    while (av[1][i])
    {
        if (av[1][i] == '\t')
            write(1, "\\t", 2);
        else if (av[1][i] == '\b')
            write(1, "\\b", 2);
        else if (av[1][i] == '\\')
            write(1, "\\\\", 2);
        else
            write(1, &av[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}