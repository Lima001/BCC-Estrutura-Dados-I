#ifndef PILHA_LISTA_ENCADEADA_DUPLA
#define PILHA_LISTA_ENCADEADA_DUPLA

#include <assert.h>
#include "../noDuplo.h"

class Pilha {

    private:

        NoDuplo *primeiro;
        NoDuplo *ultimo;
        int tamanho;

    public:

        Pilha():
            primeiro(nullptr), ultimo(nullptr), tamanho(0){
        }
        
        ~Pilha(){
            NoDuplo *tmp = primeiro;
            
            while (tmp){
                tmp = tmp->proximo;
                delete primeiro;
                primeiro = tmp;
            }
        }
        
        int pop(){
            int tmp = ultimo->valor;

            if (primeiro == ultimo){
                delete ultimo;
                primeiro = ultimo = nullptr;
            }

            else {
                NoDuplo *tmp = nullptr;
                tmp = ultimo;
                ultimo = ultimo->anterior;
                ultimo->proximo = nullptr;
                delete tmp;
            }

            tamanho--;

            return tmp;
        }
        
        void push(int n){
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