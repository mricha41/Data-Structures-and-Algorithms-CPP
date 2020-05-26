#include <stdio.h>

//natural number sums using recursion
int naturalSum(int n)
{
    if(n == 0)
        return 0;

    return naturalSum(n-1) + n;
}

int slowNaturalSum(int n)
{
    int i,s = 0;
    for(i=1; i<=n; i++)
        s = s+i;

    return s;
}

int fastNaturalSum(int n)
{
    return n*(n+1)/2;
}

int main()
{
    //int x = naturalSum(5);
    //int x = slowNaturalSum(5);
    int x = fastNaturalSum(5);
    printf("%d\n", x);
    return 0;
}
