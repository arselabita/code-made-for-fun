

#include <stdio.h>
#include <stdlib.h>

/*
what do i need?

i need to print all possible solutions for the nqueens problem:
-so i need to print an array of numbers, each number signifies a position
-as the problem says, our boar will have N columns, so on each level, we will check
one column (and therefore one row), it also means the depth of our recursive loop
will be N

notes: i itself is a column, pos[i] is a row
*/

int my_abs(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}

int is_safe(int *pos, int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        if (pos[i] == row || (my_abs(row - pos[i]) == (col - i)))
            return 0;
    }
    return 1;
}

void    solve(int *pos, int col, int n)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", pos[i]);
        }
        printf("\n");
        return ;
    }
    for (int row = 0; row < n; row++)
    {
        if (is_safe(pos, col, row))
        {
            pos[col] = row;
            solve(pos, col + 1, n);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    int n = atoi(av[1]);
    int *pos = malloc(sizeof(int) * n);
    if (!pos)
        return 1;
    solve(pos, 0, n);
    free(pos);
    return 0;
}
