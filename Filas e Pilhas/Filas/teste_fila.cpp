//#include "filaDinamicaArray.h"
#include "filaEstaticaArray.h"
//#include "filaListaEncadeadaSimples.h"
//#include "filaListaEncadeadaDupla.h"

using namespace std;

int main(){

    //Fila f;           // Usar com as filas implementadas usando lista encadadea
    Fila f = Fila(4);   // Usar com as filas implementadas usando array 

    // p.dequeue();      // Não é permitido - fila sem elementos não pode chamar dequeue(). Programa deve ser abortado
    f.enqueue(1);       // 1
    f.enqueue(2);       // 1 2
    f.enqueue(3);       // 1 2 3
    f.enqueue(4);       // 1 2 3 4
    // f.enqueue(5);       // 1 2 3 4 5    // Usar somente com fila de tamanho dinâmico

    f.print();
    cout << endl;
    
    // cout << "Dequeue: " << f.dequeue() << endl;     // 1    // Usar somente com fila de tamanho dinâmico
    cout << "Dequeue: " << f.dequeue() << endl;     // 1 | 2 (1 se for fila estática)
    cout << "Dequeue: " << f.dequeue() << endl;     // 2 | 3
    cout << "Dequeue: " << f.dequeue() << endl;     // 3 | 4
    cout << "Dequeue: " << f.dequeue() << endl;     // 4 | 5

}