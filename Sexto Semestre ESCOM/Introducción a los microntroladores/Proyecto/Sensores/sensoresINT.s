        .include "p30F3013.inc"	;Se coloca en todos los modulos que hagamos de ensamblador
	.global __INT0Interrupt
	.global __INT1Interrupt
	.global __INT2Interrupt
	.global _detectorPiso
	.global _detectorInt1
	.global _detectorInt2

;INTERRUPCION 0 SEGUNDO PISO
__INT0Interrupt:
    PUSH    W0
    BTG	    LATF,   #LATF6   
    NOP
  
    MOV	    #0,    W0
    MOV	    W0,	   _detectorPiso


    BCLR    IFS0,   #INT0IF
    POP	    W0
    RETFIE
  
;INTERRUPCION 1 PRIMER PISO
__INT1Interrupt:
    PUSH    W0
    BTG	    LATD,   #LATD8   
    NOP
    
    MOV	    #1,    W0
    MOV	    W0,	   _detectorPiso
    
    BCLR    IFS1,   #INT1IF
    POP	    W0
    RETFIE
 
;INTERRUPCION 2 PLANTA BAJA
__INT2Interrupt:
    PUSH    W0
    BTG	    LATD,   #LATD9   
    NOP
    
    MOV	    #2,    W0
    MOV	    W0,	   _detectorPiso
    
    BCLR    IFS1,   #INT2IF
    POP	    W0
    RETFIE
    
    
    