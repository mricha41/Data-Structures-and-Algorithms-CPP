#include <stdio.h>

int factorial(int n)
{
    if(n<0)
        return -1;
    else if(n==0)
        return 1;
    return n*factorial(n-1);
}

//combination using recursion
//formula:
//n!r!/(n - r)!
int combination(int n, int r)
{
    int numerator, denominator = 0;
    numerator = factorial(n);
    denominator = factorial(r)*factorial(n-r);

    return numerator/denominator;
}

int recursiveCombination(int n, int r)
{
    if(n == r || r == 0)
        return 1;

    return recursiveCombination(n-1, r-1) + recursiveCombination(n-1, r);
}

int main()
{
    //int x = combination(5, 3);
    int x = recursiveCombination(5,3);

    printf("%d\n", x);
    return 0;
}
