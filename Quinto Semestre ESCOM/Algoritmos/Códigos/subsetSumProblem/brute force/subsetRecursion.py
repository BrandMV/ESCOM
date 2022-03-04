

def esSumaConjunto(conjunto, n, sum):
    #*Casos base
        if( sum == 0 ):
            return True
        if( sum < 0 or (n == 0 and sum != 0) ):
            return False

    #* Si el último elemento es mayor a la suma que estamos verificando se ignora
    if (conjunto[n - 1] > sum):
        return esSumaConjunto(conjunto, n - 1, sum)

    #* La primera opciòn es no incluirlo, la segunda es incluirlo
    return esSumaConjunto(
        set, n-1, sum) or esSumaConjunto(
        set, n-1, sum-conjunto[n-1])

conjunto = [2,6,4,8]
sum = 10
n = len(conjunto)
if (esSumaConjunto(conjunto, n, sum) == True):
    print("Se encontro un subconjunto con la suma dada")
else:
    print("Se encontro un subconjunto con la suma dado")
