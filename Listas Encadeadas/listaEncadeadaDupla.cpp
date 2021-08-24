#include "listaEncadeadaDupla.h"

using namespace std;

int main(){

    ListaEncadeadaDupla l;

    l.inserirNo(3);         // 3 -> x
    l.inserirNo(4);         // 3 -> 4 -> x
    l.inserirNo(2);         // 2 -> 3 -> 4 -> x
    l.inserirNo(2);         // 2 -> 2 -> 3 -> 4 -> x
    l.inserirNo(2);         // 2 -> 2 -> 2 -> 3 -> 4 -> x
    l.inserirNo(1);         // 1 -> 2 -> 2 -> 2 -> 3 -> 4 -> x
    l.inserirNo(6);         // 1 -> 2 -> 2 -> 2 -> 3 -> 4 -> 6 -> x
    l.inserirNo(3);         // 1 -> 2 -> 2 -> 2 -> 3 -> 3 -> 4 -> 6 -> x
    l.inserirNo(0);         // 0 -> 1 -> 2 -> 2 -> 2 -> 3 -> 3 -> 4 -> 6 -> x
    l.inserirNo(5);         // 0 -> 1 -> 2 -> 2 -> 2 -> 3 -> 3 -> 4 -> 5 -> 6 -> x

    l.printLista();
    cout << endl << endl;;

    l.removerNo(0);         // 1 -> 2 -> 2 -> 2 -> 3 -> 3 -> 4 -> 5 -> 6 -> x
    l.removerNo(6);         // 1 -> 2 -> 2 -> 2 -> 3 -> 3 -> 4 -> 5 -> x
    l.removerNo(3);         // 1 -> 2 -> 2 -> 2 -> 3 -> 4 -> 5 -> x
    l.removerNo(2);         // 1 -> 2 -> 2 -> 3 -> 4 -> 5 -> x
    l.removerNo(2);         // 1 -> 2 -> 3 -> 4 -> 5 -> x
    l.removerNo(4);         // 1 -> 2 -> 3 -> 5 -> x

    l.printLista();
    cout << endl;

    cout << l[1] << endl;                               // 2
    cout << "Tamanho: " << l.getTamanho() << endl;      // Tamanho: 4*/

    return 0;
}