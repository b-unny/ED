#include<stdio.h>

// Questao 1) IN: 5  OUT: fib(5)=14 calls=8

int fib_and_calls(int x, int *calls)
{
    if(x==0)
     {
        *calls++;
        return 0;
     }
    else if (x==1)
    {
        *calls++;
        return 1;
    }
    return fib(x-1) + fib(x-2);
}

int main()
{
    int N, X, calls=0;

    scanf("%d", &N);

    if(!0<N<40)
        exit(0);
    
    while(N>0)
    {
        scanf("%d", &x);
        int y=x;
        fib_and_calls(x, &calls);
        printf("fib(%d)=%d  calls=%d\n", y, x, calls);
         N--;
    }
}
