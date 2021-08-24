#ifndef FILA_LISTA_ENCADEADA_DUPLA
#define FILA_LISTA_ENCADEADA_DUPLA

#include <assert.h>
#include "../noDuplo.h"

class Fila {

    private:

        NoDuplo *primeiro;
        NoDuplo *ultimo;
        int tamanho;

    public:

        Fila():
            primeiro(nullptr), ultimo(nullptr), tamanho(0){
        }
        
        ~Fila(){
            NoDuplo *tmp = primeiro;
            
            while (tmp){
                tmp = tmp->proximo;
                delete primeiro;
                primeiro = tmp;
            }
        }
        
        int dequeue(){
            int tmp = primeiro->valor;

            if (primeiro == ultimo){
                delete primeiro;
                primeiro = ultimo = nullptr;
            }
            
            else {
                NoDuplo *tmp = primeiro->proximo;
                delete primeiro;
                primeiro = tmp;
                primeiro->anterior = nullptr;   
            }

            return tmp;
        }
        
        void enqueue(int n){
            if (!primeiro){
                primeiro = new NoDuplo(n, nullptr, nullptr);
                ultimo = primeiro;
            }
            
            else {
                NoDuplo *tmp = ultimo;
                ultimo = new NoDuplo(n, nullptr, tmp);
                tmp->proximo = ultimo;
            }

            tamanho++;
        }
        
        void print(){
            NoDuplo *tmp = primeiro;
            int count = 0;

            while (tmp){
                std::cout << "[" << count << "]\n" << *tmp << "\n\n";
                tmp = tmp->proximo;
                count++;
            }
        }
};

#endif