from itertools import chain, combinations
def powerset(iterable):
    s=list(iterable)
    return chain.from_iterable(
            combinations(s,r)
            for r in range(len(s)+1))
Q=['q0','q1','q2','q3','q4']
Sigma=['a','b']
s='q0'
F=['q2','q4']
DELTA={ ('q0','a'):['q0','q3'],
        ('q0','b'):['q0','q1'],
        ('q1','b'):['q2'],
        ('q2','a'):['q2'],
        ('q2','b'):['q2'],
        ('q3','a'):['q4'],
        ('q4','a'):['q4'],
        ('q4','b'):['q4']
        }
print("DELTA", DELTA)
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

"""DELTAprima ={}
for q in Qprima:
    for s in Sigmaprima:
        estados_destino=[]
        for x in q:
            if (x,s) in DELTA.keys():
                for r in DELTA[(x,s)]:
                    if r not in estados_destino:
                        estados_destino.append(r)
        estados_destino.sort()
      #  print((q,s),estados_destino)
        DELTAprima[(q,s)]=tuple(estados_destino)
#print("DELTA PRIMA", DELTAprima)"""

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
print("DELTAprima", conver(Qprima, Sigmaprima, DELTA, DELTAprima, e))


def transicion(estado,sigma):
    #print("estado=",estado,"sigma",sigma)
    estado_siguiente=DELTAprima[(estado,sigma)]
    #print("estado siguiente=",estado_siguiente)
    return estado_siguiente

#L=[Cadenas que contengan la subcadena aa, bb o ambas]
Ejemplos_L=['aa', 'bb', 'aabb', 'abba']
Ejemplos_Lc=['ba', 'abab', 'aba', 'b']

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
