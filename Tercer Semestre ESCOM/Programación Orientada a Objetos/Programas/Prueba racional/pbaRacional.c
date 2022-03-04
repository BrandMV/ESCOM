/*
	nombre completo: Meza Vargas Brandon David
	Tema: suma y resta de racionales en c
  	fecha: 23 octubre
  	grupo: 2CM1
  	materia: Programacion Orientada a Objetos

*/



#include<stdio.h>
#include<stdlib.h>

struct racional{
	int num, den;
};

typedef struct racional Racional;


Racional *crearRacional(int num, int den)
{
	Racional *nvo;
	if(den==0) return NULL;
	nvo= (Racional *) malloc(sizeof(Racional));
	nvo->num=num;
	nvo->den=den;
	
	return nvo;
}

Racional *mult(Racional *r1, Racional *r2)
{
	return crearRacional(r1->num * r2->num, r1->den * r2->den);
}

Racional *divi(Racional *r1, Racional *r2)
{
	return crearRacional(r1->num * r2->den, r1->den * r2->num);
}

Racional *sum(Racional *r1, Racional *r2){
	return crearRacional((r1->num * r2->den) + (r1->den * r2->num), r1->den * r2->den);
}

Racional *res(Racional *r1, Racional *r2){
	return crearRacional((r1->num * r2->den) - (r1->den * r2->num), r1->den * r2->den);
}

int comparaIgual(Racional *r1, Racional *r2){
	return r1->num * r2->den == r1->den * r2->num;
}

void imprimir(Racional *r){
	printf(" %d / %d \n", r->num, r->den);
}
int main(){
	
	Racional *r1,*r2,*r3,*r4,*r5,*r6;
	r1=crearRacional(1,2);
	r2=crearRacional(1,4);
	
	
	r3=mult(r1,r2);
	imprimir(r3);
	
	r4=divi(r1,r2);
	imprimir(r4);
	
	r5=sum(r1,r2);
	imprimir(r5);
	
	r6=res(r1,r2);
	imprimir(r6);
	
	
}
