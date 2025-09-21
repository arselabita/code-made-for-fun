#include <unistd.h>

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

    
    if (ac < 2)
        return (0);
    i = ac - 1;
    while (i > 0)
    {
        j = 0;
        while (av[i][j])
        {
            write(1, &av[i][j], 1);
            j++;
        }
        if (i > 1)
            write (1, " ", 1);
        i--;
    }
 
    write(1, "\n", 1);
    return (0);
}


// arsela bita