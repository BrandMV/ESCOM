
#Programa No.1
print("Programa 1")
cadena="Hola"

print("La longitud de la cadena", cadena, "es: ",len(cadena));

#Programa No.2
print("\nPrograma 2")
from collections import Counter

cadena= "Esto es una cadena"
c= Counter(cadena)

print(c)

#Programa No.3
print("\nPrograma 3")
cadena="cadena"

if len(cadena) < 2:
    print("")
else:
    print(cadena[0:2] + cadena[-2:])

#Programa No.4
print("\nPrograma 4")
cadena="recordar"

cadenaRep= cadena[0] + cadena[1:].replace(cadena[0],"$")
print(cadenaRep)

#Programa No.5
print("\nPrograma 5")
cadena1="abcabc"
cadena2="xyzxyz"

cadena1n=cadena1[:2].replace(cadena1[:2],cadena2[:2] + cadena1[2:])
cadena2n=cadena2[0:2].replace(cadena2[0:2],cadena1[0:2] + cadena2[2:])
print(cadena1n + ' '+ cadena2n);

#Programa No.6
print("\nPrograma 6")
palabras= ["hola", "pedro", "holapedro"]
palabras.sort(key=len);
print(len(palabras[-1]))

#Programa  7
print("\nPrograma 7")
cadena ="hola"
pos=0
cadena=cadena[:pos]+cadena[pos+1:]
print(cadena)

#Programa No.8
print("\nPrograma 8")
cadena="calabaza"

nueva=cadena[-1] + cadena[1:-1] +cadena[0]
print(nueva);

#Programa No.9
print("\nPrograma 9")
cadena= "celular"
nueva=''

for i in range(len(cadena)):
    if i%2 ==0 :
        nueva+=cadena[i]

print(nueva)

#Programa No.10
print("\nPrograma 10")
cadena="El barco de el niño que viajo en barco el año que cumplio años"
list=cadena.split()
from collections import Counter

c= Counter(list)
print(c)

#Programa No.11
print("\nPrograma 11")
print("Escribe algo: ")
entrada=input()
print("Tu entrada en minusculas es: ", entrada.lower())
print("Tu entrada en mayusculas es: ", entrada.upper())

#Programa No.12
print("\nPrograma 12")
cadena="bb,aa,cc,zz"
x=cadena.split(",")
orde=sorted(x)
print(orde)

#programa No.13
print("\nPrograma 13")
def trece(cadena):
    rep=cadena[-2:]*4
    return rep
print(trece("pedro"))

#programa No.14
print("\nPrograma 14")
def firstTree(cadena):
    if(len(cadena) >= 3):
        res=cadena[:3]
    else:
        return cadena
    return res
print(firstTree("python"))

#programa No.15
print("\nPrograma 15")
def firstHalf(cadena):
    if(int(len(cadena)) % 2 == 0):
        n=cadena[:int(len(cadena)) // 2] #// lo convierte en int 
    else: 
        n="La longitud de la cadena no es par"
    return n
print(firstHalf("Holasa"))

#programa No.16
print("\nPrograma 16")
sumaBol=2+8+8
def inver(cadena):
    if sumaBol % len(cadena)   == 0:
        return(cadena[::-1])
    else:
        return "la longitud no es multiplo"
print(inver("ESCOMA"))
print(inver("ESCOM"))

#programa No.17
print("\nPrograma 17")

def mayus(cadena):
    cont=0
    for c in cadena[:4]:
        if c.isupper():
            cont+=1
    if(cont>=2):
        return cadena.upper()
    else:
        return "Tiene menos de dos mayusculas"
print(mayus("Si puedO"))
print(mayus("SImon"))

#programa No.18
print("\nPrograma 18")

def lexi(cadena):
    return ''.join(sorted(cadena))
print(lexi("xawmzrqw"))

#programa No.19
print("\nPrograma 19")
cadena="pedro"
print(cadena.startswith("p"))

#programa No.20
print("\nPrograma 20")

from string import ascii_lowercase, ascii_uppercase #agrega el alfabeto ingles
                                                    #en minusculas y mayusculas
def cifradoCesar(cadena, despl):
    res=[]

    for i in cadena:
        if i in ascii_lowercase:
            indice = ascii_lowercase.index(i)
            newindice = (indice + despl) % len(ascii_lowercase) # modulo nos permite establecer la posicion
            res.append(ascii_lowercase[newindice])
        elif i in ascii_uppercase:
            indice = ascii_uppercase.index(i)
            newindice = (indice + despl) % len(ascii_uppercase) # modulo nos permite establecer la posicion
            res.append(ascii_uppercase[newindice])
        else:
            res.append(i)

    return ''.join(res)

print(cifradoCesar('Teoria computacional',1))
print(cifradoCesar('Teoria computacional',2))

#programa No.21
print("\nPrograma 21")

from textwrap import indent
cadena = """línea 1
línea 2
línea 3
ultima"""

print(indent(cadena,".- ")) #indent agrega un prefijo a cada linea de la cadena

#programa No.22
print("\nPrograma 22")

numero=142.3268
print(f"{numero:.2f}") #uso de una f-string

#programa No.23
print("\nPrograma 23")
numero=142.3268
print(f"{numero:+,.2f}") #uso de una f-string

#programa No.24
print("\nPrograma 24")

numero=142.3268
print(f"{numero:.0f}") #uso de una f-string

#programa No.25
print("\nPrograma 25")
num="50"
ancho=5
print(num.zfill(ancho))

#programa No.26
print("\nPrograma 26")

num=50
print("{:*<5d}".format(num))

#programa No.27
print("\nPrograma 27")

num=30000000
print('{:,}'.format(num))

#programa No.28
print("\nPrograma 28")
num=25
print(f'{num:.2%}')

#programa No.29
print("\nPrograma 29")

num=25
print('Original:',num)
print(f'izq(ancho 10){num:<10}')    #a la izquierda
print(f'der(ancho 10){num:>10}')    #a la derecha
print(f'cen(ancho 10){num:^10}')    #al centro

#programa No.30
print("\nPrograma 30")

def rgb(r,g,b):
    return '#{:2x}{:2x}{:2x}'.format(r,g,b)

print(rgb(64,204,208))

#programa No.31
print("\nPrograma 31")
cadena='cadena cadena cadena soy una cadena cadena'
ocurrencias=cadena.count("cadena")
print("Hay ",ocurrencias," ocurrencias")

#programa No.32
print("\nPrograma 32")
cadena="soy una cadena"
for i in cadena.split('\n'):
    print(' '.join(i.split()[::-1]))

#programa No.33
print("\nPrograma 33")

cadena="institucional"
fuera='aeiou'
cad= [ c for c in cadena if c not in fuera]
print(''.join(cad))

#programa No.34
print("\nPrograma 34")

from collections import Counter
cadena="cabballo"
contador= Counter(cadena)
print(contador)
print([t[0:] for t in contador.items() if t[1]> 1])

#Programa  35
print("\nPrograma 35")
cadena="youtube"
for i, c in enumerate(cadena):
    print("Carácter actual ",c," posicion ",i)
    
#Programa  36
print("\nPrograma 36")
from string import ascii_lowercase

cadena="Soy una cadena"
vali=set(cadena) >= set(ascii_lowercase)
print(vali)
cadena="The quick brown fox jumps over the lazy dog"
vali=set(cadena) >= set(ascii_lowercase)
print(vali)
    
#Programa  37
print("\nPrograma 37")
cadena="Soy una cadena y sere lista"
print(cadena.split())

#Programa  38
print("\nPrograma 38")
cadena = "ESCUELA SUPERIOR "
n=4
print(cadena[:n].lower()+cadena[n:])

#Programa  39
print("\nPrograma 39")

cantidad="32.054,23"
maketrans=cantidad.maketrans
cantidad = cantidad.translate(maketrans(',.','.,'))
print(cantidad)

#Programa  40
print("\nPrograma 40")

cadena="hola"
vocales="aeiouAEIOU"
print(len([l for l in cadena if l in vocales]))

#Programa  41
print("\nPrograma 41")
cadena="hola*soy*una*cadena"
print(cadena.rsplit('*',2))

#Programa  42
print("\nPrograma 42")
cadena="hola soy una cadena*"
print(cadena.rsplit('*',1))


#Programa  43
print("\nPrograma 43")
cadena="perrera"
prefijos=[]
sufijos=[]
subcadenas=[]

for n in range(len(cadena)+1):
    print("Prefijo ", n, "=", cadena[:n], end="    ") #
    prefijos.append(cadena[:n])
    if cadena[:n] != cadena:
        print("Prefijo propio")

print('\nHay',len(prefijos),' prefijos, ',len(prefijos)-1, 'propios\n')

for n in range(len(cadena)+1):
    if n==0:
        print("Sufijo ", n, "=     sufijo propio", end="    \n")
        sufijos.append('')
    else:
        print("Sufijo ", n, "=", cadena[-n:], end="    ") #
        sufijos.append(cadena[-n:])
        if cadena[-n:] != cadena:
            print("Sufijo propio")
        else:
            print("\n")

print('\nHay',len(sufijos),' sufijos, ',len(prefijos)-1, 'propios\n')

cont=0
for n in range(len(cadena)+1):
    for m in range(n, len(cadena)+1):
        if(cadena[n:m] == "" and n>=1):
            cont=0;
        else:
            print(cadena[n:m])
            subcadenas.append(cadena[n:m])
print('\nHay',len(subcadenas),' subcadenas\n')



