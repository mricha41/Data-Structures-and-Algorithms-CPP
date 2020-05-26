#include <stdio.h>

//exponent using recursion
int exponent(int m, int n)
{
    if(n==0)
        return 1;
    return exponent(m, n-1) * m;
}

int fastExponent(int m, int n)
{
    if(n==0)
        return 1;

    if(n%2 == 0)
        return fastExponent(m*m, n/2);
    else
        return m*fastExponent(m*m, (n-1)/2);
}

int main()
{
    //int x = exponent(4,3);
    int x = fastExponent(4,3);

    printf("%d\n", x);
    return 0;
}
