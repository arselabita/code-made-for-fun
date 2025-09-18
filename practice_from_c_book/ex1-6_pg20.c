#include <stdio.h>

/*
    Exercsise 1-6. Verify that the expression 
        getchar() != EOF is 0 or 1.
*/

int main()
{
    int value;
    int c;

    // version 1:
    while ((c = getchar()) != EOF)
        printf("%i", c);        

    // version 2:
    value =((c = getchar()) != EOF);
    printf("%i", value);
    return (0);
}