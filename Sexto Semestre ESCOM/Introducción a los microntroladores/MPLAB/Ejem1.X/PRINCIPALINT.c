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

extern void iniLCD8bits( );
extern void banderaLCD( );
extern void datoLCD( unsigned short int Dato );

int main(void) 
{    
    configurarPuertos();
    
    iniLCD8bits();
    banderaLCD();
    datoLCD('I');  //W0 = 'I'
    banderaLCD();
    datoLCD('P');
    banderaLCD();
    datoLCD('N');
    
   
    for(;EVER;)
    {
        asm("nop");
    }
    
    return 0;
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

