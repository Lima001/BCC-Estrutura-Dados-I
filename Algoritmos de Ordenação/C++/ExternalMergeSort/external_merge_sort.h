/*
    Implementação do Algoritmo de Ordenação Externa
*/

#include "quick_sort.h"
#include "insertion_sort.h"

// Definição de um tipo de dados para representar ponteiros para funções de ordenação interna
typedef void (*FUNC_PTR)(Pagina*);

// Definição de variáveis para referir-se às funções de ordenação interna
FUNC_PTR quick = quick_sort;
FUNC_PTR insertion = insertion_sort;

/*
    Função para juntar duas páginas em uma só - Produz um novo arquivo
    com a junção dos dados das duas páginas ordendados
*/
void mergeFiles(Pagina* p1, Pagina* p2, const std::string nome){
    // Cria uma Nova página para o arquivo resultante do Merge
    Pagina sorted = Pagina(nome, p1->tamanho);
    sorted.iniciar_array();
    
    // Carrega os dados inicias das duas páginas que serão mescladas
    p1->carregarDados();
    p2->carregarDados();

    int i=0, j=0, k=0;

    // Enquanto tiver dados nos arquivos que serão mesclados...
    while (p1->marcacao < p1->tamanho || p2->marcacao < p2->tamanho){
        
        // Se a quantidade de elemtos no array ordenado é igual a capacidade
        // Total de uma página, salvar dados no novo arquivo
        if (k == MEMORIA_TOTAL){
            salvarDados(nome, sorted.array, k, std::ios::app);
            k = 0;
        }

        // Se o array da página 1 tiver sido esvaziado, carregar dados restantes
        if (i == MEMORIA_TOTAL){
            p1->carregarDados();
            i = 0;
        }

        // Se o array da página 2 tiver sido esvaziado, carregar dados restantes
        if (j == MEMORIA_TOTAL){
            p2->carregarDados();
            j = 0;
        }
        
        // Salvar no array ordenado os dados em ordem crescente, processo similar
        // ao que ocorre na etapa de merge do MergeSort Interno 

        if (p1->marcacao == p1->tamanho){
            sorted.array[k] = p2->array[j];
            j++;
            p2->marcacao++;
        }

        else if (p2->marcacao == p2->tamanho){
            sorted.array[k] = p1->array[i];
            i++;
            p1->marcacao++;
        }

        else if (p1->array[i] < p2->array[j]){
            sorted.array[k] = p1->array[i];
            i++;
            p1->marcacao++;
        }

        else {
            sorted.array[k] = p2->array[j];
            j++;
            p2->marcacao++;
        }
        
        k++;
    }
    // Salvar eventuais dados restantes do array ordenado no arquivo de saída
    salvarDados(nome, sorted.array, k, std::ios::app);
}

// Função principal que deve ser chamada para ordenar um arquivo
// Cria um arquivo chamado "Saida.txt" ordenado crescentemente
void externalMergeSort(const char* nome_arquivo, int tamanho_pagina, int qtd_paginas=5, FUNC_PTR sort=quick){

    // Cria as páginas inicias - No contexto da availiação sempre serão 5
    Pagina* array_paginas = dividirArquivoPaginas(nome_arquivo, tamanho_pagina, qtd_paginas);

    // Ordena cada página individualmente carregando os dados de uma por vez na memória principal
    for (int i=0; i<qtd_paginas; i++)
        // Usa o algoritmo de ordenação especificado via parâmetro - Padrão: QuickSort
        sort(&array_paginas[i]);
    
    // Dados necessários caso a quantidade de páginas seja ímpar
    bool impar = false;
    int meio;
    if (qtd_paginas % 2 == 1){
        impar = true;
        meio = qtd_paginas/2;
    }

    int runs = qtd_paginas;
    int tamanho;

    while (runs != 1){

        // Ordena páginas em conjunto de dois
        // Sempre pega a página na posição i e n-i
        // Sendo:
        //      i um inteiro que vai até quantidade de páginas / 2
        //      n a quantidade total de páginas
        for (int i=0; i<runs/2; i++){
            std::string nome = "Pagina" + std::to_string(++qtd_paginas) + ".txt"; 
            
            // Faz a Mesclagem das páginas, resultando em um arquivo de saída com os dados Ordenados
            mergeFiles(&array_paginas[i], &array_paginas[runs-i-1], nome);

            tamanho = array_paginas[i].tamanho + array_paginas[runs-i-1].tamanho;

            // Apaga as páginas que foram mescladas
            remove(array_paginas[i].endereco.c_str());
            remove(array_paginas[runs-i-1].endereco.c_str());

            // Atualiza para que a página na posição i corresponda referencie o novo arquivo ordenado criado
            array_paginas[i].limpar_array();
            array_paginas[i].endereco = nome;
            array_paginas[i].tamanho = tamanho;
        }

        runs = runs/2;
    }
    // Se for ímpar, siginifica que uma página não foi mesclada durante o laço anterior.
    // Essa página corresponde a que fica no meio do array de Páginas criado no início,
    // sendo que precisamos mesclar seu arquivo com a última saída do laço de repetição
    // executado anteriormente
    if (impar){
        // Mesclagem e criação do arquivo de saída com todos os dados ordenados
        mergeFiles(&array_paginas[0], &array_paginas[meio], "Saida.txt");
        
        // Remoção das páginas restantes utilizadas para composição do arquivo final
        remove(array_paginas[0].endereco.c_str());
        remove(array_paginas[meio].endereco.c_str());
    }
    // Se for par, todas as páginas já foram mescladas em um único arquivo ordenado
    else
        // Renomeia a última saída do laço de repetição anterior para o padrão definido pelo método 
        rename(array_paginas[0].endereco.c_str(), "Saida.txt");
    

    // Desaloca a memória necessária para os objetos pagina
    delete[] array_paginas;
}