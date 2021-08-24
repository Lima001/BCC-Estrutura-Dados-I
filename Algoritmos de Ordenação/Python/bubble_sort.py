def bubble_sort(lista):
    for i in range(len(lista)-1):
        trocou = False
        
        for j in range(len(lista)-1-i):
            if lista[j] > lista[j+1]:
                lista[j], lista[j+1] = lista[j+1], lista[j]
                trocou = True

        if not trocou:
            break
    
    return

if __name__ == "__main__":
    from random import randint
    
    lista = [randint(-500,500) for i in range(15)]
    print(lista)
    
    bubble_sort(lista)
    print(lista)