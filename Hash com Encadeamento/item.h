#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {

    public:

        std::string chave;
        int valor;
        Item* proximo;

        Item():
            chave(""), valor(0), proximo(nullptr){
        }

        Item(std::string chave, int valor):
            chave(chave), valor(valor), proximo(nullptr){
        }
        
        friend std::ostream& operator<<(std::ostream &out, const Item &i){
            out << "(" << i.chave << ": " << i.valor << ")\n"
                << "Meu endereço " << &i << "\n"
                << "Endereço proximo:" << i.proximo;

            return out;
        }

};

#endif