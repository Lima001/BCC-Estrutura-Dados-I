#ifndef LISTA_ENCADEADE_SIMPLES_H
#define LISTA_ENCADEADE_SIMPLES_H

#include <assert.h>
#include "noSimples.h"

class ListaEncadeadaSimples {

    private:

        NoSimples *primeiro;
        NoSimples *ultimo;
        int tamanho;

        /*
            Métodos Auxiliares para processamento Interno
        */    
        void inserirNoInicio(int n){
            if (!primeiro){
                primeiro = new NoSimples(n, nullptr);
                ultimo = primeiro;
            }
            
            else {
                NoSimples *tmp = primeiro;
                primeiro = new NoSimples(n, tmp);
            }

            tamanho++;
        };

        void inserirNoMeio(NoSimples *referencia, int n){
            NoSimples *anterior = nullptr;
            
            for (anterior = primeiro; anterior != referencia; anterior = anterior->proximo);

            NoSimples *posterior = anterior->proximo;
            anterior->proximo = new NoSimples(n, posterior);
            
            tamanho++;
        };    

        void inserirNoFim(int n){
            if (!primeiro){
                inserirNoInicio(n);
            }

            else {
                NoSimples *tmp = ultimo;
                ultimo = new NoSimples(n, nullptr);
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
                NoSimples *tmp = primeiro->proximo;
                delete primeiro;
                primeiro = tmp;   
                tmp = nullptr;
            }
            tamanho--;
        };

        void removerNoMeio(NoSimples *referencia){
            NoSimples *anterior = nullptr;
            
            for (anterior = primeiro; anterior->proximo != referencia; anterior = anterior->proximo);
            
            NoSimples *posterior = referencia->proximo;
            anterior->proximo = posterior;
            
            delete referencia;
            tamanho--;
        };
        
        void removerNoFim(){
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
        };

        NoSimples* buscarPorPosicao(int posicao){
            
            NoSimples *tmp = nullptr;
            int count = 0;
            
            for (tmp = primeiro; count != posicao; tmp = tmp->proximo){
                count++;
            };
            
            return tmp;
        };

    public:

        ListaEncadeadaSimples():
            primeiro(nullptr), ultimo(nullptr), tamanho(0){
        }

        ~ListaEncadeadaSimples(){
            NoSimples *tmp = primeiro;
            
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
            NoSimples *tmp = primeiro;

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
                inserirNoMeio(buscarPorPosicao(posicao-1), valor);
        }

        void removerNo(int valor){
            
            int posicao = 0;
            bool encontrou = false;
            NoSimples *tmp = primeiro;

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
            NoSimples *tmp = primeiro;
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