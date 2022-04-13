    .include "p30F3013.inc"
    .global _funcion1
    .global _funcion2
    .global _funcion3
    .global _funcion4
    .global _funcion5
    .global _funcion6
    .global _longitud	;variable compartida entre C y ensamblador
        
;@brief: Esta funcion reliza un retardo
;@param: ninguno  
;@return: ninguno
;   
_funcion1:    
    PUSH    W0
    
    MOV	    #6,	    W0
CICLO_F1:    
    DEC	    W0,	    W0
    BRA	    NZ,	    CICLO_F1
    
    POP	    W0
    return

;@brief: Esta funcion reliza una suma de dos numeros
;@param: ninguno  
;@return: W0, resultado de la suma
;El primer valor del conjunto de registros es el que se retorna, en este caso w0
_funcion2:
    MOV	    #12,    W0
    MOV	    #23,    W1
    
    ADD	    W0,	    W1,	    W0
    
    return

;@brief: Esta funcion reliza una suma de dos numeros
;@param1: W0, tiene el n1 a sumar   
;@param2: W1, tiene el n2 a sumar   
;@return: W0, resultado de la suma
;   
_funcion3:
    
    ADD	    W0,	    W1,	    W0
    
    return

;@brief: Esta funcion reliza una suma de dos numeros
;@param1: W0, tiene el n1 a sumar   
;@param2: W1, tiene el n2 a sumar   
;@param3: W2, tiene la direccion del resultado       
;@return: ninguno
;   
_funcion4:
    
    ADD	    W0,	    W1,	    W0	; W0 = W0 + W1
    MOV	    W0,	    [W2]	; *W2 = W0
    
    return
;@brief: Esta funcion regresa la longitud de una cadena
;@param1: W0, tiene la direcion del primer elemento de la cadena   
;@return: W0, longitud de la cadena
;   
_funcion5:
    PUSH    W1
    PUSH    W2
    
    CLR	    W2		    ;CONTADOR
CONTEO:    
    MOV.B   [W0++], W1	    ;W1 = *CAD, vamos recorriendo la cadena
    ;Preguntamos por el nulo de la cadena es decir el 0 (fin de cadena)
    CP0.B   W1
    BRA	    Z,	    FIN
    
    INC	    W2,	    W2	    ;CONTADOR++
    GOTO    CONTEO
FIN:
    MOV	    W2,	    W0	    ;W0 = CONTADOR
    
    POP	    W2
    POP	    W1
    return
;@brief: Esta funcion regresa la longitud de una cadena
;@param1: W0, tiene la direcion del primer elemento de la cadena   
;@return: ninguno
;   
_funcion6:
    PUSH    W1
        
    CLR	    _longitud	    ;CONTADOR
CONTEO1:    
    MOV.B   [W0++], W1	    ;W1 = *CAD
    CP0.B   W1
    BRA	    Z,	    FIN1
    
    INC	    _longitud	    ;CONTADOR++
    GOTO    CONTEO1
FIN1:
    
    POP	    W1
    return
    
    