#include <random>
#include "extra_functions.h"

void insertion_sort(int* array, int tamanho){
    int i, j, valor;

    for (i=1; i<tamanho; i++){
        valor = *(array+i);
        j = i-1;

        while (j >= 0 && *(array+j) > valor){
            *(array+j+1) += *(array+j);
            *(array+j) = *(array+j+1) - *(array+j);
            *(array+j+1) -= *(array+j);
            j--;
        }

        *(array+j+1) = valor;
    }
}

int main(){

    // Criação do Array de tamanho Fixo
    int tamanho = 15;
    int* array = new int[tamanho];

    // Preenchimento do array com números inteiros
    preencherArray(array, tamanho);

    printArray(array, tamanho);
    insertion_sort(array, tamanho);
    printArray(array, tamanho);

    delete[] array;

    return 0;
}