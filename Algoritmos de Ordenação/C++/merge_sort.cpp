#include "extra_functions.h"

void merge(int* array, int* copia, int inicio, int meio, int fim){
    int i = inicio;
    int j = meio+1;
    int k;

    for (k=inicio; k<=fim; k++){
        
        if (i > meio){
            *(copia+k) = *(array+j);
            j++;
        }
        
        else if (j > fim){
            *(copia+k) = *(array+i);
            i++;
        }

        else if (*(array+i) < *(array+j)){
            *(copia+k) = *(array+i);
            i++;
        }

        else{
            *(copia+k) = *(array+j);
            j++;
        }
    }

    for (int i=inicio; i<=fim; i++)
        *(array+i) = *(copia+i);
}

void divide(int* array, int* copia, int inicio, int fim){
    if (inicio < fim){
        int meio = (inicio + fim) / 2;

        divide(array, copia, inicio, meio);
        divide(array, copia, meio+1, fim);

        merge(array, copia, inicio, meio, fim);
    }
}

void merge_sort(int* array, int tamanho){
    int* copia = new int[tamanho];
    
    divide(array, copia, 0, tamanho-1);

    delete[] copia;
}

int main(){

    // Criação do Array de tamanho Fixo
    int tamanho = 15;
    int* array = new int[tamanho];

    // Preenchimento do array com números inteiros
    preencherArray(array, tamanho);

    printArray(array, tamanho);
    merge_sort(array, tamanho);
    printArray(array, tamanho);

    delete[] array;

    return 0;
}