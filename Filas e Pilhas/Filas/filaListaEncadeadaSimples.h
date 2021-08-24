#ifndef FILA_LISTA_ENCADEADA_SIMPLES
#define FILA_LISTA_ENCADEADA_SIMPLES

#include <assert.h>
#include "../noSimples.h"

class Fila {

    private:

        NoSimples *primeiro;
        NoSimples *ultimo;
        int tamanho;

    public:

        Fila():
            primeiro(nullptr), ultimo(nullptr), tamanho(0){
        }
        
        ~Fila(){
            NoSimples *tmp = primeiro;
            
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
                NoSimples *tmp = primeiro->proximo;
                delete primeiro;
                primeiro = tmp;   
                tmp = nullptr;
            }
            
            tamanho--;

            return tmp;
        }
        
        void enqueue(int n){
            if (!primeiro){
                primeiro = new NoSimples(n, nullptr);
                ultimo = primeiro;
            }
            
            else {
               NoSimples *tmp = ultimo;
                ultimo = new NoSimples(n, nullptr);
                tmp->proximo = ultimo;
            }

            tamanho++;
        }
        
        void print(){
            NoSimples *tmp = primeiro;
            int count = 0;

            while (tmp){
                std::cout << "[" << count << "]\n" << *tmp << "\n\n";
                tmp = tmp->proximo;
                count++;
            }
        }
};

#endif