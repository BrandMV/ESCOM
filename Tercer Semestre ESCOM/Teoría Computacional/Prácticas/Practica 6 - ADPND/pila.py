#programar automatas de pila

Q=['q0','q1','q2','q3']
sigma=['a','b','e']
Ap=['A','B',''] 
s='q0'
z='A'
F=['q3']
pila=[]

#manejarla como push pila.insert(0,'Z')

def insertar(gamma,pila):
    for s in gamma[::-1]:
        pila.insert(0,s)
    return pila;
Ejemplos_L=['','ab','aabb','aaabbb','aaaabbbb','a','aba','baba','aabbbbb']
estado=s

for y in Ejemplos_L:
    pila=[z]
    estado=s
    pos=y.find("b")
    bs=y[pos: ]
    ca=y[:pos]
       
    p=y+'e'
    for x in p:
        #print(x)
        if estado==s:
            if x==sigma[0]:
                pila.pop(0)
                insertar('BA',pila)
                estado=Q[1]       
            if x==sigma[2] and pila[0]==z:
                pila.pop(0)
                estado=Q[3]
            if x==sigma[1]:
                break;
              
        elif estado==Q[1]:
            if x==sigma[0] and pila[0]==Ap[1]:
                pila.pop(0)
                insertar('BB',pila)
                
            if x==sigma[1] and pila[0]==Ap[1]:
                pila.pop(0)
                estado=Q[2]

        elif estado==Q[2]:
            if x==sigma[0]:
                break;     
            if x==sigma[1] and pila[0]==Ap[1]:
                pila.pop(0)

            if  x==sigma[2] and pila[0]==Ap[0]:
                pila.pop(0)
                pila.insert(0,'A')
                estado=Q[3]     
    if estado in F:
        if len(bs)!=len(ca):
            print(y, "No aceptada")
        else:
            print(y, " es aceptada")
            print(pila)
    else:
        print(y,"No aceptada")
      

