#include <cs50.h>
#include <stdio.h>

int main()
{
    int h;
    do
    {
        h = get_int("Enter height of pyramid: ");

        for (int i = 0; i < h; i++)
        {
            for (int j = h; j > i+1; j--)
            {
                printf(" ");
            }
            for (int j = 0; j < i+1; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    while(h < 1);
}
