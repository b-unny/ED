#include<stdlib.h>
#include<stdio.h>
#include"sort.h"

int main( )
{
    while(1)
    {
        int t;
        printf("Tamanho (0 para sair): ");
        scanf("%d", &t);
        
        if(t==0) break;

        Vetor *v=criarVet(t);
        
        preencherVet(v);
        //verificar(v->vet, t);

        calcTempo(v, bubbleSort, &v->bubble);

        calcTempo(v, quickSort, &v->quick);
  
        calcTempo(v, heapSort,&v->heap);

        calcTempo(v, shellSort,&v->shell);

        imprimirTempo(v);

        free(v->vet);
        free(v);
        printf("\n");
    }
    return 0;
}