#ifndef LISTA_ENCADEADE_DUPLA_H
#define LISTA_ENCADEADE_DUPLA_H

#include <assert.h>
#include "noDuplo.h"

class ListaEncadeadaDupla {

    private:

        NoDuplo *primeiro;
        NoDuplo *ultimo;
        int tamanho;


        /*
            Métodos Auxiliares para processamento Interno
        */
        void inserirNoInicio(int n){
            if (!primeiro){
                primeiro = new NoDuplo(n, nullptr, nullptr);
                ultimo = primeiro;
            }
            
            else {
                NoDuplo *tmp = primeiro;
                primeiro = new NoDuplo(n, tmp, nullptr);
                tmp->anterior = primeiro;
            }

            tamanho++;
        };

        void inserirNoMeio(NoDuplo *referencia, int n){
            NoDuplo *anterior = referencia->anterior;
            
            anterior->proximo = new NoDuplo(n, referencia, anterior);
            referencia->anterior = anterior->proximo;
            
            tamanho++;
        };    

        void inserirNoFim(int n){
            if (!primeiro){
                inserirNoInicio(n);
            }

            else {
                NoDuplo *tmp = ultimo;
                ultimo = new NoDuplo(n, nullptr, tmp);
                tmp->proximo = ultimo;
            }
            tamanho++;
        };

        void removerNoInicio(){
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
            tamanho--;
        };

        void removerNoMeio(NoDuplo *referencia){
            NoDuplo *anterior = referencia->anterior;
            NoDuplo *posterior = referencia->proximo;
            
            anterior->proximo = posterior;
            posterior->anterior = anterior;
            
            delete referencia;
            tamanho--;
        };
        
        void removerNoFim(){
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
        };


        NoDuplo* buscarPorPosicao(int posicao){

            NoDuplo *tmp = nullptr;
            int count = 0;
            
            for (tmp = primeiro; count != posicao; tmp = tmp->proximo){
                count++;
            };
            
            return tmp;
        };

    
    public:

        ListaEncadeadaDupla():
            primeiro(nullptr), ultimo(nullptr), tamanho(0){
        }

        ~ListaEncadeadaDupla(){
            NoDuplo *tmp = primeiro;
            
            while (tmp){
                tmp = tmp->proximo;
                delete primeiro;
                primeiro = tmp;
            }
        }

        /*
            Operações na Lista - Métodos chamados pelo Usuário
        */
        void inserirNo(int valor){
            if (!primeiro){
                inserirNoInicio(valor);
                return;
            }
            
            int posicao = 0;
            NoDuplo *tmp = primeiro;

            while (tmp){
                
                if (tmp->valor > valor){
                    break;
                }
                
                else {
                    tmp = tmp->proximo;
                    posicao++;
                }
            }

            if (posicao == 0)
                inserirNoInicio(valor);

            else if (posicao == tamanho)
                inserirNoFim(valor);
            
            else
                inserirNoMeio(buscarPorPosicao(posicao), valor);
        }

        void removerNo(int valor){
            
            int posicao = 0;
            bool encontrou = false;
            NoDuplo *tmp = primeiro;

            while (tmp){
                if (tmp->valor == valor){
                    encontrou = true;
                    break;
                }
                else {
                    tmp = tmp->proximo;
                    posicao++;
                }
            }

            assert(encontrou);

            if (posicao == 0)
                removerNoInicio();

            else if (posicao == tamanho-1)
                removerNoFim();

            else 
                removerNoMeio(buscarPorPosicao(posicao));
        }

        int getTamanho(){
            return tamanho;
        }

        void printLista(){
            NoDuplo *tmp = primeiro;
            int count = 0;

            while (tmp){
                std::cout << "[" << count << "]\n" << *tmp << "\n\n";
                tmp = tmp->proximo;
                count++;
            }
        }

        // Sobrescrita do Operador [] para Simular acesso Indexado na Lista
        int operator[](int index){
            return buscarPorPosicao(index)->valor;
        }
};

#endif