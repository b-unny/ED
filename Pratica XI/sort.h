#ifndef#ifndef SORT_H
#define SORT_H

typedef struct vetor{
    int *vet;
    int tam;
    double bubble, quick, shell, heap; // tempos de execucao de cada algoritmo

} Vetor;

Vetor *criarVet(int tam);

void preencherVet(Vetor *v);

void bubbleSort(int *vet, int tam);

void quickSort(int *vet, int tam);

void shellSort(int *vet, int tam);

void criarHeap(int *vet, int tam, int raiz);

void heapSort(int *vet, int tam);

int *copiarVet(int *vet, int tam);

void calcTempo(Vetor *v, void (*algoritmo)(int*, int), double *campoTempo);

void imprimirTempo(Vetor *vet);

void verificar(int *vet, int tam);

#endif 