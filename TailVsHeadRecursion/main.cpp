#include <stdio.h>

//traditional way...
void loop(int n)
{
    while(n>0)
    {
        printf("Loop: %d\n", n);
        n--;
    }
}

//tail recursion instead...
void tailRecursion(int n)
{
    if(n>0)
    {
        printf("Tail recursion: %d\n", n);
        tailRecursion(n-1);
    }
}

//head recursion...
void headRecursion(int n)
{
    if(n>0)
    {
        headRecursion(n-1);
        printf("Head recursion: %d\n", n);
    }
}

//replace head recursion with loop...
void headLoop(int n)
{
    //start where you'd typically end...
    int i = 1;
    while(i<=n)
    {
        printf("Loop (head recursion replacement): %d\n", i);
        //reverse iteration direction...
        i++;
    }
}

int main()
{
    //loop...5,4,3,2,1
    int x = 5;
    loop(x);

    //tail recursion...5,4,3,2,1
    //IMPORTANT: compilers will often optimize
    //simple tail recursion into a loop to conserve
    //stack space requirements!!!
    //tail recursion has O(n) time and space complexity
    //while a loop has O(n) time and O(1) space complexity
    int y = 5;
    tailRecursion(y);

    //head recursion...1,2,3,4,5
    //IMPORTANT: cannot be easily converted to a loop
    //have to write it a bit differently
    int z = 5;
    headRecursion(z);

    //head recursion replaced by loop...1,2,3,4,5
    int p = 5;
    headLoop(p);

    return 0;
}
