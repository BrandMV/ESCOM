#AFD
#L={Cadenas que tiene un numero impar de a´s y un numero par de b's}

Q=['q0','q1','q2', 'q3']
sigma=['a','b']
s='q0'
F=['q1']

delta= { ('q0' , 'a'):'q1',
         ('q0' , 'b'):'q3',
         ('q1' , 'a'):'q0',
         ('q1' , 'b'):'q2',
         ('q2' , 'a'):'q3',
         ('q2' , 'b'):'q1',
         ('q3' , 'a'):'q2',
         ('q3' , 'b'):'q0'
        }

Ejemplos_L=['a', 'aaa', 'abb', 'abbbb', 'aaabb']
Ejemplos_Lc=['', 'aa', 'aba', 'bbba']

def transicion(estado,sigma):
    #print("estado=",estado,"sigma",sigma)
    estado_siguiente=delta[(estado,sigma)]
    #print("estado siguiente=",estado_siguiente)
    return estado_siguiente

for w in Ejemplos_L:
    estado=s
    for sigma in w:
        estado=transicion(estado,sigma)
        
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
