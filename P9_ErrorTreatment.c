#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <setjmp.h>

typedef struct tree {
    int info;
    struct tree *dir;
    struct tree *esq;
} TNo;

jmp_buf buffer; // Ponto de recuperação para erros

TNo *novoNo(int info) {
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    
    if (novo == NULL) {
        errno = ENOMEM; // Define erro de memória insuficiente
        longjmp(buffer, 1); // Retorna ao ponto definido por setjmp
    }
    
    novo->info = info;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

TNo *inserir(TNo *raiz, int info) {
    if (raiz == NULL)
        return novoNo(info); // Se raiz está vazia, cria novo nó

    if (info < raiz->info)
        raiz->esq = inserir(raiz->esq, info);
    else
        raiz->dir = inserir(raiz->dir, info);

    return raiz;
}

int procurar(TNo *raiz, int n2seek) {
    if (raiz == NULL)
        return 0;

    if (raiz->info == n2seek)
        return 1;

    if (n2seek < raiz->info)
        return procurar(raiz->esq, n2seek);

    return procurar(raiz->dir, n2seek);
}

void encontrarFilhos(TNo *raiz, int valor) {
    if (raiz == NULL)
        return;

    if (raiz->info == valor) {
        if (raiz->esq == NULL && raiz->dir == NULL)
            printf("[ ]\n"); // Nó não possui filhos
        else {
            printf("[");
            if (raiz->esq)
                printf("%d", raiz->esq->info);
            if (raiz->esq && raiz->dir)
                printf(", ");
            if (raiz->dir)
                printf("%d", raiz->dir->info);
            printf("]\n");
        }
    } else if (valor < raiz->info) {
        encontrarFilhos(raiz->esq, valor);
    } else {
        encontrarFilhos(raiz->dir, valor);
    }
}

void liberarArv(TNo *raiz) {
    if (raiz == NULL)
        return;

    liberarArv(raiz->esq);
    liberarArv(raiz->dir);

    free(raiz);
}

int main(void) {
    int n;

    // Define o ponto de recuperação para erros
    if (setjmp(buffer) != 0) {
        // Erro detectado
        perror("Erro detectado");
        return EXIT_FAILURE;
    }

    printf("Nro de casos teste: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        errno = EINVAL; // Erro de entrada inválida
        longjmp(buffer, 1);
    }

    for (int i = 0; i < n; i++) {
        int K, valor, n2seek;
        TNo *raiz = NULL;

        printf("Qtde de elementos: ");
        if (scanf("%d", &K) != 1 || K <= 0) {
            errno = EINVAL; // Erro de entrada inválida
            longjmp(buffer, 1);
        }

        for (int j = 0; j < K; j++) {
            if (scanf("%d", &valor) != 1) {
                errno = EINVAL; // Entrada inválida ao inserir
                longjmp(buffer, 1);
            }
            raiz = inserir(raiz, valor);
        }

        printf("n para busca: ");
        if (scanf("%d", &n2seek) != 1) {
            errno = EINVAL; // Entrada inválida ao buscar
            longjmp(buffer, 1);
        }

        if (procurar(raiz, n2seek))
            encontrarFilhos(raiz, n2seek);
        else
            printf("Valor %d não encontrado\n", n2seek);

        liberarArv(raiz);
    }
    return EXIT_SUCCESS;
}