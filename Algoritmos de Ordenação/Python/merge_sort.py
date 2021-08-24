def merge_sort(lista):
    copia = [0 for i in range(len(lista))]
    divide(lista, copia, 0, len(lista)-1)
    return

def divide(lista, copia, inicio, fim):
    if inicio != fim:
        meio = (inicio+fim)//2
        
        divide(lista, copia, inicio, meio)
        divide(lista, copia, meio+1, fim)
        
        merge(lista, copia, inicio, meio, fim)

    return


def merge(lista, copia, inicio, meio, fim):
    i = inicio
    j = meio+1

    for k in range(inicio, fim+1):
        if i > meio:
            copia[k] = lista[j]
            j += 1
        
        elif j > fim:
            copia[k] = lista[i]
            i += 1

        elif lista[i] < lista[j]:
            copia[k] = lista[i]
            i += 1

        else:
            copia[k] = lista[j]
            j += 1

    for i in range(inicio, fim+1):
        lista[i] = copia[i]

    return

if __name__ == "__main__":
    from random import randint
    
    lista = [randint(-500,500) for i in range(15)]
    print(lista)
    
    merge_sort(lista)
    print(lista)