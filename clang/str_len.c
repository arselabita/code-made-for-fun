#include <stdio.h>

/*
    Exercise 0.2. Write a program that prints each argument along with its length.
    
    Example:./strlen foo bar "hello world"
    Output:
            foo -> 3
            bar -> 3
            hello world -> 11
*/

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac < 2)
        return(0);
    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
            j++;
        printf("%s -> %d\n", av[i], j);
        i++;
    }
    return (0);
}