#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, string argv[])
{
    //accept a single command-line argument, a non-negative integer
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if isalpha(argv[1][i])
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    //plaintext
    string ptext = get_string("plaintext: ");
    int n = strlen(ptext);
    char ctext[n];
    //creating an array of A-Z alphabets
    char arrup[27];
    int j = 0;
    for (j = 0; j < 26; j++)
    {
        arrup[j] = 'A' + j;
    }
    arrup[j] = '\0';
    //creating an array of a-z alphabets
    char arrlow[27];
    int l = 0;
    for (l = 0; l < 26; l++)
    {
        arrlow[l] = 'a' + l;
    }
    arrlow[l] = '\0';
    for (int k = 0; k < 26; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (isalpha(ptext[i]))
            {
                if (islower(ptext[i]) && (ptext[i] == arrlow[k]))
                {
                    int c = (k + key) % 26; //Caesar’s algorithm
                    ctext[i] = arrlow[c];
                }
                else if (isupper(ptext[i]) && (ptext[i] == arrup[k]))
                {
                    int c = (k + key) % 26; //Caesar’s algorithm
                    ctext[i] = arrup[c];

                }
            }
            else
            {
                ctext[i] = ptext[i];
            }
        }
    }
    //ciphertext
    printf("ciphertext: ");
    //printing string character by character as printing string as whole was causing an error
    for (int i = 0; i < n; i++)
    {
        printf("%c", ctext[i]);
    }
    printf("\n");
    return 0;
}
