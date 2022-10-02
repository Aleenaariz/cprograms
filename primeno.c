#include <stdio.h>
int main() {
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    for( int i = 2;i<n;i++)
    {
        if (n%i == 0)
        {
            printf("Not a prime number");
            return 0;
        }
    }
    printf("Prime number");
    return 1;
}
