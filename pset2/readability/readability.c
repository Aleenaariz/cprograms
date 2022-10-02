#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    string s = "\0";
    do
    {
        s = get_string("Text: ");
    }
    while (strlen(s) < 1);
    int words = 0;
    int letters = 0;
    int sentences = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isspace(s[i]))
        {
            words += 1; //count number of words separated by whitespaces
        }

        if (isalnum(s[i]))
        {
            letters += 1; //count number of letters including a-z and A-Z
        }

        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences += 1; //count number of sentences separated by '.', '!' and '?'
        }

    }
    words = words + 1; //total words are more than whitesppaces btw them
    float L = (letters / (float)(words)) * 100.00; //average letters per 100 words
    float S = (sentences / (float)words) * 100.00; //average sentences per 100 words
    //Coleman-Liau index
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
