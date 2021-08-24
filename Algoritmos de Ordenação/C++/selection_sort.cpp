#include <random>
#include "extra_functions.h"

void selection_sort(int* array, int tamanho){
    int i,j;
    int menor;

    for (i=0; i<tamanho-1; i++){
        menor = i;

        for (j=i+1; j<tamanho; j++){
            if (*(array+j) < *(array+menor))
                menor = j;
        }

        if (menor != i){
            *(array+i) += *(array+menor);
            *(array+menor) = *(array+i) - *(array+menor);
            *(array+i) -= *(array+menor);
        }
    }
}

int main(){

    // Criação do Array de tamanho Fixo
    int tamanho = 15;
    int* array = new int[tamanho];

    // Preenchimento do array com números inteiros
    preencherArray(array, tamanho);

    printArray(array, tamanho);
    selection_sort(array, tamanho);
    printArray(array, tamanho);

    delete[] array;

    return 0;
}