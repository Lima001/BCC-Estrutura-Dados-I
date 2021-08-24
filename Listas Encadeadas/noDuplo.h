/*
    Classe que representa um Nó que armazena referências
    para Nós sucessor e antecessor. Usado na Lista Encadeada Dupla
*/

#ifndef NO_DUPLO_H
#define NO_DUPLO_H

#include <iostream>

class NoDuplo{

    public:

        int valor;
        NoDuplo *proximo;
        NoDuplo *anterior;

        NoDuplo():
            valor(0), proximo(nullptr), anterior(nullptr){    
        }
        
        NoDuplo(int valor, NoDuplo *proximo, NoDuplo *anterior):
            valor(valor), proximo(proximo), anterior(anterior){
        }

        // Sobrecarga do Insertion Operator para Saída de Dados 
        friend std::ostream& operator<<(std::ostream &out, const NoDuplo &no){
            out << "Meu End." << &no << "\n" 
                << "Meu Valor: " << no.valor << "\n"
                << "End. Proximo: " << no.proximo << "\n"
                << "End. Anterior: " << no.anterior;
            return out;
        }
};

#endif