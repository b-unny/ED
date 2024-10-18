#include<stdio.h>

// Questao 1) IN: 5  OUT: fib(5)=14 calls=8
 
int fib_and_calls(int x, int *calls)
{
    (*calls)++;
    if(x==0)
        return 0;
    else if (x==1)
        return 1;
    return fib_n_call(x-1, calls) + fib(x-2, calls);
}

int main()
{
    int N, x, result, calls=-1;

    scanf("%d", &N);

    if(N<1 || N>40)
        return 0;
    
    while(N>0)
    {
        scanf("%d", &x);
        result = fib_and_calls(x, &calls);
        printf("fib(%d)=%d  calls=%d\n", x, result, calls);
        N--;
    }
    return 0;
}
