#include <cs50.h>
#include <stdio.h>
#include <math.h>
int cal_len(long card_number);
int visa(long card_number);
int ame(long card_number);
int main(void)
{
    long number = 0;
    long card_number = 0;
    int sum = 0;
    int temp = 0;

    do
    {
        number = get_long("Number: ");
    }
    while (number < 1);
    card_number = number;
    //luhn's algorithm
    while (number > 0)
    {
        sum += number % 10;
        number = number / 10;
        temp = (number % 10) * 2;
        if (temp > 9)
        {
            temp -= 9;
        }
        sum += temp;
        number = number / 10;
    }
    string card = "INVALID";
    if (sum % 10 == 0)
    {
        int cardlen = cal_len(card_number);
        if (cardlen == 13 || cardlen == 16)
        {
            int num = visa(card_number);
            if (num == 4)
            {
                card = "VISA";
            }
            else if (cardlen == 16 && num != 4)
            {
                int num1 = ame(card_number);
                if (num1 == 51 || num1 == 52 || num1 == 53 || num1 == 54 || num1 == 55)
                {
                    card = "MASTERCARD";
                }
            }
        }
        else if (cardlen == 15)
        {
            int num = ame(card_number);
            if (num == 34 || num == 37)
            {
                card = "AMEX";
            }
        }
    }
    printf("%s\n", card);
}
//function to calculate length of card
int cal_len(long card_number)
{
    long number = card_number;
    int len = 0;
    while (number > 0)
    {
        if (number / 10 >= 0)
        {
            len += 1;
            number = number / 10;
        }
    }
    return len;
}
//function to know whether a card is visa or not
int visa(long card_number)
{
    long number = card_number;
    int cardlen = cal_len(card_number);
    for (int i = 0, n = cardlen; i < n - 1; i++)
    {
        number = number / 10;
    }
    return number;
}
//function to know whether a card is master or american express
int ame(long card_number)
{
    long number = card_number;
    int cardlen = cal_len(card_number);
    for (int i = 0, n = cardlen; i < n - 2; i++)
    {
        number = number / 10;
    }
    return number;
}