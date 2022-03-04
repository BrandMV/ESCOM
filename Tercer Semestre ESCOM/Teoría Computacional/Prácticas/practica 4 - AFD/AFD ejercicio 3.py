#AFD
#L={Cadenas que terminan ya sea con la subcadena ab o con la subcadena aa}

Q=['q0','q1','q2', 'q3']
sigma=['a','b']
s='q0'
F=['q2','q3']

delta= { ('q0' , 'a'):'q1',
         ('q0' , 'b'):'q0',
         ('q1' , 'a'):'q2',
         ('q1' , 'b'):'q3',
         ('q2' , 'a'):'q2',
         ('q2' , 'b'):'q3',
         ('q3' , 'a'):'q1',
         ('q3' , 'b'):'q0'
        }

Ejemplos_L=['ab', 'aa', 'ababab', 'babababaa', 'bbaa','aaa']
Ejemplos_Lc=['', 'a', 'b', 'ba','baaba','aababbb']

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
