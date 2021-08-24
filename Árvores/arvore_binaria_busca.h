#ifndef ARVORE_BINARIA_DE_BUSCA_H
#define ARVORE_BINARIA_DE_BUSCA_H

#include <assert.h>
#include "no.h"

class ArvoreBinariaDeBusca {

    public:

        No* raiz;

        ArvoreBinariaDeBusca():
            raiz(nullptr) {
        }

        ~ArvoreBinariaDeBusca(){
            if (raiz){
                apagar_arvore(raiz);
                raiz = nullptr;
            }
        }

        void inserir(int valor){
            No *tmp = raiz;
            No *pai = nullptr;

            while (tmp){
                pai = tmp;
                
                if (valor < tmp->valor)
                    tmp = tmp->esquerda;
                else
                    tmp = tmp->direita;
            }

            if (!raiz)
                raiz = new No(valor);
            else if (valor < pai->valor)
                pai->esquerda = new No(valor);
            else
                pai->direita = new No(valor);
        }

        void remover(int valor){
            No* tmp = raiz;
            No* pai;

            while (tmp->valor != valor){
                pai = tmp;
                
                if (valor <= tmp->valor)
                    tmp = tmp->esquerda;
                else
                    tmp = tmp->direita;
            }

            if (tmp && tmp->valor == valor){
                if (tmp == raiz)
                    remover_auxiliar(raiz, pai);

                else if (pai->esquerda == tmp)
                    remover_auxiliar(tmp, pai);

                else 
                    remover_auxiliar(tmp, pai);
            }

            else if (raiz)
                std::cout << "Elemento inexistente na Árvore" << std::endl;
            else 
                std::cout << "Árvore vazia!" << std::endl;
        }

        No* buscar_no(int valor){
            No* tmp = raiz;

            while (tmp) {
                if (valor == tmp->valor)
                    return tmp;
                else if (valor < tmp->valor)
                    tmp = tmp->esquerda;
                else
                    tmp = tmp->direita;
            }

            return nullptr;
        }

        bool verificar_valor(int valor){
            No* tmp = buscar_no(valor);

            if (tmp)
                return true;

            return false;
        }

        void exibir_pre_ordem(No* no){
            if (no){
                std::cout << *no << std::endl;
                
                exibir_pre_ordem(no->esquerda);
                exibir_pre_ordem(no->direita);
            }
        }

        void exibir_pos_ordem(No* no){
            if (no){
                exibir_pos_ordem(no->esquerda);
                exibir_pos_ordem(no->direita);

                std::cout << *no << std::endl;
            }
        }

        void exibir_em_ordem(No* no){
            if (no){
                exibir_em_ordem(no->esquerda);
                std::cout << no->valor << " ";
                exibir_em_ordem(no->direita);
            }
        }

    private:

        void remover_auxiliar(No* filho, No* pai){
            No* tmp = filho;
            
            if (!filho->esquerda || !filho->direita) {
                if (pai->esquerda == filho)
                    pai->esquerda = filho->direita;
                else
                    pai->direita = filho->esquerda;

                delete tmp;
            }
            else {
                No* pai_tmp = tmp;
                tmp = tmp->esquerda;

                while (tmp->direita){
                    pai_tmp = tmp;
                    tmp = tmp->direita;
                }
                
                filho->valor = tmp->valor;
                remover_auxiliar(tmp, pai_tmp);
            }
        }

        void apagar_arvore(No* no){
            if (no){
                apagar_arvore(no->esquerda);
                apagar_arvore(no->direita);
                
                delete no;
            }
        }
};

#endif