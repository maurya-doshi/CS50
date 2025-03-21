#include <cs50.h>
#include <math.h>
#include <stdio.h>

char checkCard(int i, long n, int c);
int checkNum(long n, int c);

int main()
{
    long num = get_long("Input card number: ");
    int counter = 0;
    long temp = num;

    while (temp > 0)
    {
        counter++;
        temp /= 10;
    }

    int checker = checkNum(num, counter);
    char card = checkCard(checker, num, counter);

    switch (card)
    {
        case 'I':
            printf("INVALID\n");
            break;
        case 'A':
            printf("AMEX\n");
            break;
        case 'M':
            printf("MASTERCARD\n");
            break;
        case 'V':
            printf("VISA\n");
            break;
    }
}

int checkNum(long n, int c)
{
    int sum = 0, r1;
    long temp = n;

    if (c != 15 && c != 16 && c != 13)
    {
        return 1;
    }

    while (n > 0)
    {
        sum = sum + (n % 10);
        n /= 10;
        r1 = (n % 10) * 2;
        while (r1 > 0)
        {
            sum = sum + r1 % 10;
            r1 /= 10;
        }
        n /= 10;
    }

    if ((sum % 10) == 0)
    {
        return 0;
    }

    return 1;
}

char checkCard(int i, long n, int c)
{
    if (i == 0)
    {
        while (n > 100)
        {
            n /= 10;
        }

        if ((n >= 51 && n <= 55) && c == 16)
        {
            return 'M';
        }

        if ((n == 34 || n == 37) && c == 15)
        {
            return 'A';
        }

        n /= 10;

        if (n == 4 && (c == 13 || c == 16))
        {
            return 'V';
        }
    }

    return 'I';
}
