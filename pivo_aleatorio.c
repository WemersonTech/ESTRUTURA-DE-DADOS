//Piv� alet�rio com os marcadores de troca e compara��o: 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//Pr�totipo de vari�veis
int trocas = 0, comparacoes = 0;

//Trocar os elementos de posi��o
void troca(int vetor[], int i, int j){
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
    trocas++;
}

//Fun��o parti��o
int particiona(int vetor[], int inicio, int fim){

    int pivo = vetor[fim];
    int pivo_indice = inicio;

    for(int i = inicio; i < fim; i++){
        comparacoes++;
        if (vetor[i] <= pivo) {
            troca(vetor, i, pivo_indice);
            pivo_indice++;
        }
    }

    troca(vetor, pivo_indice, fim);

    return pivo_indice;
}

//Escolha aleat�ria do piv�
int escolherPivo(int vetor[], int inicio, int fim){
    int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
    troca(vetor, pivo_indice, fim);
    return particiona(vetor, inicio, fim);
}

void quickSort(int vetor[], int inicio, int fim){
    if(inicio < fim) {
        int pivo_indice = escolherPivo(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo_indice - 1);
        quickSort(vetor, pivo_indice + 1, fim);
    }
}

int main(){
	setlocale(LC_ALL, "Portuguese");
    int vetor[] = {72, 34, 84, 21, 5, 16, 43, 50};
    int tam_vetor = sizeof(vetor) / sizeof(int);
    clock_t ini, fim;

    srand(time(NULL));
    trocas = 0; 
    comparacoes = 0;

    ini = clock();
    quickSort(vetor, 0, tam_vetor - 1);
    fim = clock();

    for (int i = 0; i < tam_vetor; i++){
        printf("%d ", vetor[i]);
    } 
    printf("\n");

    double tempo_total = ((double) (fim - ini)) / CLOCKS_PER_SEC;
    printf("Tempo de execu��o: %f segundos, %d trocas e %d compara��es.\n", tempo_total, trocas, comparacoes);

    return 0;
}
