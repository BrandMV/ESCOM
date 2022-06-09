        .include "p30F3013.inc"	;Se coloca en todos los modulos que hagamos de ensamblador
	.global __INT0Interrupt
	.global _habilitarRTC
	.global _USEG
	.global _DSEG
	.global _UMIN
	.global _DMIN
	.global _UHR
	.global _DHR

__T1Interrupt:
    PUSH    W0
    
    INC	    _USEG
    MOV	    #10,    W0
    CP	    _USEG   
    BRA	    NZ,	    FIN_ISR_INTO
    CLR	    _USEG
    
    INC	    _DSEG   
    MOV	    #6,    W0
    CP	    _DSEG   
    BRA	    NZ,	    FIN_ISR_INTO
    CLR	    _DSEG
    
    INC	    _UMIN   
    MOV	    #10,    W0
    CP	    _UMIN   
    BRA	    NZ,	    FIN_ISR_INTO
    CLR	    _UMIN
    
    INC	    _DMIN   
    MOV	    #6,    W0
    CP	    _DMIN   
    BRA	    NZ,	    FIN_ISR_INTO
    CLR	    _DMIN
    
    MOV	    #2,	    W0
    CP	    _DHR
    BRA	    Z,	    AUX_HR
    
    INC   _UHR
    MOV	    #10,    W0
    CP    _UHR
    BRA	    NZ,	    FIN_ISR_INTO
    CLR   _UHR
    
    INC   _DHR
    
    
FIN_ISR_INTO:
    BCLR    IFS0,   #T1IF
    POP	    W0
    RETFIE
    
AUX_HR:
    INC	   _UHR
    MOV	    #4,	    W0
    CP	    _UHR
    BRA	    NZ,	    FIN_ISR_INTO
    CLR	    _UHR
    CLR	    _DHR
    GOTO   FIN_ISR_INTO
    
    
;@BRIEF: ESTA RUTINA QUITA LA PROYECTTION DEL REGISTRO OSCCONL
;@PARAM: W0, DIRECCION DEL LCD
;@RETURN: NADA
_habilitarRTC:
    PUSH    W0
    PUSH    W1
    PUSH    W2
    
    ;QUITANDO PROTECCIÓN
    MOV	    #OSCCONL,	W0
    MOV	    #0X46,	W1
    MOV	    #0X57,	W2
    MOV.B   W1,		[W0]
    MOV.B   W2,		[W0]
    BSET    OSCCONL,	#LPOSCEN    ;ACTIVAMOS CRISTAL DE 32KHZ
    
    POP	    W2
    POP	    W1
    POP	    W0
    
    RETURN
    
    