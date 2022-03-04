#AFD
#a*b*

Q=['q0','q1','q2']
sigma=['a','b']
s='q0'
F=['q0','q1']

delta= { ('q0' , 'a'):'q0',
         ('q0' , 'b'):'q1',
         ('q1' , 'a'):'q2',
         ('q1' , 'b'):'q1',
         ('q2' , 'a'):'q2',
         ('q2' , 'b'):'q2'
        }

Ejemplos_L=['', 'a', 'aaa', 'ab', 'bbb']
Ejemplos_Lc=['ba', 'baa', 'aba', 'ababa']

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
