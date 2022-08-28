        .include "p30F3013.inc"	;Se coloca en todos los modulos que hagamos de ensamblador
	.global __INT0Interrupt
	.global __INT1Interrupt
	.global __INT2Interrupt
	.global _uni
	.global _dece
	.global _cen
	.global _umi

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
    
__INT1Interrupt:
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
    
__INT2Interrupt:
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
    
    
    