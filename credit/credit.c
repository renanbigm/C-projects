#include <cs50.h>
#include <math.h>
#include <stdio.h>

/*
american express 15 digits, starts with 34 or 37.
mastercard 16 digits, starts witch 51, 52, 53, 54 or 55.,
visa 13 or 16 digits, starts with 4.
*/

int calc2(long n);   // pairs calculation
int calc4(long n);
int calc6(long n);
int calc8(long n);
int calc10(long n);
int calc12(long n);
int calc14(long n);
int calc16(long n);

int main(void)
{
    long n = get_long("Number: ");
    if (n < 1000000000000 || n > 9999999999999999)  // the number obtained does not fit in none of the 13 or 16 digits.
    {
        printf("INVALID\n");
    }
    int c1 = n % 10;                   // calculations and identify exactly position
    int c3 = round((n % 1000) / 100);
    int c5 = round((n % 100000) / 10000);
    int c7 = round((n % 10000000) / 1000000);
    int c9 = round((n % 1000000000) / 100000000);
    int c11 = round((n % 100000000000) / 10000000000);
    int c13 = round((n % 10000000000000) / 1000000000000);
    int c15 = round((n % 1000000000000000) / 100000000000000);

    int newc14 = round((n % 100000000000000) / 10000000000000);  // new values to first digits validation
    int newc16 = round((n / 1000000000000000));

    int moredigits15 = floor((n / 10000000000000)); // validate card by initial digits
    int moredigits16 = floor((n / 100000000000000));

    if (n > 99999999999999 && n < 1000000000000000 && c15 != 4) // AMEX check
    {
        int check1 = c1 + calc2(n) + c3 + calc4(n) + c5 + calc6(n) + c7 + calc8(n) + c9 + calc10(n) + c11 + calc12(n) // sumcheck
                     + c13 + calc14(n) + c15;
        if (check1 % 10 == 0 && moredigits15 == 34)
        {
            printf("AMEX\n");
        }
        else if (check1 % 10 == 0 && moredigits15 == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (n > 999999999999999 && n < 10000000000000000 && newc16 != 4) // Master Card check
    {
        int check2 = c1 + calc2(n) + c3 + calc4(n) + c5 + calc6(n) + c7 + calc8(n) + c9 + calc10(n) + c11 + calc12(n)
                     + c13 + calc14(n) + c15 + calc16(n);
        if (check2 % 10 == 0 && moredigits16 > 50 && moredigits16 < 56)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (n > 999999999999 && n < 10000000000000000)  // check VISA
    {
        if (n > 999999999999 && n < 10000000000000)
        {
            int check3 = c1 + calc2(n) + c3 + calc4(n) + c5 + calc6(n) + c7 + calc8(n) + c9 + calc10(n) + c11 + calc12(n) + c13;
            if (check3 % 10 == 0 && c13 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (n > 9999999999999 && n < 100000000000000)
        {
            int check3_1 = c1 + calc2(n) + c3 + calc4(n) + c5 + calc6(n) + c7 + calc8(n) + c9 + calc10(n) + c11 + calc12(n)
                           + c13 + calc14(n);
            if (check3_1 % 10 == 0 && newc14 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (n > 99999999999999 && n < 1000000000000000)
        {
            int check3_2 = c1 + calc2(n) + c3 + calc4(n) + c5 + calc6(n) + c7 + calc8(n) + c9 + calc10(n) + c11 + calc12(n)
                           + c13 + calc14(n) + c15;
            if (check3_2 % 10 == 0 && c15 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (n > 999999999999999 && n < 10000000000000000)
        {
            int check3_3 = c1 + calc2(n) + c3 + calc4(n) + c5 + calc6(n) + c7 + calc8(n) + c9 + calc10(n) + c11 + calc12(n)
                           + c13 + calc14(n) + c15 + calc16(n);
            if (check3_3 % 10 == 0 && newc16 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int calc2(long n)
{
    int c2 = floor((n % 100) / 10) * 2;
    if (c2 > 9)
    {
        int sumc2 = (c2 % 10) + (c2 % 100) / 10;
        return sumc2;
    }
    else
    {
        return c2;
    }
}

int calc4(long n)
{
    int c4 = floor((n % 10000) / 1000) * 2;
    if (c4 > 9)
    {
        int sumc4 = (c4 % 10) + (c4 % 100) / 10;
        return sumc4;
    }
    else
    {
        return c4;
    }
}

int calc6(long n)
{
    int c6 = floor((n % 1000000) / 100000) * 2;
    if (c6 > 9)
    {
        int sumc6 = (c6 % 10) + (c6 % 100) / 10;
        return sumc6;
    }
    else
    {
        return c6;
    }
}

int calc8(long n)
{
    int c8 = floor((n % 100000000) / 10000000) * 2;
    if (c8 > 9)
    {
        int sumc8 = (c8 % 10) + (c8 % 100) / 10;
        return sumc8;
    }
    else
    {
        return c8;
    }
}

int calc10(long n)
{
    int c10 = floor((n % 10000000000) / 1000000000) * 2;
    if (c10 > 9)
    {
        int sumc10 = (c10 % 10) + (c10 % 100) / 10;
        return sumc10;
    }
    else
    {
        return c10;
    }
}

int calc12(long n)
{
    int c12 = floor((n % 1000000000000) / 100000000000) * 2;
    if (c12 > 9)
    {
        int sumc12 = (c12 % 10) + (c12 % 100) / 10;
        return sumc12;
    }
    else
    {
        return c12;
    }
}

int calc14(long n)
{
    int c14 = round((n % 100000000000000) / 10000000000000) * 2;
    if (c14 > 9)
    {
        int sumc14 = (c14 % 10) + (c14 % 100) / 10;
        return sumc14;
    }
    else
    {
        return c14;
    }
}

int calc16(long n)
{
    int c16 = floor((n / 1000000000000000)) * 2;
    if (c16 > 9)
    {
        int sumc16 = (c16 % 10) + (c16 % 100) / 10;
        return sumc16;
    }
    else
    {
        return c16;
    }
}
