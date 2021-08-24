def quick_sort(lista):
    divide(lista, 0, len(lista)-1)

def divide(lista, inicio, fim):
    if inicio < fim:
        
        pos_pivo = particionar(lista, inicio, fim)
        
        divide(lista, inicio, pos_pivo-1)
        divide(lista, pos_pivo+1, fim)

def particionar(lista, inicio, fim):
    pivo = lista[inicio]
    i = inicio+1
    j = fim

    executar =True
    while executar:

        while i <= j and lista[i] <= pivo:
            i = i + 1

        while lista[j] >= pivo and j >= i:
            j = j -1

        if j < i:
            executar = False
        else:
            lista[i], lista[j] = lista[j], lista[i]

    lista[inicio], lista[j] = lista[j], lista[inicio]

    return j


if __name__ == "__main__":
    from random import randint
    
    lista = [randint(-500,500) for i in range(15)]
    print(lista)

    quick_sort(lista)
    print(lista)
