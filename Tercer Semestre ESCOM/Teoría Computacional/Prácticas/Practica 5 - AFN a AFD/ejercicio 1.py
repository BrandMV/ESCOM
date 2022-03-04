from itertools import chain, combinations
def powerset(iterable):
    s=list(iterable)
    return chain.from_iterable(
            combinations(s,r)
            for r in range(len(s)+1))

#def afd(sigma, DELTA, DELTAprima, sprima, )

#print(list(powerset(['q0','q1','q2'])))

Q=['q0','q1']
Sigma=['a','b']
s='q0'
F=['q1']

DELTA={ ('q0','a'):['q0','q1'],
        ('q0','b'):['q1'],
        ('q1','b'):['q0','q1']
        }

Qprima=list(powerset(Q))
sprima=(s,) #tupla con q0
Sigmaprima=Sigma
Fprima=[]

for q in Qprima:
    for x in q:
        if x in F:
            Fprima.append(q)
print("Qprima",Qprima)
print("Fprima", Fprima)

    #desarrollar delta prima recorrer qprima y sigma

def conver(Qprima,Sigmaprima, DELTA,DELTAprima, e):
    for x in Qprima:
        for y in Sigmaprima:
            e=[]
            for z in x:
                if(DELTA.__contains__((z,y))):
                    for w in DELTA[(z,y)]:
                        if w not in e:
                            e.append(w)
            e.sort()
            DELTAprima[(x,y)]=tuple(e)
    return DELTAprima;
  
DELTAprima ={}
e=[]
print("DELTAprima: ", conver(Qprima, Sigmaprima, DELTA, DELTAprima,e))

def transicion(estado,sigma):
    #print("estado=",estado,"sigma",sigma)
    estado_siguiente=DELTAprima[(estado,sigma)]
    #print("estado siguiente=",estado_siguiente)
    return estado_siguiente

Ejemplos_L=['b', 'bbb', 'aabb', 'aaa']
Ejemplos_Lc=['ba', 'baaa', 'baba', 'bababa']

for w in Ejemplos_L:
    estado=sprima
    for Sigmaprima in w:
        estado=transicion(estado,Sigmaprima)
        
    if estado in Fprima:
        print(w, "es aceptada")
    else:
        print(w, "no es aceptada")

for w in Ejemplos_Lc:
    estado=sprima
    for Sigmaprima in w:
        estado=transicion(estado,Sigmaprima)

    if estado in Fprima:
        print(w, "es aceptada")
    else:
        print(w, "no es aceptada")
