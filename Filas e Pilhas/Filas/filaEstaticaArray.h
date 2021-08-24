#ifndef FILA_ESTATICA_ARRAY
#define FILA_ESTATICA_ARRAY

#include <assert.h>
#include <iostream>

class Fila {

    private:

        int* array = nullptr;
        int tamanho;
        int qtd_alocado;
        int primeiro;
        int ultimo;

    public:

        Fila(int tamanho=10):
            tamanho(tamanho), qtd_alocado(0), primeiro(-1), ultimo(-1)
        {
            array = new int[tamanho];
        }

        ~Fila(){
            if (array)
                delete[] array;
        }

        void enqueue(int n){
            assert(qtd_alocado != tamanho);

            if (ultimo == tamanho-1 || ultimo == -1){
                *(array) = n;
                ultimo = 0;

                if (primeiro == -1)
                    primeiro = 0;
            }

            else {
                ultimo++;
                *(array+ultimo) = n;
            }

            qtd_alocado++;
        }

        int dequeue(){
            assert(qtd_alocado != 0);
            
            int tmp = *(array+primeiro);
            *(array+primeiro) = 0;

            if (primeiro == ultimo){
                primeiro = -1;
                ultimo = -1;
            }
            
            else if (primeiro == tamanho-1)
                primeiro = 0;

            else
                primeiro++;

            tamanho--;
            qtd_alocado--;

            return tmp;
        }

        void print(){
            for (int i=primeiro; (i<=ultimo && i<tamanho); i++)
                std::cout << *(array+i) << std::endl;

            for (int i=0; i<primeiro; i++)
                std::cout << *(array+i) << std::endl;
        }
};

#endif