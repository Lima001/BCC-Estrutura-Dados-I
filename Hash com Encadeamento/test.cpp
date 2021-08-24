#include <iostream>
#include "hashTable.h"

int main(){

    HashTable t;

    std::string chaves[] = {"A", "B", "C", "AB"};
    int valores[] = {10, 20, 30, 100};

    for (int i=0; i<4; i++)
        t.inserir(chaves[i], valores[i]);

    std::cout << t.buscar("A") << "; ";
    std::cout << t.buscar("C") << "; ";
    std::cout << t.buscar("AB") << std::endl;

    std::cout << "1º -----------------------" << std::endl;
    t.print();
    std::cout << std::endl;

    t.inserir("C", 40);
    t.remover("A");
    t.remover("AB");

    std::cout << "2º -----------------------" << std::endl;
    t.print();
    std::cout << std::endl;

    t.remover("B");

    std::cout << "3º -----------------------" << std::endl;
    t.print();


    return 0;
}