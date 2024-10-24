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

TNo *insert(TNo *root, int info)
{
  if(root==NULL)
    return newNode(info); // se raiz esta vaiza, cria novo no

  if(info < root->valor)
      root->esq = insert(root->esq, info);
  else
      root->dir = insert(root->dir, info);
  return root;
}

// encontar valor
TNo* seek(TNo *root, int n2seek)
{
  if(root==NULL || root->info==n2seek)
    return root;
  if(info < root->info)
    seek(root->esq, n2seek);
  else
    seek(root->dir, n2seek;
}

// encontrar filhos

//  sei->la == (*sei).la
