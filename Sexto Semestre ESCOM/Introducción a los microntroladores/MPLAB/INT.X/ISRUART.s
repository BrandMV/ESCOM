        .include "p30F3013.inc"	;Se coloca en todos los modulos que hagamos de ensamblador
	.global __U1RXInterrupt
	.global _caracter
	.global _datoRCV
	
	
__U1RXInterrupt:
    PUSH    W0
    MOV	    U1RXREG,	W0
    MOV	    W0,		_caracter
    MOV	    #1,		W0
    MOV	    W0,		_datoRCV
    
    BCLR    IFS0,	#U1RXIF
    POP	    W0
    RETFIE
    


    