#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    int x;
    int y;
    int n = 0;
    // TODO: Prompt for start size
    do
    {
        x = get_int("Enter a starting year:");
    }
    while (x < 9);
    // TODO: Prompt for end size
    do
    {
        y = get_int("Enter an ending year:");
    }
    while (y < x);
    // TODO: Calculate number of years until we reach threshold
    int i = 0;
    while (x < y)
    {
        x = x + round(x / 3) - round(x / 4);
        n++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", n);
}