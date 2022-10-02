#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    //to convert lowercase string to uppercase
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (islower(word[i]))
        {
            word[i] = toupper(word[i]);
        }
        else
        {
            continue;
        }
    }
    //creating an array of A-Z alphabets
    char arr[27];
    int j;
    for (j = 0; j < 26; j++)
    {
        arr[j] = 'A' + j;
    }
    arr[j] = '\0'; //null terminate the array
    //comaring array of alphabets to points
    int count = 0;
    for (j = 0; j < 26; j++)
    {
        for (int i = 0, n = strlen(word); i < n; i++)
        {
            if (word[i] == arr[j]) //if the character in word given by matches the alphabet in array,then
            {
                count += POINTS[j]; //add points at same index as that character in alphabet array
            }
        }
    }
    return count;
}
