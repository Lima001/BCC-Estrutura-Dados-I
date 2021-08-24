#include "arvore_binaria_busca.h"

int main(){

    int array[10] = {15, 0, 44, 3, 21, 12, 44, 8, 93, 10};

    ArvoreBinariaDeBusca abb;

    for (int i=0; i<10; i++)
        abb.inserir(array[i]);

    abb.exibir_em_ordem(abb.raiz);
    //abb.exibir_pos_ordem(abb.raiz);
    //abb.exibir_pre_ordem(abb.raiz);
    std::cout << std::endl;

    abb.remover(10);
    abb.remover(0);
    abb.remover(12);
    abb.remover(44);
    abb.remover(15);

    abb.exibir_em_ordem(abb.raiz);
    std::cout << std::endl;

    std::cout << abb.raiz->valor << std::endl;

    std::cout << *abb.buscar_no(8) << std::endl;
    std::cout<< *abb.buscar_no(44) << std::endl;

    return 0;
}