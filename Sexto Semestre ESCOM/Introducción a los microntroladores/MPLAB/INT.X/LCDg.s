	.equ __30F3013, 1
        .include "p30F3013.inc"	;Se coloca en todos los modulos que hagamos de ensamblador
	.global _comandoLCD
	.global _datoLCD
	.global _banderaLCD
	.global _iniLCD8bits
	.global _printLCD
	.global _ubicarCursor
	.global _comandoLCD4BITS
	.global _datoLCD4BITS
	.global _banderaLCD4BITS
	.global _iniLCD4bits
	.global _printLCD4BITS
	.global _ubicarCursor4BITS

	
	.EQU	RS_LCD,	RF4
	.EQU	RW_LCD,	RF5
	.EQU	E_LCD,	RD8
	.EQU	BF_LCD,	RB7
	.EQU	E_LCD4BITS, RB2

;@BRIEF: ESTA RUTINA UBICA EL CURSOR EN EL LCD
;@PARAM: W0, DIRECCION DEL LCD
;@RETURN: NADA
_ubicarCursor:
    
   IOR	    #0X80,  W0
   CALL	    _banderaLCD
   CALL	    _comandoLCD
    
   RETURN
   
;@BRIEF: ESTA RUTINA UBICA EL CURSOR EN EL LCD EN MODO DE 4 BITS
;@PARAM: W0, DIRECCION DEL LCD
;@RETURN: NADA
_ubicarCursor4BITS:
    
   IOR	    #0X80,  W0
   CALL	    _banderaLCD4BITS
   CALL	    _comandoLCD4BITS
    
   RETURN
   
;@BRIEF: ESTA RUTINA IMPRIME UNA CADENA EN EL LCD EN MODO DE 4 BITS
;@PARAM: W0, TIENE LA DIRECCION DE LA CADENA
;@RETURN: NADA
_printLCD4BITS:
    PUSH    W1
    ;LENGUAJE C COLOCA UNA CADENA EN MEMORIA DE DATOS
    ;PAARA LEER DE MEMORIA DE DATOS USAMOS MOV
    ;EN W0 ESTA LA DIRECCION DE LA CADENA Y LA COLOCAMOS EN W0
    MOV		    W0,	    W1
SGT_LETRA4BITS:
    MOV.B	    [W1++],   W0
    ;PREGUNTANDO POR EL FIN DE LA CADENA
    CP0.B   W0
    BRA	    Z,	    FIN_PRINT4BITS
    
    CALL    _banderaLCD4BITS
    CALL    _datoLCD4BITS
    GOTO    SGT_LETRA4BITS
    
FIN_PRINT4BITS:
    POP	    W1
    RETURN
    
;@BRIEF: ESTA RUTINA IMPRIME UNA CADENA EN EL LCD
;@PARAM: W0, TIENE LA DIRECCION DE LA CADENA
;@RETURN: NADA
_printLCD:
    PUSH    W1
    ;LENGUAJE C COLOCA UNA CADENA EN MEMORIA DE DATOS
    ;PAARA LEER DE MEMORIA DE DATOS USAMOS MOV
    ;EN W0 ESTA LA DIRECCION DE LA CADENA Y LA COLOCAMOS EN W0
    MOV		    W0,	    W1
SGT_LETRA:
    MOV.B	    [W1++],   W0
    ;PREGUNTANDO POR EL FIN DE LA CADENA
    CP0.B   W0
    BRA	    Z,	    FIN_PRINT
    
    CALL    _banderaLCD
    CALL    _datoLCD
    GOTO    SGT_LETRA
    
FIN_PRINT:
    POP	    W1
    RETURN
    
	    
;@BRIEF: ESTA RUTINA INICIALIZA EL LCD EN MODO DE 8 BITS
;@PARAM: NINGUNO
;@RETURN: NADA
_iniLCD8bits:
    ;CICLO QUE SE HACE 3 VECES
DO  #2,	    INI_LCD
    MOV	    #15,	W0
    CALL    _RETARDO_1mS
    MOV	    #0x30,	W0
    CALL    _comandoLCD
INI_LCD:    
    NOP

    CALL    _banderaLCD
    MOV	    #0x38,	W0
    CALL    _comandoLCD
    
    CALL    _banderaLCD
    MOV	    #0x08,	W0
    CALL    _comandoLCD

    CALL    _banderaLCD
    MOV	    #0x01,	W0
    CALL    _comandoLCD

    CALL    _banderaLCD
    MOV	    #0x06,	W0
    CALL    _comandoLCD

    CALL    _banderaLCD
    MOV	    #0x0F,	W0
    CALL    _comandoLCD
    
    RETURN
    
 ;@BRIEF: ESTA RUTINA INICIALIZA EL LCD EN MODO DE 4 BITS
;@PARAM: NINGUNO
;@RETURN: NADA
_iniLCD4bits:
    ;CICLO QUE SE HACE 3 VECES
DO  #2,	    INI_LCD4BITS
    MOV	    #15,	W0
    CALL    _RETARDO_1mS
    MOV	    #0x30,	W0
    CALL    _comandoLCD4BITS
INI_LCD4BITS:    
    NOP

    CALL    _banderaLCD4BITS
    MOV	    #0x38,	W0
    CALL    _comandoLCD4BITS
    
    CALL    _banderaLCD4BITS
    MOV	    #0x08,	W0
    CALL    _comandoLCD4BITS

    CALL    _banderaLCD4BITS
    MOV	    #0x01,	W0
    CALL    _comandoLCD4BITS

    CALL    _banderaLCD4BITS
    MOV	    #0x06,	W0
    CALL    _comandoLCD4BITS

    CALL    _banderaLCD4BITS
    MOV	    #0x0F,	W0
    CALL    _comandoLCD4BITS
    
    RETURN
    
;@BRIEF: ESTA RUTINA VERIFICA BF DEL LCD EN MODO DE 4 BITS
;@PARAM: NONGUNO
;@RETURN: NADA
_banderaLCD4BITS:
    PUSH    TRISB
    PUSH    W0

    MOV	    #0X00F0,	W0
    IOR	    TRISB
    NOP
    
    BCLR    PORTF,	#RS_LCD	;R5 = 0
    NOP
    BSET    PORTF,	#RW_LCD	;RW = 0
    NOP
    BSET    PORTB,	#E_LCD4BITS	;E = 1
    NOP
ESPERA_LCD4BITS:
    ;CUANDO BIT 7 TIENE UN 1 SALTA Y EN 0 ESCAPA DESPUES DE GOTO
    BTSC    PORTB,	#BF_LCD
    GOTO    ESPERA_LCD4BITS
    
    BCLR    PORTB,	#E_LCD4BITS	;E = 0
    NOP
    BCLR    PORTF,	#RW_LCD	 ;RW = 0
    NOP
    
    POP	    W0
    POP	    TRISB
    NOP
    
    RETURN
    
;@BRIEF: ESTA RUTINA VERIFICA BF DEL LCD
;@PARAM: NONGUNO
;@RETURN: NADA
_banderaLCD:
    BCLR    PORTF,	#RS_LCD	;R5 = 0
    NOP
    SETM.B  TRISB		;TRISB(7:0) = 0XFF
    NOP
    BSET    PORTF,	#RW_LCD	;RW = 0
    NOP
    BSET    PORTD,	#E_LCD	;E = 1
    NOP
ESPERA_LCD:
    ;CUANDO BIT 7 TIENE UN 1 SALTA Y EN 0 ESCAPA DESPUES DE GOTO
    BTSC    PORTB,	#BF_LCD
    GOTO ESPERA_LCD
    
    BCLR    PORTD,	#E_LCD	;E = 0
    NOP
    BCLR    PORTF,	#RW_LCD	 ;RW = 0
    NOP
    CLR.B   TRISB,		;TRISB(7:0) = 0X00
    NOP
    
    RETURN
	
;@BRIEF: ESTA RUTINA MANDA COMANDOS AL LCD EN MODO DE 4 BITS
;@PARAM: W0, COMANDO A ENVIAR AL LCD
;@RETURN: NADA
_comandoLCD4BITS:
    PUSH    W1
    BCLR    PORTF,	#RS_LCD	;R5 = 0
    NOP
    BCLR    PORTF,	#RW_LCD	;RW = 0
    NOP
    BSET    PORTB,	#E_LCD4BITS	;E = 1
    NOP
    
    MOV	    W0,	    W1
    
    MOV	    #0XFF0F,	W0	;20 = 0XFF0F
    AND	    PORTB
    NOP
    MOV	    #0x00F0,	W0
    AND	    W0,		W1,	W0
    IOR	    PORTB
    NOP
    BCLR    PORTB,	#E_LCD4BITS
    NOP
    
    BSET    PORTB,	#E_LCD4BITS
    NOP
    MOV	    #0XFF0F,	W0	;20 = 0XFF0F
    AND	    PORTB
    NOP
    MOV	    #0x000F,	W0
    AND	    W0,		W1,	W0
    LSR	    W0,		#4,	W0	;W0 = W0 << 4
    IOR	    PORTB
    NOP
    BCLR    PORTB,	#E_LCD4BITS
    NOP
    
    POP W1
    
    RETURN
	
;@BRIEF: ESTA RUTINA MANDA COMANDOS AL LCD
;@PARAM: W0, COMANDO A ENVIAR AL LCD
;@RETURN: NADA
_comandoLCD:
    BCLR    PORTF,	#RS_LCD	;R5 = 0
    NOP
    BCLR    PORTF,	#RW_LCD	;RW = 0
    NOP
    BSET    PORTD,	#E_LCD	;E = 1
    NOP
    MOV.B   WREG,	PORTB	;PORTB(7:0) = COMANDO
    NOP
    BCLR    PORTD,	#E_LCD	;E = 0
    NOP
    
    RETURN
    
    
;@BRIEF: ESTA RUTINA MANDA DATOS AL LCD EN MODO DE 4 BITS
;@PARAM: W0, COMANDO A ENVIAR AL LCD
;@RETURN: NADA
_datoLCD4BITS:
    PUSH    W1
    
    BSET    PORTF,	#RS_LCD	;R5 = 0
    NOP
    BCLR    PORTF,	#RW_LCD	;RW = 0
    NOP
    BSET    PORTB,	#E_LCD4BITS	;E = 1
    NOP
    
    MOV	    W0,	    W1
    
    MOV	    #0XFF0F,	W0	;20 = 0XFF0F
    AND	    PORTB
    NOP
    MOV	    #0x00F0,	W0
    AND	    W0,		W1,	W0
    IOR	    PORTB
    NOP
    BCLR    PORTB,	#E_LCD4BITS
    NOP
    
    BSET    PORTB,	#E_LCD4BITS
    NOP
    MOV	    #0XFF0F,	W0	;20 = 0XFF0F
    AND	    PORTB
    NOP
    MOV	    #0x000F,	W0
    AND	    W0,		W1,	W0
    LSR	    W0,		#4,	W0	;W0 = W0 << 4
    IOR	    PORTB
    NOP
    BCLR    PORTB,	#E_LCD4BITS
    NOP
    
    POP W1
    
    RETURN
;@BRIEF: ESTA RUTINA MANDA DATOS AL LCD
;@PARAM: W0, COMANDO A ENVIAR AL LCD
;@RETURN: NADA   
_datoLCD:
    BSET    PORTF,	#RS_LCD	;R5 = 1
    NOP
    BCLR    PORTF,	#RW_LCD	;RW = 0
    NOP
    BSET    PORTD,	#E_LCD	;E = 1
    NOP
    MOV.B   WREG,	PORTB	;PORTB(7:0) = COMANDO
    NOP
    BCLR    PORTD,	#E_LCD	;E = 0
    NOP
    
    RETURN


