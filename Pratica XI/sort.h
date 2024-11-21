#ifndef SORT_H
#define SORT_H

typedef struct vetor{
    int vet[tam];
    float t_bubble;
     
} Vetor;

void bubble_sort(int vet[], int tam);

void quick_sort(int vet[], int tam);

void shell_sort(int vet[], int tam); 

void heap_sort(int vet[], int tam);

// f p/ atribuir vlr aleatorio os vetores

// f p/ calc tempo de execucao e registrar valores