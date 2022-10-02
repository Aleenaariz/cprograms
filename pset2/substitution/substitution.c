#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, string argv[])
{
    //accept a single command-line argument,the key to use for the substitution
    char key[26];
    if (argc == 2)
    {

        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i])) //check wheather string contains alphabet
            {
                key[i] = argv[1][i];
                //check for duplicate keys
                int count = 0;
                for (int j = 0; j <= i; j++)
                {
                    if (key[j] == argv[1][i])
                    {
                        count += 1;
                    }
                    if (count > 1) //check occurences of same character in key
                    {
                        printf("Duplicate keys are not allowed\n");
                        return 1;
                    }
                }
            }
            else
            {
                printf("Key must contain alphabets only\n");
                return 1;
            }
        }
        //check length of key
        if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    //invalid keys show error
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //prompt user  for a string of plaintext
    string ptext = get_string("plaintext: ");
    int n = strlen(ptext);
    char ctext[n];
    //encryption of plaintext
    char arr[27];
    int j;
    for (j = 0; j < 26; j++)
    {
        arr[j] = 'A' + j;
    }
    arr[j] = '\0';
    for (j = 0; j < 26; j++)
    {
        for (int i = 0; i < n; i++)
        {
            //check whether plaintext contains alphabets or not
            if (isalpha(ptext[i]))
            {
                //checking case of plaintext and encrypting in same case of ciphertext
                if (islower(ptext[i]) && ptext[i] == tolower(arr[j]))
                {
                    ctext[i] = tolower(key[j]);
                }
                else if (isupper(ptext[i]) && ptext[i] == (arr[j]))
                {
                    ctext[i] = toupper(key[j]);
                }
            }
            else //leaving characters other than alphabets as they are
            {
                ctext[i] = ptext[i];
            }
        }
    }
    //ciphertext-corresponding character in the ciphertext
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        printf("%c", ctext[i]);
    }
    printf("\n");
    return 0;
}


