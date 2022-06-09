        .include "p30F3013.inc"	;Se coloca en todos los modulos que hagamos de ensamblador
	.global __T1Interrupt
	
	
	
__T1Interrupt
    BTG	    LATB,   #LATB9
    NOP
    BCLR    IFS0,   #T1IF
    RETFIE
    


    