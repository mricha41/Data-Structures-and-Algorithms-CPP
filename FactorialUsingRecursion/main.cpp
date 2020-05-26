#include <stdio.h>

//factorial using recursion
int factorial(int n)
{
    if(n<0)
        return -1;
    else if(n==0)
        return 1;
    return n*factorial(n-1);
}

int iterativeFactorial(int n)
{
    if(n<0)
        return -1;

    int f=1;
    for(int i=1; i<=n; i++)
        f=f*i;

    return f;
}

int main()
{
    int x = factorial(5);
    //int x = iterativeFactorial(5);

    printf("%d\n", x);
    return 0;
}
