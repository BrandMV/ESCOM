.include "p30F3013.inc"
.global _RETARDO_1S
.global _RETARDO_1mS
    
;/**@brief ESTA RUTINA GENERA UN RETARDO DE 1 SEG DE TIEMPO
;  * @param NINGUNO
;  * @return Nada
; */
_RETARDO_1S:
    ;PUSH PARA GUARDAR INFORMACION EN LA PILA, GUARDAMOS LOS REGISTROS QUE USAMOS
    PUSH W0
    PUSH W1
    MOV	    #10,    W1
  
CICLO2_1S:
    CLR	    W0	    ;W0 = 0
CICLO1_1S:
    DEC	    W0,	    W0	    ;WO = -1	1 CICLO
    
    BRA	    NZ,	    CICLO1_1S	;Z = 1 SI ES DIFERENTE DE 0 BRINCA  2 CICLOS
    
    DEC	    W1,	    W1
    BRA	    NZ,	    CICLO2_1S
    ;tiempo = 65536 * 3 * 542ns = 106.66 ms
    ;FOSC = FRC = 7.3728MHZ
    ;FCY = FOSC / 4 = 7.3728MHZ / 4 = 1,8432MHZ
    ;TCY = 1 / FCY = 1 / 1.8432MHZ = 542 nS
    ;SACAMOS EL ULTIMO QUE SE SACO, PUES ES UNA PILA
    POP W1
    POP W0
    RETURN;
;/**@brief ESTA RUTINA GENERA UN RETARDO DE 1mS DE TIEMPO
;  * @param W0, VALOR DEL RETARDO EN MILISEGUNDOS
;  * @return Nada
; */
_RETARDO_1mS:
    ;PUSH PARA GUARDAR INFORMACION EN LA PILA, GUARDAMOS LOS REGISTROS QUE USAMOS
    PUSH W1

CICLO2_1mS:
    MOV	    #614,	W1

CICLO1_1mS:
    DEC	    W1,	    W1	    ;WO = -1	1 CICLO
    BRA	    NZ,	    CICLO1_1mS	;Z = 1 SI ES DIFERENTE DE 0 BRINCA  2 CICLOS
    
    DEC	    W0,	    W0
    BRA	    NZ,	    CICLO2_1mS
    
    ;tiempo = 614 * 3 * 542ns = 106.66 ms
    ;FOSC = FRC = 7.3728MHZ
    ;FCY = FOSC / 4 = 7.3728MHZ / 4 = 1,8432MHZ
    ;TCY = 1 / FCY = 1 / 1.8432MHZ = 542 nS
    ;SACAMOS EL ULTIMO QUE SE SACO, PUES ES UNA PILA
    POP W1
    RETURN;


