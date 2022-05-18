        .include "p30F3013.inc"	;Se coloca en todos los modulos que hagamos de ensamblador
	.global __INT0Interrupt
	.global _habilitarRTC
	.global _USEG
	.global _DSEG
	.global _UMIN
	.global _DMIN
	.global _UHR
	.global _DHR

__INT0Interrupt:
    PUSH    W0
    BTG	    LATD,   #LATD9   
    NOP
    
    INC.B   _uni
    MOV	    #10,    W0
    
    CP.B    _uni
    BRA	    NZ,	    FIN_ISR_INTO
    CLR.B   _uni
    
    INC.B   _dece
    CP.B    _dece
    BRA	    NZ,	    FIN_ISR_INTO
    CLR.B   _dece
    
    INC.B   _cen
    CP.B    _cen
    BRA	    NZ,	    FIN_ISR_INTO
    CLR.B   _cen
    
    INC.B   _umi
    CP.B    _umi
    BRA	    NZ,	    FIN_ISR_INTO
    CLR.B   _umi
    
FIN_ISR_INTO:
    BCLR    IFS0,   #INT0IF
    POP	    W0
    RETFIE
    
    
;@BRIEF: ESTA RUTINA QUITA LA PROYECTTION DEL REGISTRO OSCCONL
;@PARAM: W0, DIRECCION DEL LCD
;@RETURN: NADA
_habilitarRTC:
    PUSH    W0
    PUSH    W1
    PUSH    W2
    
    ;QUITANDO PROTECCIÓN
    MOV	    #OXCCONL,	W0
    MOV	    #0X46,	W1
    MOV	    #0X57,	W2
    
    POP	    W2
    POP	    W1
    POP	    W0
    
    RETURN
    
    