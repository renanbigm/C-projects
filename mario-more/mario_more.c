#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int q = n - 1; q > i; q--)
        {
            printf(" ");
        }
        for (int t = 0; t <= i; t++)
        {
            printf("#");
        }
        if (i < n)
        {
            printf("  ");
        }
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf ("\n");
    }
}
