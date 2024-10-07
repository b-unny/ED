#### Estrutura de Dados
###### Pratica 7


#include <stdio.h>
#include <stdlib.h>

/* Criar uma fila, compara-las e devolver quantos alunos presisam 
mudar de ordem, de acordo com a nota*/

typedef struct {
    float info;
    struct Node *prox;
} Node;

Node *newNode(int info){
    Node *new = (Node*)malloc(sizeof(Node));
    if(!new){
        exit(1);
    }
    new->info=info;
    new->prox=NULL;
}

void enqueue(Node **front, int info){
    Node *new = newNode(info);

    if(front == NULL){
        (*front)=new;
        return;
    }
    Node *aux = *front;
    
    while(aux->prox != NULL)
        aux=aux->prox;

    (*aux)->prox = new;
}

void dequeue(Node **front){
    if(front == NULL){
        printf("Fila vazia.\n");
        return;
    }
    Node *aux = *front;
    (*front) = (*front)->prox;
    free(aux);
} 

#define MAX 1000

int main(void){
    int i, M, nota, cont=0;
    Node *fila = NULL;
    
    scanf("%d", &M);
    // num of M tests

    if(M>MAX)
       exit(0);

    for(i=0; i<MAX; i++){
        scanf("%d", &nota);
        enqueue(&fila, nota);
    } // fila criada

    // TODO "ordenar" a fila e contar quantos foram mudados de lugar

    while(fila.prox != NULL){
        if(fila.info < fila.prox.info)
            cont++
    fila = fila.prox;
    }

    printf("%d\n", cont);
}
