def selection_sort(lista):
    for i in range(len(lista)-1):
        menor = i

        for j in range(i+1, len(lista)):
            if lista[j] < lista[menor]:
                menor = j

        if menor != i:
            lista[i], lista[menor] = lista[menor], lista[i]

    return

if __name__ == "__main__":
    from random import randint
    
    lista = [randint(-500,500) for i in range(15)]
    print(lista)
    
    selection_sort(lista)
    print(lista)