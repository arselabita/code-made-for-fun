#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
    Exercise 0.3. Simple Calculator.
    Accept three arguments:
            number1
            operator (+, -, *, /
            number2
    Example: ./calc 7 * 3
    Output:  21
*/

int main(int ac, char **av)
{
    int i;
    int num1;
    int num2;
    int value;

    if (ac < 4)
        return (write(1, "please write 3 args: a number a sign and another number!\n", 57), 0);
    num1 = atoi(av[1]);
    num2 = atoi(av[3]);
    if (av[2][0] == '-')
        value = num1 - num2;
    else if (av[2][0] == '+')
        value = num1 + num2;
    else if (av[2][0] == '*')
        value = num1 * num2;
    else if (av[2][0] == '/')
        value = num1 / num2;
    printf("%d", value);
    return (0);
}