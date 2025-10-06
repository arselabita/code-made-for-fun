#include <stdio.h>
#include <string.h>

void permute(char *a, int curr_index, int len);
void swap(char *a, char *b);

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    permute(av[1], 0, strlen(av[1]));
}
void permute(char *a, int curr_index, int len)
{
    if (curr_index == len - 1)
    {
        printf("%s\n", a);
        return ;
    }
    for (int i = curr_index; i < len; i++)
    {
        swap(&a[i], &a[curr_index]);
        permute(a, curr_index + 1, len);
        swap(&a[i], &a[curr_index]);
    }
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}