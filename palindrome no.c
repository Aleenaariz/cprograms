#include <stdio.h>

void ispal(int num)
{
    int temp = num;
    int rem, sum = 0;
    while (num>0)
    {
        rem = num%10;
        sum = (sum*10) + rem;
        num = num/10;
    }
    if (temp == sum)
    {
        printf("PAL");
        return;
    }
    printf("Not PAL");
    return;
}
int main()
{
    int num;
    printf("Enter number\n");
    scanf("%d", &num);
    ispal(num);
}
