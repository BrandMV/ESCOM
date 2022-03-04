cadena="examen"
cadena3=cadena*3
subcadenas=[]

cont=0
for n in range(len(cadena3)+1):
    for m in range(n, len(cadena3)+1):
        if(cadena3[n:m] == "" and n>=1):
            cont=0;
        else:
            print(cadena3[n:m])
            subcadenas.append(cadena3[n:m])
print('\nHay',len(subcadenas),' subcadenas\n')
