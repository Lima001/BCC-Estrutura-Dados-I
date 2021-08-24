//#include "pilhaDinamicaArray.h"
#include "pilhaEstaticaArray.h"
//#include "pilhaListaEncadeadaSimples.h"
//#include "pilhaListaEncadeadaDupla.h"

using namespace std;

int main(){

    // Pilha p;         // Usar com as pilhas implementadas usando lista encadadea
    Pilha p = Pilha(4); // Usar com as pilhas implementadas usando array 

    //p.pop();      // Não é permitido - Pilha sem elementos não pode chamar pop(). Programa deve ser abortado
    p.push(1);      // 1
    p.push(2);      // 1 2
    p.push(3);      // 1 2 3
    p.push(4);      // 1 2 3 4
    //p.push(5);    // 1 2 3 4 5    // Usar somente com pilha de tamanho dinâmico

    p.print();
    cout << endl;

    //cout << "Pop: " << p.pop() << endl;     // 5    // Usar somente com pilha de tamanho dinâmico
    cout << "Pop: " << p.pop() << endl;     // 4
    cout << "Pop: " << p.pop() << endl;     // 3
    cout << "Pop: " << p.pop() << endl;     // 2
    cout << "Pop: " << p.pop() << endl;     // 1

}