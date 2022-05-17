;==========================================================================
;  PIC30F3013 Standard Assembly Include File
; 
;  (c) Copyright 2022 Microchip Technology, All rights reserved
;  Part support version 2.00.A(24-Jan-2022)
; 
 ; This software is developed by Microchip Technology Inc. and its
 ; subsidiaries ("Microchip").
 ; 
 ; Redistribution and use in source and binary forms, with or without
 ; modification, are permitted provided that the following conditions are 
 ; met:
 ; 
 ; 1.      Redistributions of source code must retain the above copyright
 ;         notice, this list of conditions and the following disclaimer.
 ; 2.      Redistributions in binary form must reproduce the above 
 ;         copyright notice, this list of conditions and the following 
 ;         disclaimer in the documentation and/or other materials provided 
 ;         with the distribution. Publication is not required when
 ;         this file is used in an embedded application.
 ; 3.      Microchip's name may not be used to endorse or promote products
 ;         derived from this software without specific prior written 
 ;         permission.
 ; 
 ; THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 ; WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 ; MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 ; SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 ; EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 ; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 ; OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 ; WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 ; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ; ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ; 
 ;

.ifndef __30F3013_INC
.equ __30F3013_INC,1
.NOLIST

;==========================================================================
;  This header file defines configurations, registers, and other useful
;  bits of information for the PIC30F3013 microcontroller.  These names
;  are taken to match the data sheets as closely as possible.
;
;  Note that the processor must be selected before this file is included.
;  The processor may be selected the following ways:
;
;       1. Command line switch:
;               C:\> pic30-as file.s -p30F3013
;       2. Placing a ".equ" directive before the ".include":
;               .equ __30F3013, 1
;               .include "p30F3013.inc"
;       3. Setting the processor in the MPLAB IDE Project Dialog
;==========================================================================

;==========================================================================
;
;       Verify Processor
;
;==========================================================================

.IFNDEF __30F3013
   .ERROR "Include file does not match processor setting."
.ENDIF


;==========================================================================
;
;       Register Definitions
;
;==========================================================================

;----- Register Equates (Low Byte, High Byte) -----------------------------

        .extern WREG0
        .equiv  WREG0L, _WREG0
        .equiv  WREG0H, _WREG0+1

        .extern WREG1
        .equiv  WREG1L, _WREG1
        .equiv  WREG1H, _WREG1+1

        .extern WREG2
        .equiv  WREG2L, _WREG2
        .equiv  WREG2H, _WREG2+1

        .extern WREG3
        .equiv  WREG3L, _WREG3
        .equiv  WREG3H, _WREG3+1

        .extern WREG4
        .equiv  WREG4L, _WREG4
        .equiv  WREG4H, _WREG4+1

        .extern WREG5
        .equiv  WREG5L, _WREG5
        .equiv  WREG5H, _WREG5+1

        .extern WREG6
        .equiv  WREG6L, _WREG6
        .equiv  WREG6H, _WREG6+1

        .extern WREG7
        .equiv  WREG7L, _WREG7
        .equiv  WREG7H, _WREG7+1

        .extern WREG8
        .equiv  WREG8L, _WREG8
        .equiv  WREG8H, _WREG8+1

        .extern WREG9
        .equiv  WREG9L, _WREG9
        .equiv  WREG9H, _WREG9+1

        .extern WREG10
        .equiv  WREG10L, _WREG10
        .equiv  WREG10H, _WREG10+1

        .extern WREG11
        .equiv  WREG11L, _WREG11
        .equiv  WREG11H, _WREG11+1

        .extern WREG12
        .equiv  WREG12L, _WREG12
        .equiv  WREG12H, _WREG12+1

        .extern WREG13
        .equiv  WREG13L, _WREG13
        .equiv  WREG13H, _WREG13+1

        .extern WREG14
        .equiv  WREG14L, _WREG14
        .equiv  WREG14H, _WREG14+1

        .extern WREG15
        .equiv  WREG15L, _WREG15
        .equiv  WREG15H, _WREG15+1

        .extern SPLIM
        .equiv  SPLIML, _SPLIM
        .equiv  SPLIMH, _SPLIM+1

        .extern ACCAL
        .equiv  ACCALL, _ACCAL
        .equiv  ACCALH, _ACCAL+1

        .extern ACCAH
        .equiv  ACCAHL, _ACCAH
        .equiv  ACCAHH, _ACCAH+1

        .extern ACCAU
        .equiv  ACCAUL, _ACCAU
        .equiv  ACCAUH, _ACCAU+1

        .extern ACCBL
        .equiv  ACCBLL, _ACCBL
        .equiv  ACCBLH, _ACCBL+1

        .extern ACCBH
        .equiv  ACCBHL, _ACCBH
        .equiv  ACCBHH, _ACCBH+1

        .extern ACCBU
        .equiv  ACCBUL, _ACCBU
        .equiv  ACCBUH, _ACCBU+1

        .extern PCL
        .equiv  PCLL, _PCL
        .equiv  PCLH, _PCL+1

        .extern PCH
        .equiv  PCHL, _PCH
        .equiv  PCHH, _PCH+1

        .extern TBLPAG
        .equiv  TBLPAGL, _TBLPAG
        .equiv  TBLPAGH, _TBLPAG+1

        .extern PSVPAG
        .equiv  PSVPAGL, _PSVPAG
        .equiv  PSVPAGH, _PSVPAG+1

        .extern RCOUNT
        .equiv  RCOUNTL, _RCOUNT
        .equiv  RCOUNTH, _RCOUNT+1

        .extern DCOUNT
        .equiv  DCOUNTL, _DCOUNT
        .equiv  DCOUNTH, _DCOUNT+1

        .extern DOSTARTL
        .equiv  DOSTARTLL, _DOSTARTL
        .equiv  DOSTARTLH, _DOSTARTL+1

        .extern DOSTARTH
        .equiv  DOSTARTHL, _DOSTARTH
        .equiv  DOSTARTHH, _DOSTARTH+1

        .extern DOENDL
        .equiv  DOENDLL, _DOENDL
        .equiv  DOENDLH, _DOENDL+1

        .extern DOENDH
        .equiv  DOENDHL, _DOENDH
        .equiv  DOENDHH, _DOENDH+1

        .extern SR
        .equiv  SRL, _SR
        .equiv  SRH, _SR+1

        .extern CORCON
        .equiv  CORCONL, _CORCON
        .equiv  CORCONH, _CORCON+1

        .extern MODCON
        .equiv  MODCONL, _MODCON
        .equiv  MODCONH, _MODCON+1

        .extern XMODSRT
        .equiv  XMODSRTL, _XMODSRT
        .equiv  XMODSRTH, _XMODSRT+1

        .extern XMODEND
        .equiv  XMODENDL, _XMODEND
        .equiv  XMODENDH, _XMODEND+1

        .extern YMODSRT
        .equiv  YMODSRTL, _YMODSRT
        .equiv  YMODSRTH, _YMODSRT+1

        .extern YMODEND
        .equiv  YMODENDL, _YMODEND
        .equiv  YMODENDH, _YMODEND+1

        .extern XBREV
        .equiv  XBREVL, _XBREV
        .equiv  XBREVH, _XBREV+1

        .extern DISICNT
        .equiv  DISICNTL, _DISICNT
        .equiv  DISICNTH, _DISICNT+1

        .extern INTCON1
        .equiv  INTCON1L, _INTCON1
        .equiv  INTCON1H, _INTCON1+1

        .extern INTCON2
        .equiv  INTCON2L, _INTCON2
        .equiv  INTCON2H, _INTCON2+1

        .extern IFS0
        .equiv  IFS0L, _IFS0
        .equiv  IFS0H, _IFS0+1

        .extern IFS1
        .equiv  IFS1L, _IFS1
        .equiv  IFS1H, _IFS1+1

        .extern IFS2
        .equiv  IFS2L, _IFS2
        .equiv  IFS2H, _IFS2+1

        .extern IEC0
        .equiv  IEC0L, _IEC0
        .equiv  IEC0H, _IEC0+1

        .extern IEC1
        .equiv  IEC1L, _IEC1
        .equiv  IEC1H, _IEC1+1

        .extern IEC2
        .equiv  IEC2L, _IEC2
        .equiv  IEC2H, _IEC2+1

        .extern IPC0
        .equiv  IPC0L, _IPC0
        .equiv  IPC0H, _IPC0+1

        .extern IPC1
        .equiv  IPC1L, _IPC1
        .equiv  IPC1H, _IPC1+1

        .extern IPC2
        .equiv  IPC2L, _IPC2
        .equiv  IPC2H, _IPC2+1

        .extern IPC3
        .equiv  IPC3L, _IPC3
        .equiv  IPC3H, _IPC3+1

        .extern IPC4
        .equiv  IPC4L, _IPC4
        .equiv  IPC4H, _IPC4+1

        .extern IPC5
        .equiv  IPC5L, _IPC5
        .equiv  IPC5H, _IPC5+1

        .extern IPC6
        .equiv  IPC6L, _IPC6
        .equiv  IPC6H, _IPC6+1

        .extern IPC10
        .equiv  IPC10L, _IPC10
        .equiv  IPC10H, _IPC10+1

        .extern INTTREG
        .equiv  INTTREGL, _INTTREG
        .equiv  INTTREGH, _INTTREG+1

        .extern CNEN1
        .equiv  CNEN1L, _CNEN1
        .equiv  CNEN1H, _CNEN1+1

        .extern CNEN2
        .equiv  CNEN2L, _CNEN2
        .equiv  CNEN2H, _CNEN2+1

        .extern CNPU1
        .equiv  CNPU1L, _CNPU1
        .equiv  CNPU1H, _CNPU1+1

        .extern CNPU2
        .equiv  CNPU2L, _CNPU2
        .equiv  CNPU2H, _CNPU2+1

        .extern TMR1
        .equiv  TMR1L, _TMR1
        .equiv  TMR1H, _TMR1+1

        .extern PR1
        .equiv  PR1L, _PR1
        .equiv  PR1H, _PR1+1

        .extern T1CON
        .equiv  T1CONL, _T1CON
        .equiv  T1CONH, _T1CON+1

        .extern TMR2
        .equiv  TMR2L, _TMR2
        .equiv  TMR2H, _TMR2+1

        .extern TMR3HLD
        .equiv  TMR3HLDL, _TMR3HLD
        .equiv  TMR3HLDH, _TMR3HLD+1

        .extern TMR3
        .equiv  TMR3L, _TMR3
        .equiv  TMR3H, _TMR3+1

        .extern PR2
        .equiv  PR2L, _PR2
        .equiv  PR2H, _PR2+1

        .extern PR3
        .equiv  PR3L, _PR3
        .equiv  PR3H, _PR3+1

        .extern T2CON
        .equiv  T2CONL, _T2CON
        .equiv  T2CONH, _T2CON+1

        .extern T3CON
        .equiv  T3CONL, _T3CON
        .equiv  T3CONH, _T3CON+1

        .extern IC1BUF
        .equiv  IC1BUFL, _IC1BUF
        .equiv  IC1BUFH, _IC1BUF+1

        .extern IC1CON
        .equiv  IC1CONL, _IC1CON
        .equiv  IC1CONH, _IC1CON+1

        .extern IC2BUF
        .equiv  IC2BUFL, _IC2BUF
        .equiv  IC2BUFH, _IC2BUF+1

        .extern IC2CON
        .equiv  IC2CONL, _IC2CON
        .equiv  IC2CONH, _IC2CON+1

        .extern OC1RS
        .equiv  OC1RSL, _OC1RS
        .equiv  OC1RSH, _OC1RS+1

        .extern OC1R
        .equiv  OC1RL, _OC1R
        .equiv  OC1RH, _OC1R+1

        .extern OC1CON
        .equiv  OC1CONL, _OC1CON
        .equiv  OC1CONH, _OC1CON+1

        .extern OC2RS
        .equiv  OC2RSL, _OC2RS
        .equiv  OC2RSH, _OC2RS+1

        .extern OC2R
        .equiv  OC2RL, _OC2R
        .equiv  OC2RH, _OC2R+1

        .extern OC2CON
        .equiv  OC2CONL, _OC2CON
        .equiv  OC2CONH, _OC2CON+1

        .extern I2CRCV
        .equiv  I2CRCVL, _I2CRCV
        .equiv  I2CRCVH, _I2CRCV+1

        .extern I2CTRN
        .equiv  I2CTRNL, _I2CTRN
        .equiv  I2CTRNH, _I2CTRN+1

        .extern I2CBRG
        .equiv  I2CBRGL, _I2CBRG
        .equiv  I2CBRGH, _I2CBRG+1

        .extern I2CCON
        .equiv  I2CCONL, _I2CCON
        .equiv  I2CCONH, _I2CCON+1

        .extern I2CSTAT
        .equiv  I2CSTATL, _I2CSTAT
        .equiv  I2CSTATH, _I2CSTAT+1

        .extern I2CADD
        .equiv  I2CADDL, _I2CADD
        .equiv  I2CADDH, _I2CADD+1

        .extern U1MODE
        .equiv  U1MODEL, _U1MODE
        .equiv  U1MODEH, _U1MODE+1

        .extern U1STA
        .equiv  U1STAL, _U1STA
        .equiv  U1STAH, _U1STA+1

        .extern U1TXREG
        .equiv  U1TXREGL, _U1TXREG
        .equiv  U1TXREGH, _U1TXREG+1

        .extern U1RXREG
        .equiv  U1RXREGL, _U1RXREG
        .equiv  U1RXREGH, _U1RXREG+1

        .extern U1BRG
        .equiv  U1BRGL, _U1BRG
        .equiv  U1BRGH, _U1BRG+1

        .extern U2MODE
        .equiv  U2MODEL, _U2MODE
        .equiv  U2MODEH, _U2MODE+1

        .extern U2STA
        .equiv  U2STAL, _U2STA
        .equiv  U2STAH, _U2STA+1

        .extern U2TXREG
        .equiv  U2TXREGL, _U2TXREG
        .equiv  U2TXREGH, _U2TXREG+1

        .extern U2RXREG
        .equiv  U2RXREGL, _U2RXREG
        .equiv  U2RXREGH, _U2RXREG+1

        .extern U2BRG
        .equiv  U2BRGL, _U2BRG
        .equiv  U2BRGH, _U2BRG+1

        .extern SPI1STAT
        .equiv  SPI1STATL, _SPI1STAT
        .equiv  SPI1STATH, _SPI1STAT+1

        .extern SPI1CON
        .equiv  SPI1CONL, _SPI1CON
        .equiv  SPI1CONH, _SPI1CON+1

        .extern SPI1BUF
        .equiv  SPI1BUFL, _SPI1BUF
        .equiv  SPI1BUFH, _SPI1BUF+1

        .extern ADCBUF0
        .equiv  ADCBUF0L, _ADCBUF0
        .equiv  ADCBUF0H, _ADCBUF0+1

        .extern ADCBUF1
        .equiv  ADCBUF1L, _ADCBUF1
        .equiv  ADCBUF1H, _ADCBUF1+1

        .extern ADCBUF2
        .equiv  ADCBUF2L, _ADCBUF2
        .equiv  ADCBUF2H, _ADCBUF2+1

        .extern ADCBUF3
        .equiv  ADCBUF3L, _ADCBUF3
        .equiv  ADCBUF3H, _ADCBUF3+1

        .extern ADCBUF4
        .equiv  ADCBUF4L, _ADCBUF4
        .equiv  ADCBUF4H, _ADCBUF4+1

        .extern ADCBUF5
        .equiv  ADCBUF5L, _ADCBUF5
        .equiv  ADCBUF5H, _ADCBUF5+1

        .extern ADCBUF6
        .equiv  ADCBUF6L, _ADCBUF6
        .equiv  ADCBUF6H, _ADCBUF6+1

        .extern ADCBUF7
        .equiv  ADCBUF7L, _ADCBUF7
        .equiv  ADCBUF7H, _ADCBUF7+1

        .extern ADCBUF8
        .equiv  ADCBUF8L, _ADCBUF8
        .equiv  ADCBUF8H, _ADCBUF8+1

        .extern ADCBUF9
        .equiv  ADCBUF9L, _ADCBUF9
        .equiv  ADCBUF9H, _ADCBUF9+1

        .extern ADCBUFA
        .equiv  ADCBUFAL, _ADCBUFA
        .equiv  ADCBUFAH, _ADCBUFA+1

        .extern ADCBUFB
        .equiv  ADCBUFBL, _ADCBUFB
        .equiv  ADCBUFBH, _ADCBUFB+1

        .extern ADCBUFC
        .equiv  ADCBUFCL, _ADCBUFC
        .equiv  ADCBUFCH, _ADCBUFC+1

        .extern ADCBUFD
        .equiv  ADCBUFDL, _ADCBUFD
        .equiv  ADCBUFDH, _ADCBUFD+1

        .extern ADCBUFE
        .equiv  ADCBUFEL, _ADCBUFE
        .equiv  ADCBUFEH, _ADCBUFE+1

        .extern ADCBUFF
        .equiv  ADCBUFFL, _ADCBUFF
        .equiv  ADCBUFFH, _ADCBUFF+1

        .extern ADCON1
        .equiv  ADCON1L, _ADCON1
        .equiv  ADCON1H, _ADCON1+1

        .extern ADCON2
        .equiv  ADCON2L, _ADCON2
        .equiv  ADCON2H, _ADCON2+1

        .extern ADCON3
        .equiv  ADCON3L, _ADCON3
        .equiv  ADCON3H, _ADCON3+1

        .extern ADCHS
        .equiv  ADCHSL, _ADCHS
        .equiv  ADCHSH, _ADCHS+1

        .extern ADPCFG
        .equiv  ADPCFGL, _ADPCFG
        .equiv  ADPCFGH, _ADPCFG+1

        .extern ADCSSL
        .equiv  ADCSSLL, _ADCSSL
        .equiv  ADCSSLH, _ADCSSL+1

        .extern TRISB
        .equiv  TRISBL, _TRISB
        .equiv  TRISBH, _TRISB+1

        .extern PORTB
        .equiv  PORTBL, _PORTB
        .equiv  PORTBH, _PORTB+1

        .extern LATB
        .equiv  LATBL, _LATB
        .equiv  LATBH, _LATB+1

        .extern TRISC
        .equiv  TRISCL, _TRISC
        .equiv  TRISCH, _TRISC+1

        .extern PORTC
        .equiv  PORTCL, _PORTC
        .equiv  PORTCH, _PORTC+1

        .extern LATC
        .equiv  LATCL, _LATC
        .equiv  LATCH, _LATC+1

        .extern TRISD
        .equiv  TRISDL, _TRISD
        .equiv  TRISDH, _TRISD+1

        .extern PORTD
        .equiv  PORTDL, _PORTD
        .equiv  PORTDH, _PORTD+1

        .extern LATD
        .equiv  LATDL, _LATD
        .equiv  LATDH, _LATD+1

        .extern TRISF
        .equiv  TRISFL, _TRISF
        .equiv  TRISFH, _TRISF+1

        .extern PORTF
        .equiv  PORTFL, _PORTF
        .equiv  PORTFH, _PORTF+1

        .extern LATF
        .equiv  LATFL, _LATF
        .equiv  LATFH, _LATF+1

        .extern RCON
        .equiv  RCONL, _RCON
        .equiv  RCONH, _RCON+1

        .extern OSCCON

        .extern OSCCONL
        .equiv  OSCCONLL, _OSCCONL
        .equiv  OSCCONLH, _OSCCONL+1

        .extern OSCCONH
        .equiv  OSCCONHL, _OSCCONH
        .equiv  OSCCONHH, _OSCCONH+1

        .extern OSCTUN
        .equiv  OSCTUNL, _OSCTUN
        .equiv  OSCTUNH, _OSCTUN+1

        .extern NVMCON
        .equiv  NVMCONL, _NVMCON
        .equiv  NVMCONH, _NVMCON+1

        .extern NVMADR
        .equiv  NVMADRL, _NVMADR
        .equiv  NVMADRH, _NVMADR+1

        .extern NVMADRU
        .equiv  NVMADRUL, _NVMADRU
        .equiv  NVMADRUH, _NVMADRU+1

        .extern NVMKEY
        .equiv  NVMKEYL, _NVMKEY
        .equiv  NVMKEYH, _NVMKEY+1

        .extern PMD1
        .equiv  PMD1L, _PMD1
        .equiv  PMD1H, _PMD1+1

        .extern PMD2
        .equiv  PMD2L, _PMD2
        .equiv  PMD2H, _PMD2+1

;----- SR Bits -----------------------------------------------------
        .equiv C,       0x0000
        .equiv Z,       0x0001
        .equiv OV,      0x0002
        .equiv N,       0x0003
        .equiv RA,      0x0004
        .equiv DC,      0x0008
        .equiv DA,      0x0009
        .equiv SAB,     0x000A
        .equiv OAB,     0x000B
        .equiv SB,      0x000C
        .equiv SA,      0x000D
        .equiv OB,      0x000E
        .equiv OA,      0x000F

        .equiv IPL0,    0x0005
        .equiv IPL1,    0x0006
        .equiv IPL2,    0x0007


;----- CORCON Bits -----------------------------------------------------
        .equiv IF,      0x0000
        .equiv RND,     0x0001
        .equiv PSV,     0x0002
        .equiv IPL3,    0x0003
        .equiv ACCSAT,  0x0004
        .equiv SATDW,   0x0005
        .equiv SATB,    0x0006
        .equiv SATA,    0x0007
        .equiv EDT,     0x000B
        .equiv US,      0x000C

        .equiv DL0,     0x0008
        .equiv DL1,     0x0009
        .equiv DL2,     0x000A


;----- MODCON Bits -----------------------------------------------------
        .equiv YMODEN,  0x000E
        .equiv XMODEN,  0x000F

        .equiv XWM0,    0x0000
        .equiv XWM1,    0x0001
        .equiv XWM2,    0x0002
        .equiv XWM3,    0x0003
        .equiv YWM0,    0x0004
        .equiv YWM1,    0x0005
        .equiv YWM2,    0x0006
        .equiv YWM3,    0x0007
        .equiv BWM0,    0x0008
        .equiv BWM1,    0x0009
        .equiv BWM2,    0x000A
        .equiv BWM3,    0x000B


;----- XBREV Bits -----------------------------------------------------
        .equiv BREN,    0x000F

        .equiv XB0,     0x0000
        .equiv XB1,     0x0001
        .equiv XB2,     0x0002
        .equiv XB3,     0x0003
        .equiv XB4,     0x0004
        .equiv XB5,     0x0005
        .equiv XB6,     0x0006
        .equiv XB7,     0x0007
        .equiv XB8,     0x0008
        .equiv XB9,     0x0009
        .equiv XB10,    0x000A
        .equiv XB11,    0x000B
        .equiv XB12,    0x000C
        .equiv XB13,    0x000D
        .equiv XB14,    0x000E


;----- INTCON1 Bits -----------------------------------------------------
        .equiv OSCFAIL, 0x0001
        .equiv STKERR,  0x0002
        .equiv ADDRERR, 0x0003
        .equiv MATHERR, 0x0004
        .equiv COVTE,   0x0008
        .equiv OVBTE,   0x0009
        .equiv OVATE,   0x000A
        .equiv NSTDIS,  0x000F


;----- INTCON2 Bits -----------------------------------------------------
        .equiv INT0EP,  0x0000
        .equiv INT1EP,  0x0001
        .equiv INT2EP,  0x0002
        .equiv DISI,    0x000E
        .equiv ALTIVT,  0x000F


;----- IFS0 Bits -----------------------------------------------------
        .equiv INT0IF,  0x0000
        .equiv IC1IF,   0x0001
        .equiv OC1IF,   0x0002
        .equiv T1IF,    0x0003
        .equiv IC2IF,   0x0004
        .equiv OC2IF,   0x0005
        .equiv T2IF,    0x0006
        .equiv T3IF,    0x0007
        .equiv SPI1IF,  0x0008
        .equiv U1RXIF,  0x0009
        .equiv U1TXIF,  0x000A
        .equiv ADIF,    0x000B
        .equiv NVMIF,   0x000C
        .equiv SI2CIF,  0x000D
        .equiv MI2CIF,  0x000E
        .equiv CNIF,    0x000F


;----- IFS1 Bits -----------------------------------------------------
        .equiv INT1IF,  0x0000
        .equiv INT2IF,  0x0007
        .equiv U2RXIF,  0x0008
        .equiv U2TXIF,  0x0009


;----- IFS2 Bits -----------------------------------------------------
        .equiv LVDIF,   0x000A


;----- IEC0 Bits -----------------------------------------------------
        .equiv INT0IE,  0x0000
        .equiv IC1IE,   0x0001
        .equiv OC1IE,   0x0002
        .equiv T1IE,    0x0003
        .equiv IC2IE,   0x0004
        .equiv OC2IE,   0x0005
        .equiv T2IE,    0x0006
        .equiv T3IE,    0x0007
        .equiv SPI1IE,  0x0008
        .equiv U1RXIE,  0x0009
        .equiv U1TXIE,  0x000A
        .equiv ADIE,    0x000B
        .equiv NVMIE,   0x000C
        .equiv SI2CIE,  0x000D
        .equiv MI2CIE,  0x000E
        .equiv CNIE,    0x000F


;----- IEC1 Bits -----------------------------------------------------
        .equiv INT1IE,  0x0000
        .equiv INT2IE,  0x0007
        .equiv U2RXIE,  0x0008
        .equiv U2TXIE,  0x0009


;----- IEC2 Bits -----------------------------------------------------
        .equiv LVDIE,   0x000A


;----- IPC0 Bits -----------------------------------------------------
        .equiv INT0IP0, 0x0000
        .equiv INT0IP1, 0x0001
        .equiv INT0IP2, 0x0002
        .equiv IC1IP0,  0x0004
        .equiv IC1IP1,  0x0005
        .equiv IC1IP2,  0x0006
        .equiv OC1IP0,  0x0008
        .equiv OC1IP1,  0x0009
        .equiv OC1IP2,  0x000A
        .equiv T1IP0,   0x000C
        .equiv T1IP1,   0x000D
        .equiv T1IP2,   0x000E


;----- IPC1 Bits -----------------------------------------------------
        .equiv IC2IP0,  0x0000
        .equiv IC2IP1,  0x0001
        .equiv IC2IP2,  0x0002
        .equiv OC2IP0,  0x0004
        .equiv OC2IP1,  0x0005
        .equiv OC2IP2,  0x0006
        .equiv T2IP0,   0x0008
        .equiv T2IP1,   0x0009
        .equiv T2IP2,   0x000A
        .equiv T3IP0,   0x000C
        .equiv T3IP1,   0x000D
        .equiv T3IP2,   0x000E


;----- IPC2 Bits -----------------------------------------------------
        .equiv SPI1IP0, 0x0000
        .equiv SPI1IP1, 0x0001
        .equiv SPI1IP2, 0x0002
        .equiv U1RXIP0, 0x0004
        .equiv U1RXIP1, 0x0005
        .equiv U1RXIP2, 0x0006
        .equiv U1TXIP0, 0x0008
        .equiv U1TXIP1, 0x0009
        .equiv U1TXIP2, 0x000A
        .equiv ADIP0,   0x000C
        .equiv ADIP1,   0x000D
        .equiv ADIP2,   0x000E


;----- IPC3 Bits -----------------------------------------------------
        .equiv NVMIP0,  0x0000
        .equiv NVMIP1,  0x0001
        .equiv NVMIP2,  0x0002
        .equiv SI2CIP0, 0x0004
        .equiv SI2CIP1, 0x0005
        .equiv SI2CIP2, 0x0006
        .equiv MI2CIP0, 0x0008
        .equiv MI2CIP1, 0x0009
        .equiv MI2CIP2, 0x000A
        .equiv CNIP0,   0x000C
        .equiv CNIP1,   0x000D
        .equiv CNIP2,   0x000E


;----- IPC4 Bits -----------------------------------------------------
        .equiv INT1IP0, 0x0000
        .equiv INT1IP1, 0x0001
        .equiv INT1IP2, 0x0002


;----- IPC5 Bits -----------------------------------------------------
        .equiv INT2IP0, 0x000C
        .equiv INT2IP1, 0x000D
        .equiv INT2IP2, 0x000E


;----- IPC6 Bits -----------------------------------------------------
        .equiv U2RXIP0, 0x0000
        .equiv U2RXIP1, 0x0001
        .equiv U2RXIP2, 0x0002
        .equiv U2TXIP0, 0x0004
        .equiv U2TXIP1, 0x0005
        .equiv U2TXIP2, 0x0006


;----- IPC10 Bits -----------------------------------------------------
        .equiv LVDIP0,  0x0008
        .equiv LVDIP1,  0x0009
        .equiv LVDIP2,  0x000A


;----- INTTREG Bits -----------------------------------------------------
        .equiv VHOLD,   0x000D
        .equiv TMODE,   0x000E
        .equiv IRQTOCPU, 0x000F

        .equiv VECNUM0, 0x0000
        .equiv VECNUM1, 0x0001
        .equiv VECNUM2, 0x0002
        .equiv VECNUM3, 0x0003
        .equiv VECNUM4, 0x0004
        .equiv VECNUM5, 0x0005
        .equiv ILR0,    0x0008
        .equiv ILR1,    0x0009
        .equiv ILR2,    0x000A
        .equiv ILR3,    0x000B


;----- CNEN1 Bits -----------------------------------------------------
        .equiv CN0IE,   0x0000
        .equiv CN1IE,   0x0001
        .equiv CN2IE,   0x0002
        .equiv CN3IE,   0x0003
        .equiv CN4IE,   0x0004
        .equiv CN5IE,   0x0005
        .equiv CN6IE,   0x0006
        .equiv CN7IE,   0x0007


;----- CNEN2 Bits -----------------------------------------------------
        .equiv CN17IE,  0x0001
        .equiv CN18IE,  0x0002


;----- CNPU1 Bits -----------------------------------------------------
        .equiv CN0PUE,  0x0000
        .equiv CN1PUE,  0x0001
        .equiv CN2PUE,  0x0002
        .equiv CN3PUE,  0x0003
        .equiv CN4PUE,  0x0004
        .equiv CN5PUE,  0x0005
        .equiv CN6PUE,  0x0006
        .equiv CN7PUE,  0x0007


;----- CNPU2 Bits -----------------------------------------------------
        .equiv CN17PUE, 0x0001
        .equiv CN18PUE, 0x0002


;----- T1CON Bits -----------------------------------------------------
        .equiv TCS,     0x0001
        .equiv TSYNC,   0x0002
        .equiv TGATE,   0x0006
        .equiv TSIDL,   0x000D
        .equiv TON,     0x000F

        .equiv TCKPS0,  0x0004
        .equiv TCKPS1,  0x0005


;----- T2CON Bits -----------------------------------------------------
       ;.equiv TCS,     0x0001
        .equiv T32,     0x0003
       ;.equiv TGATE,   0x0006
       ;.equiv TSIDL,   0x000D
       ;.equiv TON,     0x000F

       ;.equiv TCKPS0,  0x0004
       ;.equiv TCKPS1,  0x0005


;----- T3CON Bits -----------------------------------------------------
       ;.equiv TCS,     0x0001
       ;.equiv TGATE,   0x0006
       ;.equiv TSIDL,   0x000D
       ;.equiv TON,     0x000F

       ;.equiv TCKPS0,  0x0004
       ;.equiv TCKPS1,  0x0005


;----- IC1CON Bits -----------------------------------------------------
        .equiv ICBNE,   0x0003
        .equiv ICOV,    0x0004
        .equiv ICTMR,   0x0007
        .equiv ICSIDL,  0x000D

        .equiv ICM0,    0x0000
        .equiv ICM1,    0x0001
        .equiv ICM2,    0x0002
        .equiv ICI0,    0x0005
        .equiv ICI1,    0x0006


;----- IC2CON Bits -----------------------------------------------------
       ;.equiv ICBNE,   0x0003
       ;.equiv ICOV,    0x0004
       ;.equiv ICTMR,   0x0007
       ;.equiv ICSIDL,  0x000D

       ;.equiv ICM0,    0x0000
       ;.equiv ICM1,    0x0001
       ;.equiv ICM2,    0x0002
       ;.equiv ICI0,    0x0005
       ;.equiv ICI1,    0x0006


;----- OC1CON Bits -----------------------------------------------------
        .equiv OCTSEL,  0x0003
        .equiv OCFLT,   0x0004
        .equiv OCSIDL,  0x000D

        .equiv OCM0,    0x0000
        .equiv OCM1,    0x0001
        .equiv OCM2,    0x0002


;----- OC2CON Bits -----------------------------------------------------
       ;.equiv OCTSEL,  0x0003
       ;.equiv OCFLT,   0x0004
       ;.equiv OCSIDL,  0x000D

       ;.equiv OCM0,    0x0000
       ;.equiv OCM1,    0x0001
       ;.equiv OCM2,    0x0002


;----- I2CRCV Bits -----------------------------------------------------
        .equiv I2CRCV0, 0x0000
        .equiv I2CRCV1, 0x0001
        .equiv I2CRCV2, 0x0002
        .equiv I2CRCV3, 0x0003
        .equiv I2CRCV4, 0x0004
        .equiv I2CRCV5, 0x0005
        .equiv I2CRCV6, 0x0006
        .equiv I2CRCV7, 0x0007


;----- I2CTRN Bits -----------------------------------------------------
        .equiv I2CTRN0, 0x0000
        .equiv I2CTRN1, 0x0001
        .equiv I2CTRN2, 0x0002
        .equiv I2CTRN3, 0x0003
        .equiv I2CTRN4, 0x0004
        .equiv I2CTRN5, 0x0005
        .equiv I2CTRN6, 0x0006
        .equiv I2CTRN7, 0x0007


;----- I2CCON Bits -----------------------------------------------------
        .equiv SEN,     0x0000
        .equiv RSEN,    0x0001
        .equiv PEN,     0x0002
        .equiv RCEN,    0x0003
        .equiv ACKEN,   0x0004
        .equiv ACKDT,   0x0005
        .equiv STREN,   0x0006
        .equiv GCEN,    0x0007
        .equiv SMEN,    0x0008
        .equiv DISSLW,  0x0009
        .equiv A10M,    0x000A
        .equiv IPMIEN,  0x000B
        .equiv SCLREL,  0x000C
        .equiv I2CSIDL, 0x000D
        .equiv I2CEN,   0x000F


;----- I2CSTAT Bits -----------------------------------------------------
        .equiv TBF,     0x0000
        .equiv RBF,     0x0001
        .equiv R_NOT_W, 0x0002
        .equiv S,       0x0003
        .equiv P,       0x0004
        .equiv D_NOT_A, 0x0005
        .equiv I2COV,   0x0006
        .equiv IWCOL,   0x0007
        .equiv ADD10,   0x0008
        .equiv GCSTAT,  0x0009
        .equiv BCL,     0x000A
        .equiv TRSTAT,  0x000E
        .equiv ACKSTAT, 0x000F

        .equiv R_W,     0x0002
        .equiv D_A,     0x0005


;----- U1MODE Bits -----------------------------------------------------
        .equiv STSEL,   0x0000
        .equiv ABAUD,   0x0005
        .equiv LPBACK,  0x0006
        .equiv WAKE,    0x0007
        .equiv ALTIO,   0x000A
        .equiv USIDL,   0x000D
        .equiv UARTEN,  0x000F

        .equiv PDSEL0,  0x0001
        .equiv PDSEL1,  0x0002


;----- U1STA Bits -----------------------------------------------------
        .equiv URXDA,   0x0000
        .equiv OERR,    0x0001
        .equiv FERR,    0x0002
        .equiv PERR,    0x0003
        .equiv RIDLE,   0x0004
        .equiv ADDEN,   0x0005
        .equiv TRMT,    0x0008
        .equiv UTXBF,   0x0009
        .equiv UTXEN,   0x000A
        .equiv UTXBRK,  0x000B
        .equiv UTXISEL, 0x000F

        .equiv URXISEL0, 0x0006
        .equiv URXISEL1, 0x0007


;----- U1TXREG Bits -----------------------------------------------------
        .equiv UTXREG0, 0x0000
        .equiv UTXREG1, 0x0001
        .equiv UTXREG2, 0x0002
        .equiv UTXREG3, 0x0003
        .equiv UTXREG4, 0x0004
        .equiv UTXREG5, 0x0005
        .equiv UTXREG6, 0x0006
        .equiv UTXREG7, 0x0007
        .equiv UTXREG8, 0x0008

        .equiv UTX8,    0x0008


;----- U1RXREG Bits -----------------------------------------------------
        .equiv URXREG0, 0x0000
        .equiv URXREG1, 0x0001
        .equiv URXREG2, 0x0002
        .equiv URXREG3, 0x0003
        .equiv URXREG4, 0x0004
        .equiv URXREG5, 0x0005
        .equiv URXREG6, 0x0006
        .equiv URXREG7, 0x0007
        .equiv URXREG8, 0x0008

        .equiv URX8,    0x0008


;----- U2MODE Bits -----------------------------------------------------
       ;.equiv STSEL,   0x0000
       ;.equiv ABAUD,   0x0005
       ;.equiv LPBACK,  0x0006
       ;.equiv WAKE,    0x0007
       ;.equiv USIDL,   0x000D
       ;.equiv UARTEN,  0x000F

       ;.equiv PDSEL0,  0x0001
       ;.equiv PDSEL1,  0x0002


;----- U2STA Bits -----------------------------------------------------
       ;.equiv URXDA,   0x0000
       ;.equiv OERR,    0x0001
       ;.equiv FERR,    0x0002
       ;.equiv PERR,    0x0003
       ;.equiv RIDLE,   0x0004
       ;.equiv ADDEN,   0x0005
       ;.equiv TRMT,    0x0008
       ;.equiv UTXBF,   0x0009
       ;.equiv UTXEN,   0x000A
       ;.equiv UTXBRK,  0x000B
       ;.equiv UTXISEL, 0x000F

       ;.equiv URXISEL0, 0x0006
       ;.equiv URXISEL1, 0x0007


;----- U2TXREG Bits -----------------------------------------------------
       ;.equiv UTXREG0, 0x0000
       ;.equiv UTXREG1, 0x0001
       ;.equiv UTXREG2, 0x0002
       ;.equiv UTXREG3, 0x0003
       ;.equiv UTXREG4, 0x0004
       ;.equiv UTXREG5, 0x0005
       ;.equiv UTXREG6, 0x0006
       ;.equiv UTXREG7, 0x0007
       ;.equiv UTXREG8, 0x0008

       ;.equiv UTX8,    0x0008


;----- U2RXREG Bits -----------------------------------------------------
       ;.equiv URXREG0, 0x0000
       ;.equiv URXREG1, 0x0001
       ;.equiv URXREG2, 0x0002
       ;.equiv URXREG3, 0x0003
       ;.equiv URXREG4, 0x0004
       ;.equiv URXREG5, 0x0005
       ;.equiv URXREG6, 0x0006
       ;.equiv URXREG7, 0x0007
       ;.equiv URXREG8, 0x0008

       ;.equiv URX8,    0x0008


;----- SPI1STAT Bits -----------------------------------------------------
        .equiv SPIRBF,  0x0000
        .equiv SPITBF,  0x0001
        .equiv SPIROV,  0x0006
        .equiv SPISIDL, 0x000D
        .equiv SPIEN,   0x000F


;----- SPI1CON Bits -----------------------------------------------------
        .equiv PPRE0,   0x0000
        .equiv PPRE1,   0x0001
        .equiv SPRE0,   0x0002
        .equiv SPRE1,   0x0003
        .equiv SPRE2,   0x0004
        .equiv MSTEN,   0x0005
        .equiv CKP,     0x0006
        .equiv SSEN,    0x0007
        .equiv CKE,     0x0008
        .equiv SMP,     0x0009
        .equiv MODE16,  0x000A
        .equiv DISSDO,  0x000B
        .equiv SPIFSD,  0x000D
        .equiv FRMEN,   0x000E



;----- ADCON1 Bits -----------------------------------------------------
        .equiv DONE,    0x0000
        .equiv SAMP,    0x0001
        .equiv ASAM,    0x0002
        .equiv ADSIDL,  0x000D
        .equiv ADON,    0x000F

        .equiv SSRC0,   0x0005
        .equiv SSRC1,   0x0006
        .equiv SSRC2,   0x0007
        .equiv FORM0,   0x0008
        .equiv FORM1,   0x0009


;----- ADCON2 Bits -----------------------------------------------------
        .equiv ALTS,    0x0000
        .equiv BUFM,    0x0001
        .equiv BUFS,    0x0007
        .equiv CSCNA,   0x000A

        .equiv SMPI0,   0x0002
        .equiv SMPI1,   0x0003
        .equiv SMPI2,   0x0004
        .equiv SMPI3,   0x0005
        .equiv VCFG0,   0x000D
        .equiv VCFG1,   0x000E
        .equiv VCFG2,   0x000F


;----- ADCON3 Bits -----------------------------------------------------
        .equiv ADRC,    0x0007

        .equiv ADCS0,   0x0000
        .equiv ADCS1,   0x0001
        .equiv ADCS2,   0x0002
        .equiv ADCS3,   0x0003
        .equiv ADCS4,   0x0004
        .equiv ADCS5,   0x0005
        .equiv SAMC0,   0x0008
        .equiv SAMC1,   0x0009
        .equiv SAMC2,   0x000A
        .equiv SAMC3,   0x000B
        .equiv SAMC4,   0x000C


;----- ADCHS Bits -----------------------------------------------------
        .equiv CH0NA,   0x0004
        .equiv CH0NB,   0x000C

        .equiv CH0SA0,  0x0000
        .equiv CH0SA1,  0x0001
        .equiv CH0SA2,  0x0002
        .equiv CH0SA3,  0x0003
        .equiv CH0SB0,  0x0008
        .equiv CH0SB1,  0x0009
        .equiv CH0SB2,  0x000A
        .equiv CH0SB3,  0x000B


;----- ADPCFG Bits -----------------------------------------------------
        .equiv PCFG0,   0x0000
        .equiv PCFG1,   0x0001
        .equiv PCFG2,   0x0002
        .equiv PCFG3,   0x0003
        .equiv PCFG4,   0x0004
        .equiv PCFG5,   0x0005
        .equiv PCFG6,   0x0006
        .equiv PCFG7,   0x0007
        .equiv PCFG8,   0x0008
        .equiv PCFG9,   0x0009


;----- ADCSSL Bits -----------------------------------------------------
        .equiv CSSL0,   0x0000
        .equiv CSSL1,   0x0001
        .equiv CSSL2,   0x0002
        .equiv CSSL3,   0x0003
        .equiv CSSL4,   0x0004
        .equiv CSSL5,   0x0005
        .equiv CSSL6,   0x0006
        .equiv CSSL7,   0x0007
        .equiv CSSL8,   0x0008
        .equiv CSSL9,   0x0009


;----- TRISB Bits -----------------------------------------------------
        .equiv TRISB0,  0x0000
        .equiv TRISB1,  0x0001
        .equiv TRISB2,  0x0002
        .equiv TRISB3,  0x0003
        .equiv TRISB4,  0x0004
        .equiv TRISB5,  0x0005
        .equiv TRISB6,  0x0006
        .equiv TRISB7,  0x0007
        .equiv TRISB8,  0x0008
        .equiv TRISB9,  0x0009


;----- PORTB Bits -----------------------------------------------------
        .equiv RB0,     0x0000
        .equiv RB1,     0x0001
        .equiv RB2,     0x0002
        .equiv RB3,     0x0003
        .equiv RB4,     0x0004
        .equiv RB5,     0x0005
        .equiv RB6,     0x0006
        .equiv RB7,     0x0007
        .equiv RB8,     0x0008
        .equiv RB9,     0x0009


;----- LATB Bits -----------------------------------------------------
        .equiv LATB0,   0x0000
        .equiv LATB1,   0x0001
        .equiv LATB2,   0x0002
        .equiv LATB3,   0x0003
        .equiv LATB4,   0x0004
        .equiv LATB5,   0x0005
        .equiv LATB6,   0x0006
        .equiv LATB7,   0x0007
        .equiv LATB8,   0x0008
        .equiv LATB9,   0x0009


;----- TRISC Bits -----------------------------------------------------
        .equiv TRISC13, 0x000D
        .equiv TRISC14, 0x000E
        .equiv TRISC15, 0x000F


;----- PORTC Bits -----------------------------------------------------
        .equiv RC13,    0x000D
        .equiv RC14,    0x000E
        .equiv RC15,    0x000F


;----- LATC Bits -----------------------------------------------------
        .equiv LATC13,  0x000D
        .equiv LATC14,  0x000E
        .equiv LATC15,  0x000F


;----- TRISD Bits -----------------------------------------------------
        .equiv TRISD8,  0x0008
        .equiv TRISD9,  0x0009


;----- PORTD Bits -----------------------------------------------------
        .equiv RD8,     0x0008
        .equiv RD9,     0x0009


;----- LATD Bits -----------------------------------------------------
        .equiv LATD8,   0x0008
        .equiv LATD9,   0x0009


;----- TRISF Bits -----------------------------------------------------
        .equiv TRISF2,  0x0002
        .equiv TRISF3,  0x0003
        .equiv TRISF4,  0x0004
        .equiv TRISF5,  0x0005
        .equiv TRISF6,  0x0006


;----- PORTF Bits -----------------------------------------------------
        .equiv RF2,     0x0002
        .equiv RF3,     0x0003
        .equiv RF4,     0x0004
        .equiv RF5,     0x0005
        .equiv RF6,     0x0006


;----- LATF Bits -----------------------------------------------------
        .equiv LATF2,   0x0002
        .equiv LATF3,   0x0003
        .equiv LATF4,   0x0004
        .equiv LATF5,   0x0005
        .equiv LATF6,   0x0006


;----- RCON Bits -----------------------------------------------------
        .equiv POR,     0x0000
        .equiv BOR,     0x0001
        .equiv IDLE,    0x0002
        .equiv SLEEP,   0x0003
        .equiv WDTO,    0x0004
        .equiv SWDTEN,  0x0005
        .equiv SWR,     0x0006
        .equiv EXTR,    0x0007
        .equiv LVDEN,   0x000C
        .equiv BGST,    0x000D
        .equiv IOPUWR,  0x000E
        .equiv TRAPR,   0x000F

        .equiv LVDL0,   0x0008
        .equiv LVDL1,   0x0009
        .equiv LVDL2,   0x000A
        .equiv LVDL3,   0x000B


;----- OSCCON Bits -----------------------------------------------------
        .equiv OSWEN,   0x0000
        .equiv LPOSCEN, 0x0001
        .equiv CF,      0x0003
        .equiv LOCK,    0x0005

        .equiv POST0,   0x0006
        .equiv POST1,   0x0007
        .equiv NOSC0,   0x0008
        .equiv NOSC1,   0x0009
        .equiv NOSC2,   0x000A
        .equiv COSC0,   0x000C
        .equiv COSC1,   0x000D
        .equiv COSC2,   0x000E


;----- OSCTUN Bits -----------------------------------------------------
        .equiv TUN0,    0x0000
        .equiv TUN1,    0x0001
        .equiv TUN2,    0x0002
        .equiv TUN3,    0x0003


;----- NVMCON Bits -----------------------------------------------------
        .equiv TWRI,    0x0008
        .equiv WRERR,   0x000D
        .equiv WREN,    0x000E
        .equiv WR,      0x000F

        .equiv PROGOP0, 0x0000
        .equiv PROGOP1, 0x0001
        .equiv PROGOP2, 0x0002
        .equiv PROGOP3, 0x0003
        .equiv PROGOP4, 0x0004
        .equiv PROGOP5, 0x0005
        .equiv PROGOP6, 0x0006


;----- PMD1 Bits -----------------------------------------------------
        .equiv ADCMD,   0x0000
        .equiv SPI1MD,  0x0003
        .equiv U1MD,    0x0005
        .equiv U2MD,    0x0006
        .equiv I2CMD,   0x0007
        .equiv T1MD,    0x000B
        .equiv T2MD,    0x000C
        .equiv T3MD,    0x000D


;----- PMD2 Bits -----------------------------------------------------
        .equiv OC1MD,   0x0000
        .equiv OC2MD,   0x0001
        .equiv IC1MD,   0x0008
        .equiv IC2MD,   0x0009




;  Some useful macros for PWRSAV instructions

   .equiv SLEEP_MODE, 0x0
   .equiv IDLE_MODE, 0x1


;==========================================================================
;
;   Configuration Words
;
;   Configuration words exist in Program Space and their locations are
;   defined in the device linker script. They can be set in source code
;   or in the MPLAB IDE. Each configuration word should be specified
;   only once (multiple settings may be combined.)
;
;==========================================================================
;
;  Setting configuration words using macros:
;
;  The following macro named 'config' can be used to set configuration words:
;==========================================================================
;  NOTICE: CONFIG MACRO IS ****D E P R E C A T E D****
;  Please use #pragma in a separate C file in the project.
;  Some features in linker and compiler cannot use values
;  set using this method. Please migrate to #pragma config method.
;==========================================================================
;
        .macro config REG, VALUE
        .pushsection \REG.sec, code
        .global \REG
        .warn "DEPRECATED. Please use #pragma config in a C file"
\REG:   .pword \VALUE
        .popsection
        .endm
;
;  For example, to set CONFIG_REG using the macro above, the following line
;  can be pasted only at the beginning of the assembly source code,
;  immediately below the '.include' directive.
;
;        config __CONFIG_REG, SETTING_A & SETTING_B
;
;  Note that the 'config' macro takes two arguments: the first is the name
;  of a configuration word (in this case, __CONFIG_REG), the second argument
;  is a boolean expression that may include multiple settings.
;  The example above would enable SETTING_A and also SETTING_B.
;
;  A description of all possible settings for each configuration word
;  appears below.
;
;==========================================================================
;
;  Setting configuration words without using macros:
;
;  To set configuration words without using the 'config' macro,
;  use the following format:
;
;           .section __CONFIG_REG.sec, code
;           .global __CONFIG_REG
;__CONFIG_REG: .pword SETTING_A & SETTING_B
;
;  This source code is equivalent to the expanded macro from the previous
;  example.
;
;==========================================================================


;----- FUID0 (0x8005c0) --------------------------------------------------
;
;  The following settings are available for FUID0:
;
;   :
;


;----- FUID1 (0x8005c2) --------------------------------------------------
;
;  The following settings are available for FUID1:
;
;   :
;


;----- FUID2 (0x8005c4) --------------------------------------------------
;
;  The following settings are available for FUID2:
;
;   :
;


;----- FUID3 (0x8005c6) --------------------------------------------------
;
;  The following settings are available for FUID3:
;
;   :
;


;----- FOSC (0xf80000) --------------------------------------------------
;
;  The following settings are available for FOSC:
;
;   Oscillator:
;     LP                   Low-Power 32KHz Osc (No change to Primary Osc Mode bits)
;     FRC                  Internal Fast RC (No change to Primary Osc Mode bits)
;     LPRC                 Internal Low-Power RC (No change to Primary Osc Mode bits)
;     XTL                  XTL
;     HS                   HS
;     XT                   XT
;     ERCIO                ERCIO
;     ERC                  ERC
;     EC                   EC
;     ECIO                 ECIO
;     FRC_PLL4             FRC w/PLL 4x
;     FRC_PLL16            FRC w/PLL 16x
;     XT_PLL4              XT w/PLL 4x
;     XT_PLL8              XT w/PLL 8x
;     XT_PLL16             XT w/PLL 16x
;     FRC_PLL8             FRC w/PLL 8x
;     ECIO_PLL4            ECIO w/PLL 4x
;     ECIO_PLL8            ECIO w/PLL 8x
;     ECIO_PLL16           ECIO w/PLL 16x
;     HS2_PLL4             HS2 w/PLL 4x
;     HS2_PLL8             HS2 w/PLL 8x
;     HS2_PLL16            HS2 w/PLL 16x
;     HS3_PLL4             HS3 w/PLL 4x
;     HS3_PLL8             HS3 w/PLL 8x
;     HS3_PLL16            HS3 w/PLL 16x
;
;   Clock Switching and Monitor:
;     CSW_FSCM_ON          Sw Enabled, Mon Enabled
;     CSW_ON_FSCM_OFF      Sw Enabled, Mon Disabled
;     CSW_FSCM_OFF         Sw Disabled, Mon Disabled
;
        .equiv LP,              0xF8E0 ; Low-Power 32KHz Osc (No change to Primary Osc Mode bits)
        .equiv FRC,             0xF9E0 ; Internal Fast RC (No change to Primary Osc Mode bits)
        .equiv LPRC,            0xFAE0 ; Internal Low-Power RC (No change to Primary Osc Mode bits)
        .equiv XTL,             0xFBE0 ; XTL
        .equiv HS,              0xFBE2 ; HS
        .equiv XT,              0xFBE4 ; XT
        .equiv ERCIO,           0xFBE8 ; ERCIO
        .equiv ERC,             0xFBE9 ; ERC
        .equiv EC,              0xFBEB ; EC
        .equiv ECIO,            0xFBEC ; ECIO
        .equiv FRC_PLL4,        0xFFE1 ; FRC w/PLL 4x
        .equiv FRC_PLL16,       0xFFE3 ; FRC w/PLL 16x
        .equiv XT_PLL4,         0xFFE5 ; XT w/PLL 4x
        .equiv XT_PLL8,         0xFFE6 ; XT w/PLL 8x
        .equiv XT_PLL16,        0xFFE7 ; XT w/PLL 16x
        .equiv FRC_PLL8,        0xFFEA ; FRC w/PLL 8x
        .equiv ECIO_PLL4,       0xFFED ; ECIO w/PLL 4x
        .equiv ECIO_PLL8,       0xFFEE ; ECIO w/PLL 8x
        .equiv ECIO_PLL16,      0xFFEF ; ECIO w/PLL 16x
        .equiv HS2_PLL4,        0xFFF1 ; HS2 w/PLL 4x
        .equiv HS2_PLL8,        0xFFF2 ; HS2 w/PLL 8x
        .equiv HS2_PLL16,       0xFFF3 ; HS2 w/PLL 16x
        .equiv HS3_PLL4,        0xFFF5 ; HS3 w/PLL 4x
        .equiv HS3_PLL8,        0xFFF6 ; HS3 w/PLL 8x
        .equiv HS3_PLL16,       0xFFF7 ; HS3 w/PLL 16x

        .equiv CSW_FSCM_ON,     0x3FFF ; Sw Enabled, Mon Enabled
        .equiv CSW_ON_FSCM_OFF, 0x7FFF ; Sw Enabled, Mon Disabled
        .equiv CSW_FSCM_OFF,    0xBFFF ; Sw Disabled, Mon Disabled


;----- FWDT (0xf80002) --------------------------------------------------
;
;  The following settings are available for FWDT:
;
;   WDT Prescaler B:
;     WDTPSB_1             1:1
;     WDTPSB_2             1:2
;     WDTPSB_3             1:3
;     WDTPSB_4             1:4
;     WDTPSB_5             1:5
;     WDTPSB_6             1:6
;     WDTPSB_7             1:7
;     WDTPSB_8             1:8
;     WDTPSB_9             1:9
;     WDTPSB_10            1:10
;     WDTPSB_11            1:11
;     WDTPSB_12            1:12
;     WDTPSB_13            1:13
;     WDTPSB_14            1:14
;     WDTPSB_15            1:15
;     WDTPSB_16            1:16
;
;   WDT Prescaler A:
;     WDTPSA_1             1:1
;     WDTPSA_8             1:8
;     WDTPSA_64            1:64
;     WDTPSA_512           1:512
;
;   Watchdog Timer:
;     WDT_OFF              Disabled
;     WDT_ON               Enabled
;
        .equiv WDTPSB_1,        0xFFF0 ; 1:1
        .equiv WDTPSB_2,        0xFFF1 ; 1:2
        .equiv WDTPSB_3,        0xFFF2 ; 1:3
        .equiv WDTPSB_4,        0xFFF3 ; 1:4
        .equiv WDTPSB_5,        0xFFF4 ; 1:5
        .equiv WDTPSB_6,        0xFFF5 ; 1:6
        .equiv WDTPSB_7,        0xFFF6 ; 1:7
        .equiv WDTPSB_8,        0xFFF7 ; 1:8
        .equiv WDTPSB_9,        0xFFF8 ; 1:9
        .equiv WDTPSB_10,       0xFFF9 ; 1:10
        .equiv WDTPSB_11,       0xFFFA ; 1:11
        .equiv WDTPSB_12,       0xFFFB ; 1:12
        .equiv WDTPSB_13,       0xFFFC ; 1:13
        .equiv WDTPSB_14,       0xFFFD ; 1:14
        .equiv WDTPSB_15,       0xFFFE ; 1:15
        .equiv WDTPSB_16,       0xFFFF ; 1:16

        .equiv WDTPSA_1,        0xFFCF ; 1:1
        .equiv WDTPSA_8,        0xFFDF ; 1:8
        .equiv WDTPSA_64,       0xFFEF ; 1:64
        .equiv WDTPSA_512,      0xFFFF ; 1:512

        .equiv WDT_OFF,         0x7FFF ; Disabled
        .equiv WDT_ON,          0xFFFF ; Enabled


;----- FBORPOR (0xf80004) --------------------------------------------------
;
;  The following settings are available for FBORPOR:
;
;   POR Timer Value:
;     PWRT_OFF             Timer Disabled
;     PWRT_4               4ms
;     PWRT_16              16ms
;     PWRT_64              64ms
;
;   Brown Out Voltage:
;     BORV45               4.5V
;     BORV42               4.2V
;     BORV27               2.7V
;     BORV20               Reserved
;
;   PBOR Enable:
;     PBOR_OFF             Disabled
;     PBOR_ON              Enabled
;
;   Master Clear Enable:
;     MCLR_DIS             Disabled
;     MCLR_EN              Enabled
;
        .equiv PWRT_OFF,        0xFFFC ; Timer Disabled
        .equiv PWRT_4,          0xFFFD ; 4ms
        .equiv PWRT_16,         0xFFFE ; 16ms
        .equiv PWRT_64,         0xFFFF ; 64ms

        .equiv BORV45,          0xFFCF ; 4.5V
        .equiv BORV42,          0xFFDF ; 4.2V
        .equiv BORV27,          0xFFEF ; 2.7V
        .equiv BORV20,          0xFFFF ; Reserved

        .equiv PBOR_OFF,        0xFF7F ; Disabled
        .equiv PBOR_ON,         0xFFFF ; Enabled

        .equiv MCLR_DIS,        0x7FFF ; Disabled
        .equiv MCLR_EN,         0xFFFF ; Enabled


;----- RESERVED1 (0xf80006) --------------------------------------------------
;
;  The following settings are available for RESERVED1:
;

;----- RESERVED2 (0xf80008) --------------------------------------------------
;
;  The following settings are available for RESERVED2:
;

;----- FGS (0xf8000a) --------------------------------------------------
;
;  The following settings are available for FGS:
;
;   General Code Segment Write Protect:
;     GWRP_ON              Enabled
;     GWRP_OFF             Disabled
;
;   General Segment Code Protection:
;     CODE_PROT_ON         Enabled
;     CODE_PROT_OFF        Disabled
;
        .equiv GWRP_ON,         0xFFFE ; Enabled
        .equiv GWRP_OFF,        0xFFFF ; Disabled

        .equiv CODE_PROT_ON,    0xFFF9 ; Enabled
        .equiv CODE_PROT_OFF,   0xFFFF ; Disabled


;----- FICD (0xf8000c) --------------------------------------------------
;
;  The following settings are available for FICD:
;
;   Comm Channel Select:
;     ICS_PGD3             Use EMUC3 and EMUD3
;     PGD3                 Use EMUC3 and EMUD3
;     ICS_PGD2             Use EMUC2 and EMUD2
;     PGD2                 Use EMUC2 and EMUD2
;     ICS_PGD1             Use EMUC1 and EMUD1
;     PGD1                 Use EMUC1 and EMUD1
;     ICS_PGD              Use PGC/EMUC and PGD/EMUD
;     PGD                  Use PGC/EMUC and PGD/EMUD
;
        .equiv ICS_PGD3,        0xFFFC ; Use EMUC3 and EMUD3
        .equiv PGD3,            0xFFFC ; Use EMUC3 and EMUD3
        .equiv ICS_PGD2,        0xFFFD ; Use EMUC2 and EMUD2
        .equiv PGD2,            0xFFFD ; Use EMUC2 and EMUD2
        .equiv ICS_PGD1,        0xFFFE ; Use EMUC1 and EMUD1
        .equiv PGD1,            0xFFFE ; Use EMUC1 and EMUD1
        .equiv ICS_PGD,         0xFFFF ; Use PGC/EMUC and PGD/EMUD
        .equiv PGD,             0xFFFF ; Use PGC/EMUC and PGD/EMUD


.LIST
.endif
