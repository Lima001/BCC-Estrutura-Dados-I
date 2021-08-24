def insertion_sort(lista):
    for i in range(1, len(lista)):
        valor = lista[i]
        j = i-1

        while j >= 0 and lista[j] > valor:
            lista[j+1] = lista[j]
            j -= 1

        lista[j+1] = valor
        
    return

if __name__ == "__main__":
    from random import randint
    
    lista = [randint(-500,500) for i in range(15)]
    print(lista)
    
    insertion_sort(lista)
    print(lista)