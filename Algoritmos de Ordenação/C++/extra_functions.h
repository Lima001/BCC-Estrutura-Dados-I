#include <iostream>
#include <stdlib.h>
#include <time.h>

void printArray(int* array, int tamanho){
    for (int i=0; i<tamanho; i++)
        std::cout << *(array+i) << " ";
    
    std::cout << std::endl;
}

void preencherArray(int* array, int tamanho, int max_value=1000){
    srand(time(NULL));
    
    for (int i=0; i<tamanho; i++)
        *(array+i) = rand()%max_value + 1;
}

int getMaior(int* array, int tamanho){
    int maior = *(array+0);

    for (int i=1; i<tamanho; i++){
        
        if (*(array+i) > maior)
            maior = *(array+i);
    }

    return maior;
}