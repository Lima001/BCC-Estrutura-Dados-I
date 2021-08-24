// Implementação do QuickSort para orendeção em memória principal

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "pagina.h"
#include "funcoes_extras.h"

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

void quick_sort(Pagina* pag){
    // Carrega os dados do arquivo referenciado pela página na memória principal
    pag->carregarDados();
    // Ordena os dados
    divide(pag->array, 0, pag->tamanho-1);
    // Salva todos os dados ordenados no arquivo
    salvarDados(pag->endereco, pag->array, pag->tamanho);
    // Apaga qualquer dado do arquivo que esteja na memória principal
    pag->limpar_array();
}

#endif