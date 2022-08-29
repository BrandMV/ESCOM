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

void configurarPuertos();
void configurarInterrupciones();

extern void iniLCD8bits( );
extern void banderaLCD( );
extern void comandoLCD(short int);
extern void ubicarCursor(short int);
extern void printLCD(char *);
extern void datoLCD( unsigned short int Dato );
char contador[5];

int main(void) 
{    
    configurarPuertos();
    iniLCD8bits();
    
    //banderaLCD(); //*Preguntamos si esta libre el LCD
    //comandoLCD(0x84); //DDRAM_ADDRESS_SET 4
    ubicarCursor(4);


    configurarInterrupciones();
    
    //contador[4] = 0; //nulo
    
    for(;EVER;)
    {

        ubicarCursor(0X46);
        printLCD(contador);
     //   asm("nop");
    }
    
    return 0;
}
void configurarInterrupciones(){
    //INTERRUPCIONES SEGUNDO PISO
    IFS0bits.INT0IF = 0;
    INTCON2bits.INT0EP = 1;     //set up INTO on negative edge (falling edge 1, rising edge 0) 
    //INTCON2BITS.INT0EP = 1; //FLANCO BAJADA
    IEC0bits.INT0IE = 1; //HABILITAMOS
    
    //INTERRUPCIONES PRIMER PISO
    IFS0bits.INT1IF = 0;
    INTCON2bits.INT1EP = 1;     //set up INTO on negative edge (falling edge 1, rising edge 0) 
    //INTCON2BITS.INT0EP = 1; //FLANCO BAJADA
    IEC0bits.INT1IE = 1; //HABILITAMOS
    
    //INTERRUPCIONES PLANTA BAJA
    IFS0bits.INT2IF = 0;
    INTCON2bits.INT2EP = 1;     //set up INTO on negative edge (falling edge 1, rising edge 0) 
    //INTCON2BITS.INT0EP = 1; //FLANCO BAJADA
    IEC0bits.INT2IE = 1; //HABILITAMOS
    
}
void configurarPuertos()
{
    PORTD = 0;              //CLR       PORTD
    asm("nop");             //ENSAMBLADOR EN LINEA
    LATD = 0;               //CLR       LATD
    asm("nop");
    TRISDbits.TRISD8 = 0;   //BCLR TRISD, #TRISD8
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

