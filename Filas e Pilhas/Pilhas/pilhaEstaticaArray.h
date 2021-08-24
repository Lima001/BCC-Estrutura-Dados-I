#ifndef PILHA_ESTATICA_ARRAY
#define PILHA_ESTATICA_ARRAY

#include <iostream>
#include <assert.h>

class Pilha {

    private:

        int tamanho;
        int ultimo;
        int* array = nullptr;

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
            assert(ultimo != tamanho-1);
            
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