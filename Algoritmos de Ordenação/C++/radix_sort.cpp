#include "extra_functions.h"

int get_digito(int numero, int indice){
    for (int i=0; i<indice; i++)
        numero /= 10;

    return numero % 10;   
}

int get_qtd_digitos(int numero){
    int i = 0;
    
    while (numero > 0){
        numero /= 10;
        i++;
    }

    return i;
}

void counting_sort(int* array, int tamanho, int indice){
    int i; 

    int* saida = new int[tamanho]();
    int* count = new int[10]();

    for (i=0; i<tamanho; i++)
        count[get_digito(array[i], indice)] += 1;

    for (i=1; i<10; i++)
        count[i] += count[i-1];

    for (i=tamanho-1; i>=0; i--){
        saida[count[get_digito(array[i], indice)]-1] = array[i];
        count[get_digito(array[i], indice)] -= 1;
    }    

    for (i=0; i<tamanho; i++)
        *(array+i) = *(saida+i);

    delete[] saida;
    delete[] count;
}

void radix_sort(int* array, int tamanho){
    int qtd_digitos_max = get_qtd_digitos(getMaior(array, tamanho));
    
    for (int i=0; i<qtd_digitos_max; i++)
        counting_sort(array, tamanho, i);
}

int main(){

    // Criação do Array de tamanho Fixo
    int tamanho = 15;
    int* array = new int[tamanho];

    // Preenchimento do array com números inteiros
    preencherArray(array, tamanho);

    printArray(array, tamanho);
    radix_sort(array, tamanho);
    printArray(array, tamanho);

    delete[] array;

    return 0;
}