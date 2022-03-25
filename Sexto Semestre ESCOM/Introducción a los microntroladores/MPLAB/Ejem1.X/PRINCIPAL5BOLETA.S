;/**@brief ESTE PROGRAMA MANDA NUESTRO NUMERO DE BOLETA AL PUERTO B
; * SE USA UN DISPLAY DE CATODO COMUN
; * RD8 = 1 - W1--
  * RD8 = 0 - W1++
; * @device: DSPIC30F4013
; * @oscilLator: FRC, 7.3728MHz
; */
        .equ __30F3013, 1
        .include "p30F3013.inc"
;******************************************************************************
; BITS DE CONFIGURACIÓN
;******************************************************************************
;..............................................................................
;SE DESACTIVA EL CLOCK SWITCHING Y EL FAIL-SAFE CLOCK MONITOR (FSCM) Y SE 
;ACTIVA EL OSCILADOR INTERNO DE 7.3728MHZ(FAST RC) PARA TRABAJAR
;FSCM: PERMITE AL DISPOSITIVO CONTINUAR OPERANDO AUN CUANDO OCURRA UNA FALLA 
;EN EL OSCILADOR. CUANDO OCURRE UNA FALLA EN EL OSCILADOR SE GENERA UNA TRAMPA
;Y SE CAMBIA EL RELOJ AL OSCILADOR FRC  
;..............................................................................
        config __FOSC, CSW_FSCM_OFF & FRC   
;..............................................................................
;SE DESACTIVA EL WATCHDOG
;..............................................................................
        config __FWDT, WDT_OFF 
;..............................................................................
;SE ACTIVA EL POWER ON RESET (POR), BROWN OUT RESET (BOR), POWER UP TIMER (PWRT)
;Y EL MASTER CLEAR (MCLR)
;POR: AL MOMENTO DE ALIMENTAR EL DSPIC OCURRE UN RESET CUANDO EL VOLTAJE DE 
;ALIMENTACIÓN ALCANZA UN VOLTAJE DE UMBRAL (VPOR), EL CUAL ES 1.85V
;BOR: ESTE MODULO GENERA UN RESET CUANDO EL VOLTAJE DE ALIMENTACIÓN DECAE
;POR DEBAJO DE UN CIERTO UMBRAL ESTABLECIDO (2.7V) 
;PWRT: MANTIENE AL DSPIC EN RESET POR UN CIERTO TIEMPO ESTABLECIDO, ESTO AYUDA
;A ASEGURAR QUE EL VOLTAJE DE ALIMENTACIÓN SE HA ESTABILIZADO (16ms) 
;..............................................................................
        config __FBORPOR, PBOR_ON & BORV27 & PWRT_16 & MCLR_EN
;..............................................................................
;SE DESACTIVA EL CÓDIGO DE PROTECCIÓN
;..............................................................................
   	config __FGS, CODE_PROT_OFF & GWRP_OFF      

;******************************************************************************
; SECCIÓN DE DECLARACIÓN DE CONSTANTES CON LA DIRECTIVA .EQU (= DEFINE EN C)
;******************************************************************************
        .equ	MUESTRAS,   64         ;NÚMERO DE MUESTRAS
	.EQU	CERO,	    0X7E
	.EQU	UNO,	    0X37
	.EQU	DOS,	    0X6D
	.EQU	TRES,	    0X79
	.EQU	CUATRO,	    0X77
	.EQU	CINCO,	    0X77
	.EQU	SEIS,	    0X5F
	.EQU	SIETE,	    0X77
	.EQU	OCHO,	    0X7F
	.EQU	NUEVE,	    0X77
	.EQU	NULL,	    0

;******************************************************************************
; DECLARACIONES GLOBALES
;******************************************************************************
;..............................................................................
;PROPORCIONA ALCANCE GLOBAL A LA FUNCIÓN _wreg_init, ESTO PERMITE LLAMAR A LA 
;FUNCIÓN DESDE UN OTRO PROGRAMA EN ENSAMBLADOR O EN C COLOCANDO LA DECLARACIÓN
;"EXTERN"
;..............................................................................
        .global _wreg_init     
;..............................................................................
;ETIQUETA DE LA PRIMER LINEA DE CÓDIGO
;..............................................................................
        .global __reset          
;..............................................................................
;DECLARACIÓN DE LA ISR DEL TIMER 1 COMO GLOBAL
;..............................................................................
        .global __T1Interrupt    

;******************************************************************************
;CONSTANTES ALMACENADAS EN EL ESPACIO DE LA MEMORIA DE PROGRAMA
;******************************************************************************
        .section .myconstbuffer, code
;..............................................................................
;ALINEA LA SIGUIENTE PALABRA ALMACENADA EN LA MEMORIA 
;DE PROGRAMA A UNA DIRECCION MULTIPLO DE 2
;..............................................................................
        .palign 2                

ps_coeff:
        .hword   0x0002, 0x0003, 0x0005, 0x000A
BOLETA:
	.BYTE	 NULL, DOS, CERO, DOS, CERO, SEIS, TRES, CERO, DOS, OCHO, OCHO, NULL

;******************************************************************************
;VARIABLES NO INICIALIZADAS EN EL ESPACIO X DE LA MEMORIA DE DATOS
;******************************************************************************
         .section .xbss, bss, xmemory

x_input: .space 2*MUESTRAS        ;RESERVANDO ESPACIO (EN BYTES) A LA VARIABLE

;******************************************************************************
;VARIABLES NO INICIALIZADAS EN EL ESPACIO Y DE LA MEMORIA DE DATOS
;******************************************************************************

          .section .ybss, bss, ymemory

y_input:  .space 2*MUESTRAS       ;RESERVANDO ESPACIO (EN BYTES) A LA VARIABLE
;******************************************************************************
;VARIABLES NO INICIALIZADAS LA MEMORIA DE DATOS CERCANA (NEAR), LOCALIZADA
;EN LOS PRIMEROS 8KB DE RAM
;******************************************************************************
          .section .nbss, bss, near

var1:     .space 2               ;LA VARIABLE VAR1 RESERVA 1 WORD DE ESPACIO

;******************************************************************************
;SECCION DE CODIGO EN LA MEMORIA DE PROGRAMA
;******************************************************************************
.text					;INICIO DE LA SECCION DE CODIGO

__reset:
        MOV	#__SP_init, 	W15	;INICIALIZA EL STACK POINTER

        MOV 	#__SPLIM_init, 	W0     	;INICIALIZA EL REGISTRO STACK POINTER LIMIT 
        MOV 	W0, 		SPLIM

        NOP                       	;UN NOP DESPUES DE LA INICIALIZACION DE SPLIM

        CALL 	_WREG_INIT          	;SE LLAMA A LA RUTINA DE INICIALIZACION DE REGISTROS
                                  	;OPCIONALMENTE USAR RCALL EN LUGAR DE CALL
        CALL    INI_PERIFERICOS		;INICIALIZAMOS PERIFERICOS
	

CICLO:
	
	MOV		#tblpage(BOLETA),	W0	    ;OBTENEMOS LA PAGINA DEL ARREGLO, TRAE LOS 8 BITS MAS SIGNIFICATIVOS
	MOV		W0,			TBLPAG	    ;COLOCAMOS LA PARTE ALTA DE LA DIRECCION EN TBLPAG
	MOV		#tbloffset(BOLETA),	W1	    ;W1 ES EL OFFSET, PRIMEROS 16 BITS - TBPAG:W1 = BOLETA
    
	BTSS	PORTD,	#RD8	    ;SI RD8 ES CERO SE MUESTRA ASCENDENTE
	GOTO	BOLETA_ASC
	
	GOTO	FINAL_BOLETA	    ;SI RD8 ES UNO NOS POSICIONAMOS EN EL ULTIMO DIGITO DE LA BOLETA
BOLETA_ASC:
	CLR	W0
	TBLRDL.B	[W1++],			W0	;PARA BRINCARNOS EL PRIMER NULL
	;EMPEZAMOS A LEER LA BOLETA
	TBLRDL.B	[W1++],			W0	
	CP0.B		W0
	BRA	Z,		CICLO
	
	MOV.B	WREG,		PORTB
	NOP
	CALL	_RETARDO_1S
	
	BTSS	PORTD,	    #RD8    ;SI RD8 SIGUE SIENDO 0 SEGUIMOS EN ASCENDENTE
	GOTO	BOLETA_ASC
	
        GOTO    BOLETA_DESC	    ;SI RD8 ES 1 LEEMOS DESCENDETE
	
FINAL_BOLETA:
	REPEAT	    #9
	TBLRDL.B    [W1++]	;REPETIMOS HASTA LLEGAR AL FINAL DE LA BOLETA
	GOTO	    BOLETA_DESC
	
BOLETA_DESC:
	CLR		W0
	TBLRDL.B	[W1--],			W0	    ;VAMOS DISMINUYENDO LOS DIGITOS DE LA BOLETA
	CP0.B		W0
	BRA		Z,			CICLO
	
	MOV.B		WREG,			PORTB
	NOP
	CALL		_RETARDO_1S
    
	BTSS	PORTD,	    #RD8    ;SI RD8 SIGUE SIENDO 0 SEGUIMOS EN ASCENDENTE
	GOTO	BOLETA_ASC
	
        GOTO    BOLETA_DESC	    ;SI RD8 ES 1 LEEMOS DESCENDETE
    
;/**@brief ESTA RUTINA INICIALIZA LOS PERIFERICOS DEL DSC
; */
INI_PERIFERICOS:
	;NOP ES PARA DAR CICLO ADICIONAL PARA ESCRIBIR EL VALOR CORRECTAMENTE
	CLR PORTF   ;PORTF = 0
	NOP	    
	CLR LATF    ;LATF = 0 
	NOP
	SETM TRISF  ;TRISF = 0XFFFF
	NOP
	
	CLR PORTB   ;PORTB = 0
	NOP
	CLR LATB    ;LATB = 0
	NOP
	CLR TRISB   ;TRISB = 0
	NOP
	SETM ADPCFG ;ADPCFG = 0XFFFF
		    ;SE DESHABILITA EL ADC
	CLR PORTD   ;PORTD = 0
	NOP	    
	CLR LATD    ;LATD = 0
	NOP
	BSET TRISD, #TRISD8 ;TRISD, TRISD8 = 1
	NOP

        RETURN

;/**@brief ESTA RUTINA INICIALIZA LOS REGISTROS Wn A 0X0000
; */
_WREG_INIT:
        CLR 	W0
        MOV 	W0, 				W14
        REPEAT 	#12
        MOV 	W0, 				[++W14]
        CLR 	W14
        RETURN

;/**@brief ISR (INTERRUPT SERVICE ROUTINE) DEL TIMER 1
; * SE USA PUSH.S PARA GUARDAR LOS REGISTROS W0, W1, W2, W3, 
; * C, Z, N Y DC EN LOS REGISTROS SOMBRA
; */
__T1Interrupt:
        PUSH.S 


        BCLR IFS0, #T1IF           ;SE LIMPIA LA BANDERA DE INTERRUPCION DEL TIMER 1

        POP.S

        RETFIE                     ;REGRESO DE LA ISR


.END                               ;TERMINACION DEL CODIGO DE PROGRAMA EN ESTE ARCHIVO






