#include<avl.h>

typedef struct AVLnode{
  int info;
  int altura = 0; 
  struct AVLnode *esq;
  struct AVLnode *dir;
} avl;

avl *novoNo(int info)
{
  alv *novo = (avl*)malloc(sizeof(avl));
  if(novo==NULL)
  {
    printf("Erro de alocação para %d\n", info);
    exit(1);
  }
  novo->info = info;
  novo->dir  = NULL;
  novo->esq  = NULL;
  return novo;
}

avl *adicionar(avl *raiz, int info)
{
  
}
