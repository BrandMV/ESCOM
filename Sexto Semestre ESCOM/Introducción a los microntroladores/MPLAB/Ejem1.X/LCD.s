	.equ __30F3013, 1
        .include "p30F3013.inc"	;Se coloca en todos los modulos que hagamos de ensamblador
	.global _comandoLCD
	.global _datoLCD
	.global _banderaLCD
	.global _iniLCD8bits
	
	.EQU	RS_LCD,	RF4
	.EQU	RW_LCD,	RF5
	.EQU	E_LCD,	RD8
	.EQU	BF_LCD,	RB7
	
;@BRIEF: ESTA RUTINA INICIALIZA EL LCD EN MODO DE 8 BITS
;@PARAM: NONGUNO
;@RETURN: NADA
_iniLCD8bits:
    ;CICLO QUE SE HACE 3 VECES
    DO	    #2	    INI_LCD
	    MOV	    #15,    W0
	    CALL    _RETARDO_1mS
	    MOV	    #0X30,  W0
INI_LCD:    CALL    _comandoLCD
    ;Preguntamos si esta ocupado BF
    ;PODRIAMOS HACER LO MISMO QUE EN EL PROGRAMA DE LA BOLETA
    CALL    _banderaLCD
    MOV	    #0X38,	W0
    CALL    _comandoLCD
    
    CALL    _banderaLCD
    MOV	    #0X08,	W0
    CALL    _comandoLCD
    
    CALL    _banderaLCD
    MOV	    #0X01,	W0
    CALL    _comandoLCD
    
    CALL    _banderaLCD
    MOV	    #0X06,	W0
    CALL    _comandoLCD
    
    CALL    _banderaLCD
    MOV	    #0X0F,	W0
    CALL    _comandoLCD
    
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


