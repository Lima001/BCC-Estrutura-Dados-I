#ifndef PILHA_DINAMICA_ARRAY
#define PILHA_DINAMICA_ARRAY

#include <iostream>
#include <assert.h>

class Pilha {

    private:

        int tamanho;
        int ultimo;
        int* array = nullptr;

        void resize(){
            tamanho += tamanho/3;

            int* tmp = new int[tamanho];

            for (int i=0; i<=ultimo; i++)
                *(tmp+i) = *(array+i);
            
            delete array;
            array = tmp;
        }

    public:

        Pilha(int tamanho=10):
            tamanho(tamanho), ultimo(-1)
        {
            array = new int[tamanho];
        };
        
        ~Pilha(){
            if (array)
                delete[] array;
        }
        
        int pop(){
            assert(ultimo != -1);
            
            int valor = *(array+ultimo);
            
            *(array+ultimo) = 0;
            ultimo--;

            return valor;
        }
        
        void push(int valor){
            if (ultimo == tamanho-1)
                resize();

            ultimo++;
            *(array+ultimo) = valor;

            return;
        }

        void print(){
            for (int i=0; i<=ultimo; i++)
                std::cout << *(array+i) << std::endl;
        }
};

#endif