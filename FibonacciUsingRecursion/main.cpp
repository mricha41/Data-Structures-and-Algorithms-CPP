#include <stdio.h>

//fibonacci sequence using recursion
//this function is "excessively recursive"
int fibonacci(int n)
{
    if(n<=1)
        return n;

    return fibonacci(n-2) + fibonacci(n-1);
}

int iterativeFibonacci(int n)
{
    int sum = 0;
    int t0 = 0;
    int t1 = 1;
    if(n<=1)
        return n;

    for(int i=2; i<=n; i++)
    {
        sum = t0 + t1;
        t0 = t1;
        t1 = sum;
    }
    return sum;
}

//memoization applied to fibonacci
//makes fewer fibonacci function calls
//less stack space and faster
int fib[10];
int memoizedFibonacci(int n)
{
    if(n<=1)
    {
        fib[n] = n;
        return n;
    }
    else
    {
        if(fib[n-2] == -1)
            fib[n-2] = memoizedFibonacci(n-2);
        if(fib[n-1] == -1)
            fib[n-1] = memoizedFibonacci(n-1);

        fib[n] = fib[n-2] + fib[n-1];

        return fib[n-2] + fib[n-1];
    }
}

int main()
{
    //int x = fibonacci(10);
    //int x = iterativeFibonacci(10);

    //fill fib
    for(int i=0; i<10; i++)
        fib[i] = -1;

    int x = memoizedFibonacci(10);

    printf("%d\n", x);
    return 0;
}
