#include <unistd.h>
#include <stdio.h>

/*  
    Exercise 0.1. Write a program that prints all 
    command-line arguments in reverse order. 

    Example: ./reverse hello world test
    Output:            test world hello
*/

int reverse(char *av)
{
    int j;
    int end;

    j = 0;
    while (av[j])
        j++;
    end = 0;
    while (av[j])
    {
        write(1, &av[j], 1);
        j++;
    }
    write(1, " ", 1);
    return (0);
}

int main(int ac, char **av)
{
    int i;

    if (ac < 2)
        return (0);
    i = 1;
    while (i < ac)
    {
        reverse(av[i]);
        i++;
    } 
    write(1, "\n", 1);
    return (0);
}