// PRECISA REVER

#include "extra_functions.h"

int partition(int* array, int inicio, int fim){
    int pivo = *(array+inicio);
    
    *(array+inicio) = *(array+fim);
    *(array+fim) = pivo;
    
    int i=inicio, j=inicio;
    int temp;
    
    for (j; j<fim; j++){
        
        if (*(array+j) < pivo){
            
            temp = *(array+j);
            *(array+j) = *(array+i);
            *(array+i) = temp;

            i++;
        }
    }

    *(array+fim) = *(array+i);
    *(array+i) = pivo;

    return i;
}

void divide(int* array, int inicio, int fim){
    if (inicio < fim){

        int pos_pivo = partition(array, inicio, fim);

        divide(array, inicio, pos_pivo-1);
        divide(array, pos_pivo+1, fim);

    }
}

void quick_sort(int* array, int tamanho){
    divide(array, 0, tamanho-1);
}

int main(){

    // Criação do Array de tamanho Fixo
    int tamanho = 15;
    int* array = new int[tamanho];

    // Preenchimento do array com números inteiros
    preencherArray(array, tamanho);

    printArray(array, tamanho);
    quick_sort(array, tamanho);
    printArray(array, tamanho);

    delete[] array;

    return 0;
}