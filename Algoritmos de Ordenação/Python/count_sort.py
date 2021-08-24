def countsort(lista):
    saida = [0 for i in range(len(lista))]
    count = [0 for i in range(max(lista)+1)]
    
    for num in lista:
        count[num] += 1

    for i in range(1,len(count)):
        count[i] += count[i-1]
    
    for i in range(len(lista)-1,-1,-1):
        saida[count[lista[i]]-1] = lista[i]
        count[lista[i]] -= 1

    for i in range(len(saida)):
        lista[i] = saida[i]
    
    return

if __name__ == "__main__":
    from random import randint
    
    lista = [randint(0,1000) for i in range(15)]
    print(lista)

    countsort(lista)
    print(lista)
