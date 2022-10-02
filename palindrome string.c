#include <stdio.h>
#include<string.h>
void ispal(char str[])
{
    int l = 0;
    int h = strlen(str) - 1;
    while(h>l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s Not palindrome", str);
            return;
        }
    }
    printf("%s palindrome",str);
}
int main()
{
    char str[100];
    printf("Enter string\n");
    scanf("%s", str);
    ispal(str);
}
