#include "p30F3013.h"


//_FOSC(CSW_FSCM_OFF & FRC); 
#pragma config FOSFPR = FRC             // Oscillator (Internal Fast RC (No change to Primary Osc Mode bits))
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)
/********************************************************************************/
/* SE DESACTIVA EL WAvoid habilitarPerifericos()TCHDOG														*/
//_FWDT(WDT_OFF); 
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)
/********************************************************************************/
//_FBORPOR( PBOR_ON & BORV27 & PWRT_16 & MCLR_EN ); 
// FBORPOR
#pragma config FPWRT  = PWRT_16          // POR Timer Value (16ms)
#pragma config BODENV = BORV20           // Brown Out Voltage (2.7V)
#pragma config BOREN  = PBOR_ON          // PBOR Enable (Enabled)
#pragma config MCLRE  = MCLR_EN          // Master Clear Enable (Enabled)
/********************************************************************************/
//_FGS(CODE_PROT_OFF)
// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = CODE_PROT_OFF      // General Segment Code Protection (Disabled)

/********************************************************************************/
/* SECCI?N DE DECLARACI?N DE CONSTANTES CON DEFINE								*/
/********************************************************************************/
#define EVER 1
//#define MUESTRAS 64

/********************************************************************************/
/* DECLARACIONES GLOBALES														*/
/********************************************************************************/
/*DECLARACI?N DE LA ISR DEL TIMER 1 USANDO __attribute__						*/
/********************************************************************************/
void __attribute__((__interrupt__)) _U2RXInterrupt( void );

#define BAJAR 1
#define SUBIR 0
#define ABRIR 1
#define CERRAR 0

void configurarPuertos();
void configurarInterrupciones();
void configurarTimer();
void configurarUART();
void bajarPiso(short int piso);
void subirPiso(short int piso);
void controlPuerta();

extern void iniLCD8bits( );
extern void banderaLCD( );
extern void comandoLCD(short int);
extern void ubicarCursor(short int);
extern void printLCD(char *);
extern void datoLCD( unsigned short int Dato );
extern void RETARDO_1S();

short int comandoUART, datoRCV; //Indica si sube o baja el motor de la puerta
short int detectorInt0,detectorInt1,detectorInt2 = 0;
short int detectorPiso;

int main(void) 
{    
    configurarPuertos();
    configurarTimer();
    iniLCD8bits();
    configurarUART();
    configurarInterrupciones();
    
    for(;EVER;)
    {
        if(datoRCV == 1){
            if(comandoUART == 1){
                subirPiso(detectorPiso);
            } else if(comandoUART == 2){
                bajarPiso(detectorPiso);
            }else{
                controlPuerta();
            }
            datoRCV = 0;
        }
     //   asm("nop");
    }
    
    return 0;
}

void configurarUART(){
    U1MODE = 0X04A0;
    U1STA = 0X8000;
    U1BRG = 11;
}

void configurarTimer(){
    TMR1 = 0;
    PR1 = 900;
    T1CON = 0;
    //TIMER 2
    TMR2 = 0;
    PR2 = 900;
    T2CON = 0;
}

void bajarPiso(short int piso){
    //Activamos motor
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    T1CONbits.TON = 1; //Activamos Timer
    PORTBbits.RB8 = BAJAR;
    asm("nop");
    //Si detecta que esta en el segundo piso
    if(detectorPiso == 0){
        printLCD("Piso 2");
    }else if(detectorPiso == 1){
        printLCD("Bajo: piso 1");
    }else{
        printLCD("Bajo: Planta baja");
    }
    
    //DESACTIVANDO MOTOR
    IEC0bits.T1IE = 0;
    T1CONbits.TON = 0; //Activamos Timer
    PORTBbits.RB8 = 0;
    asm("nop");
    
    banderaLCD();
    comandoLCD(1);   //Limpiar DISPLAY
    banderaLCD();
}
void subirPiso(short int piso){
    //Activamos motor
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    T1CONbits.TON = 1; //Activamos Timer
    PORTBbits.RB8 = SUBIR;
    asm("nop");
    //Si detecta que esta en el segundo piso
    if(detectorPiso == 0){
        printLCD("Sube: piso 2");
    }else if(detectorPiso == 1){
        printLCD("Sube: piso 1");
    }else{
        printLCD("Planta baja");
    }
    
    //DESACTIVANDO MOTOR
    IEC0bits.T1IE = 0;
    T1CONbits.TON = 0; //Activamos Timer
    PORTBbits.RB8 = 0;
    asm("nop");
    
    banderaLCD();
    comandoLCD(1);   //Limpiar DISPLAY
    banderaLCD();
}
void controlPuerta(){
    //Activamos motor
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;
    T2CONbits.TON = 1; //Activamos Timer
    PORTBbits.RB9 = ABRIR;
    RETARDO_1S();
    PORTBbits.RB9 = CERRAR;
    
    //DESCATIVANDO
    IEC0bits.T2IE = 0;
    T2CONbits.TON = 0; //Activamos Timer
    PORTBbits.RB9 = 0;
    asm("nop");
}

void configurarInterrupciones(){
    
    
    //INTERRUPCIONES SENSOR SEGUNDO PISO
    IFS0bits.INT0IF = 0;
    INTCON2bits.INT0EP = 1; //FLANCO BAJADA
    IEC0bits.INT0IE = 1; //HABILITAMOS
    
    /***/
    //INTERRUPCIONES SENSOR PRIMER PISO
    IFS1bits.INT1IF = 0;
    INTCON2bits.INT1EP = 1;     //set up INTO on negative edge (falling edge 1, rising edge 0) 
    IEC1bits.INT1IE = 1;
    
    //INTERRUPCIONES SENSOR PLANTA BAJA
    IFS1bits.INT2IF = 0;
    INTCON2bits.INT2EP = 1;     //set up INTO on negative edge (falling edge 1, rising edge 0) 
    IEC1bits.INT2IE = 1; //HABILITAMOS
    
    //Interrupciones UART
    IFS0bits.U1RXIF = 0;
    IEC0bits.U1RXIE = 1;
    
}
void configurarPuertos()
{
    PORTD = 0;              //CLR       PORTD
    asm("nop");             //ENSAMBLADOR EN LINEA
    LATD = 0;               //CLR       LATD
    asm("nop");
    TRISDbits.TRISD8 = 1;   //BCLR TRISD, #TRISD8
    asm("nop");
    TRISDbits.TRISD9 = 1;   //BCLR TRISD, #TRISD8
    asm("nop");

    PORTF = 0;
    asm("nop");
    LATF = 0;
    asm("nop");
    TRISFbits.TRISF4 = 0;
    asm("nop");
    TRISFbits.TRISF5 = 0;
    asm("nop");
    TRISFbits.TRISF6 = 1;
    asm("nop");
    
    PORTB = 0;
    asm("nop");
    LATB = 0;
    asm("nop");
    TRISB = 0;

    asm("nop");
    ADPCFG = 0XFFFF;
    
    PORTC = 0;
    asm("nop");
    LATC = 0;
    asm("nop");
    TRISCbits.TRISC13 = 0;
    asm("nop");
    TRISCbits.TRISC14 = 1;
    asm("nop");
    
}
/**  @brief: CONFIGURACION DEL UART 1. EL UART 1 SE COMUNICA CON 
 *           EL FT232 PARA COMUNICACION CON PC
 *   @baudrate: 115200 BAUDIOS
 *   @frame: 8 BITS X DATO, SIN PARIDAD, 1 BIT DE PARO
 */

/********************************************************************************/
/* DESCRICION:	ISR (INTERRUPT SERVICE ROUTINE) DE RECEPCION DEL UART 2			*/
/* LA RUTINA TIENE QUE SER GLOBAL PARA SER UNA ISR								*/	
/* SE USA PUSH.S PARA GUARDAR LOS REGISTROS W0, W1, W2, W3, C, Z, N Y DC EN LOS */
/* REGISTROS SOMBRA																*/
/********************************************************************************/
void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt( void )
{
  
    IFS1bits.U2RXIF = 0;
}

