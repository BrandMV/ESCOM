#AFD
#L(M)={cadenas que tengan un #par de b's}

Q=['q0','q1']
sigma=['a','b']
s='q0'
F=['q0']

delta= { ('q0' , 'a'):'q0',
         ('q0' , 'b'):'q1',
         ('q1' , 'a'):'q1',
         ('q1' , 'b'):'q0'
        }

Ejemplos_L=['', 'bb', 'abb', 'aaa']
Ejemplos_Lc=['b', 'ab', 'ba', 'bbb']

def transicion(estado,sigma):
    #print("estado=",estado,"sigma",sigma)
    estado_siguiente=delta[(estado,sigma)]
    #print("estado siguiente=",estado_siguiente)
    return estado_siguiente

#w='baab'

for w in Ejemplos_L:
    estado=s
    for sigma in w:
        estado=transicion(estado,sigma)
        print(delta[(estado,sigma)])
    if estado in F:
        print(w, "es aceptada")
    else:
        print(w, "no es aceptada")

for w in Ejemplos_Lc:
    estado=s
    for sigma in w:
        estado=transicion(estado,sigma)

    if estado in F:
        print(w, "es aceptada")
    else:
        print(w, "no es aceptada")
