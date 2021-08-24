/*
    Funções extras que auxiliam na implementação do MergeSort externo e também
    na implementação de testes
*/

#ifndef FUNC_EXTRA
#define FUNC_EXTRA

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "pagina.h"

void criarArquivoPreenchido(const char* nome, int quantidade_elementos, int valor_maximo=1000){
    std::fstream arquivo;

    arquivo.open(nome, std::ios::out);

    srand(time(NULL));
    
    for (int i=0; i<quantidade_elementos; i++){
        arquivo << rand()%valor_maximo + 1;

        if (i != quantidade_elementos-1)
            arquivo << "\n"; 
    }

    arquivo.close();
}

/* 
    Divide um arquivo em Páginas cujo tamanho inicial possibilita que até 3 páginas
    carreguem seus dados na memória principal
*/
Pagina* dividirArquivoPaginas(const std::string &nome, int tamanho_pagina, int qtd_paginas=5){
    int i, j;

    Pagina* paginas = new Pagina[qtd_paginas];

    std::fstream arquivo;
    std::fstream pagina;

    arquivo.open(nome, std::ios::in);
    
    for (j=1; j<=qtd_paginas; j++){
        std::string nom_pagina = "Pagina" + std::to_string(j) + ".txt";

        Pagina p = Pagina(nom_pagina, 0);

        pagina.open(nom_pagina, std::ios::out);
        
        for (i=0; i<tamanho_pagina && !arquivo.eof(); i++){
            char linha[100];
            
            arquivo >> linha;
            pagina << linha;

            if (i != tamanho_pagina-1)
                pagina << "\n";

            p.tamanho++;
        }
        paginas[j-1] = p;
        
        pagina.close();
    }

    arquivo.close();

    return paginas;
}

void salvarDados(const std::string &nome, int* array, int tamanho, std::ios_base::openmode modo=std::ios::out){
    std::fstream arquivo;
    arquivo.open(nome, modo);

    for (int i=0; i<tamanho; i++){
        arquivo << *(array+i);
        arquivo << "\n";
    }
}

#endif