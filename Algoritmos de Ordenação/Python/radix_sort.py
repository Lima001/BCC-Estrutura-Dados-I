def countsort(lista, indice):
    saida = [0 for i in range(len(lista))]
    count = [0 for i in range(10)] #Precisa melhorar
    
    for num in lista:
        count[get_digito(num,indice)] += 1

    for i in range(1,len(count)):
        count[i] += count[i-1]
    
    for i in range(len(lista)-1,-1,-1):
        saida[count[get_digito(lista[i],indice)]-1] = lista[i]
        count[get_digito(lista[i],indice)] -= 1

    for i in range(len(saida)):
        lista[i] = saida[i]
    
    return

def get_digito(numero, indice):
    for i in range(indice):
        numero //= 10
    
    return numero % 10

def get_qtd_digitos(numero):
    i = 0
    
    while numero > 0:
        numero //= 10
        i += 1

    return i

def radix_sort(lista):
    qtd_digitos_max = get_qtd_digitos(max(lista))
    
    for i in range(qtd_digitos_max):
        countsort(lista,i)

    return

if __name__ == "__main__":
    from random import randint
    
    lista = [randint(0,1000) for i in range(15)]
    print(lista)
    
    radix_sort(lista)
    print(lista)