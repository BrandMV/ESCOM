#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    int l, a, b, nInstru=0, r, i, auxa=0, auxb=0;

    if(argc != 3)
        exit(1);

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    l = (a<b)?a:b; nInstru+=2;
    r=1; nInstru++;

    for(i=2,nInstru++;i<=l;i++,nInstru++){
        nInstru++; //Comparacions true
        if(a%i==0&&b%i==0)
            printf("\n true %d %d %d",a%i,b%i, i);

        if(a%i==0&&b%i==0){
            nInstru+=5;
            nInstru++; //Condicional TRUE if
            r=i;nInstru++;
            nInstru++; //Salto TRUE if
            auxa++;
        }else{
            nInstru+=5;
            nInstru++; //salto false
            nInstru++; //condicional false
        }
        nInstru++; //salto true
    }
    nInstru++; //comparacion FALSE i
    nInstru++; //Salto FALSE i
    printf("\nInstrucciones: %d", nInstru);

    auxb = auxa + 9*l-2;
    nInstru+=auxb; 

    printf("\nInstrucciones: %d", auxb);
    

    return 0;
}