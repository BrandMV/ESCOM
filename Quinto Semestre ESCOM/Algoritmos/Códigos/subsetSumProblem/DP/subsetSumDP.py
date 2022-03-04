def esSumaConjunto(conjunto, n, sum):
    #*Se crea la tabla inicializando los valores subconjunto[n+1][sum+1]
    subconjunto =([[False for i in range(sum + 1)]
            for i in range(n + 1)])
    
    #*Si la suma a buscar es 0, se regresa true
    for i in range(n + 1):
        subconjunto[i][0] = True

    #*Si la suma no es 0, pero el conjunto es vacio se regresa false
    for i in range(1, sum + 1):
        subconjunto[0][i]= False
            
    #*Se llena la tabla recorriendo la suma y los elementos del conjunto
    for i in range(1, n + 1):
        for j in range(1, sum + 1):
            #*Si el elemento actual es mayor al valor actual de la suma copiamos el valor del caso anterior
            if j<conjunto[i-1]:
                subconjunto[i][j] = subconjunto[i-1][j]
            #*Si el valor actual de la suma es mayor que el iesimo elemento
            #*hacemos or entre los casos previos y el caso de j-valor de suma actual
            if j>= conjunto[i-1]:
                subconjunto[i][j] = (subconjunto[i-1][j] or
                                subconjunto[i - 1][j-conjunto[i-1]])

    return subconjunto[n][sum]

conjunto = [2,6,4,8]
sum = 10
n = len(conjunto)
if (esSumaConjunto(conjunto, n, sum) == True):
    print("Se encontro un subconjunto con la suma dada")
else:
    print("Se encontro un subconjunto con la suma dado")


tab = [[-1 for i in range(2000)] for j in range(2000)]

def esSumaConjunto(conjunto, n, sum):

    if (sum == 0):
        return 1
    
    if (n <= 0):
        return 0

    if (tab[n - 1][sum] != -1):
        return tab[n - 1][sum]

    if (conjunto[n - 1] > sum):
        tab[n - 1][sum] = esSumaConjunto(conjunto, n - 1, sum)
        return tab[n - 1][sum]
    else:
        tab[n - 1][sum] = esSumaConjunto(conjunto, n - 1, sum)
        return tab[n - 1][sum] or esSumaConjunto(conjunto, n - 1, sum - conjunto[n - 1])

conjunto = [2,6,4,8]
sum = 10
n = len(conjunto)
if (esSumaConjunto(conjunto, n, sum) == True):
    print("Se encontro un subconjunto con la suma dada")
else:
    print("Se encontro un subconjunto con la suma dado")

