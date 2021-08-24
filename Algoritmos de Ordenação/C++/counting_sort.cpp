#include "extra_functions.h"

void counting_sort(int* array, int tamanho){
    int i; 
    int maior = getMaior(array,tamanho);

    int* saida = new int[tamanho]();
    int* count = new int[maior+1]();

    for (i=0; i<tamanho; i++)
        count[array[i]] += 1;

    for (i=1; i<=maior; i++)
        count[i] += count[i-1];

    for (i=tamanho-1; i>=0; i--){
        saida[count[array[i]]-1] = array[i];
        count[array[i]] -= 1;
    }    

    for (i=0; i<tamanho; i++)
        *(array+i) = *(saida+i);

    delete[] saida;
    delete[] count;
}

int main(){

    // Criação do Array de tamanho Fixo
    int tamanho = 15;
    int* array = new int[tamanho];

    // Preenchimento do array com números inteiros
    preencherArray(array, tamanho);

    printArray(array, tamanho);
    counting_sort(array, tamanho);
    printArray(array, tamanho);

    delete[] array;

    return 0;
}