#include <unistd.h>
#include <stdlib.h>

int my_abs(int x)
{
    return (x < 0) ? -x : x;
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

void solve(int *pos, int col, int n)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                write(1, " ", 1);
            char c = pos[i] + '0';
            write(1, &c, 1);
        }
        write(1, "\n", 1);
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
    int *pos = (int *)malloc(sizeof(int) * n);
    if (!pos)
        return 1;
    solve(pos, 0, n);
    free(pos);
}

