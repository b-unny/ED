#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int info;
    struct ArvBin* dir;
    struct ArvBin* esq;
} ArvBin;

ArvBin *insere(ArvBin *raiz, int valor)
{
    if(raiz==NULL)
    {
        ArvBin* folha = (ArvBin*)malloc(sizeof(ArvBin));
        folha->info=valor;
        folha->dir=NULL;
        folha->dir=NULL;
        return folha;
    }
    if(raiz->info < valor)
        raiz->dir = insere(raiz->dir, valor);
    else
        raiz->esq = insere(raiz->esq, valor);
    
    return raiz;
}

// agora o msm so que procedimento 
void insere(ArvBin **raiz, int valor)
{
    if(*raiz==NULL)
    {
        ArvBin* folha = (ArvBin*)malloc(sizeof(ArvBin));
        folha->info=valor;
        folha->dir=NULL;
        folha->dir=NULL;
    }
    if(raiz->info < valor)
        insere(&raiz->dir, valor);
    else
        insere(&raiz->esq, valor);
}

/*  BSF Percurso em Profundidade (altura)
        Ordem: esq->raiz->dir
    Pre Ordem: raiz->esq->dir
    Pos Ordem: esq->dir->raiz
 */

/*  BFS Percuso em Largura (qtde de nós por nivel)
    Usa-se fila: T-T
 */
