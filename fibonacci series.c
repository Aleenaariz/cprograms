#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of terms: \n");
    scanf("%d", &n);
    printf("Fibonacci Series:");
    int t0 = 0;
    int t1 = 1;
    if (n == 0)
    {
        printf("%d", t0);
    }
    else if (n == 1)
    {
        printf("%d,%d", t0, t1);
    }
    else
    {
        printf("%d, %d,", t0, t1);
        int t = t0 + t1;
        for (int i = 2; i < n; i++)
        {
            printf("%d,", t);
            t0 = t1;
            t1 = t;
            t = t0 + t1;
        }
    }
    
}
