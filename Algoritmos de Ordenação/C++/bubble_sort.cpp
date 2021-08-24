#include <random>
#include "extra_functions.h"

void bubble_sort(int* array, int tamanho){
    int i,j;
    bool trocou = false;

    for (i=0; i<tamanho-1; i++){

        for (j=0; j<tamanho-1-i; j++){
            if (*(array+j) > *(array+j+1)){

                *(array+j) += *(array+j+1);
                *(array+j+1) = *(array+j) - *(array+j+1);
                *(array+j) -= *(array+j+1);

                trocou = true;
            }
        }

        if (!trocou)
            break;
    }

    return;
}

int main(){

    // Criação do Array de tamanho Fixo
    int tamanho = 15;
    int* array = new int[tamanho];

    // Preenchimento do array com números inteiros
    preencherArray(array, tamanho);

    printArray(array, tamanho);
    bubble_sort(array, tamanho);
    printArray(array, tamanho);

    delete[] array;

    return 0;
}