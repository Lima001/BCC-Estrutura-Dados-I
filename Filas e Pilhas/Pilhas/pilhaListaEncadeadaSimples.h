#ifndef PILHA_LISTA_ENCADEADA_SIMPLES
#define PILHA_LISTA_ENCADEADA_SIMPLES

#include <assert.h>
#include "../noSimples.h"

class Pilha {

    private:

        NoSimples *primeiro;
        NoSimples *ultimo;
        int tamanho;

    public:

        Pilha():
            primeiro(nullptr), ultimo(nullptr), tamanho(0){
        }
        
        ~Pilha(){
            NoSimples *tmp = primeiro;
            
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
                NoSimples *tmp = nullptr;
                for (tmp = primeiro; tmp->proximo != ultimo; tmp = tmp->proximo);
                delete ultimo;
                ultimo = tmp;
                ultimo->proximo = nullptr;
            }

            tamanho--;

            return tmp;
        }
        
        void push(int n){
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