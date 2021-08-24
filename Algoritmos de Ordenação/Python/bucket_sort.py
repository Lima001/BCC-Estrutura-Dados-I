from math import floor

def insertion_sort(lista):
    for i in range(1, len(lista)):
        valor = lista[i]
        j = i-1

        while j >= 0 and lista[j] > valor:
            lista[j+1] = lista[j]
            j -= 1

        lista[j+1] = valor
        
    return

def bucket_sort(lista, n=10):
    baldes = [[] for i in range(n)]

    maior = max(lista)

    for i in lista:
        #print((i*n)//maior -1)
        baldes[floor(i/maior * (n-1))].append(i)

    #print(baldes)
    for i in baldes:
        insertion_sort(i)

    lista.clear()
    for i in baldes:
        lista += i

    

if __name__ == "__main__":
    from random import randint
    
    lista = [randint(0,1000) for i in range(15)]
    print(lista)
    
    bucket_sort(lista)
    print(lista)