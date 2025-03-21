#include <cs50.h>
#include <stdio.h>

int getChange(int n);

int main()
{
    int amount;
    
    do
    {
        amount = get_int("Enter change amount: ");
    }
    while (amount < 0);

    int number = getChange(amount);
    printf("No. of coins to be dispensed : %i\n", number);
}

int getChange(int n)
{
    int counter = 0;

    while (n >= 25)
    {
        n -= 25;
        counter++;
    }
    while (n >= 10)
    {
        n -= 10;
        counter++;
    }
    while (n >= 5)
    {
        n -= 5;
        counter++;
    }
    while (n >= 1)
    {
        n -= 1;
        counter++;
    }
    return counter;
}
