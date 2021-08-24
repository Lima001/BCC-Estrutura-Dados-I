#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TAMANHO_MAX 100

#include <assert.h>
#include "item.h"

class HashTable {

    private:

        int preenchido;
        Item** itens;

    
        int funcao_hash(const std::string &chave){
            int valor = 0;

            // Função Hash melhor
            /*for (int i=0; i<chave.length(); i++)
                valor += int(chave[i])*(i+1);

            return valor % TAMANHO_MAX;*/

            // Cálculo simples para causar colisão e visualizar o tratamento a esses casos
            return chave.length() % TAMANHO_MAX;
        }
    
    public:

        HashTable():
            preenchido(0) {

                itens = new Item*[TAMANHO_MAX];

                for (int i=0; i<TAMANHO_MAX; i++)
                    itens[i] = nullptr;
        }

        ~HashTable(){
            Item* tmp;
            Item* deletar;
            
            for (int i=0; i<TAMANHO_MAX; i++){

                if (itens[i]){
                    tmp = itens[i];
                    
                    while (tmp){
                        deletar = tmp;
                        tmp = tmp->proximo;
                        delete deletar; 
                    }
                }
            }
        
            delete[] itens;
        }

        void inserir(std::string chave, int valor){
            int posicao = funcao_hash(chave);

            if (!itens[posicao]){
                itens[posicao] = new Item(chave, valor);
                preenchido++;
            }
            else {
                Item* tmp = itens[posicao];

                while (tmp->chave != chave && tmp->proximo)
                        tmp = tmp->proximo;
                 
                if (tmp->chave == chave)
                    tmp->valor = valor;
                else
                    tmp->proximo = new Item(chave, valor);
            }
        }

        int buscar(std::string chave){
            int posicao = funcao_hash(chave);
            
            Item* tmp = itens[posicao];

            while (tmp->chave != chave && tmp->proximo)
                    tmp = tmp->proximo;
                
            assert(tmp->chave == chave);
            return tmp->valor;
        }

        void remover(std::string chave){
            int posicao = funcao_hash(chave);

            if (!itens[posicao])
                std::cout << "Chave inexistente" << std::endl;
            
            else {
                Item* tmp = itens[posicao];

                if (tmp->chave == chave){
                    itens[posicao] = tmp->proximo;
                    delete tmp;
                    preenchido--;
                }
                else {
                    while (tmp->proximo && tmp->proximo->chave != chave)
                        tmp = tmp->proximo;

                    if (!tmp->proximo)
                        std::cout << "Chave inexistente" << std::endl;
                    
                    else {
                        Item* deletar = tmp->proximo;
                        tmp->proximo = tmp->proximo->proximo;
                        delete deletar;
                    }
                }
            }
        }

        bool verificarChave(std::string chave){
            int posicao = funcao_hash(chave);
            
            Item* tmp = itens[posicao];

            while (tmp->chave != chave && tmp->proximo)
                    tmp = tmp->proximo;

            return tmp->chave == chave;
        }

        bool verificar_lotado(){
            return preenchido < TAMANHO_MAX;
        }

        void print(){
            Item* tmp;
            
            for (int i=0; i<TAMANHO_MAX; i++){

                if (itens[i]){
                    tmp = itens[i];
                    
                    while (tmp){
                        std::cout << *tmp << std::endl;
                        tmp = tmp->proximo; 
                    }
                }
            }
        }
};

#endif