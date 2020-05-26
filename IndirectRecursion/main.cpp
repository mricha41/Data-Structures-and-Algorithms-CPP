#include <stdio.h>

//indirect recursion
void functionA(int n);
void functionB(int n);

int main()
{
    functionA(20);

    return 0;
}

void functionA(int n)
{
    if(n>0)
    {
        printf("%d ", n);
        functionB(n-1);
    }
}

void functionB(int n)
{
    if(n>1)
    {
        printf("%d ", n);
        functionA(n/2);
    }
}
