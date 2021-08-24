#ifndef NO_H
#define NO_H

#include <iostream>

class No {

    public:

        int valor;
        No* esquerda;
        No* direita;

        No():
            valor(0), esquerda(nullptr), direita(nullptr) {
        }
        
        No(int valor):
            valor(valor), esquerda(nullptr), direita(nullptr) {
        }

        No(int valor, No* esquerda, No* direita):
            valor(valor), esquerda(esquerda), direita(direita) {
        }

        friend std::ostream& operator<<(std::ostream &out, const No &no){
            out << "Meu End. " << &no << "\n"
                << "Meu valor: " << no.valor << "\n" 
                << "End. Esquerda: " << no.esquerda << "\n"
                << "End. Direita: " << no.direita << std::endl;
            
            return out;
        }

};

#endif