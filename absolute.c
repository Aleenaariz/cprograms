#include <stdio.h>
int absolute(int n)
{
    if (n < 0)
    {
        n= (-1)*n;
    }
    return n;
}
int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    printf("Absolute of %d is %d", n, absolute(n));
}
