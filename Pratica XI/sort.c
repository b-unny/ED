#include"sort.h"
#include<stdio.h>
#include<time.h>

Vetor *criarVet(int tam)
{
    Vetor *v = (Vetor *)malloc(sizeof(Vetor));
    if (v == NULL) {
        printf("Erro de alocacao da estrutura.\n");
        exit(1);
    }

    v->vet = (int*)malloc(tam * sizeof(int)); // Aloca memória para o vetor interno
    if (v->vet == NULL) {
        printf("Erro de alocacao do vetor interno.\n");
        free(v);
        exit(1);
    }

    v->tam = tam;
    return v;
}

void preencherVet(Vetor *v)
{
    srand(time(NULL));
    for(int i=0; i<v->tam; i++){
        v->vet[i]= rand()%1000; // numeros entre 0 e 999
    }
}

void bubbleSort(int *vet, int tam)
{
    //printf("chamando bubble\n");
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

void quickSort(int *vet, int tam)
 {
    //printf("chamando quick\n");
    if (tam <= 1) return; // Caso base: vetor já ordenado ou vazio
    
    // Partição
    int pivot = vet[tam - 1]; // Último elemento como pivô
    int i = -1;               // Índice do menor elemento

    for (int j = 0; j < tam - 1; j++)
    {
        if (vet[j] <= pivot)
        {
            i++;
            int temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }
    // Posicionar o pivô no lugar correto
    int pos_pivot = i + 1;
    int temp = vet[pos_pivot];
    vet[pos_pivot] = vet[tam - 1];
    vet[tam - 1] = temp;

     // Chamadas recursivas para as subpartições
    quickSort(vet, pos_pivot);    
    quickSort(vet + pos_pivot + 1, tam - pos_pivot - 1); 

}

void shellSort(int *vet, int tam)
{
    //printf("chamando shell\n");
    int incremento = tam / 2; // Define o incremento inicial
    while (incremento > 0) 
    {
        for (int i = incremento; i < tam; i++) 
        {
            int atual = vet[i];
            int j = i;

            // Comparação e deslocamento dos elementos
            while (j >= incremento && vet[j - incremento] > atual)
            {
                vet[j] = vet[j - incremento];
                j -= incremento;
            }
            vet[j] = atual;
        }
        incremento /= 2; // Reduz o incremento
    }
}

void criarHeap(int *vet, int tam, int raiz) 
{
    int maior = raiz;         // Assume a raiz como o maior elemento
    int esquerda = 2 * raiz + 1; // Filho à esquerda
    int direita = 2 * raiz + 2;  // Filho à direita

    // Verifica se o filho à esquerda é maior que a raiz
    if (esquerda < tam && vet[esquerda] > vet[maior])
        maior = esquerda;

    // Verifica se o filho à direita é maior que o maior atual
    if (direita < tam && vet[direita] > vet[maior]) 
        maior = direita;

    // Se o maior não for a raiz, realiza a troca e reorganiza recursivamente
    if (maior != raiz) 
    {
        int temp = vet[raiz];
        vet[raiz] = vet[maior];
        vet[maior] = temp;
        criarHeap(vet, tam, maior); // Reorganiza o subárvore afetado
    }
}

void heapSort(int *vet, int tam) 
{
    //printf("chamando heap\n");
    // Constrói o heap (reorganiza o vetor)
    for (int i = tam / 2 - 1; i >= 0; i--)
        criarHeap(vet, tam, i);

    // Extrai elementos do heap, um por um
    for (int i = tam - 1; i > 0; i--) 
    {
        // Move a raiz (maior elemento) para o final
        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;

        // Chama criarHeap para reorganizar o heap com o restante dos elementos
        criarHeap(vet, i, 0);
    }
}

int *copiarVet(int *vet, int tam)
{
    int *copia=(int*)malloc(tam*sizeof(int));
    if(copia==NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }
    for(int i=0; i<tam; i++)
        copia[i]=vet[i];

    return copia;
}

void calcTempo(Vetor *v, void (*algoritmo)(int*, int), double *campoTempo)
{
    int *copia = copiarVet(v->vet, v->tam);
    clock_t ini=clock();
    algoritmo(copia, v->tam);
    clock_t fim=clock();
    *campoTempo=(double)(fim-ini)/CLOCKS_PER_SEC;
}

void imprimirTempo(Vetor *vet)
{
    printf("Tempos de ordenacao:\n");
    printf("BubbleSort: %.17lf s\n", vet->bubble);
    printf("QuickSort : %.17lf s\n", vet->quick);
    printf("HeapSort  : %.17lf s\n", vet->heap);
    printf("ShellSort : %.17lf s\n", vet->shell);
}

void verificar(int *vet, int tam)
{   //verficar se vetores (pequenos) estao preenchidos
    printf("[");
    for(int i=0; i<tam; i++)
        printf("%d ", vet[i]);
    printf("]");
}