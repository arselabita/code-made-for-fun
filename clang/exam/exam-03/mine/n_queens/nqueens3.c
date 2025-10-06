#include <stdio.h>
#include <stdlib.h>

void solve(int *pos, int col, int n);
int is_safe(int *pos, int col, int row);
int my_abs(int x);

int main(int ac, char **av)
{
    int n;
    int *pos;

    if (ac != 2 && av[1][0] == '-')
        return (1);
    n = atoi(av[1]);
    pos = (int *)malloc(sizeof(int) * n);
    if (!pos)
        return (1);
    solve(pos, 0, n);
    free(pos);
    return (0);
}

void solve(int *pos, int col, int n)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                printf(" ");
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

int is_safe(int *pos, int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        if (pos[i] == row || (my_abs(row - pos[i]) == (col - i)))
            return (0);
    }
    return (1);
}

int my_abs(int x)
{
    if (x < 0)
        return (-x);
    else
        return (x);
}