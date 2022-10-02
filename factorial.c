#include <stdio.h>
long int fact();
int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    printf("Factorial of %d is %ld", n, fact(n));
}
long int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n*fact(n-1);
}
