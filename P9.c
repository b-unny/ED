#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
  int info;
  struct tree *dir, *esq;
} TNo;

TNo *novoNo(int info)
{
  TNo *novo=(TNo*)malloc(sizeof(TNo));
  
  if(novo==NULL)  exit(1);
  
  novo->info=info;
  novo->dir=NULL;
  novo->esq=NULL;
  
  return novo;
}

TNo *inserir(TNo *raiz, int info)
{
  if(raiz==NULL)
    return novoNo(info); // se raiz esta vaiza, cria novo no

  if(info < raiz->info)
      raiz->esq = inserir(raiz->esq, info);
  else
      raiz->dir = inserir(raiz->dir, info);
  
  return raiz;
}

// encontar valor
int procurar(TNo *raiz, int n2seek)
{
  if(raiz==NULL)    
    return 0;
  
  if(raiz->info == n2seek)
    return 1;
  
  if(n2seek < raiz->info)
    return procurar(raiz->esq, n2seek);
  
  return procurar(raiz->dir, n2seek);
}

void encontrarFilhos(TNo *raiz, int valor)
{
    if(raiz == NULL) return;
    
    if(raiz->info == valor)
    {
      if(raiz->esq==NULL && raiz->dir==NULL) 
        printf("[ ]\n"); // no nao possui filhos  
        
      else
      {
        printf("[");
        if(raiz->esq)
            printf("%d", raiz->esq->info);
        if(raiz->esq && raiz->dir)
            printf(", ");
        if(raiz->dir)
            printf("%d", raiz->dir->info);      
        printf("]\n");                   
      }
    }
    else if(valor < raiz->info)
        encontrarFilhos(raiz->esq, valor);
    else
        encontrarFilhos(raiz->dir, valor);     
}

void liberarArv(TNo *raiz)
{
    if(raiz == NULL) return;
    
    liberarArv(raiz->esq);
    liberarArv(raiz->dir);
    
    free(raiz);
}

//  sei->la equivs to (*sei).la

int main(void)
{
    int n;
    
    printf("Nro de casos teste: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        int K, valor, n2seek;
        TNo *raiz = NULL;
        
        printf("Qtde de elementos: ");
        scanf("%d",&K);
        
        for(int j=0; j<K; j++)
        {
            scanf("%d",&valor);
            raiz=inserir(raiz, valor);
        }
        printf("n para busca: ");e
        scanf("%d",&n2seek);
        
        if(procurar(raiz, n2seek))
            encontrarFilhos(raiz, n2seek);
        else 
            printf("valor %d nao encontrado\n", n2seek);
            
        liberarArv(raiz);
        
        //system("clear");
    }
    return 0;
}
