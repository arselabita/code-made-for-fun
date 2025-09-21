#include <unistd.h>
#include <stdio.h>

/*  
    Exercise 0.1. Write a program that prints all 
    command-line arguments in reverse order. 

    Example: ./reverse hello world test
    Output:            test world hello
*/

int main(int ac, char **av)
{
    int i;
    int j;
    char **last;

    
    if (ac < 2)
        return (0);
    i = 1;
    while (i < ac)
    {
        last = av[i][ac - 1];
        while (last[j])
        {
            write(1, &last, 1);
            j++;
        }
        i++;
    }
 
    write(1, "\n", 1);
    return (0);
}


// arsela bita