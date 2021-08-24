// Implementação do InsertionSort para orendeção em memória principal

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "funcoes_extras.h"
#include "pagina.h"

void insertion_sort(Pagina* pag){
    // Carrega os dados do arquivo referenciado pela página na memória principal
    pag->carregarDados();
    int i, j, valor;

    for (i=1; i<pag->tamanho; i++){
        valor = *(pag->array+i);
        j = i-1;

        while (j >= 0 && *(pag->array+j) > valor){
            *(pag->array+j+1) += *(pag->array+j);
            *(pag->array+j) = *(pag->array+j+1) - *(pag->array+j);
            *(pag->array+j+1) -= *(pag->array+j);
            j--;
        }

        *(pag->array+j+1) = valor;
    }
    // Salva todos os dados ordenados no arquivo
    salvarDados(pag->endereco, pag->array, pag->tamanho);
    // Apaga qualquer dado do arquivo que esteja na memória principal
    pag->limpar_array();
}

#endif