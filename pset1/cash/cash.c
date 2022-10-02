#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float dollars = 0.0;
    //prompts user for change owed
    do
    {
        dollars = get_float("Change owed:");
    }
    while (dollars < 0);
    int cents = round(dollars * 100);
    int coins = 0;
    //calculate 25c coins
    while ((cents - 25) >= 0)
    {
        coins = coins + 1;
        cents = cents - 25;
    }
    //calculate 10c coins
    while ((cents - 10) >= 0)
    {
        coins = coins + 1;
        cents = cents - 10;
    }
    //calculate 5c coins
    while ((cents - 5) >= 0)
    {
        coins = coins + 1;
        cents = cents - 5;
    }
    //calculate 1c coins
    while ((cents - 1) >= 0)
    {
        coins = coins + 1;
        cents = cents - 1;
    }
    printf("%i\n", coins);
}
