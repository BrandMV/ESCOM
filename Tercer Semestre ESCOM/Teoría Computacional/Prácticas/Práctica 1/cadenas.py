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

    
    
