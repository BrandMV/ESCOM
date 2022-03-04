Q=['q0','q1']
sigma=['a','b','e']
Ap=['A','B','Z'] 
s='q0'
z='Z'
F=['q1']
pila=[]

def insertar(gamma,pila):
    for s in gamma[::-1]:
        pila.insert(0,s)
    return pila;

Ejemplos_L=['','ab','ba','aabb','abb','a','b','abab','baba','ababa','abba']
estado=s
c=0

for y in Ejemplos_L:
    pila=[z]
    estado=s
    p=y+'e'
    for x in p:
        c=0
        #print(x)
        if estado==s:
            if x==sigma[0] and pila[0]==z and c==0:
                pila.pop(0)
                insertar('AZ',pila)
                c=1
            if x==sigma[0] and pila[0]==Ap[0] and c==0:
                pila.pop(0)
                insertar('AA',pila)
                c=1
            if x==sigma[0] and pila[0]==Ap[1] and c==0:
                pila.pop(0)
                c=1
            if x==sigma[1] and pila[0]==z and c==0:
                pila.pop(0)
                insertar('BZ',pila)
                c=1
            if x==sigma[1] and pila[0]==Ap[1] and c==0:
                pila.pop(0)
                insertar('BB',pila)
                c=1
            if x==sigma[1] and pila[0]==Ap[0]and c==0:
                pila.pop(0)
                c=1
            if x==sigma[2] and pila[0]==z and c==0:
                pila.pop(0)
                pila.insert(0,z)
                estado=Q[1]
                c=1
    if estado in F:
            print(y, " es aceptada")
            print(pila)
    else:
        print(y,"No aceptada")
            
