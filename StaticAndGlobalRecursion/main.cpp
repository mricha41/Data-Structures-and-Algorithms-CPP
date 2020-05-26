#include <stdio.h>

//global...
int x = 0;

int fun(int n)
{
    //vs. static...
    //static int x = 0;
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int r = 0;

    //should give 25...
    r = fun(5);
    printf("%d\n", r);

    //running it a second time will give 50...
    r = fun(5);
    printf("%d\n", r);

    return 0;
}
