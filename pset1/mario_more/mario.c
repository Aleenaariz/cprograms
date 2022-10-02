#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int h;
    //prompts the user for the pyramid’s height
    do
    {
        h = get_int("Height:");
    }
    while (h < 1 || h > 8);
    //rows
    for (int i = 1; i <= h; i++)
    {
        //to print spaces
        for (int k = 0; k < h - i; k++)
        {
            printf(" ");
        }
        //to print #
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}