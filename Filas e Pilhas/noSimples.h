/*
    Classe que representa um Nó que armazena apenas uma referência
    para um Nó sucessor. Usado na Lista Encadeada Simples
*/

#ifndef NO_SIMPLES_H
#define NO_SIMPLES_H

#include <iostream>

class NoSimples {

    public:

        int valor;
        NoSimples *proximo;

        NoSimples():
            valor(0), proximo(nullptr){    
        }
        
        NoSimples(int valor, NoSimples *proximo):
            valor(valor), proximo(proximo){
        }

        // Sobrecarga do Insertion Operator para Saída de Dados 
        friend std::ostream& operator<<(std::ostream &out, const NoSimples &no){
            out << "Meu End." << &no << "\n" 
                << "Meu Valor: " << no.valor << "\n"
                << "End. Proximo: " << no.proximo;
            return out;
        }
};

#endif