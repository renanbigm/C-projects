#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return 0; // check command-line arguments.
    }

    string s = argv[1];
    for (int i = 0, n = strlen(s[1]); i < n; i++)
    {
        if (isdigit(s[i]))
        {
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
}
