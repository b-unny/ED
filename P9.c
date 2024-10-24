#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int info;
  struct TNo *dir;
  struct Tno *esq;
} TNo;

void insertInTree(TNo **root, int info)
{
  
