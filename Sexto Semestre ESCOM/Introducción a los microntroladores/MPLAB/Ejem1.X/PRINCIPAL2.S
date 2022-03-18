;/**@brief ESTE PROGRAMA SUMA O RESTRA UNA CONSTANTE AL PUERTO F Y COLOCA EL RESULTADO EN EL PUERTO B DEPENDIENDO DE RD8
;*ADEMAS DIVIDE O MULTIPLICA LA MISMA CONSTANTE AL PUERTO F Y SE GUARDA EN EL PUERTO B DEPENDIENDO DE RD9
;* IF( RD8 = 0)
;*    PORTB = W0 - K
;   ELSE
;	PORTB = W0 + K
;    CON K = 5
;* IF( RD9 = 0)
;*    PORTB = W0 * K
;   ELSE
;	PORTB = W0 / K
;    CON K = 5
;* @device: DSPIC30F4013
;* @oscilLator: FRC, 7.3728MHz
;*/
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
        .equ MUESTRAS, 64         ;NÚMERO DE MUESTRAS

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
	
	

	
	;DESPUES DE INICIALIZAR LOS PERIFERICOS COLOCAMOS EL ALGORITMO
CICLO:
	;PROGRAMA 2
	MOV	PORTF,	    W0
	;NOP CUANDO HAY PUERTOS
	NOP
	LSR	W0,	#2,	W0	;W0 = WO >> 2
	AND	#0X0F,	W0		;ESTAMOS USANDO 16 BITS PERO EL PROCESADOR COMPLETA 
					;LO QUE NO ALCANZA CON CEROS W0 = W0 & 0X000F
					
	MOV	#5,	W1		;W1 = 5 SERÁ LA CONSTANTE
	BTSC	PORTD,	#RD8		;SI RD8 == 1 AVANZAMOS A LA FUNCION
	GOTO	SELECTRD9
	
	BTSC	PORTD,	#RD9		;SI RD9 == 1 Y RD8 FUE 0 SUMAMOS
	GOTO SUMA
	;SI FUE 0 RESTAMOS
	GOTO RESTA
	
SELECTRD9:
	BTSC    PORTD,	#RD9		;SI RD9 == 1 DIVIDIMOS, SI NO MULTIPLICAMOS
	GOTO	DIVISION
	GOTO MULTIPLICACION
DIVISION:
	;COMO LA DIVISION TARDA 18 CICLOS REPETIMOS 18 VECES
	MOV	    #5,	    W2
	REPEAT	    #17
	DIV.U	    W0,	    W2
	NOP
	GOTO	SAVEDATA    
MULTIPLICACION:
	MUL.UU	W0,	W1,	W0	;W0 = W0 * W1
	NOP
	GOTO	SAVEDATA
SUMA:
	ADD	W1,	W0,	W0	;W0 = W0 + W1
	NOP
	GOTO	SAVEDATA
RESTA:
	SUB	W0,	W1,	W0	;W0 = W0 - W1
	NOP
	GOTO	SAVEDATA

SAVEDATA:
	MOV	W0,	PORTB		;PORTB = W0
	NOP
        GOTO    CICLO 
    

;/**@brief ESTA RUTINA INICIALIZA LOS PERIFERICOS DEL DSC
; */
INI_PERIFERICOS:
	;NOP ES PARA DAR CICLO ADICIONAL PARA ESCRIBIR EL VALOR CORRECTAMENTE
	CLR	PORTF		    ;PORTF = 0
	NOP	    
	CLR	LATF		    ;LATF = 0 
	NOP
	SETM	TRISF		    ;TRISF = 0XFFFF
	NOP
	
	CLR	PORTB		    ;PORTB = 0
	NOP
	CLR	LATB		    ;LATB = 0
	NOP
	CLR	TRISB		    ;TRISB = 0
	NOP
	SETM	ADPCFG		    ;ADPCFG = 0XFFFF
				    ;SE DESHABILITA EL ADC
	CLR	PORTD		    ;PORTD = 0
	NOP	    
	CLR	LATD		    ;LATD = 0
	NOP
	BSET	TRISD,	#TRISD8	    ;TRISD, TRISD8 = 1
	NOP
	BSET	TRISD,	#TRISD9	    ;TRISD, TRISD9 = 1
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






