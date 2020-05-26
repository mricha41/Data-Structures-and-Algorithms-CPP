#include <stdio.h>

//nested recursion
int nestedRecursion(int n)
{
    if(n>100)
        return n-10;

    return nestedRecursion(nestedRecursion(n+11));
}

int main()
{
    //any value less than or equal to 101 gives 91 as a result...
    //int x = nestedRecursion(10); //91
    //otherwise it will give you n-10 as a result...
    int x = nestedRecursion(200); //190
    printf("%d\n", x);
    return 0;
}
