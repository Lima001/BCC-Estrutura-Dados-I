#include "definicao_memoria.h"
#include "pagina.h"
#include "quick_sort.h"
#include "insertion_sort.h"
#include "funcoes_extras.h"
#include "external_merge_sort.h"

int main(){

    // Variável para armazenar o tempo de execução de um procedimento
    clock_t tempo;

    // Quantidade de elementos na pagina
    int tamanho;              
    
    std::cin >> tamanho;

    criarArquivoPreenchido("Teste.txt", tamanho*5);

    tempo = clock();
    
    externalMergeSort("Teste.txt", tamanho, 5, insertion);
    
    tempo = clock() - tempo;
    std::cout << ((float)tempo)/CLOCKS_PER_SEC << std::endl;

    return 0;
}