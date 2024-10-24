#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int info;
  struct TNo *dir;
  struct Tno *esq;
} TNo;

TNo *newNode(int info)
{
  TNo *new=(Tno*)malloc(sizeof(Tno));
  if(!new)
    exit(1);
  new.info=info;
  new.dir=NULL;
  new.esq=NULL;
  return new;
}

TNo *insertInTree(TNo *root, int info)
{
  if(root==NULL)
    return newNode(info); // se raiz esta vaiza, cria novo no

  if(info < root->valor)
      root->esq = insertinTree(root->esq, info);
  else
      root->dir = insertInTree(root->dir, info);
  return root;
  
}

//  sei->la == (*sei).la
