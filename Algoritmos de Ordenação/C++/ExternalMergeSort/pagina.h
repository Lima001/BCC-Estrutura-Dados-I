/* 
    Estrutura responsável por manter referência aos arquivos que estamos odernando.
    Ao executar o MergeSort Externo, um arquivo será separado em páginas e essas serão
    ordenas e posteriormente mescladas para formar um único arquivo ordenado.
*/

#include "definicao_memoria.h"
#include <fstream>
#include <iostream>
#include <string>

#ifndef PAGINA_H
#define PAGINA_H

class Pagina {

    public:
        std::string endereco;
        int marcacao;               // Em que elemento do arquivo paramos
        int tamanho;                // Quantidade de elementos no arquivo
        
        /* 
            Array onde os elementos do arquivo serão carregado. 
            
            Obs. Um arquivo pode conter mais elementos que a memória principal
            suporta. Dessa forma, apenas uma parte do arquivo é carregada ao chamar
            o método carregarDados(). Caso existam mais dados no arquivo, ao chamar
            o mesmo método novamente, os elementos que sobraram no arquivo serão carregados.
            O processo se repete até todos os elementos terem sido carregados.

            Nesse contexto que usamos a variável marcação. Ela guarda a posição no arquivo do
            último elemento carregado, para que posteriormente seja possível carregar os dados
            a partir desse ponto na memória principal visando o processamento dos dados.

            Após ter carregado todos os dados, caso deseja refazer o processo desde o início,
            é necessário invocar o método limparArray()
        */
        int* array = nullptr;       

    Pagina():
        endereco("NONE"), marcacao(0), tamanho(0){
    };
    
    Pagina(std::string endereco, int tamanho):
        endereco(endereco), marcacao(0), tamanho(tamanho){
    }

    ~Pagina(){
        if (array)
            delete[] array;
    }

    void carregarDados(){
        if (!array)
            iniciar_array();

        int i = 0, j = 0;
        std::string garbage;

        std::fstream arquivo;
        arquivo.open(endereco, std::ios::in);

        while (!arquivo.eof()){
            // MEMORIA_TOTAL -> Olhe as anotações feitas em definicao_memoria.h
            if (i == MEMORIA_TOTAL)
                break;

            if (j>=marcacao){
                arquivo >> *(array+i);
                i++;
            }

            std::getline(arquivo, garbage);
            j++;
        }
    }

    void iniciar_array(){
        array = new int[MEMORIA_TOTAL];
    }

    // Função para resetar os dados referentes ao array da página
    void limpar_array(){
        if (array){
            delete[] array;
            array = nullptr;
            marcacao = 0;
        }
    }
};

#endif