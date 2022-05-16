/*-------------------------------------------------------------------------
 * MPLAB-Cxx  dsPIC30F3013 processor header
 *
 * (c) Copyright 1999-2022 Microchip Technology, All rights reserved
 * Part support version 2.00.A(24-Jan-2022)
 *
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above 
 *         copyright notice, this list of conditions and the following 
 *         disclaimer in the documentation and/or other materials provided 
 *         with the distribution. Publication is not required when
 *         this file is used in an embedded application.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written 
 *         permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef __dsPIC30F3013__
#error "Include file does not match processor setting"
#endif

#include <stdint.h>

#ifndef __30F3013_H
#define __30F3013_H

#define __XC16_PART_SUPPORT_VERSION 2000
#define __XC16_PART_SUPPORT_UPDATE 'A'

#define __write_to_IEC(X) \
   ( (void)(X), \
     __builtin_nop() \
   )

#define WREG0 WREG0
extern volatile uint16_t WREG0 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG1 WREG1
extern volatile uint16_t WREG1 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG2 WREG2
extern volatile uint16_t WREG2 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG3 WREG3
extern volatile uint16_t WREG3 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG4 WREG4
extern volatile uint16_t WREG4 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG5 WREG5
extern volatile uint16_t WREG5 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG6 WREG6
extern volatile uint16_t WREG6 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG7 WREG7
extern volatile uint16_t WREG7 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG8 WREG8
extern volatile uint16_t WREG8 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG9 WREG9
extern volatile uint16_t WREG9 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG10 WREG10
extern volatile uint16_t WREG10 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG11 WREG11
extern volatile uint16_t WREG11 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG12 WREG12
extern volatile uint16_t WREG12 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG13 WREG13
extern volatile uint16_t WREG13 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG14 WREG14
extern volatile uint16_t WREG14 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define WREG15 WREG15
extern volatile uint16_t WREG15 __attribute__((__sfr__,__deprecated__,__unsafe__));
#define SPLIM SPLIM
extern volatile uint16_t SPLIM __attribute__((__sfr__));
typedef struct tagACC {
    uint16_t L;
    uint16_t H;
    uint16_t U;
} ACC;

/* SFR blocks for each ACC module */
#define ACCA ACCA
extern volatile ACC ACCA __attribute__((__sfr__));

#define ACCAL ACCAL
extern volatile uint16_t ACCAL __attribute__((__sfr__,__deprecated__,__unsafe__));
#define ACCAH ACCAH
extern volatile uint16_t ACCAH __attribute__((__sfr__,__deprecated__,__unsafe__));
#define ACCAU ACCAU
extern volatile uint8_t ACCAU __attribute__((__sfr__,__deprecated__,__unsafe__));

/* SFR blocks for each ACC module */
#define ACCB ACCB
extern volatile ACC ACCB __attribute__((__sfr__));

#define ACCBL ACCBL
extern volatile uint16_t ACCBL __attribute__((__sfr__,__deprecated__,__unsafe__));
#define ACCBH ACCBH
extern volatile uint16_t ACCBH __attribute__((__sfr__,__deprecated__,__unsafe__));
#define ACCBU ACCBU
extern volatile uint8_t ACCBU __attribute__((__sfr__,__deprecated__,__unsafe__));
#define PCL PCL
extern volatile uint16_t PCL __attribute__((__sfr__));
#define PCH PCH
extern volatile uint8_t PCH __attribute__((__sfr__));
#define TBLPAG TBLPAG
extern volatile uint8_t TBLPAG __attribute__((__sfr__));
#define PSVPAG PSVPAG
extern volatile uint8_t PSVPAG __attribute__((__sfr__));
#define RCOUNT RCOUNT
extern volatile uint16_t RCOUNT __attribute__((__sfr__));
#define DCOUNT DCOUNT
extern volatile uint16_t DCOUNT __attribute__((__sfr__));
#define DOSTARTL DOSTARTL
extern volatile uint16_t DOSTARTL __attribute__((__sfr__));
#define DOSTARTH DOSTARTH
extern volatile uint16_t DOSTARTH __attribute__((__sfr__));
#define DOENDL DOENDL
extern volatile uint16_t DOENDL __attribute__((__sfr__));
#define DOENDH DOENDH
extern volatile uint16_t DOENDH __attribute__((__sfr__));
#define SR SR
extern volatile uint16_t SR __attribute__((__sfr__));
__extension__ typedef struct tagSRBITS {
  union {
    struct {
      uint16_t C:1;
      uint16_t Z:1;
      uint16_t OV:1;
      uint16_t N:1;
      uint16_t RA:1;
      uint16_t IPL:3;
      uint16_t DC:1;
      uint16_t DA:1;
      uint16_t SAB:1;
      uint16_t OAB:1;
      uint16_t SB:1;
      uint16_t SA:1;
      uint16_t OB:1;
      uint16_t OA:1;
    };
    struct {
      uint16_t :5;
      uint16_t IPL0:1;
      uint16_t IPL1:1;
      uint16_t IPL2:1;
    };
  };
} SRBITS;
extern volatile SRBITS SRbits __attribute__((__sfr__));

#define CORCON CORCON
extern volatile uint16_t CORCON __attribute__((__sfr__));
__extension__ typedef struct tagCORCONBITS {
  union {
    struct {
      uint16_t IF:1;
      uint16_t RND:1;
      uint16_t PSV:1;
      uint16_t IPL3:1;
      uint16_t ACCSAT:1;
      uint16_t SATDW:1;
      uint16_t SATB:1;
      uint16_t SATA:1;
      uint16_t DL:3;
      uint16_t EDT:1;
      uint16_t US:1;
    };
    struct {
      uint16_t :8;
      uint16_t DL0:1;
      uint16_t DL1:1;
      uint16_t DL2:1;
    };
  };
} CORCONBITS;
extern volatile CORCONBITS CORCONbits __attribute__((__sfr__));

#define MODCON MODCON
extern volatile uint16_t MODCON __attribute__((__sfr__));
__extension__ typedef struct tagMODCONBITS {
  union {
    struct {
      uint16_t XWM:4;
      uint16_t YWM:4;
      uint16_t BWM:4;
      uint16_t :2;
      uint16_t YMODEN:1;
      uint16_t XMODEN:1;
    };
    struct {
      uint16_t XWM0:1;
      uint16_t XWM1:1;
      uint16_t XWM2:1;
      uint16_t XWM3:1;
      uint16_t YWM0:1;
      uint16_t YWM1:1;
      uint16_t YWM2:1;
      uint16_t YWM3:1;
      uint16_t BWM0:1;
      uint16_t BWM1:1;
      uint16_t BWM2:1;
      uint16_t BWM3:1;
    };
  };
} MODCONBITS;
extern volatile MODCONBITS MODCONbits __attribute__((__sfr__));

#define XMODSRT XMODSRT
extern volatile uint16_t XMODSRT __attribute__((__sfr__));
#define XMODEND XMODEND
extern volatile uint16_t XMODEND __attribute__((__sfr__));
#define YMODSRT YMODSRT
extern volatile uint16_t YMODSRT __attribute__((__sfr__));
#define YMODEND YMODEND
extern volatile uint16_t YMODEND __attribute__((__sfr__));
#define XBREV XBREV
extern volatile uint16_t XBREV __attribute__((__sfr__));
__extension__ typedef struct tagXBREVBITS {
  union {
    struct {
      uint16_t XB:15;
      uint16_t BREN:1;
    };
    struct {
      uint16_t XB0:1;
      uint16_t XB1:1;
      uint16_t XB2:1;
      uint16_t XB3:1;
      uint16_t XB4:1;
      uint16_t XB5:1;
      uint16_t XB6:1;
      uint16_t XB7:1;
      uint16_t XB8:1;
      uint16_t XB9:1;
      uint16_t XB10:1;
      uint16_t XB11:1;
      uint16_t XB12:1;
      uint16_t XB13:1;
      uint16_t XB14:1;
    };
  };
} XBREVBITS;
extern volatile XBREVBITS XBREVbits __attribute__((__sfr__));

#define DISICNT DISICNT
extern volatile uint16_t DISICNT __attribute__((__sfr__));
typedef struct tagDISICNTBITS {
  uint16_t DISICNT:14;
} DISICNTBITS;
extern volatile DISICNTBITS DISICNTbits __attribute__((__sfr__));

#define INTCON1 INTCON1
extern volatile uint16_t INTCON1 __attribute__((__sfr__));
typedef struct tagINTCON1BITS {
  uint16_t :1;
  uint16_t OSCFAIL:1;
  uint16_t STKERR:1;
  uint16_t ADDRERR:1;
  uint16_t MATHERR:1;
  uint16_t :3;
  uint16_t COVTE:1;
  uint16_t OVBTE:1;
  uint16_t OVATE:1;
  uint16_t :4;
  uint16_t NSTDIS:1;
} INTCON1BITS;
extern volatile INTCON1BITS INTCON1bits __attribute__((__sfr__));

#define INTCON2 INTCON2
extern volatile uint16_t INTCON2 __attribute__((__sfr__));
typedef struct tagINTCON2BITS {
  uint16_t INT0EP:1;
  uint16_t INT1EP:1;
  uint16_t INT2EP:1;
  uint16_t :11;
  uint16_t DISI:1;
  uint16_t ALTIVT:1;
} INTCON2BITS;
extern volatile INTCON2BITS INTCON2bits __attribute__((__sfr__));

#define IFS0 IFS0
extern volatile uint16_t IFS0 __attribute__((__sfr__));
typedef struct tagIFS0BITS {
  uint16_t INT0IF:1;
  uint16_t IC1IF:1;
  uint16_t OC1IF:1;
  uint16_t T1IF:1;
  uint16_t IC2IF:1;
  uint16_t OC2IF:1;
  uint16_t T2IF:1;
  uint16_t T3IF:1;
  uint16_t SPI1IF:1;
  uint16_t U1RXIF:1;
  uint16_t U1TXIF:1;
  uint16_t ADIF:1;
  uint16_t NVMIF:1;
  uint16_t SI2CIF:1;
  uint16_t MI2CIF:1;
  uint16_t CNIF:1;
} IFS0BITS;
extern volatile IFS0BITS IFS0bits __attribute__((__sfr__));

#define IFS1 IFS1
extern volatile uint16_t IFS1 __attribute__((__sfr__));
typedef struct tagIFS1BITS {
  uint16_t INT1IF:1;
  uint16_t :6;
  uint16_t INT2IF:1;
  uint16_t U2RXIF:1;
  uint16_t U2TXIF:1;
} IFS1BITS;
extern volatile IFS1BITS IFS1bits __attribute__((__sfr__));

#define IFS2 IFS2
extern volatile uint16_t IFS2 __attribute__((__sfr__));
typedef struct tagIFS2BITS {
  uint16_t :10;
  uint16_t LVDIF:1;
} IFS2BITS;
extern volatile IFS2BITS IFS2bits __attribute__((__sfr__));

#define IEC0 IEC0
extern volatile uint16_t IEC0 __attribute__((__sfr__));
typedef struct tagIEC0BITS {
  uint16_t INT0IE:1;
  uint16_t IC1IE:1;
  uint16_t OC1IE:1;
  uint16_t T1IE:1;
  uint16_t IC2IE:1;
  uint16_t OC2IE:1;
  uint16_t T2IE:1;
  uint16_t T3IE:1;
  uint16_t SPI1IE:1;
  uint16_t U1RXIE:1;
  uint16_t U1TXIE:1;
  uint16_t ADIE:1;
  uint16_t NVMIE:1;
  uint16_t SI2CIE:1;
  uint16_t MI2CIE:1;
  uint16_t CNIE:1;
} IEC0BITS;
extern volatile IEC0BITS IEC0bits __attribute__((__sfr__));

#define IEC1 IEC1
extern volatile uint16_t IEC1 __attribute__((__sfr__));
typedef struct tagIEC1BITS {
  uint16_t INT1IE:1;
  uint16_t :6;
  uint16_t INT2IE:1;
  uint16_t U2RXIE:1;
  uint16_t U2TXIE:1;
} IEC1BITS;
extern volatile IEC1BITS IEC1bits __attribute__((__sfr__));

#define IEC2 IEC2
extern volatile uint16_t IEC2 __attribute__((__sfr__));
typedef struct tagIEC2BITS {
  uint16_t :10;
  uint16_t LVDIE:1;
} IEC2BITS;
extern volatile IEC2BITS IEC2bits __attribute__((__sfr__));

#define IPC0 IPC0
extern volatile uint16_t IPC0 __attribute__((__sfr__));
__extension__ typedef struct tagIPC0BITS {
  union {
    struct {
      uint16_t INT0IP:3;
      uint16_t :1;
      uint16_t IC1IP:3;
      uint16_t :1;
      uint16_t OC1IP:3;
      uint16_t :1;
      uint16_t T1IP:3;
    };
    struct {
      uint16_t INT0IP0:1;
      uint16_t INT0IP1:1;
      uint16_t INT0IP2:1;
      uint16_t :1;
      uint16_t IC1IP0:1;
      uint16_t IC1IP1:1;
      uint16_t IC1IP2:1;
      uint16_t :1;
      uint16_t OC1IP0:1;
      uint16_t OC1IP1:1;
      uint16_t OC1IP2:1;
      uint16_t :1;
      uint16_t T1IP0:1;
      uint16_t T1IP1:1;
      uint16_t T1IP2:1;
    };
  };
} IPC0BITS;
extern volatile IPC0BITS IPC0bits __attribute__((__sfr__));

#define IPC1 IPC1
extern volatile uint16_t IPC1 __attribute__((__sfr__));
__extension__ typedef struct tagIPC1BITS {
  union {
    struct {
      uint16_t IC2IP:3;
      uint16_t :1;
      uint16_t OC2IP:3;
      uint16_t :1;
      uint16_t T2IP:3;
      uint16_t :1;
      uint16_t T3IP:3;
    };
    struct {
      uint16_t IC2IP0:1;
      uint16_t IC2IP1:1;
      uint16_t IC2IP2:1;
      uint16_t :1;
      uint16_t OC2IP0:1;
      uint16_t OC2IP1:1;
      uint16_t OC2IP2:1;
      uint16_t :1;
      uint16_t T2IP0:1;
      uint16_t T2IP1:1;
      uint16_t T2IP2:1;
      uint16_t :1;
      uint16_t T3IP0:1;
      uint16_t T3IP1:1;
      uint16_t T3IP2:1;
    };
  };
} IPC1BITS;
extern volatile IPC1BITS IPC1bits __attribute__((__sfr__));

#define IPC2 IPC2
extern volatile uint16_t IPC2 __attribute__((__sfr__));
__extension__ typedef struct tagIPC2BITS {
  union {
    struct {
      uint16_t SPI1IP:3;
      uint16_t :1;
      uint16_t U1RXIP:3;
      uint16_t :1;
      uint16_t U1TXIP:3;
      uint16_t :1;
      uint16_t ADIP:3;
    };
    struct {
      uint16_t SPI1IP0:1;
      uint16_t SPI1IP1:1;
      uint16_t SPI1IP2:1;
      uint16_t :1;
      uint16_t U1RXIP0:1;
      uint16_t U1RXIP1:1;
      uint16_t U1RXIP2:1;
      uint16_t :1;
      uint16_t U1TXIP0:1;
      uint16_t U1TXIP1:1;
      uint16_t U1TXIP2:1;
      uint16_t :1;
      uint16_t ADIP0:1;
      uint16_t ADIP1:1;
      uint16_t ADIP2:1;
    };
  };
} IPC2BITS;
extern volatile IPC2BITS IPC2bits __attribute__((__sfr__));

#define IPC3 IPC3
extern volatile uint16_t IPC3 __attribute__((__sfr__));
__extension__ typedef struct tagIPC3BITS {
  union {
    struct {
      uint16_t NVMIP:3;
      uint16_t :1;
      uint16_t SI2CIP:3;
      uint16_t :1;
      uint16_t MI2CIP:3;
      uint16_t :1;
      uint16_t CNIP:3;
    };
    struct {
      uint16_t NVMIP0:1;
      uint16_t NVMIP1:1;
      uint16_t NVMIP2:1;
      uint16_t :1;
      uint16_t SI2CIP0:1;
      uint16_t SI2CIP1:1;
      uint16_t SI2CIP2:1;
      uint16_t :1;
      uint16_t MI2CIP0:1;
      uint16_t MI2CIP1:1;
      uint16_t MI2CIP2:1;
      uint16_t :1;
      uint16_t CNIP0:1;
      uint16_t CNIP1:1;
      uint16_t CNIP2:1;
    };
  };
} IPC3BITS;
extern volatile IPC3BITS IPC3bits __attribute__((__sfr__));

#define IPC4 IPC4
extern volatile uint16_t IPC4 __attribute__((__sfr__));
__extension__ typedef struct tagIPC4BITS {
  union {
    struct {
      uint16_t INT1IP:3;
    };
    struct {
      uint16_t INT1IP0:1;
      uint16_t INT1IP1:1;
      uint16_t INT1IP2:1;
    };
  };
} IPC4BITS;
extern volatile IPC4BITS IPC4bits __attribute__((__sfr__));

#define IPC5 IPC5
extern volatile uint16_t IPC5 __attribute__((__sfr__));
__extension__ typedef struct tagIPC5BITS {
  union {
    struct {
      uint16_t :12;
      uint16_t INT2IP:3;
    };
    struct {
      uint16_t :12;
      uint16_t INT2IP0:1;
      uint16_t INT2IP1:1;
      uint16_t INT2IP2:1;
    };
  };
} IPC5BITS;
extern volatile IPC5BITS IPC5bits __attribute__((__sfr__));

#define IPC6 IPC6
extern volatile uint16_t IPC6 __attribute__((__sfr__));
__extension__ typedef struct tagIPC6BITS {
  union {
    struct {
      uint16_t U2RXIP:3;
      uint16_t :1;
      uint16_t U2TXIP:3;
    };
    struct {
      uint16_t U2RXIP0:1;
      uint16_t U2RXIP1:1;
      uint16_t U2RXIP2:1;
      uint16_t :1;
      uint16_t U2TXIP0:1;
      uint16_t U2TXIP1:1;
      uint16_t U2TXIP2:1;
    };
  };
} IPC6BITS;
extern volatile IPC6BITS IPC6bits __attribute__((__sfr__));

#define IPC10 IPC10
extern volatile uint16_t IPC10 __attribute__((__sfr__));
__extension__ typedef struct tagIPC10BITS {
  union {
    struct {
      uint16_t :8;
      uint16_t LVDIP:3;
    };
    struct {
      uint16_t :8;
      uint16_t LVDIP0:1;
      uint16_t LVDIP1:1;
      uint16_t LVDIP2:1;
    };
  };
} IPC10BITS;
extern volatile IPC10BITS IPC10bits __attribute__((__sfr__));

#define INTTREG INTTREG
extern volatile uint16_t INTTREG __attribute__((__sfr__));
__extension__ typedef struct tagINTTREGBITS {
  union {
    struct {
      uint16_t VECNUM:6;
      uint16_t :2;
      uint16_t ILR:4;
      uint16_t :1;
      uint16_t VHOLD:1;
      uint16_t TMODE:1;
      uint16_t IRQTOCPU:1;
    };
    struct {
      uint16_t VECNUM0:1;
      uint16_t VECNUM1:1;
      uint16_t VECNUM2:1;
      uint16_t VECNUM3:1;
      uint16_t VECNUM4:1;
      uint16_t VECNUM5:1;
      uint16_t :2;
      uint16_t ILR0:1;
      uint16_t ILR1:1;
      uint16_t ILR2:1;
      uint16_t ILR3:1;
    };
  };
} INTTREGBITS;
extern volatile INTTREGBITS INTTREGbits __attribute__((__sfr__));

#define CNEN1 CNEN1
extern volatile uint16_t CNEN1 __attribute__((__sfr__));
typedef struct tagCNEN1BITS {
  uint16_t CN0IE:1;
  uint16_t CN1IE:1;
  uint16_t CN2IE:1;
  uint16_t CN3IE:1;
  uint16_t CN4IE:1;
  uint16_t CN5IE:1;
  uint16_t CN6IE:1;
  uint16_t CN7IE:1;
} CNEN1BITS;
extern volatile CNEN1BITS CNEN1bits __attribute__((__sfr__));

#define CNEN2 CNEN2
extern volatile uint16_t CNEN2 __attribute__((__sfr__));
typedef struct tagCNEN2BITS {
  uint16_t :1;
  uint16_t CN17IE:1;
  uint16_t CN18IE:1;
} CNEN2BITS;
extern volatile CNEN2BITS CNEN2bits __attribute__((__sfr__));

#define CNPU1 CNPU1
extern volatile uint16_t CNPU1 __attribute__((__sfr__));
typedef struct tagCNPU1BITS {
  uint16_t CN0PUE:1;
  uint16_t CN1PUE:1;
  uint16_t CN2PUE:1;
  uint16_t CN3PUE:1;
  uint16_t CN4PUE:1;
  uint16_t CN5PUE:1;
  uint16_t CN6PUE:1;
  uint16_t CN7PUE:1;
} CNPU1BITS;
extern volatile CNPU1BITS CNPU1bits __attribute__((__sfr__));

#define CNPU2 CNPU2
extern volatile uint16_t CNPU2 __attribute__((__sfr__));
typedef struct tagCNPU2BITS {
  uint16_t :1;
  uint16_t CN17PUE:1;
  uint16_t CN18PUE:1;
} CNPU2BITS;
extern volatile CNPU2BITS CNPU2bits __attribute__((__sfr__));

#define TMR1 TMR1
extern volatile uint16_t TMR1 __attribute__((__sfr__));
#define PR1 PR1
extern volatile uint16_t PR1 __attribute__((__sfr__));
#define T1CON T1CON
extern volatile uint16_t T1CON __attribute__((__sfr__));
__extension__ typedef struct tagT1CONBITS {
  union {
    struct {
      uint16_t :1;
      uint16_t TCS:1;
      uint16_t TSYNC:1;
      uint16_t :1;
      uint16_t TCKPS:2;
      uint16_t TGATE:1;
      uint16_t :6;
      uint16_t TSIDL:1;
      uint16_t :1;
      uint16_t TON:1;
    };
    struct {
      uint16_t :4;
      uint16_t TCKPS0:1;
      uint16_t TCKPS1:1;
    };
  };
} T1CONBITS;
extern volatile T1CONBITS T1CONbits __attribute__((__sfr__));

#define TMR2 TMR2
extern volatile uint16_t TMR2 __attribute__((__sfr__));
#define TMR3HLD TMR3HLD
extern volatile uint16_t TMR3HLD __attribute__((__sfr__));
#define TMR3 TMR3
extern volatile uint16_t TMR3 __attribute__((__sfr__));
#define PR2 PR2
extern volatile uint16_t PR2 __attribute__((__sfr__));
#define PR3 PR3
extern volatile uint16_t PR3 __attribute__((__sfr__));
#define T2CON T2CON
extern volatile uint16_t T2CON __attribute__((__sfr__));
__extension__ typedef struct tagT2CONBITS {
  union {
    struct {
      uint16_t :1;
      uint16_t TCS:1;
      uint16_t :1;
      uint16_t T32:1;
      uint16_t TCKPS:2;
      uint16_t TGATE:1;
      uint16_t :6;
      uint16_t TSIDL:1;
      uint16_t :1;
      uint16_t TON:1;
    };
    struct {
      uint16_t :4;
      uint16_t TCKPS0:1;
      uint16_t TCKPS1:1;
    };
  };
} T2CONBITS;
extern volatile T2CONBITS T2CONbits __attribute__((__sfr__));

#define T3CON T3CON
extern volatile uint16_t T3CON __attribute__((__sfr__));
__extension__ typedef struct tagT3CONBITS {
  union {
    struct {
      uint16_t :1;
      uint16_t TCS:1;
      uint16_t :2;
      uint16_t TCKPS:2;
      uint16_t TGATE:1;
      uint16_t :6;
      uint16_t TSIDL:1;
      uint16_t :1;
      uint16_t TON:1;
    };
    struct {
      uint16_t :4;
      uint16_t TCKPS0:1;
      uint16_t TCKPS1:1;
    };
  };
} T3CONBITS;
extern volatile T3CONBITS T3CONbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Input Capture modules */
typedef struct tagIC {
        uint16_t icxbuf;
        uint16_t icxcon;
} IC, *PIC;


/* SFR blocks for Input Capture modules */
#define IC1 IC1
extern volatile IC IC1 __attribute__((__sfr__));

#define IC1BUF IC1BUF
extern volatile uint16_t IC1BUF __attribute__((__sfr__));
#define IC1CON IC1CON
extern volatile uint16_t IC1CON __attribute__((__sfr__));
__extension__ typedef struct tagIC1CONBITS {
  union {
    struct {
      uint16_t ICM:3;
      uint16_t ICBNE:1;
      uint16_t ICOV:1;
      uint16_t ICI:2;
      uint16_t ICTMR:1;
      uint16_t :5;
      uint16_t ICSIDL:1;
    };
    struct {
      uint16_t ICM0:1;
      uint16_t ICM1:1;
      uint16_t ICM2:1;
      uint16_t :2;
      uint16_t ICI0:1;
      uint16_t ICI1:1;
    };
  };
} IC1CONBITS;
extern volatile IC1CONBITS IC1CONbits __attribute__((__sfr__));


/* SFR blocks for Input Capture modules */
#define IC2 IC2
extern volatile IC IC2 __attribute__((__sfr__));

#define IC2BUF IC2BUF
extern volatile uint16_t IC2BUF __attribute__((__sfr__));
#define IC2CON IC2CON
extern volatile uint16_t IC2CON __attribute__((__sfr__));
__extension__ typedef struct tagIC2CONBITS {
  union {
    struct {
      uint16_t ICM:3;
      uint16_t ICBNE:1;
      uint16_t ICOV:1;
      uint16_t ICI:2;
      uint16_t ICTMR:1;
      uint16_t :5;
      uint16_t ICSIDL:1;
    };
    struct {
      uint16_t ICM0:1;
      uint16_t ICM1:1;
      uint16_t ICM2:1;
      uint16_t :2;
      uint16_t ICI0:1;
      uint16_t ICI1:1;
    };
  };
} IC2CONBITS;
extern volatile IC2CONBITS IC2CONbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for Output Compare modules */
typedef struct tagOC {
        uint16_t ocxrs;
        uint16_t ocxr;
        uint16_t ocxcon;
} OC, *POC;


/* SFR blocks for Output Compare modules */
#define OC1 OC1
extern volatile OC OC1 __attribute__((__sfr__));

#define OC1RS OC1RS
extern volatile uint16_t OC1RS __attribute__((__sfr__));
#define OC1R OC1R
extern volatile uint16_t OC1R __attribute__((__sfr__));
#define OC1CON OC1CON
extern volatile uint16_t OC1CON __attribute__((__sfr__));
__extension__ typedef struct tagOC1CONBITS {
  union {
    struct {
      uint16_t OCM:3;
      uint16_t OCTSEL:1;
      uint16_t OCFLT:1;
      uint16_t :8;
      uint16_t OCSIDL:1;
    };
    struct {
      uint16_t OCM0:1;
      uint16_t OCM1:1;
      uint16_t OCM2:1;
    };
  };
} OC1CONBITS;
extern volatile OC1CONBITS OC1CONbits __attribute__((__sfr__));


/* SFR blocks for Output Compare modules */
#define OC2 OC2
extern volatile OC OC2 __attribute__((__sfr__));

#define OC2RS OC2RS
extern volatile uint16_t OC2RS __attribute__((__sfr__));
#define OC2R OC2R
extern volatile uint16_t OC2R __attribute__((__sfr__));
#define OC2CON OC2CON
extern volatile uint16_t OC2CON __attribute__((__sfr__));
__extension__ typedef struct tagOC2CONBITS {
  union {
    struct {
      uint16_t OCM:3;
      uint16_t OCTSEL:1;
      uint16_t OCFLT:1;
      uint16_t :8;
      uint16_t OCSIDL:1;
    };
    struct {
      uint16_t OCM0:1;
      uint16_t OCM1:1;
      uint16_t OCM2:1;
    };
  };
} OC2CONBITS;
extern volatile OC2CONBITS OC2CONbits __attribute__((__sfr__));

#define I2CRCV I2CRCV
extern volatile uint16_t I2CRCV __attribute__((__sfr__));
__extension__ typedef struct tagI2CRCVBITS {
  union {
    struct {
      uint16_t I2CRCV:8;
    };
    struct {
      uint16_t I2CRCV0:1;
      uint16_t I2CRCV1:1;
      uint16_t I2CRCV2:1;
      uint16_t I2CRCV3:1;
      uint16_t I2CRCV4:1;
      uint16_t I2CRCV5:1;
      uint16_t I2CRCV6:1;
      uint16_t I2CRCV7:1;
    };
  };
} I2CRCVBITS;
extern volatile I2CRCVBITS I2CRCVbits __attribute__((__sfr__));

#define I2CTRN I2CTRN
extern volatile uint16_t I2CTRN __attribute__((__sfr__));
__extension__ typedef struct tagI2CTRNBITS {
  union {
    struct {
      uint16_t I2CTRN:8;
    };
    struct {
      uint16_t I2CTRN0:1;
      uint16_t I2CTRN1:1;
      uint16_t I2CTRN2:1;
      uint16_t I2CTRN3:1;
      uint16_t I2CTRN4:1;
      uint16_t I2CTRN5:1;
      uint16_t I2CTRN6:1;
      uint16_t I2CTRN7:1;
    };
  };
} I2CTRNBITS;
extern volatile I2CTRNBITS I2CTRNbits __attribute__((__sfr__));

#define I2CBRG I2CBRG
extern volatile uint16_t I2CBRG __attribute__((__sfr__));
typedef struct tagI2CBRGBITS {
  uint16_t I2CBRG:9;
} I2CBRGBITS;
extern volatile I2CBRGBITS I2CBRGbits __attribute__((__sfr__));

#define I2CCON I2CCON
extern volatile uint16_t I2CCON __attribute__((__sfr__));
typedef struct tagI2CCONBITS {
  uint16_t SEN:1;
  uint16_t RSEN:1;
  uint16_t PEN:1;
  uint16_t RCEN:1;
  uint16_t ACKEN:1;
  uint16_t ACKDT:1;
  uint16_t STREN:1;
  uint16_t GCEN:1;
  uint16_t SMEN:1;
  uint16_t DISSLW:1;
  uint16_t A10M:1;
  uint16_t IPMIEN:1;
  uint16_t SCLREL:1;
  uint16_t I2CSIDL:1;
  uint16_t :1;
  uint16_t I2CEN:1;
} I2CCONBITS;
extern volatile I2CCONBITS I2CCONbits __attribute__((__sfr__));

#define I2CSTAT I2CSTAT
extern volatile uint16_t I2CSTAT __attribute__((__sfr__));
__extension__ typedef struct tagI2CSTATBITS {
  union {
    struct {
      uint16_t TBF:1;
      uint16_t RBF:1;
      uint16_t R_NOT_W:1;
      uint16_t S:1;
      uint16_t P:1;
      uint16_t D_NOT_A:1;
      uint16_t I2COV:1;
      uint16_t IWCOL:1;
      uint16_t ADD10:1;
      uint16_t GCSTAT:1;
      uint16_t BCL:1;
      uint16_t :3;
      uint16_t TRSTAT:1;
      uint16_t ACKSTAT:1;
    };
    struct {
      uint16_t :2;
      uint16_t R_W:1;
      uint16_t :2;
      uint16_t D_A:1;
    };
  };
} I2CSTATBITS;
extern volatile I2CSTATBITS I2CSTATbits __attribute__((__sfr__));

#define I2CADD I2CADD
extern volatile uint16_t I2CADD __attribute__((__sfr__));
typedef struct tagI2CADDBITS {
  uint16_t I2CADD:10;
} I2CADDBITS;
extern volatile I2CADDBITS I2CADDbits __attribute__((__sfr__));


/* Generic structure of entire SFR area for each UART module */
typedef struct tagUART {
        uint16_t uxmode;
        uint16_t uxsta;
        uint16_t uxtxreg;
        uint16_t uxrxreg;
        uint16_t uxbrg;
} UART, *PUART;

#define UxMODEBITS U1MODEBITS
#define UxSTABITS U1STABITS
#define UxTXREGBITS U1TXREGBITS
#define UxRXREGBITS U1RXREGBITS
#define UxBRGBITS U1BRGBITS


/* SFR blocks for each UART module */
#define UART1 UART1
extern volatile UART UART1 __attribute__((__sfr__));

#define U1MODE U1MODE
extern volatile uint16_t U1MODE __attribute__((__sfr__));
__extension__ typedef struct tagU1MODEBITS {
  union {
    struct {
      uint16_t STSEL:1;
      uint16_t PDSEL:2;
      uint16_t :2;
      uint16_t ABAUD:1;
      uint16_t LPBACK:1;
      uint16_t WAKE:1;
      uint16_t :2;
      uint16_t ALTIO:1;
      uint16_t :2;
      uint16_t USIDL:1;
      uint16_t :1;
      uint16_t UARTEN:1;
    };
    struct {
      uint16_t :1;
      uint16_t PDSEL0:1;
      uint16_t PDSEL1:1;
    };
  };
} U1MODEBITS;
extern volatile U1MODEBITS U1MODEbits __attribute__((__sfr__));

#define U1STA U1STA
extern volatile uint16_t U1STA __attribute__((__sfr__));
__extension__ typedef struct tagU1STABITS {
  union {
    struct {
      uint16_t URXDA:1;
      uint16_t OERR:1;
      uint16_t FERR:1;
      uint16_t PERR:1;
      uint16_t RIDLE:1;
      uint16_t ADDEN:1;
      uint16_t URXISEL:2;
      uint16_t TRMT:1;
      uint16_t UTXBF:1;
      uint16_t UTXEN:1;
      uint16_t UTXBRK:1;
      uint16_t :3;
      uint16_t UTXISEL:1;
    };
    struct {
      uint16_t :6;
      uint16_t URXISEL0:1;
      uint16_t URXISEL1:1;
    };
  };
} U1STABITS;
extern volatile U1STABITS U1STAbits __attribute__((__sfr__));

#define U1TXREG U1TXREG
extern volatile uint16_t U1TXREG __attribute__((__sfr__));
__extension__ typedef struct tagU1TXREGBITS {
  union {
    struct {
      uint16_t UTXREG0:1;
      uint16_t UTXREG1:1;
      uint16_t UTXREG2:1;
      uint16_t UTXREG3:1;
      uint16_t UTXREG4:1;
      uint16_t UTXREG5:1;
      uint16_t UTXREG6:1;
      uint16_t UTXREG7:1;
      uint16_t UTXREG8:1;
    };
    struct {
      uint16_t :8;
      uint16_t UTX8:1;
    };
  };
} U1TXREGBITS;
extern volatile U1TXREGBITS U1TXREGbits __attribute__((__sfr__));

#define U1RXREG U1RXREG
extern volatile uint16_t U1RXREG __attribute__((__sfr__));
__extension__ typedef struct tagU1RXREGBITS {
  union {
    struct {
      uint16_t URXREG0:1;
      uint16_t URXREG1:1;
      uint16_t URXREG2:1;
      uint16_t URXREG3:1;
      uint16_t URXREG4:1;
      uint16_t URXREG5:1;
      uint16_t URXREG6:1;
      uint16_t URXREG7:1;
      uint16_t URXREG8:1;
    };
    struct {
      uint16_t :8;
      uint16_t URX8:1;
    };
  };
} U1RXREGBITS;
extern volatile U1RXREGBITS U1RXREGbits __attribute__((__sfr__));

#define U1BRG U1BRG
extern volatile uint16_t U1BRG __attribute__((__sfr__));

/* SFR blocks for each UART module */
#define UART2 UART2
extern volatile UART UART2 __attribute__((__sfr__));

#define U2MODE U2MODE
extern volatile uint16_t U2MODE __attribute__((__sfr__));
__extension__ typedef struct tagU2MODEBITS {
  union {
    struct {
      uint16_t STSEL:1;
      uint16_t PDSEL:2;
      uint16_t :2;
      uint16_t ABAUD:1;
      uint16_t LPBACK:1;
      uint16_t WAKE:1;
      uint16_t :5;
      uint16_t USIDL:1;
      uint16_t :1;
      uint16_t UARTEN:1;
    };
    struct {
      uint16_t :1;
      uint16_t PDSEL0:1;
      uint16_t PDSEL1:1;
    };
  };
} U2MODEBITS;
extern volatile U2MODEBITS U2MODEbits __attribute__((__sfr__));

#define U2STA U2STA
extern volatile uint16_t U2STA __attribute__((__sfr__));
__extension__ typedef struct tagU2STABITS {
  union {
    struct {
      uint16_t URXDA:1;
      uint16_t OERR:1;
      uint16_t FERR:1;
      uint16_t PERR:1;
      uint16_t RIDLE:1;
      uint16_t ADDEN:1;
      uint16_t URXISEL:2;
      uint16_t TRMT:1;
      uint16_t UTXBF:1;
      uint16_t UTXEN:1;
      uint16_t UTXBRK:1;
      uint16_t :3;
      uint16_t UTXISEL:1;
    };
    struct {
      uint16_t :6;
      uint16_t URXISEL0:1;
      uint16_t URXISEL1:1;
    };
  };
} U2STABITS;
extern volatile U2STABITS U2STAbits __attribute__((__sfr__));

#define U2TXREG U2TXREG
extern volatile uint16_t U2TXREG __attribute__((__sfr__));
__extension__ typedef struct tagU2TXREGBITS {
  union {
    struct {
      uint16_t UTXREG0:1;
      uint16_t UTXREG1:1;
      uint16_t UTXREG2:1;
      uint16_t UTXREG3:1;
      uint16_t UTXREG4:1;
      uint16_t UTXREG5:1;
      uint16_t UTXREG6:1;
      uint16_t UTXREG7:1;
      uint16_t UTXREG8:1;
    };
    struct {
      uint16_t :8;
      uint16_t UTX8:1;
    };
  };
} U2TXREGBITS;
extern volatile U2TXREGBITS U2TXREGbits __attribute__((__sfr__));

#define U2RXREG U2RXREG
extern volatile uint16_t U2RXREG __attribute__((__sfr__));
__extension__ typedef struct tagU2RXREGBITS {
  union {
    struct {
      uint16_t URXREG0:1;
      uint16_t URXREG1:1;
      uint16_t URXREG2:1;
      uint16_t URXREG3:1;
      uint16_t URXREG4:1;
      uint16_t URXREG5:1;
      uint16_t URXREG6:1;
      uint16_t URXREG7:1;
      uint16_t URXREG8:1;
    };
    struct {
      uint16_t :8;
      uint16_t URX8:1;
    };
  };
} U2RXREGBITS;
extern volatile U2RXREGBITS U2RXREGbits __attribute__((__sfr__));

#define U2BRG U2BRG
extern volatile uint16_t U2BRG __attribute__((__sfr__));

/* Generic structure of entire SFR area for each SPI module */
typedef struct tagSPI {
        uint16_t spixstat;
        uint16_t spixcon1;
        uint16_t spixcon2;
        uint16_t unused;
        uint16_t spixbuf;
} SPI, *PSPI;

#define SPIxSTATBITS SPI1STATBITS
#define SPIxCONBITS SPI1CONBITS


/* SFR blocks for each SPI module */
#define SPI1 SPI1
extern volatile SPI SPI1 __attribute__((__sfr__));

#define SPI1STAT SPI1STAT
extern volatile uint16_t SPI1STAT __attribute__((__sfr__));
typedef struct tagSPI1STATBITS {
  uint16_t SPIRBF:1;
  uint16_t SPITBF:1;
  uint16_t :4;
  uint16_t SPIROV:1;
  uint16_t :6;
  uint16_t SPISIDL:1;
  uint16_t :1;
  uint16_t SPIEN:1;
} SPI1STATBITS;
extern volatile SPI1STATBITS SPI1STATbits __attribute__((__sfr__));

#define SPI1CON SPI1CON
extern volatile uint16_t SPI1CON __attribute__((__sfr__));
__extension__ typedef struct tagSPI1CONBITS {
  union {
    struct {
      uint16_t PPRE0:1;
      uint16_t PPRE1:1;
      uint16_t SPRE0:1;
      uint16_t SPRE1:1;
      uint16_t SPRE2:1;
      uint16_t MSTEN:1;
      uint16_t CKP:1;
      uint16_t SSEN:1;
      uint16_t CKE:1;
      uint16_t SMP:1;
      uint16_t MODE16:1;
      uint16_t DISSDO:1;
      uint16_t :1;
      uint16_t SPIFSD:1;
      uint16_t FRMEN:1;
    };
    struct {
      uint16_t PPRE:2;
      uint16_t SPRE:3;
    };
  };
} SPI1CONBITS;
extern volatile SPI1CONBITS SPI1CONbits __attribute__((__sfr__));

#define SPI1BUF SPI1BUF
extern volatile uint16_t SPI1BUF __attribute__((__sfr__));
#define ADCBUF0 ADCBUF0
extern volatile uint16_t ADCBUF0 __attribute__((__sfr__));
#define ADCBUF1 ADCBUF1
extern volatile uint16_t ADCBUF1 __attribute__((__sfr__));
#define ADCBUF2 ADCBUF2
extern volatile uint16_t ADCBUF2 __attribute__((__sfr__));
#define ADCBUF3 ADCBUF3
extern volatile uint16_t ADCBUF3 __attribute__((__sfr__));
#define ADCBUF4 ADCBUF4
extern volatile uint16_t ADCBUF4 __attribute__((__sfr__));
#define ADCBUF5 ADCBUF5
extern volatile uint16_t ADCBUF5 __attribute__((__sfr__));
#define ADCBUF6 ADCBUF6
extern volatile uint16_t ADCBUF6 __attribute__((__sfr__));
#define ADCBUF7 ADCBUF7
extern volatile uint16_t ADCBUF7 __attribute__((__sfr__));
#define ADCBUF8 ADCBUF8
extern volatile uint16_t ADCBUF8 __attribute__((__sfr__));
#define ADCBUF9 ADCBUF9
extern volatile uint16_t ADCBUF9 __attribute__((__sfr__));
#define ADCBUFA ADCBUFA
extern volatile uint16_t ADCBUFA __attribute__((__sfr__));
#define ADCBUFB ADCBUFB
extern volatile uint16_t ADCBUFB __attribute__((__sfr__));
#define ADCBUFC ADCBUFC
extern volatile uint16_t ADCBUFC __attribute__((__sfr__));
#define ADCBUFD ADCBUFD
extern volatile uint16_t ADCBUFD __attribute__((__sfr__));
#define ADCBUFE ADCBUFE
extern volatile uint16_t ADCBUFE __attribute__((__sfr__));
#define ADCBUFF ADCBUFF
extern volatile uint16_t ADCBUFF __attribute__((__sfr__));
#define ADCON1 ADCON1
extern volatile uint16_t ADCON1 __attribute__((__sfr__));
__extension__ typedef struct tagADCON1BITS {
  union {
    struct {
      uint16_t DONE:1;
      uint16_t SAMP:1;
      uint16_t ASAM:1;
      uint16_t :2;
      uint16_t SSRC:3;
      uint16_t FORM:2;
      uint16_t :3;
      uint16_t ADSIDL:1;
      uint16_t :1;
      uint16_t ADON:1;
    };
    struct {
      uint16_t :5;
      uint16_t SSRC0:1;
      uint16_t SSRC1:1;
      uint16_t SSRC2:1;
      uint16_t FORM0:1;
      uint16_t FORM1:1;
    };
  };
} ADCON1BITS;
extern volatile ADCON1BITS ADCON1bits __attribute__((__sfr__));

#define ADCON2 ADCON2
extern volatile uint16_t ADCON2 __attribute__((__sfr__));
__extension__ typedef struct tagADCON2BITS {
  union {
    struct {
      uint16_t ALTS:1;
      uint16_t BUFM:1;
      uint16_t SMPI:4;
      uint16_t :1;
      uint16_t BUFS:1;
      uint16_t :2;
      uint16_t CSCNA:1;
      uint16_t :2;
      uint16_t VCFG:3;
    };
    struct {
      uint16_t :2;
      uint16_t SMPI0:1;
      uint16_t SMPI1:1;
      uint16_t SMPI2:1;
      uint16_t SMPI3:1;
      uint16_t :7;
      uint16_t VCFG0:1;
      uint16_t VCFG1:1;
      uint16_t VCFG2:1;
    };
  };
} ADCON2BITS;
extern volatile ADCON2BITS ADCON2bits __attribute__((__sfr__));

#define ADCON3 ADCON3
extern volatile uint16_t ADCON3 __attribute__((__sfr__));
__extension__ typedef struct tagADCON3BITS {
  union {
    struct {
      uint16_t ADCS:6;
      uint16_t :1;
      uint16_t ADRC:1;
      uint16_t SAMC:5;
    };
    struct {
      uint16_t ADCS0:1;
      uint16_t ADCS1:1;
      uint16_t ADCS2:1;
      uint16_t ADCS3:1;
      uint16_t ADCS4:1;
      uint16_t ADCS5:1;
      uint16_t :2;
      uint16_t SAMC0:1;
      uint16_t SAMC1:1;
      uint16_t SAMC2:1;
      uint16_t SAMC3:1;
      uint16_t SAMC4:1;
    };
  };
} ADCON3BITS;
extern volatile ADCON3BITS ADCON3bits __attribute__((__sfr__));

#define ADCHS ADCHS
extern volatile uint16_t ADCHS __attribute__((__sfr__));
__extension__ typedef struct tagADCHSBITS {
  union {
    struct {
      uint16_t CH0SA:4;
      uint16_t CH0NA:1;
      uint16_t :3;
      uint16_t CH0SB:4;
      uint16_t CH0NB:1;
    };
    struct {
      uint16_t CH0SA0:1;
      uint16_t CH0SA1:1;
      uint16_t CH0SA2:1;
      uint16_t CH0SA3:1;
      uint16_t :4;
      uint16_t CH0SB0:1;
      uint16_t CH0SB1:1;
      uint16_t CH0SB2:1;
      uint16_t CH0SB3:1;
    };
  };
} ADCHSBITS;
extern volatile ADCHSBITS ADCHSbits __attribute__((__sfr__));

#define ADPCFG ADPCFG
extern volatile uint16_t ADPCFG __attribute__((__sfr__));
typedef struct tagADPCFGBITS {
  uint16_t PCFG0:1;
  uint16_t PCFG1:1;
  uint16_t PCFG2:1;
  uint16_t PCFG3:1;
  uint16_t PCFG4:1;
  uint16_t PCFG5:1;
  uint16_t PCFG6:1;
  uint16_t PCFG7:1;
  uint16_t PCFG8:1;
  uint16_t PCFG9:1;
} ADPCFGBITS;
extern volatile ADPCFGBITS ADPCFGbits __attribute__((__sfr__));

#define ADCSSL ADCSSL
extern volatile uint16_t ADCSSL __attribute__((__sfr__));
typedef struct tagADCSSLBITS {
  uint16_t CSSL0:1;
  uint16_t CSSL1:1;
  uint16_t CSSL2:1;
  uint16_t CSSL3:1;
  uint16_t CSSL4:1;
  uint16_t CSSL5:1;
  uint16_t CSSL6:1;
  uint16_t CSSL7:1;
  uint16_t CSSL8:1;
  uint16_t CSSL9:1;
} ADCSSLBITS;
extern volatile ADCSSLBITS ADCSSLbits __attribute__((__sfr__));

#define TRISB TRISB
extern volatile uint16_t TRISB __attribute__((__sfr__));
typedef struct tagTRISBBITS {
  uint16_t TRISB0:1;
  uint16_t TRISB1:1;
  uint16_t TRISB2:1;
  uint16_t TRISB3:1;
  uint16_t TRISB4:1;
  uint16_t TRISB5:1;
  uint16_t TRISB6:1;
  uint16_t TRISB7:1;
  uint16_t TRISB8:1;
  uint16_t TRISB9:1;
} TRISBBITS;
extern volatile TRISBBITS TRISBbits __attribute__((__sfr__));

#define PORTB PORTB
extern volatile uint16_t PORTB __attribute__((__sfr__));
typedef struct tagPORTBBITS {
  uint16_t RB0:1;
  uint16_t RB1:1;
  uint16_t RB2:1;
  uint16_t RB3:1;
  uint16_t RB4:1;
  uint16_t RB5:1;
  uint16_t RB6:1;
  uint16_t RB7:1;
  uint16_t RB8:1;
  uint16_t RB9:1;
} PORTBBITS;
extern volatile PORTBBITS PORTBbits __attribute__((__sfr__));

#define LATB LATB
extern volatile uint16_t LATB __attribute__((__sfr__));
typedef struct tagLATBBITS {
  uint16_t LATB0:1;
  uint16_t LATB1:1;
  uint16_t LATB2:1;
  uint16_t LATB3:1;
  uint16_t LATB4:1;
  uint16_t LATB5:1;
  uint16_t LATB6:1;
  uint16_t LATB7:1;
  uint16_t LATB8:1;
  uint16_t LATB9:1;
} LATBBITS;
extern volatile LATBBITS LATBbits __attribute__((__sfr__));

#define TRISC TRISC
extern volatile uint16_t TRISC __attribute__((__sfr__));
typedef struct tagTRISCBITS {
  uint16_t :13;
  uint16_t TRISC13:1;
  uint16_t TRISC14:1;
  uint16_t TRISC15:1;
} TRISCBITS;
extern volatile TRISCBITS TRISCbits __attribute__((__sfr__));

#define PORTC PORTC
extern volatile uint16_t PORTC __attribute__((__sfr__));
typedef struct tagPORTCBITS {
  uint16_t :13;
  uint16_t RC13:1;
  uint16_t RC14:1;
  uint16_t RC15:1;
} PORTCBITS;
extern volatile PORTCBITS PORTCbits __attribute__((__sfr__));

#define LATC LATC
extern volatile uint16_t LATC __attribute__((__sfr__));
typedef struct tagLATCBITS {
  uint16_t :13;
  uint16_t LATC13:1;
  uint16_t LATC14:1;
  uint16_t LATC15:1;
} LATCBITS;
extern volatile LATCBITS LATCbits __attribute__((__sfr__));

#define TRISD TRISD
extern volatile uint16_t TRISD __attribute__((__sfr__));
typedef struct tagTRISDBITS {
  uint16_t :8;
  uint16_t TRISD8:1;
  uint16_t TRISD9:1;
} TRISDBITS;
extern volatile TRISDBITS TRISDbits __attribute__((__sfr__));

#define PORTD PORTD
extern volatile uint16_t PORTD __attribute__((__sfr__));
typedef struct tagPORTDBITS {
  uint16_t :8;
  uint16_t RD8:1;
  uint16_t RD9:1;
} PORTDBITS;
extern volatile PORTDBITS PORTDbits __attribute__((__sfr__));

#define LATD LATD
extern volatile uint16_t LATD __attribute__((__sfr__));
typedef struct tagLATDBITS {
  uint16_t :8;
  uint16_t LATD8:1;
  uint16_t LATD9:1;
} LATDBITS;
extern volatile LATDBITS LATDbits __attribute__((__sfr__));

#define TRISF TRISF
extern volatile uint16_t TRISF __attribute__((__sfr__));
typedef struct tagTRISFBITS {
  uint16_t :2;
  uint16_t TRISF2:1;
  uint16_t TRISF3:1;
  uint16_t TRISF4:1;
  uint16_t TRISF5:1;
  uint16_t TRISF6:1;
} TRISFBITS;
extern volatile TRISFBITS TRISFbits __attribute__((__sfr__));

#define PORTF PORTF
extern volatile uint16_t PORTF __attribute__((__sfr__));
typedef struct tagPORTFBITS {
  uint16_t :2;
  uint16_t RF2:1;
  uint16_t RF3:1;
  uint16_t RF4:1;
  uint16_t RF5:1;
  uint16_t RF6:1;
} PORTFBITS;
extern volatile PORTFBITS PORTFbits __attribute__((__sfr__));

#define LATF LATF
extern volatile uint16_t LATF __attribute__((__sfr__));
typedef struct tagLATFBITS {
  uint16_t :2;
  uint16_t LATF2:1;
  uint16_t LATF3:1;
  uint16_t LATF4:1;
  uint16_t LATF5:1;
  uint16_t LATF6:1;
} LATFBITS;
extern volatile LATFBITS LATFbits __attribute__((__sfr__));

#define RCON RCON
extern volatile uint16_t RCON __attribute__((__sfr__));
__extension__ typedef struct tagRCONBITS {
  union {
    struct {
      uint16_t POR:1;
      uint16_t BOR:1;
      uint16_t IDLE:1;
      uint16_t SLEEP:1;
      uint16_t WDTO:1;
      uint16_t SWDTEN:1;
      uint16_t SWR:1;
      uint16_t EXTR:1;
      uint16_t LVDL:4;
      uint16_t LVDEN:1;
      uint16_t BGST:1;
      uint16_t IOPUWR:1;
      uint16_t TRAPR:1;
    };
    struct {
      uint16_t :8;
      uint16_t LVDL0:1;
      uint16_t LVDL1:1;
      uint16_t LVDL2:1;
      uint16_t LVDL3:1;
    };
  };
} RCONBITS;
extern volatile RCONBITS RCONbits __attribute__((__sfr__));

#define OSCCON OSCCON
extern volatile uint16_t OSCCON __attribute__((__sfr__));
__extension__ typedef struct tagOSCCONBITS {
  union {
    struct {
      uint16_t OSWEN:1;
      uint16_t LPOSCEN:1;
      uint16_t :1;
      uint16_t CF:1;
      uint16_t :1;
      uint16_t LOCK:1;
      uint16_t POST:2;
      uint16_t NOSC:3;
      uint16_t :1;
      uint16_t COSC:3;
    };
    struct {
      uint16_t :6;
      uint16_t POST0:1;
      uint16_t POST1:1;
      uint16_t NOSC0:1;
      uint16_t NOSC1:1;
      uint16_t NOSC2:1;
      uint16_t :1;
      uint16_t COSC0:1;
      uint16_t COSC1:1;
      uint16_t COSC2:1;
    };
  };
} OSCCONBITS;
extern volatile OSCCONBITS OSCCONbits __attribute__((__sfr__));

#define OSCCONL OSCCONL
extern volatile uint8_t OSCCONL __attribute__((__sfr__));
#define OSCCONH OSCCONH
extern volatile uint8_t OSCCONH __attribute__((__sfr__));
#define OSCTUN OSCTUN
extern volatile uint16_t OSCTUN __attribute__((__sfr__));
typedef struct tagOSCTUNBITS {
  uint16_t TUN0:1;
  uint16_t TUN1:1;
  uint16_t TUN2:1;
  uint16_t TUN3:1;
} OSCTUNBITS;
extern volatile OSCTUNBITS OSCTUNbits __attribute__((__sfr__));

#define NVMCON NVMCON
extern volatile uint16_t NVMCON __attribute__((__sfr__));
__extension__ typedef struct tagNVMCONBITS {
  union {
    struct {
      uint16_t PROGOP:7;
      uint16_t :1;
      uint16_t TWRI:1;
      uint16_t :4;
      uint16_t WRERR:1;
      uint16_t WREN:1;
      uint16_t WR:1;
    };
    struct {
      uint16_t PROGOP0:1;
      uint16_t PROGOP1:1;
      uint16_t PROGOP2:1;
      uint16_t PROGOP3:1;
      uint16_t PROGOP4:1;
      uint16_t PROGOP5:1;
      uint16_t PROGOP6:1;
    };
  };
} NVMCONBITS;
extern volatile NVMCONBITS NVMCONbits __attribute__((__sfr__));

#define NVMADR NVMADR
extern volatile uint16_t NVMADR __attribute__((__sfr__));
#define NVMADRU NVMADRU
extern volatile uint16_t NVMADRU __attribute__((__sfr__));
typedef struct tagNVMADRUBITS {
  uint16_t NVMADR:8;
} NVMADRUBITS;
extern volatile NVMADRUBITS NVMADRUbits __attribute__((__sfr__));

#define NVMKEY NVMKEY
extern volatile uint16_t NVMKEY __attribute__((__sfr__));
#define PMD1 PMD1
extern volatile uint16_t PMD1 __attribute__((__sfr__));
typedef struct tagPMD1BITS {
  uint16_t ADCMD:1;
  uint16_t :2;
  uint16_t SPI1MD:1;
  uint16_t :1;
  uint16_t U1MD:1;
  uint16_t U2MD:1;
  uint16_t I2CMD:1;
  uint16_t :3;
  uint16_t T1MD:1;
  uint16_t T2MD:1;
  uint16_t T3MD:1;
} PMD1BITS;
extern volatile PMD1BITS PMD1bits __attribute__((__sfr__));

#define PMD2 PMD2
extern volatile uint16_t PMD2 __attribute__((__sfr__));
typedef struct tagPMD2BITS {
  uint16_t OC1MD:1;
  uint16_t OC2MD:1;
  uint16_t :6;
  uint16_t IC1MD:1;
  uint16_t IC2MD:1;
} PMD2BITS;
extern volatile PMD2BITS PMD2bits __attribute__((__sfr__));



/* ---------------------------------------------------------- */
/* Defines for unique SFR bit names                           */
/* ---------------------------------------------------------- */

/* SR */
#define _C SRbits.C
#define _Z SRbits.Z
#define _OV SRbits.OV
#define _N SRbits.N
#define _RA SRbits.RA
#define _IPL SRbits.IPL
#define _DC SRbits.DC
#define _DA SRbits.DA
#define _SAB SRbits.SAB
#define _OAB SRbits.OAB
#define _SB SRbits.SB
#define _SA SRbits.SA
#define _OB SRbits.OB
#define _OA SRbits.OA
#define _IPL0 SRbits.IPL0
#define _IPL1 SRbits.IPL1
#define _IPL2 SRbits.IPL2

/* CORCON */
#define _IF CORCONbits.IF
#define _RND CORCONbits.RND
#define _PSV CORCONbits.PSV
#define _IPL3 CORCONbits.IPL3
#define _ACCSAT CORCONbits.ACCSAT
#define _SATDW CORCONbits.SATDW
#define _SATB CORCONbits.SATB
#define _SATA CORCONbits.SATA
#define _DL CORCONbits.DL
#define _EDT CORCONbits.EDT
#define _US CORCONbits.US
#define _DL0 CORCONbits.DL0
#define _DL1 CORCONbits.DL1
#define _DL2 CORCONbits.DL2

/* MODCON */
#define _XWM MODCONbits.XWM
#define _YWM MODCONbits.YWM
#define _BWM MODCONbits.BWM
#define _YMODEN MODCONbits.YMODEN
#define _XMODEN MODCONbits.XMODEN
#define _XWM0 MODCONbits.XWM0
#define _XWM1 MODCONbits.XWM1
#define _XWM2 MODCONbits.XWM2
#define _XWM3 MODCONbits.XWM3
#define _YWM0 MODCONbits.YWM0
#define _YWM1 MODCONbits.YWM1
#define _YWM2 MODCONbits.YWM2
#define _YWM3 MODCONbits.YWM3
#define _BWM0 MODCONbits.BWM0
#define _BWM1 MODCONbits.BWM1
#define _BWM2 MODCONbits.BWM2
#define _BWM3 MODCONbits.BWM3

/* XBREV */
#define _XB XBREVbits.XB
#define _BREN XBREVbits.BREN
#define _XB0 XBREVbits.XB0
#define _XB1 XBREVbits.XB1
#define _XB2 XBREVbits.XB2
#define _XB3 XBREVbits.XB3
#define _XB4 XBREVbits.XB4
#define _XB5 XBREVbits.XB5
#define _XB6 XBREVbits.XB6
#define _XB7 XBREVbits.XB7
#define _XB8 XBREVbits.XB8
#define _XB9 XBREVbits.XB9
#define _XB10 XBREVbits.XB10
#define _XB11 XBREVbits.XB11
#define _XB12 XBREVbits.XB12
#define _XB13 XBREVbits.XB13
#define _XB14 XBREVbits.XB14

/* DISICNT */
#define _DISICNT DISICNTbits.DISICNT

/* INTCON1 */
#define _OSCFAIL INTCON1bits.OSCFAIL
#define _STKERR INTCON1bits.STKERR
#define _ADDRERR INTCON1bits.ADDRERR
#define _MATHERR INTCON1bits.MATHERR
#define _COVTE INTCON1bits.COVTE
#define _OVBTE INTCON1bits.OVBTE
#define _OVATE INTCON1bits.OVATE
#define _NSTDIS INTCON1bits.NSTDIS

/* INTCON2 */
#define _INT0EP INTCON2bits.INT0EP
#define _INT1EP INTCON2bits.INT1EP
#define _INT2EP INTCON2bits.INT2EP
#define _DISI INTCON2bits.DISI
#define _ALTIVT INTCON2bits.ALTIVT

/* IFS0 */
#define _INT0IF IFS0bits.INT0IF
#define _IC1IF IFS0bits.IC1IF
#define _OC1IF IFS0bits.OC1IF
#define _T1IF IFS0bits.T1IF
#define _IC2IF IFS0bits.IC2IF
#define _OC2IF IFS0bits.OC2IF
#define _T2IF IFS0bits.T2IF
#define _T3IF IFS0bits.T3IF
#define _SPI1IF IFS0bits.SPI1IF
#define _U1RXIF IFS0bits.U1RXIF
#define _U1TXIF IFS0bits.U1TXIF
#define _ADIF IFS0bits.ADIF
#define _NVMIF IFS0bits.NVMIF
#define _SI2CIF IFS0bits.SI2CIF
#define _MI2CIF IFS0bits.MI2CIF
#define _CNIF IFS0bits.CNIF

/* IFS1 */
#define _INT1IF IFS1bits.INT1IF
#define _INT2IF IFS1bits.INT2IF
#define _U2RXIF IFS1bits.U2RXIF
#define _U2TXIF IFS1bits.U2TXIF

/* IFS2 */
#define _LVDIF IFS2bits.LVDIF

/* IEC0 */
#define _INT0IE IEC0bits.INT0IE
#define _IC1IE IEC0bits.IC1IE
#define _OC1IE IEC0bits.OC1IE
#define _T1IE IEC0bits.T1IE
#define _IC2IE IEC0bits.IC2IE
#define _OC2IE IEC0bits.OC2IE
#define _T2IE IEC0bits.T2IE
#define _T3IE IEC0bits.T3IE
#define _SPI1IE IEC0bits.SPI1IE
#define _U1RXIE IEC0bits.U1RXIE
#define _U1TXIE IEC0bits.U1TXIE
#define _ADIE IEC0bits.ADIE
#define _NVMIE IEC0bits.NVMIE
#define _SI2CIE IEC0bits.SI2CIE
#define _MI2CIE IEC0bits.MI2CIE
#define _CNIE IEC0bits.CNIE

/* IEC1 */
#define _INT1IE IEC1bits.INT1IE
#define _INT2IE IEC1bits.INT2IE
#define _U2RXIE IEC1bits.U2RXIE
#define _U2TXIE IEC1bits.U2TXIE

/* IEC2 */
#define _LVDIE IEC2bits.LVDIE

/* IPC0 */
#define _INT0IP IPC0bits.INT0IP
#define _IC1IP IPC0bits.IC1IP
#define _OC1IP IPC0bits.OC1IP
#define _T1IP IPC0bits.T1IP
#define _INT0IP0 IPC0bits.INT0IP0
#define _INT0IP1 IPC0bits.INT0IP1
#define _INT0IP2 IPC0bits.INT0IP2
#define _IC1IP0 IPC0bits.IC1IP0
#define _IC1IP1 IPC0bits.IC1IP1
#define _IC1IP2 IPC0bits.IC1IP2
#define _OC1IP0 IPC0bits.OC1IP0
#define _OC1IP1 IPC0bits.OC1IP1
#define _OC1IP2 IPC0bits.OC1IP2
#define _T1IP0 IPC0bits.T1IP0
#define _T1IP1 IPC0bits.T1IP1
#define _T1IP2 IPC0bits.T1IP2

/* IPC1 */
#define _IC2IP IPC1bits.IC2IP
#define _OC2IP IPC1bits.OC2IP
#define _T2IP IPC1bits.T2IP
#define _T3IP IPC1bits.T3IP
#define _IC2IP0 IPC1bits.IC2IP0
#define _IC2IP1 IPC1bits.IC2IP1
#define _IC2IP2 IPC1bits.IC2IP2
#define _OC2IP0 IPC1bits.OC2IP0
#define _OC2IP1 IPC1bits.OC2IP1
#define _OC2IP2 IPC1bits.OC2IP2
#define _T2IP0 IPC1bits.T2IP0
#define _T2IP1 IPC1bits.T2IP1
#define _T2IP2 IPC1bits.T2IP2
#define _T3IP0 IPC1bits.T3IP0
#define _T3IP1 IPC1bits.T3IP1
#define _T3IP2 IPC1bits.T3IP2

/* IPC2 */
#define _SPI1IP IPC2bits.SPI1IP
#define _U1RXIP IPC2bits.U1RXIP
#define _U1TXIP IPC2bits.U1TXIP
#define _ADIP IPC2bits.ADIP
#define _SPI1IP0 IPC2bits.SPI1IP0
#define _SPI1IP1 IPC2bits.SPI1IP1
#define _SPI1IP2 IPC2bits.SPI1IP2
#define _U1RXIP0 IPC2bits.U1RXIP0
#define _U1RXIP1 IPC2bits.U1RXIP1
#define _U1RXIP2 IPC2bits.U1RXIP2
#define _U1TXIP0 IPC2bits.U1TXIP0
#define _U1TXIP1 IPC2bits.U1TXIP1
#define _U1TXIP2 IPC2bits.U1TXIP2
#define _ADIP0 IPC2bits.ADIP0
#define _ADIP1 IPC2bits.ADIP1
#define _ADIP2 IPC2bits.ADIP2

/* IPC3 */
#define _NVMIP IPC3bits.NVMIP
#define _SI2CIP IPC3bits.SI2CIP
#define _MI2CIP IPC3bits.MI2CIP
#define _CNIP IPC3bits.CNIP
#define _NVMIP0 IPC3bits.NVMIP0
#define _NVMIP1 IPC3bits.NVMIP1
#define _NVMIP2 IPC3bits.NVMIP2
#define _SI2CIP0 IPC3bits.SI2CIP0
#define _SI2CIP1 IPC3bits.SI2CIP1
#define _SI2CIP2 IPC3bits.SI2CIP2
#define _MI2CIP0 IPC3bits.MI2CIP0
#define _MI2CIP1 IPC3bits.MI2CIP1
#define _MI2CIP2 IPC3bits.MI2CIP2
#define _CNIP0 IPC3bits.CNIP0
#define _CNIP1 IPC3bits.CNIP1
#define _CNIP2 IPC3bits.CNIP2

/* IPC4 */
#define _INT1IP IPC4bits.INT1IP
#define _INT1IP0 IPC4bits.INT1IP0
#define _INT1IP1 IPC4bits.INT1IP1
#define _INT1IP2 IPC4bits.INT1IP2

/* IPC5 */
#define _INT2IP IPC5bits.INT2IP
#define _INT2IP0 IPC5bits.INT2IP0
#define _INT2IP1 IPC5bits.INT2IP1
#define _INT2IP2 IPC5bits.INT2IP2

/* IPC6 */
#define _U2RXIP IPC6bits.U2RXIP
#define _U2TXIP IPC6bits.U2TXIP
#define _U2RXIP0 IPC6bits.U2RXIP0
#define _U2RXIP1 IPC6bits.U2RXIP1
#define _U2RXIP2 IPC6bits.U2RXIP2
#define _U2TXIP0 IPC6bits.U2TXIP0
#define _U2TXIP1 IPC6bits.U2TXIP1
#define _U2TXIP2 IPC6bits.U2TXIP2

/* IPC10 */
#define _LVDIP IPC10bits.LVDIP
#define _LVDIP0 IPC10bits.LVDIP0
#define _LVDIP1 IPC10bits.LVDIP1
#define _LVDIP2 IPC10bits.LVDIP2

/* INTTREG */
#define _VECNUM INTTREGbits.VECNUM
#define _ILR INTTREGbits.ILR
#define _VHOLD INTTREGbits.VHOLD
#define _TMODE INTTREGbits.TMODE
#define _IRQTOCPU INTTREGbits.IRQTOCPU
#define _VECNUM0 INTTREGbits.VECNUM0
#define _VECNUM1 INTTREGbits.VECNUM1
#define _VECNUM2 INTTREGbits.VECNUM2
#define _VECNUM3 INTTREGbits.VECNUM3
#define _VECNUM4 INTTREGbits.VECNUM4
#define _VECNUM5 INTTREGbits.VECNUM5
#define _ILR0 INTTREGbits.ILR0
#define _ILR1 INTTREGbits.ILR1
#define _ILR2 INTTREGbits.ILR2
#define _ILR3 INTTREGbits.ILR3

/* CNEN1 */
#define _CN0IE CNEN1bits.CN0IE
#define _CN1IE CNEN1bits.CN1IE
#define _CN2IE CNEN1bits.CN2IE
#define _CN3IE CNEN1bits.CN3IE
#define _CN4IE CNEN1bits.CN4IE
#define _CN5IE CNEN1bits.CN5IE
#define _CN6IE CNEN1bits.CN6IE
#define _CN7IE CNEN1bits.CN7IE

/* CNEN2 */
#define _CN17IE CNEN2bits.CN17IE
#define _CN18IE CNEN2bits.CN18IE

/* CNPU1 */
#define _CN0PUE CNPU1bits.CN0PUE
#define _CN1PUE CNPU1bits.CN1PUE
#define _CN2PUE CNPU1bits.CN2PUE
#define _CN3PUE CNPU1bits.CN3PUE
#define _CN4PUE CNPU1bits.CN4PUE
#define _CN5PUE CNPU1bits.CN5PUE
#define _CN6PUE CNPU1bits.CN6PUE
#define _CN7PUE CNPU1bits.CN7PUE

/* CNPU2 */
#define _CN17PUE CNPU2bits.CN17PUE
#define _CN18PUE CNPU2bits.CN18PUE

/* T1CON */
#define _TCS T1CONbits.TCS
#define _TSYNC T1CONbits.TSYNC
#define _TCKPS T1CONbits.TCKPS
#define _TGATE T1CONbits.TGATE
#define _TSIDL T1CONbits.TSIDL
#define _TON T1CONbits.TON
#define _TCKPS0 T1CONbits.TCKPS0
#define _TCKPS1 T1CONbits.TCKPS1

/* T2CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
#define _T32 T2CONbits.T32
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* T3CON */
/* Bitname _TCS cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS cannot be defined because it is used by more than one SFR */
/* Bitname _TGATE cannot be defined because it is used by more than one SFR */
/* Bitname _TSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _TON cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS0 cannot be defined because it is used by more than one SFR */
/* Bitname _TCKPS1 cannot be defined because it is used by more than one SFR */

/* IC1CON */
#define _ICM IC1CONbits.ICM
#define _ICBNE IC1CONbits.ICBNE
#define _ICOV IC1CONbits.ICOV
#define _ICI IC1CONbits.ICI
#define _ICTMR IC1CONbits.ICTMR
#define _ICSIDL IC1CONbits.ICSIDL
#define _ICM0 IC1CONbits.ICM0
#define _ICM1 IC1CONbits.ICM1
#define _ICM2 IC1CONbits.ICM2
#define _ICI0 IC1CONbits.ICI0
#define _ICI1 IC1CONbits.ICI1

/* IC2CON */
/* Bitname _ICM cannot be defined because it is used by more than one SFR */
/* Bitname _ICBNE cannot be defined because it is used by more than one SFR */
/* Bitname _ICOV cannot be defined because it is used by more than one SFR */
/* Bitname _ICI cannot be defined because it is used by more than one SFR */
/* Bitname _ICTMR cannot be defined because it is used by more than one SFR */
/* Bitname _ICSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _ICM0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM1 cannot be defined because it is used by more than one SFR */
/* Bitname _ICM2 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI0 cannot be defined because it is used by more than one SFR */
/* Bitname _ICI1 cannot be defined because it is used by more than one SFR */

/* OC1CON */
#define _OCM OC1CONbits.OCM
#define _OCTSEL OC1CONbits.OCTSEL
#define _OCFLT OC1CONbits.OCFLT
#define _OCSIDL OC1CONbits.OCSIDL
#define _OCM0 OC1CONbits.OCM0
#define _OCM1 OC1CONbits.OCM1
#define _OCM2 OC1CONbits.OCM2

/* OC2CON */
/* Bitname _OCM cannot be defined because it is used by more than one SFR */
/* Bitname _OCTSEL cannot be defined because it is used by more than one SFR */
/* Bitname _OCFLT cannot be defined because it is used by more than one SFR */
/* Bitname _OCSIDL cannot be defined because it is used by more than one SFR */
/* Bitname _OCM0 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM1 cannot be defined because it is used by more than one SFR */
/* Bitname _OCM2 cannot be defined because it is used by more than one SFR */

/* I2CRCV */
#define _I2CRCV I2CRCVbits.I2CRCV
#define _I2CRCV0 I2CRCVbits.I2CRCV0
#define _I2CRCV1 I2CRCVbits.I2CRCV1
#define _I2CRCV2 I2CRCVbits.I2CRCV2
#define _I2CRCV3 I2CRCVbits.I2CRCV3
#define _I2CRCV4 I2CRCVbits.I2CRCV4
#define _I2CRCV5 I2CRCVbits.I2CRCV5
#define _I2CRCV6 I2CRCVbits.I2CRCV6
#define _I2CRCV7 I2CRCVbits.I2CRCV7

/* I2CTRN */
#define _I2CTRN I2CTRNbits.I2CTRN
#define _I2CTRN0 I2CTRNbits.I2CTRN0
#define _I2CTRN1 I2CTRNbits.I2CTRN1
#define _I2CTRN2 I2CTRNbits.I2CTRN2
#define _I2CTRN3 I2CTRNbits.I2CTRN3
#define _I2CTRN4 I2CTRNbits.I2CTRN4
#define _I2CTRN5 I2CTRNbits.I2CTRN5
#define _I2CTRN6 I2CTRNbits.I2CTRN6
#define _I2CTRN7 I2CTRNbits.I2CTRN7

/* I2CBRG */
#define _I2CBRG I2CBRGbits.I2CBRG

/* I2CCON */
#define _SEN I2CCONbits.SEN
#define _RSEN I2CCONbits.RSEN
#define _PEN I2CCONbits.PEN
#define _RCEN I2CCONbits.RCEN
#define _ACKEN I2CCONbits.ACKEN
#define _ACKDT I2CCONbits.ACKDT
#define _STREN I2CCONbits.STREN
#define _GCEN I2CCONbits.GCEN
#define _SMEN I2CCONbits.SMEN
#define _DISSLW I2CCONbits.DISSLW
#define _A10M I2CCONbits.A10M
#define _IPMIEN I2CCONbits.IPMIEN
#define _SCLREL I2CCONbits.SCLREL
#define _I2CSIDL I2CCONbits.I2CSIDL
#define _I2CEN I2CCONbits.I2CEN

/* I2CSTAT */
#define _TBF I2CSTATbits.TBF
#define _RBF I2CSTATbits.RBF
#define _R_NOT_W I2CSTATbits.R_NOT_W
#define _S I2CSTATbits.S
#define _P I2CSTATbits.P
#define _D_NOT_A I2CSTATbits.D_NOT_A
#define _I2COV I2CSTATbits.I2COV
#define _IWCOL I2CSTATbits.IWCOL
#define _ADD10 I2CSTATbits.ADD10
#define _GCSTAT I2CSTATbits.GCSTAT
#define _BCL I2CSTATbits.BCL
#define _TRSTAT I2CSTATbits.TRSTAT
#define _ACKSTAT I2CSTATbits.ACKSTAT
#define _R_W I2CSTATbits.R_W
#define _D_A I2CSTATbits.D_A

/* I2CADD */
#define _I2CADD I2CADDbits.I2CADD

/* U1MODE */
#define _STSEL U1MODEbits.STSEL
#define _PDSEL U1MODEbits.PDSEL
#define _ABAUD U1MODEbits.ABAUD
#define _LPBACK U1MODEbits.LPBACK
#define _WAKE U1MODEbits.WAKE
#define _ALTIO U1MODEbits.ALTIO
#define _USIDL U1MODEbits.USIDL
#define _UARTEN U1MODEbits.UARTEN
#define _PDSEL0 U1MODEbits.PDSEL0
#define _PDSEL1 U1MODEbits.PDSEL1

/* U1STA */
#define _URXDA U1STAbits.URXDA
#define _OERR U1STAbits.OERR
#define _FERR U1STAbits.FERR
#define _PERR U1STAbits.PERR
#define _RIDLE U1STAbits.RIDLE
#define _ADDEN U1STAbits.ADDEN
#define _URXISEL U1STAbits.URXISEL
#define _TRMT U1STAbits.TRMT
#define _UTXBF U1STAbits.UTXBF
#define _UTXEN U1STAbits.UTXEN
#define _UTXBRK U1STAbits.UTXBRK
#define _UTXISEL U1STAbits.UTXISEL
#define _URXISEL0 U1STAbits.URXISEL0
#define _URXISEL1 U1STAbits.URXISEL1

/* U1TXREG */
#define _UTXREG0 U1TXREGbits.UTXREG0
#define _UTXREG1 U1TXREGbits.UTXREG1
#define _UTXREG2 U1TXREGbits.UTXREG2
#define _UTXREG3 U1TXREGbits.UTXREG3
#define _UTXREG4 U1TXREGbits.UTXREG4
#define _UTXREG5 U1TXREGbits.UTXREG5
#define _UTXREG6 U1TXREGbits.UTXREG6
#define _UTXREG7 U1TXREGbits.UTXREG7
#define _UTXREG8 U1TXREGbits.UTXREG8
#define _UTX8 U1TXREGbits.UTX8

/* U1RXREG */
#define _URXREG0 U1RXREGbits.URXREG0
#define _URXREG1 U1RXREGbits.URXREG1
#define _URXREG2 U1RXREGbits.URXREG2
#define _URXREG3 U1RXREGbits.URXREG3
#define _URXREG4 U1RXREGbits.URXREG4
#define _URXREG5 U1RXREGbits.URXREG5
#define _URXREG6 U1RXREGbits.URXREG6
#define _URXREG7 U1RXREGbits.URXREG7
#define _URXREG8 U1RXREGbits.URXREG8
#define _URX8 U1RXREGbits.URX8

/* U2MODE */
/* Bitname _STSEL cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL cannot be defined because it is used by more than one SFR */
/* Bitname _ABAUD cannot be defined because it is used by more than one SFR */
/* Bitname _LPBACK cannot be defined because it is used by more than one SFR */
/* Bitname _WAKE cannot be defined because it is used by more than one SFR */
/* Bitname _USIDL cannot be defined because it is used by more than one SFR */
/* Bitname _UARTEN cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _PDSEL1 cannot be defined because it is used by more than one SFR */

/* U2STA */
/* Bitname _URXDA cannot be defined because it is used by more than one SFR */
/* Bitname _OERR cannot be defined because it is used by more than one SFR */
/* Bitname _FERR cannot be defined because it is used by more than one SFR */
/* Bitname _PERR cannot be defined because it is used by more than one SFR */
/* Bitname _RIDLE cannot be defined because it is used by more than one SFR */
/* Bitname _ADDEN cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL cannot be defined because it is used by more than one SFR */
/* Bitname _TRMT cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBF cannot be defined because it is used by more than one SFR */
/* Bitname _UTXEN cannot be defined because it is used by more than one SFR */
/* Bitname _UTXBRK cannot be defined because it is used by more than one SFR */
/* Bitname _UTXISEL cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXISEL1 cannot be defined because it is used by more than one SFR */

/* U2TXREG */
/* Bitname _UTXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _UTXREG8 cannot be defined because it is used by more than one SFR */
/* Bitname _UTX8 cannot be defined because it is used by more than one SFR */

/* U2RXREG */
/* Bitname _URXREG0 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG1 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG2 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG3 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG4 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG5 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG6 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG7 cannot be defined because it is used by more than one SFR */
/* Bitname _URXREG8 cannot be defined because it is used by more than one SFR */
/* Bitname _URX8 cannot be defined because it is used by more than one SFR */

/* SPI1STAT */
#define _SPIRBF SPI1STATbits.SPIRBF
#define _SPITBF SPI1STATbits.SPITBF
#define _SPIROV SPI1STATbits.SPIROV
#define _SPISIDL SPI1STATbits.SPISIDL
#define _SPIEN SPI1STATbits.SPIEN

/* SPI1CON */
#define _PPRE0 SPI1CONbits.PPRE0
#define _PPRE1 SPI1CONbits.PPRE1
#define _SPRE0 SPI1CONbits.SPRE0
#define _SPRE1 SPI1CONbits.SPRE1
#define _SPRE2 SPI1CONbits.SPRE2
#define _MSTEN SPI1CONbits.MSTEN
#define _CKP SPI1CONbits.CKP
#define _SSEN SPI1CONbits.SSEN
#define _CKE SPI1CONbits.CKE
#define _SMP SPI1CONbits.SMP
#define _MODE16 SPI1CONbits.MODE16
#define _DISSDO SPI1CONbits.DISSDO
#define _SPIFSD SPI1CONbits.SPIFSD
#define _FRMEN SPI1CONbits.FRMEN
#define _PPRE SPI1CONbits.PPRE
#define _SPRE SPI1CONbits.SPRE

/* ADCON1 */
#define _DONE ADCON1bits.DONE
#define _SAMP ADCON1bits.SAMP
#define _ASAM ADCON1bits.ASAM
#define _SSRC ADCON1bits.SSRC
#define _FORM ADCON1bits.FORM
#define _ADSIDL ADCON1bits.ADSIDL
#define _ADON ADCON1bits.ADON
#define _SSRC0 ADCON1bits.SSRC0
#define _SSRC1 ADCON1bits.SSRC1
#define _SSRC2 ADCON1bits.SSRC2
#define _FORM0 ADCON1bits.FORM0
#define _FORM1 ADCON1bits.FORM1

/* ADCON2 */
#define _ALTS ADCON2bits.ALTS
#define _BUFM ADCON2bits.BUFM
#define _SMPI ADCON2bits.SMPI
#define _BUFS ADCON2bits.BUFS
#define _CSCNA ADCON2bits.CSCNA
#define _VCFG ADCON2bits.VCFG
#define _SMPI0 ADCON2bits.SMPI0
#define _SMPI1 ADCON2bits.SMPI1
#define _SMPI2 ADCON2bits.SMPI2
#define _SMPI3 ADCON2bits.SMPI3
#define _VCFG0 ADCON2bits.VCFG0
#define _VCFG1 ADCON2bits.VCFG1
#define _VCFG2 ADCON2bits.VCFG2

/* ADCON3 */
#define _ADCS ADCON3bits.ADCS
#define _ADRC ADCON3bits.ADRC
#define _SAMC ADCON3bits.SAMC
#define _ADCS0 ADCON3bits.ADCS0
#define _ADCS1 ADCON3bits.ADCS1
#define _ADCS2 ADCON3bits.ADCS2
#define _ADCS3 ADCON3bits.ADCS3
#define _ADCS4 ADCON3bits.ADCS4
#define _ADCS5 ADCON3bits.ADCS5
#define _SAMC0 ADCON3bits.SAMC0
#define _SAMC1 ADCON3bits.SAMC1
#define _SAMC2 ADCON3bits.SAMC2
#define _SAMC3 ADCON3bits.SAMC3
#define _SAMC4 ADCON3bits.SAMC4

/* ADCHS */
#define _CH0SA ADCHSbits.CH0SA
#define _CH0NA ADCHSbits.CH0NA
#define _CH0SB ADCHSbits.CH0SB
#define _CH0NB ADCHSbits.CH0NB
#define _CH0SA0 ADCHSbits.CH0SA0
#define _CH0SA1 ADCHSbits.CH0SA1
#define _CH0SA2 ADCHSbits.CH0SA2
#define _CH0SA3 ADCHSbits.CH0SA3
#define _CH0SB0 ADCHSbits.CH0SB0
#define _CH0SB1 ADCHSbits.CH0SB1
#define _CH0SB2 ADCHSbits.CH0SB2
#define _CH0SB3 ADCHSbits.CH0SB3

/* ADPCFG */
#define _PCFG0 ADPCFGbits.PCFG0
#define _PCFG1 ADPCFGbits.PCFG1
#define _PCFG2 ADPCFGbits.PCFG2
#define _PCFG3 ADPCFGbits.PCFG3
#define _PCFG4 ADPCFGbits.PCFG4
#define _PCFG5 ADPCFGbits.PCFG5
#define _PCFG6 ADPCFGbits.PCFG6
#define _PCFG7 ADPCFGbits.PCFG7
#define _PCFG8 ADPCFGbits.PCFG8
#define _PCFG9 ADPCFGbits.PCFG9

/* ADCSSL */
#define _CSSL0 ADCSSLbits.CSSL0
#define _CSSL1 ADCSSLbits.CSSL1
#define _CSSL2 ADCSSLbits.CSSL2
#define _CSSL3 ADCSSLbits.CSSL3
#define _CSSL4 ADCSSLbits.CSSL4
#define _CSSL5 ADCSSLbits.CSSL5
#define _CSSL6 ADCSSLbits.CSSL6
#define _CSSL7 ADCSSLbits.CSSL7
#define _CSSL8 ADCSSLbits.CSSL8
#define _CSSL9 ADCSSLbits.CSSL9

/* TRISB */
#define _TRISB0 TRISBbits.TRISB0
#define _TRISB1 TRISBbits.TRISB1
#define _TRISB2 TRISBbits.TRISB2
#define _TRISB3 TRISBbits.TRISB3
#define _TRISB4 TRISBbits.TRISB4
#define _TRISB5 TRISBbits.TRISB5
#define _TRISB6 TRISBbits.TRISB6
#define _TRISB7 TRISBbits.TRISB7
#define _TRISB8 TRISBbits.TRISB8
#define _TRISB9 TRISBbits.TRISB9

/* PORTB */
#define _RB0 PORTBbits.RB0
#define _RB1 PORTBbits.RB1
#define _RB2 PORTBbits.RB2
#define _RB3 PORTBbits.RB3
#define _RB4 PORTBbits.RB4
#define _RB5 PORTBbits.RB5
#define _RB6 PORTBbits.RB6
#define _RB7 PORTBbits.RB7
#define _RB8 PORTBbits.RB8
#define _RB9 PORTBbits.RB9

/* LATB */
#define _LATB0 LATBbits.LATB0
#define _LATB1 LATBbits.LATB1
#define _LATB2 LATBbits.LATB2
#define _LATB3 LATBbits.LATB3
#define _LATB4 LATBbits.LATB4
#define _LATB5 LATBbits.LATB5
#define _LATB6 LATBbits.LATB6
#define _LATB7 LATBbits.LATB7
#define _LATB8 LATBbits.LATB8
#define _LATB9 LATBbits.LATB9

/* TRISC */
#define _TRISC13 TRISCbits.TRISC13
#define _TRISC14 TRISCbits.TRISC14
#define _TRISC15 TRISCbits.TRISC15

/* PORTC */
#define _RC13 PORTCbits.RC13
#define _RC14 PORTCbits.RC14
#define _RC15 PORTCbits.RC15

/* LATC */
#define _LATC13 LATCbits.LATC13
#define _LATC14 LATCbits.LATC14
#define _LATC15 LATCbits.LATC15

/* TRISD */
#define _TRISD8 TRISDbits.TRISD8
#define _TRISD9 TRISDbits.TRISD9

/* PORTD */
#define _RD8 PORTDbits.RD8
#define _RD9 PORTDbits.RD9

/* LATD */
#define _LATD8 LATDbits.LATD8
#define _LATD9 LATDbits.LATD9

/* TRISF */
#define _TRISF2 TRISFbits.TRISF2
#define _TRISF3 TRISFbits.TRISF3
#define _TRISF4 TRISFbits.TRISF4
#define _TRISF5 TRISFbits.TRISF5
#define _TRISF6 TRISFbits.TRISF6

/* PORTF */
#define _RF2 PORTFbits.RF2
#define _RF3 PORTFbits.RF3
#define _RF4 PORTFbits.RF4
#define _RF5 PORTFbits.RF5
#define _RF6 PORTFbits.RF6

/* LATF */
#define _LATF2 LATFbits.LATF2
#define _LATF3 LATFbits.LATF3
#define _LATF4 LATFbits.LATF4
#define _LATF5 LATFbits.LATF5
#define _LATF6 LATFbits.LATF6

/* RCON */
#define _POR RCONbits.POR
#define _BOR RCONbits.BOR
#define _IDLE RCONbits.IDLE
#define _SLEEP RCONbits.SLEEP
#define _WDTO RCONbits.WDTO
#define _SWDTEN RCONbits.SWDTEN
#define _SWR RCONbits.SWR
#define _EXTR RCONbits.EXTR
#define _LVDL RCONbits.LVDL
#define _LVDEN RCONbits.LVDEN
#define _BGST RCONbits.BGST
#define _IOPUWR RCONbits.IOPUWR
#define _TRAPR RCONbits.TRAPR
#define _LVDL0 RCONbits.LVDL0
#define _LVDL1 RCONbits.LVDL1
#define _LVDL2 RCONbits.LVDL2
#define _LVDL3 RCONbits.LVDL3

/* OSCCON */
#define _OSWEN OSCCONbits.OSWEN
#define _LPOSCEN OSCCONbits.LPOSCEN
#define _CF OSCCONbits.CF
#define _LOCK OSCCONbits.LOCK
#define _POST OSCCONbits.POST
#define _NOSC OSCCONbits.NOSC
#define _COSC OSCCONbits.COSC
#define _POST0 OSCCONbits.POST0
#define _POST1 OSCCONbits.POST1
#define _NOSC0 OSCCONbits.NOSC0
#define _NOSC1 OSCCONbits.NOSC1
#define _NOSC2 OSCCONbits.NOSC2
#define _COSC0 OSCCONbits.COSC0
#define _COSC1 OSCCONbits.COSC1
#define _COSC2 OSCCONbits.COSC2

/* OSCTUN */
#define _TUN0 OSCTUNbits.TUN0
#define _TUN1 OSCTUNbits.TUN1
#define _TUN2 OSCTUNbits.TUN2
#define _TUN3 OSCTUNbits.TUN3

/* NVMCON */
#define _PROGOP NVMCONbits.PROGOP
#define _TWRI NVMCONbits.TWRI
#define _WRERR NVMCONbits.WRERR
#define _WREN NVMCONbits.WREN
#define _WR NVMCONbits.WR
#define _PROGOP0 NVMCONbits.PROGOP0
#define _PROGOP1 NVMCONbits.PROGOP1
#define _PROGOP2 NVMCONbits.PROGOP2
#define _PROGOP3 NVMCONbits.PROGOP3
#define _PROGOP4 NVMCONbits.PROGOP4
#define _PROGOP5 NVMCONbits.PROGOP5
#define _PROGOP6 NVMCONbits.PROGOP6

/* NVMADRU */
#define _NVMADR NVMADRUbits.NVMADR

/* PMD1 */
#define _ADCMD PMD1bits.ADCMD
#define _SPI1MD PMD1bits.SPI1MD
#define _U1MD PMD1bits.U1MD
#define _U2MD PMD1bits.U2MD
#define _I2CMD PMD1bits.I2CMD
#define _T1MD PMD1bits.T1MD
#define _T2MD PMD1bits.T2MD
#define _T3MD PMD1bits.T3MD

/* PMD2 */
#define _OC1MD PMD2bits.OC1MD
#define _OC2MD PMD2bits.OC2MD
#define _IC1MD PMD2bits.IC1MD
#define _IC2MD PMD2bits.IC2MD


/*----------------------------------------------------------- */
/* Some useful macros for allocating data memory              */
/*----------------------------------------------------------- */

/* The following macros require an argument N that specifies  */
/* alignment. N must a power of two, minimum value = 2.       */
/* For example, to declare an uninitialized array in X memory */
/* that is aligned to a 32 byte address:                      */
/*                                                            */
/* int _XBSS(32) xbuf[16];                                    */
/*                                                            */
#define _XBSS(N)    __attribute__((space(xmemory),aligned(N)))
#define _XDATA(N)   __attribute__((space(xmemory),aligned(N)))
#define _YBSS(N)    __attribute__((space(ymemory),aligned(N)))
#define _YDATA(N)   __attribute__((space(ymemory),aligned(N)))
/*                                                            */
/* To declare an initialized array in data EEPROM without     */
/* special alignment:                                         */
/*                                                            */
/* int _EEDATA(2) table1[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};   */
/*                                                            */
#define _EEDATA(N)   __attribute__((space(eedata),aligned(N)))

/* The following macros do not require an argument. They can  */
/* be used to locate a variable in persistent data memory or  */
/* in near data memory. For example, to declare two variables */
/* that retain their values across a device reset:            */
/*                                                            */
/* int _PERSISTENT var1,var2;                                 */
/*                                                            */
#define _PERSISTENT __attribute__((persistent))
#define _NEAR       __attribute__((near))

/* ---------------------------------------------------------- */
/* Some useful macros for declaring functions                 */
/* ---------------------------------------------------------- */

/* The following macros can be used to declare interrupt      */
/* service routines (ISRs). For example, to declare an ISR    */
/* for the timer1 interrupt:                                  */
/*                                                            */
/* void _ISR _T1Interrupt(void);                              */
/*                                                            */
/* To declare an ISR for the SPI1 interrupt with fast         */
/* context save:                                              */
/*                                                            */
/* void _ISRFAST _SPI1Interrupt(void);                        */
/*                                                            */
/* Note: ISRs will be installed into the interrupt vector     */
/* tables automatically if the reserved names listed in the   */
/* MPLAB C30 Compiler User's Guide (DS51284) are used.        */
/*                                                            */
#define _ISR __attribute__((interrupt))
#define _ISRFAST __attribute__((interrupt, shadow))

/* ---------------------------------------------------------- */
/* Some useful macros for changing the CPU IPL                */
/* ---------------------------------------------------------- */

/* The following macros can be used to modify the current CPU */
/* IPL. The definition of the macro may vary from device to   */
/* device.                                                    */
/*                                                            */
/* To safely set the CPU IPL, use SET_CPU_IPL(ipl); the       */
/* valid range of ipl is 0-7, it may be any expression.       */
/*                                                            */
/* SET_CPU_IPL(7);                                            */
/*                                                            */
/* To preserve the current IPL and save it use                */
/* SET_AND_SAVE_CPU_IPL(save_to, ipl); the valid range of ipl */
/* is 0-7 and may be any expression, save_to should denote    */
/* some temporary storage.                                    */
/*                                                            */
/* uint16_t old_ipl;                                      */
/*                                                            */
/* SET_AND_SAVE_CPU_IPL(old_ipl, 7);                          */
/*                                                            */
/* The IPL can be restored with RESTORE_CPU_IPL(saved_to)     */
/*                                                            */
/* RESTORE_CPU_IPL(old_ipl);                                  */

#define SET_CPU_IPL(ipl) {       \
  uint16_t DISI_save;        \
                                 \
  DISI_save = DISICNT;           \
  asm volatile ("disi #0x3FFF"); \
  SRbits.IPL = ipl;              \
  DISICNT = DISI_save;           \
} (void) 0

#define SET_AND_SAVE_CPU_IPL(save_to, ipl) { \
  save_to = SRbits.IPL; \
  SET_CPU_IPL(ipl); } (void) 0;

#define RESTORE_CPU_IPL(saved_to) SET_CPU_IPL(saved_to)

#define _SR_C_POSITION                           0x00000000
#define _SR_C_MASK                               0x00000001
#define _SR_C_LENGTH                             0x00000001

#define _SR_Z_POSITION                           0x00000001
#define _SR_Z_MASK                               0x00000002
#define _SR_Z_LENGTH                             0x00000001

#define _SR_OV_POSITION                          0x00000002
#define _SR_OV_MASK                              0x00000004
#define _SR_OV_LENGTH                            0x00000001

#define _SR_N_POSITION                           0x00000003
#define _SR_N_MASK                               0x00000008
#define _SR_N_LENGTH                             0x00000001

#define _SR_RA_POSITION                          0x00000004
#define _SR_RA_MASK                              0x00000010
#define _SR_RA_LENGTH                            0x00000001

#define _SR_IPL_POSITION                         0x00000005
#define _SR_IPL_MASK                             0x000000E0
#define _SR_IPL_LENGTH                           0x00000003

#define _SR_DC_POSITION                          0x00000008
#define _SR_DC_MASK                              0x00000100
#define _SR_DC_LENGTH                            0x00000001

#define _SR_DA_POSITION                          0x00000009
#define _SR_DA_MASK                              0x00000200
#define _SR_DA_LENGTH                            0x00000001

#define _SR_SAB_POSITION                         0x0000000A
#define _SR_SAB_MASK                             0x00000400
#define _SR_SAB_LENGTH                           0x00000001

#define _SR_OAB_POSITION                         0x0000000B
#define _SR_OAB_MASK                             0x00000800
#define _SR_OAB_LENGTH                           0x00000001

#define _SR_SB_POSITION                          0x0000000C
#define _SR_SB_MASK                              0x00001000
#define _SR_SB_LENGTH                            0x00000001

#define _SR_SA_POSITION                          0x0000000D
#define _SR_SA_MASK                              0x00002000
#define _SR_SA_LENGTH                            0x00000001

#define _SR_OB_POSITION                          0x0000000E
#define _SR_OB_MASK                              0x00004000
#define _SR_OB_LENGTH                            0x00000001

#define _SR_OA_POSITION                          0x0000000F
#define _SR_OA_MASK                              0x00008000
#define _SR_OA_LENGTH                            0x00000001

#define _SR_IPL0_POSITION                        0x00000005
#define _SR_IPL0_MASK                            0x00000020
#define _SR_IPL0_LENGTH                          0x00000001

#define _SR_IPL1_POSITION                        0x00000006
#define _SR_IPL1_MASK                            0x00000040
#define _SR_IPL1_LENGTH                          0x00000001

#define _SR_IPL2_POSITION                        0x00000007
#define _SR_IPL2_MASK                            0x00000080
#define _SR_IPL2_LENGTH                          0x00000001

#define _CORCON_IF_POSITION                      0x00000000
#define _CORCON_IF_MASK                          0x00000001
#define _CORCON_IF_LENGTH                        0x00000001

#define _CORCON_RND_POSITION                     0x00000001
#define _CORCON_RND_MASK                         0x00000002
#define _CORCON_RND_LENGTH                       0x00000001

#define _CORCON_PSV_POSITION                     0x00000002
#define _CORCON_PSV_MASK                         0x00000004
#define _CORCON_PSV_LENGTH                       0x00000001

#define _CORCON_IPL3_POSITION                    0x00000003
#define _CORCON_IPL3_MASK                        0x00000008
#define _CORCON_IPL3_LENGTH                      0x00000001

#define _CORCON_ACCSAT_POSITION                  0x00000004
#define _CORCON_ACCSAT_MASK                      0x00000010
#define _CORCON_ACCSAT_LENGTH                    0x00000001

#define _CORCON_SATDW_POSITION                   0x00000005
#define _CORCON_SATDW_MASK                       0x00000020
#define _CORCON_SATDW_LENGTH                     0x00000001

#define _CORCON_SATB_POSITION                    0x00000006
#define _CORCON_SATB_MASK                        0x00000040
#define _CORCON_SATB_LENGTH                      0x00000001

#define _CORCON_SATA_POSITION                    0x00000007
#define _CORCON_SATA_MASK                        0x00000080
#define _CORCON_SATA_LENGTH                      0x00000001

#define _CORCON_DL_POSITION                      0x00000008
#define _CORCON_DL_MASK                          0x00000700
#define _CORCON_DL_LENGTH                        0x00000003

#define _CORCON_EDT_POSITION                     0x0000000B
#define _CORCON_EDT_MASK                         0x00000800
#define _CORCON_EDT_LENGTH                       0x00000001

#define _CORCON_US_POSITION                      0x0000000C
#define _CORCON_US_MASK                          0x00001000
#define _CORCON_US_LENGTH                        0x00000001

#define _CORCON_DL0_POSITION                     0x00000008
#define _CORCON_DL0_MASK                         0x00000100
#define _CORCON_DL0_LENGTH                       0x00000001

#define _CORCON_DL1_POSITION                     0x00000009
#define _CORCON_DL1_MASK                         0x00000200
#define _CORCON_DL1_LENGTH                       0x00000001

#define _CORCON_DL2_POSITION                     0x0000000A
#define _CORCON_DL2_MASK                         0x00000400
#define _CORCON_DL2_LENGTH                       0x00000001

#define _MODCON_XWM_POSITION                     0x00000000
#define _MODCON_XWM_MASK                         0x0000000F
#define _MODCON_XWM_LENGTH                       0x00000004

#define _MODCON_YWM_POSITION                     0x00000004
#define _MODCON_YWM_MASK                         0x000000F0
#define _MODCON_YWM_LENGTH                       0x00000004

#define _MODCON_BWM_POSITION                     0x00000008
#define _MODCON_BWM_MASK                         0x00000F00
#define _MODCON_BWM_LENGTH                       0x00000004

#define _MODCON_YMODEN_POSITION                  0x0000000E
#define _MODCON_YMODEN_MASK                      0x00004000
#define _MODCON_YMODEN_LENGTH                    0x00000001

#define _MODCON_XMODEN_POSITION                  0x0000000F
#define _MODCON_XMODEN_MASK                      0x00008000
#define _MODCON_XMODEN_LENGTH                    0x00000001

#define _MODCON_XWM0_POSITION                    0x00000000
#define _MODCON_XWM0_MASK                        0x00000001
#define _MODCON_XWM0_LENGTH                      0x00000001

#define _MODCON_XWM1_POSITION                    0x00000001
#define _MODCON_XWM1_MASK                        0x00000002
#define _MODCON_XWM1_LENGTH                      0x00000001

#define _MODCON_XWM2_POSITION                    0x00000002
#define _MODCON_XWM2_MASK                        0x00000004
#define _MODCON_XWM2_LENGTH                      0x00000001

#define _MODCON_XWM3_POSITION                    0x00000003
#define _MODCON_XWM3_MASK                        0x00000008
#define _MODCON_XWM3_LENGTH                      0x00000001

#define _MODCON_YWM0_POSITION                    0x00000004
#define _MODCON_YWM0_MASK                        0x00000010
#define _MODCON_YWM0_LENGTH                      0x00000001

#define _MODCON_YWM1_POSITION                    0x00000005
#define _MODCON_YWM1_MASK                        0x00000020
#define _MODCON_YWM1_LENGTH                      0x00000001

#define _MODCON_YWM2_POSITION                    0x00000006
#define _MODCON_YWM2_MASK                        0x00000040
#define _MODCON_YWM2_LENGTH                      0x00000001

#define _MODCON_YWM3_POSITION                    0x00000007
#define _MODCON_YWM3_MASK                        0x00000080
#define _MODCON_YWM3_LENGTH                      0x00000001

#define _MODCON_BWM0_POSITION                    0x00000008
#define _MODCON_BWM0_MASK                        0x00000100
#define _MODCON_BWM0_LENGTH                      0x00000001

#define _MODCON_BWM1_POSITION                    0x00000009
#define _MODCON_BWM1_MASK                        0x00000200
#define _MODCON_BWM1_LENGTH                      0x00000001

#define _MODCON_BWM2_POSITION                    0x0000000A
#define _MODCON_BWM2_MASK                        0x00000400
#define _MODCON_BWM2_LENGTH                      0x00000001

#define _MODCON_BWM3_POSITION                    0x0000000B
#define _MODCON_BWM3_MASK                        0x00000800
#define _MODCON_BWM3_LENGTH                      0x00000001

#define _XBREV_XB_POSITION                       0x00000000
#define _XBREV_XB_MASK                           0x00007FFF
#define _XBREV_XB_LENGTH                         0x0000000F

#define _XBREV_BREN_POSITION                     0x0000000F
#define _XBREV_BREN_MASK                         0x00008000
#define _XBREV_BREN_LENGTH                       0x00000001

#define _XBREV_XB0_POSITION                      0x00000000
#define _XBREV_XB0_MASK                          0x00000001
#define _XBREV_XB0_LENGTH                        0x00000001

#define _XBREV_XB1_POSITION                      0x00000001
#define _XBREV_XB1_MASK                          0x00000002
#define _XBREV_XB1_LENGTH                        0x00000001

#define _XBREV_XB2_POSITION                      0x00000002
#define _XBREV_XB2_MASK                          0x00000004
#define _XBREV_XB2_LENGTH                        0x00000001

#define _XBREV_XB3_POSITION                      0x00000003
#define _XBREV_XB3_MASK                          0x00000008
#define _XBREV_XB3_LENGTH                        0x00000001

#define _XBREV_XB4_POSITION                      0x00000004
#define _XBREV_XB4_MASK                          0x00000010
#define _XBREV_XB4_LENGTH                        0x00000001

#define _XBREV_XB5_POSITION                      0x00000005
#define _XBREV_XB5_MASK                          0x00000020
#define _XBREV_XB5_LENGTH                        0x00000001

#define _XBREV_XB6_POSITION                      0x00000006
#define _XBREV_XB6_MASK                          0x00000040
#define _XBREV_XB6_LENGTH                        0x00000001

#define _XBREV_XB7_POSITION                      0x00000007
#define _XBREV_XB7_MASK                          0x00000080
#define _XBREV_XB7_LENGTH                        0x00000001

#define _XBREV_XB8_POSITION                      0x00000008
#define _XBREV_XB8_MASK                          0x00000100
#define _XBREV_XB8_LENGTH                        0x00000001

#define _XBREV_XB9_POSITION                      0x00000009
#define _XBREV_XB9_MASK                          0x00000200
#define _XBREV_XB9_LENGTH                        0x00000001

#define _XBREV_XB10_POSITION                     0x0000000A
#define _XBREV_XB10_MASK                         0x00000400
#define _XBREV_XB10_LENGTH                       0x00000001

#define _XBREV_XB11_POSITION                     0x0000000B
#define _XBREV_XB11_MASK                         0x00000800
#define _XBREV_XB11_LENGTH                       0x00000001

#define _XBREV_XB12_POSITION                     0x0000000C
#define _XBREV_XB12_MASK                         0x00001000
#define _XBREV_XB12_LENGTH                       0x00000001

#define _XBREV_XB13_POSITION                     0x0000000D
#define _XBREV_XB13_MASK                         0x00002000
#define _XBREV_XB13_LENGTH                       0x00000001

#define _XBREV_XB14_POSITION                     0x0000000E
#define _XBREV_XB14_MASK                         0x00004000
#define _XBREV_XB14_LENGTH                       0x00000001

#define _DISICNT_DISICNT_POSITION                0x00000000
#define _DISICNT_DISICNT_MASK                    0x00003FFF
#define _DISICNT_DISICNT_LENGTH                  0x0000000E

#define _INTCON1_OSCFAIL_POSITION                0x00000001
#define _INTCON1_OSCFAIL_MASK                    0x00000002
#define _INTCON1_OSCFAIL_LENGTH                  0x00000001

#define _INTCON1_STKERR_POSITION                 0x00000002
#define _INTCON1_STKERR_MASK                     0x00000004
#define _INTCON1_STKERR_LENGTH                   0x00000001

#define _INTCON1_ADDRERR_POSITION                0x00000003
#define _INTCON1_ADDRERR_MASK                    0x00000008
#define _INTCON1_ADDRERR_LENGTH                  0x00000001

#define _INTCON1_MATHERR_POSITION                0x00000004
#define _INTCON1_MATHERR_MASK                    0x00000010
#define _INTCON1_MATHERR_LENGTH                  0x00000001

#define _INTCON1_COVTE_POSITION                  0x00000008
#define _INTCON1_COVTE_MASK                      0x00000100
#define _INTCON1_COVTE_LENGTH                    0x00000001

#define _INTCON1_OVBTE_POSITION                  0x00000009
#define _INTCON1_OVBTE_MASK                      0x00000200
#define _INTCON1_OVBTE_LENGTH                    0x00000001

#define _INTCON1_OVATE_POSITION                  0x0000000A
#define _INTCON1_OVATE_MASK                      0x00000400
#define _INTCON1_OVATE_LENGTH                    0x00000001

#define _INTCON1_NSTDIS_POSITION                 0x0000000F
#define _INTCON1_NSTDIS_MASK                     0x00008000
#define _INTCON1_NSTDIS_LENGTH                   0x00000001

#define _INTCON2_INT0EP_POSITION                 0x00000000
#define _INTCON2_INT0EP_MASK                     0x00000001
#define _INTCON2_INT0EP_LENGTH                   0x00000001

#define _INTCON2_INT1EP_POSITION                 0x00000001
#define _INTCON2_INT1EP_MASK                     0x00000002
#define _INTCON2_INT1EP_LENGTH                   0x00000001

#define _INTCON2_INT2EP_POSITION                 0x00000002
#define _INTCON2_INT2EP_MASK                     0x00000004
#define _INTCON2_INT2EP_LENGTH                   0x00000001

#define _INTCON2_DISI_POSITION                   0x0000000E
#define _INTCON2_DISI_MASK                       0x00004000
#define _INTCON2_DISI_LENGTH                     0x00000001

#define _INTCON2_ALTIVT_POSITION                 0x0000000F
#define _INTCON2_ALTIVT_MASK                     0x00008000
#define _INTCON2_ALTIVT_LENGTH                   0x00000001

#define _IFS0_INT0IF_POSITION                    0x00000000
#define _IFS0_INT0IF_MASK                        0x00000001
#define _IFS0_INT0IF_LENGTH                      0x00000001

#define _IFS0_IC1IF_POSITION                     0x00000001
#define _IFS0_IC1IF_MASK                         0x00000002
#define _IFS0_IC1IF_LENGTH                       0x00000001

#define _IFS0_OC1IF_POSITION                     0x00000002
#define _IFS0_OC1IF_MASK                         0x00000004
#define _IFS0_OC1IF_LENGTH                       0x00000001

#define _IFS0_T1IF_POSITION                      0x00000003
#define _IFS0_T1IF_MASK                          0x00000008
#define _IFS0_T1IF_LENGTH                        0x00000001

#define _IFS0_IC2IF_POSITION                     0x00000004
#define _IFS0_IC2IF_MASK                         0x00000010
#define _IFS0_IC2IF_LENGTH                       0x00000001

#define _IFS0_OC2IF_POSITION                     0x00000005
#define _IFS0_OC2IF_MASK                         0x00000020
#define _IFS0_OC2IF_LENGTH                       0x00000001

#define _IFS0_T2IF_POSITION                      0x00000006
#define _IFS0_T2IF_MASK                          0x00000040
#define _IFS0_T2IF_LENGTH                        0x00000001

#define _IFS0_T3IF_POSITION                      0x00000007
#define _IFS0_T3IF_MASK                          0x00000080
#define _IFS0_T3IF_LENGTH                        0x00000001

#define _IFS0_SPI1IF_POSITION                    0x00000008
#define _IFS0_SPI1IF_MASK                        0x00000100
#define _IFS0_SPI1IF_LENGTH                      0x00000001

#define _IFS0_U1RXIF_POSITION                    0x00000009
#define _IFS0_U1RXIF_MASK                        0x00000200
#define _IFS0_U1RXIF_LENGTH                      0x00000001

#define _IFS0_U1TXIF_POSITION                    0x0000000A
#define _IFS0_U1TXIF_MASK                        0x00000400
#define _IFS0_U1TXIF_LENGTH                      0x00000001

#define _IFS0_ADIF_POSITION                      0x0000000B
#define _IFS0_ADIF_MASK                          0x00000800
#define _IFS0_ADIF_LENGTH                        0x00000001

#define _IFS0_NVMIF_POSITION                     0x0000000C
#define _IFS0_NVMIF_MASK                         0x00001000
#define _IFS0_NVMIF_LENGTH                       0x00000001

#define _IFS0_SI2CIF_POSITION                    0x0000000D
#define _IFS0_SI2CIF_MASK                        0x00002000
#define _IFS0_SI2CIF_LENGTH                      0x00000001

#define _IFS0_MI2CIF_POSITION                    0x0000000E
#define _IFS0_MI2CIF_MASK                        0x00004000
#define _IFS0_MI2CIF_LENGTH                      0x00000001

#define _IFS0_CNIF_POSITION                      0x0000000F
#define _IFS0_CNIF_MASK                          0x00008000
#define _IFS0_CNIF_LENGTH                        0x00000001

#define _IFS1_INT1IF_POSITION                    0x00000000
#define _IFS1_INT1IF_MASK                        0x00000001
#define _IFS1_INT1IF_LENGTH                      0x00000001

#define _IFS1_INT2IF_POSITION                    0x00000007
#define _IFS1_INT2IF_MASK                        0x00000080
#define _IFS1_INT2IF_LENGTH                      0x00000001

#define _IFS1_U2RXIF_POSITION                    0x00000008
#define _IFS1_U2RXIF_MASK                        0x00000100
#define _IFS1_U2RXIF_LENGTH                      0x00000001

#define _IFS1_U2TXIF_POSITION                    0x00000009
#define _IFS1_U2TXIF_MASK                        0x00000200
#define _IFS1_U2TXIF_LENGTH                      0x00000001

#define _IFS2_LVDIF_POSITION                     0x0000000A
#define _IFS2_LVDIF_MASK                         0x00000400
#define _IFS2_LVDIF_LENGTH                       0x00000001

#define _IEC0_INT0IE_POSITION                    0x00000000
#define _IEC0_INT0IE_MASK                        0x00000001
#define _IEC0_INT0IE_LENGTH                      0x00000001

#define _IEC0_IC1IE_POSITION                     0x00000001
#define _IEC0_IC1IE_MASK                         0x00000002
#define _IEC0_IC1IE_LENGTH                       0x00000001

#define _IEC0_OC1IE_POSITION                     0x00000002
#define _IEC0_OC1IE_MASK                         0x00000004
#define _IEC0_OC1IE_LENGTH                       0x00000001

#define _IEC0_T1IE_POSITION                      0x00000003
#define _IEC0_T1IE_MASK                          0x00000008
#define _IEC0_T1IE_LENGTH                        0x00000001

#define _IEC0_IC2IE_POSITION                     0x00000004
#define _IEC0_IC2IE_MASK                         0x00000010
#define _IEC0_IC2IE_LENGTH                       0x00000001

#define _IEC0_OC2IE_POSITION                     0x00000005
#define _IEC0_OC2IE_MASK                         0x00000020
#define _IEC0_OC2IE_LENGTH                       0x00000001

#define _IEC0_T2IE_POSITION                      0x00000006
#define _IEC0_T2IE_MASK                          0x00000040
#define _IEC0_T2IE_LENGTH                        0x00000001

#define _IEC0_T3IE_POSITION                      0x00000007
#define _IEC0_T3IE_MASK                          0x00000080
#define _IEC0_T3IE_LENGTH                        0x00000001

#define _IEC0_SPI1IE_POSITION                    0x00000008
#define _IEC0_SPI1IE_MASK                        0x00000100
#define _IEC0_SPI1IE_LENGTH                      0x00000001

#define _IEC0_U1RXIE_POSITION                    0x00000009
#define _IEC0_U1RXIE_MASK                        0x00000200
#define _IEC0_U1RXIE_LENGTH                      0x00000001

#define _IEC0_U1TXIE_POSITION                    0x0000000A
#define _IEC0_U1TXIE_MASK                        0x00000400
#define _IEC0_U1TXIE_LENGTH                      0x00000001

#define _IEC0_ADIE_POSITION                      0x0000000B
#define _IEC0_ADIE_MASK                          0x00000800
#define _IEC0_ADIE_LENGTH                        0x00000001

#define _IEC0_NVMIE_POSITION                     0x0000000C
#define _IEC0_NVMIE_MASK                         0x00001000
#define _IEC0_NVMIE_LENGTH                       0x00000001

#define _IEC0_SI2CIE_POSITION                    0x0000000D
#define _IEC0_SI2CIE_MASK                        0x00002000
#define _IEC0_SI2CIE_LENGTH                      0x00000001

#define _IEC0_MI2CIE_POSITION                    0x0000000E
#define _IEC0_MI2CIE_MASK                        0x00004000
#define _IEC0_MI2CIE_LENGTH                      0x00000001

#define _IEC0_CNIE_POSITION                      0x0000000F
#define _IEC0_CNIE_MASK                          0x00008000
#define _IEC0_CNIE_LENGTH                        0x00000001

#define _IEC1_INT1IE_POSITION                    0x00000000
#define _IEC1_INT1IE_MASK                        0x00000001
#define _IEC1_INT1IE_LENGTH                      0x00000001

#define _IEC1_INT2IE_POSITION                    0x00000007
#define _IEC1_INT2IE_MASK                        0x00000080
#define _IEC1_INT2IE_LENGTH                      0x00000001

#define _IEC1_U2RXIE_POSITION                    0x00000008
#define _IEC1_U2RXIE_MASK                        0x00000100
#define _IEC1_U2RXIE_LENGTH                      0x00000001

#define _IEC1_U2TXIE_POSITION                    0x00000009
#define _IEC1_U2TXIE_MASK                        0x00000200
#define _IEC1_U2TXIE_LENGTH                      0x00000001

#define _IEC2_LVDIE_POSITION                     0x0000000A
#define _IEC2_LVDIE_MASK                         0x00000400
#define _IEC2_LVDIE_LENGTH                       0x00000001

#define _IPC0_INT0IP_POSITION                    0x00000000
#define _IPC0_INT0IP_MASK                        0x00000007
#define _IPC0_INT0IP_LENGTH                      0x00000003

#define _IPC0_IC1IP_POSITION                     0x00000004
#define _IPC0_IC1IP_MASK                         0x00000070
#define _IPC0_IC1IP_LENGTH                       0x00000003

#define _IPC0_OC1IP_POSITION                     0x00000008
#define _IPC0_OC1IP_MASK                         0x00000700
#define _IPC0_OC1IP_LENGTH                       0x00000003

#define _IPC0_T1IP_POSITION                      0x0000000C
#define _IPC0_T1IP_MASK                          0x00007000
#define _IPC0_T1IP_LENGTH                        0x00000003

#define _IPC0_INT0IP0_POSITION                   0x00000000
#define _IPC0_INT0IP0_MASK                       0x00000001
#define _IPC0_INT0IP0_LENGTH                     0x00000001

#define _IPC0_INT0IP1_POSITION                   0x00000001
#define _IPC0_INT0IP1_MASK                       0x00000002
#define _IPC0_INT0IP1_LENGTH                     0x00000001

#define _IPC0_INT0IP2_POSITION                   0x00000002
#define _IPC0_INT0IP2_MASK                       0x00000004
#define _IPC0_INT0IP2_LENGTH                     0x00000001

#define _IPC0_IC1IP0_POSITION                    0x00000004
#define _IPC0_IC1IP0_MASK                        0x00000010
#define _IPC0_IC1IP0_LENGTH                      0x00000001

#define _IPC0_IC1IP1_POSITION                    0x00000005
#define _IPC0_IC1IP1_MASK                        0x00000020
#define _IPC0_IC1IP1_LENGTH                      0x00000001

#define _IPC0_IC1IP2_POSITION                    0x00000006
#define _IPC0_IC1IP2_MASK                        0x00000040
#define _IPC0_IC1IP2_LENGTH                      0x00000001

#define _IPC0_OC1IP0_POSITION                    0x00000008
#define _IPC0_OC1IP0_MASK                        0x00000100
#define _IPC0_OC1IP0_LENGTH                      0x00000001

#define _IPC0_OC1IP1_POSITION                    0x00000009
#define _IPC0_OC1IP1_MASK                        0x00000200
#define _IPC0_OC1IP1_LENGTH                      0x00000001

#define _IPC0_OC1IP2_POSITION                    0x0000000A
#define _IPC0_OC1IP2_MASK                        0x00000400
#define _IPC0_OC1IP2_LENGTH                      0x00000001

#define _IPC0_T1IP0_POSITION                     0x0000000C
#define _IPC0_T1IP0_MASK                         0x00001000
#define _IPC0_T1IP0_LENGTH                       0x00000001

#define _IPC0_T1IP1_POSITION                     0x0000000D
#define _IPC0_T1IP1_MASK                         0x00002000
#define _IPC0_T1IP1_LENGTH                       0x00000001

#define _IPC0_T1IP2_POSITION                     0x0000000E
#define _IPC0_T1IP2_MASK                         0x00004000
#define _IPC0_T1IP2_LENGTH                       0x00000001

#define _IPC1_IC2IP_POSITION                     0x00000000
#define _IPC1_IC2IP_MASK                         0x00000007
#define _IPC1_IC2IP_LENGTH                       0x00000003

#define _IPC1_OC2IP_POSITION                     0x00000004
#define _IPC1_OC2IP_MASK                         0x00000070
#define _IPC1_OC2IP_LENGTH                       0x00000003

#define _IPC1_T2IP_POSITION                      0x00000008
#define _IPC1_T2IP_MASK                          0x00000700
#define _IPC1_T2IP_LENGTH                        0x00000003

#define _IPC1_T3IP_POSITION                      0x0000000C
#define _IPC1_T3IP_MASK                          0x00007000
#define _IPC1_T3IP_LENGTH                        0x00000003

#define _IPC1_IC2IP0_POSITION                    0x00000000
#define _IPC1_IC2IP0_MASK                        0x00000001
#define _IPC1_IC2IP0_LENGTH                      0x00000001

#define _IPC1_IC2IP1_POSITION                    0x00000001
#define _IPC1_IC2IP1_MASK                        0x00000002
#define _IPC1_IC2IP1_LENGTH                      0x00000001

#define _IPC1_IC2IP2_POSITION                    0x00000002
#define _IPC1_IC2IP2_MASK                        0x00000004
#define _IPC1_IC2IP2_LENGTH                      0x00000001

#define _IPC1_OC2IP0_POSITION                    0x00000004
#define _IPC1_OC2IP0_MASK                        0x00000010
#define _IPC1_OC2IP0_LENGTH                      0x00000001

#define _IPC1_OC2IP1_POSITION                    0x00000005
#define _IPC1_OC2IP1_MASK                        0x00000020
#define _IPC1_OC2IP1_LENGTH                      0x00000001

#define _IPC1_OC2IP2_POSITION                    0x00000006
#define _IPC1_OC2IP2_MASK                        0x00000040
#define _IPC1_OC2IP2_LENGTH                      0x00000001

#define _IPC1_T2IP0_POSITION                     0x00000008
#define _IPC1_T2IP0_MASK                         0x00000100
#define _IPC1_T2IP0_LENGTH                       0x00000001

#define _IPC1_T2IP1_POSITION                     0x00000009
#define _IPC1_T2IP1_MASK                         0x00000200
#define _IPC1_T2IP1_LENGTH                       0x00000001

#define _IPC1_T2IP2_POSITION                     0x0000000A
#define _IPC1_T2IP2_MASK                         0x00000400
#define _IPC1_T2IP2_LENGTH                       0x00000001

#define _IPC1_T3IP0_POSITION                     0x0000000C
#define _IPC1_T3IP0_MASK                         0x00001000
#define _IPC1_T3IP0_LENGTH                       0x00000001

#define _IPC1_T3IP1_POSITION                     0x0000000D
#define _IPC1_T3IP1_MASK                         0x00002000
#define _IPC1_T3IP1_LENGTH                       0x00000001

#define _IPC1_T3IP2_POSITION                     0x0000000E
#define _IPC1_T3IP2_MASK                         0x00004000
#define _IPC1_T3IP2_LENGTH                       0x00000001

#define _IPC2_SPI1IP_POSITION                    0x00000000
#define _IPC2_SPI1IP_MASK                        0x00000007
#define _IPC2_SPI1IP_LENGTH                      0x00000003

#define _IPC2_U1RXIP_POSITION                    0x00000004
#define _IPC2_U1RXIP_MASK                        0x00000070
#define _IPC2_U1RXIP_LENGTH                      0x00000003

#define _IPC2_U1TXIP_POSITION                    0x00000008
#define _IPC2_U1TXIP_MASK                        0x00000700
#define _IPC2_U1TXIP_LENGTH                      0x00000003

#define _IPC2_ADIP_POSITION                      0x0000000C
#define _IPC2_ADIP_MASK                          0x00007000
#define _IPC2_ADIP_LENGTH                        0x00000003

#define _IPC2_SPI1IP0_POSITION                   0x00000000
#define _IPC2_SPI1IP0_MASK                       0x00000001
#define _IPC2_SPI1IP0_LENGTH                     0x00000001

#define _IPC2_SPI1IP1_POSITION                   0x00000001
#define _IPC2_SPI1IP1_MASK                       0x00000002
#define _IPC2_SPI1IP1_LENGTH                     0x00000001

#define _IPC2_SPI1IP2_POSITION                   0x00000002
#define _IPC2_SPI1IP2_MASK                       0x00000004
#define _IPC2_SPI1IP2_LENGTH                     0x00000001

#define _IPC2_U1RXIP0_POSITION                   0x00000004
#define _IPC2_U1RXIP0_MASK                       0x00000010
#define _IPC2_U1RXIP0_LENGTH                     0x00000001

#define _IPC2_U1RXIP1_POSITION                   0x00000005
#define _IPC2_U1RXIP1_MASK                       0x00000020
#define _IPC2_U1RXIP1_LENGTH                     0x00000001

#define _IPC2_U1RXIP2_POSITION                   0x00000006
#define _IPC2_U1RXIP2_MASK                       0x00000040
#define _IPC2_U1RXIP2_LENGTH                     0x00000001

#define _IPC2_U1TXIP0_POSITION                   0x00000008
#define _IPC2_U1TXIP0_MASK                       0x00000100
#define _IPC2_U1TXIP0_LENGTH                     0x00000001

#define _IPC2_U1TXIP1_POSITION                   0x00000009
#define _IPC2_U1TXIP1_MASK                       0x00000200
#define _IPC2_U1TXIP1_LENGTH                     0x00000001

#define _IPC2_U1TXIP2_POSITION                   0x0000000A
#define _IPC2_U1TXIP2_MASK                       0x00000400
#define _IPC2_U1TXIP2_LENGTH                     0x00000001

#define _IPC2_ADIP0_POSITION                     0x0000000C
#define _IPC2_ADIP0_MASK                         0x00001000
#define _IPC2_ADIP0_LENGTH                       0x00000001

#define _IPC2_ADIP1_POSITION                     0x0000000D
#define _IPC2_ADIP1_MASK                         0x00002000
#define _IPC2_ADIP1_LENGTH                       0x00000001

#define _IPC2_ADIP2_POSITION                     0x0000000E
#define _IPC2_ADIP2_MASK                         0x00004000
#define _IPC2_ADIP2_LENGTH                       0x00000001

#define _IPC3_NVMIP_POSITION                     0x00000000
#define _IPC3_NVMIP_MASK                         0x00000007
#define _IPC3_NVMIP_LENGTH                       0x00000003

#define _IPC3_SI2CIP_POSITION                    0x00000004
#define _IPC3_SI2CIP_MASK                        0x00000070
#define _IPC3_SI2CIP_LENGTH                      0x00000003

#define _IPC3_MI2CIP_POSITION                    0x00000008
#define _IPC3_MI2CIP_MASK                        0x00000700
#define _IPC3_MI2CIP_LENGTH                      0x00000003

#define _IPC3_CNIP_POSITION                      0x0000000C
#define _IPC3_CNIP_MASK                          0x00007000
#define _IPC3_CNIP_LENGTH                        0x00000003

#define _IPC3_NVMIP0_POSITION                    0x00000000
#define _IPC3_NVMIP0_MASK                        0x00000001
#define _IPC3_NVMIP0_LENGTH                      0x00000001

#define _IPC3_NVMIP1_POSITION                    0x00000001
#define _IPC3_NVMIP1_MASK                        0x00000002
#define _IPC3_NVMIP1_LENGTH                      0x00000001

#define _IPC3_NVMIP2_POSITION                    0x00000002
#define _IPC3_NVMIP2_MASK                        0x00000004
#define _IPC3_NVMIP2_LENGTH                      0x00000001

#define _IPC3_SI2CIP0_POSITION                   0x00000004
#define _IPC3_SI2CIP0_MASK                       0x00000010
#define _IPC3_SI2CIP0_LENGTH                     0x00000001

#define _IPC3_SI2CIP1_POSITION                   0x00000005
#define _IPC3_SI2CIP1_MASK                       0x00000020
#define _IPC3_SI2CIP1_LENGTH                     0x00000001

#define _IPC3_SI2CIP2_POSITION                   0x00000006
#define _IPC3_SI2CIP2_MASK                       0x00000040
#define _IPC3_SI2CIP2_LENGTH                     0x00000001

#define _IPC3_MI2CIP0_POSITION                   0x00000008
#define _IPC3_MI2CIP0_MASK                       0x00000100
#define _IPC3_MI2CIP0_LENGTH                     0x00000001

#define _IPC3_MI2CIP1_POSITION                   0x00000009
#define _IPC3_MI2CIP1_MASK                       0x00000200
#define _IPC3_MI2CIP1_LENGTH                     0x00000001

#define _IPC3_MI2CIP2_POSITION                   0x0000000A
#define _IPC3_MI2CIP2_MASK                       0x00000400
#define _IPC3_MI2CIP2_LENGTH                     0x00000001

#define _IPC3_CNIP0_POSITION                     0x0000000C
#define _IPC3_CNIP0_MASK                         0x00001000
#define _IPC3_CNIP0_LENGTH                       0x00000001

#define _IPC3_CNIP1_POSITION                     0x0000000D
#define _IPC3_CNIP1_MASK                         0x00002000
#define _IPC3_CNIP1_LENGTH                       0x00000001

#define _IPC3_CNIP2_POSITION                     0x0000000E
#define _IPC3_CNIP2_MASK                         0x00004000
#define _IPC3_CNIP2_LENGTH                       0x00000001

#define _IPC4_INT1IP_POSITION                    0x00000000
#define _IPC4_INT1IP_MASK                        0x00000007
#define _IPC4_INT1IP_LENGTH                      0x00000003

#define _IPC4_INT1IP0_POSITION                   0x00000000
#define _IPC4_INT1IP0_MASK                       0x00000001
#define _IPC4_INT1IP0_LENGTH                     0x00000001

#define _IPC4_INT1IP1_POSITION                   0x00000001
#define _IPC4_INT1IP1_MASK                       0x00000002
#define _IPC4_INT1IP1_LENGTH                     0x00000001

#define _IPC4_INT1IP2_POSITION                   0x00000002
#define _IPC4_INT1IP2_MASK                       0x00000004
#define _IPC4_INT1IP2_LENGTH                     0x00000001

#define _IPC5_INT2IP_POSITION                    0x0000000C
#define _IPC5_INT2IP_MASK                        0x00007000
#define _IPC5_INT2IP_LENGTH                      0x00000003

#define _IPC5_INT2IP0_POSITION                   0x0000000C
#define _IPC5_INT2IP0_MASK                       0x00001000
#define _IPC5_INT2IP0_LENGTH                     0x00000001

#define _IPC5_INT2IP1_POSITION                   0x0000000D
#define _IPC5_INT2IP1_MASK                       0x00002000
#define _IPC5_INT2IP1_LENGTH                     0x00000001

#define _IPC5_INT2IP2_POSITION                   0x0000000E
#define _IPC5_INT2IP2_MASK                       0x00004000
#define _IPC5_INT2IP2_LENGTH                     0x00000001

#define _IPC6_U2RXIP_POSITION                    0x00000000
#define _IPC6_U2RXIP_MASK                        0x00000007
#define _IPC6_U2RXIP_LENGTH                      0x00000003

#define _IPC6_U2TXIP_POSITION                    0x00000004
#define _IPC6_U2TXIP_MASK                        0x00000070
#define _IPC6_U2TXIP_LENGTH                      0x00000003

#define _IPC6_U2RXIP0_POSITION                   0x00000000
#define _IPC6_U2RXIP0_MASK                       0x00000001
#define _IPC6_U2RXIP0_LENGTH                     0x00000001

#define _IPC6_U2RXIP1_POSITION                   0x00000001
#define _IPC6_U2RXIP1_MASK                       0x00000002
#define _IPC6_U2RXIP1_LENGTH                     0x00000001

#define _IPC6_U2RXIP2_POSITION                   0x00000002
#define _IPC6_U2RXIP2_MASK                       0x00000004
#define _IPC6_U2RXIP2_LENGTH                     0x00000001

#define _IPC6_U2TXIP0_POSITION                   0x00000004
#define _IPC6_U2TXIP0_MASK                       0x00000010
#define _IPC6_U2TXIP0_LENGTH                     0x00000001

#define _IPC6_U2TXIP1_POSITION                   0x00000005
#define _IPC6_U2TXIP1_MASK                       0x00000020
#define _IPC6_U2TXIP1_LENGTH                     0x00000001

#define _IPC6_U2TXIP2_POSITION                   0x00000006
#define _IPC6_U2TXIP2_MASK                       0x00000040
#define _IPC6_U2TXIP2_LENGTH                     0x00000001

#define _IPC10_LVDIP_POSITION                    0x00000008
#define _IPC10_LVDIP_MASK                        0x00000700
#define _IPC10_LVDIP_LENGTH                      0x00000003

#define _IPC10_LVDIP0_POSITION                   0x00000008
#define _IPC10_LVDIP0_MASK                       0x00000100
#define _IPC10_LVDIP0_LENGTH                     0x00000001

#define _IPC10_LVDIP1_POSITION                   0x00000009
#define _IPC10_LVDIP1_MASK                       0x00000200
#define _IPC10_LVDIP1_LENGTH                     0x00000001

#define _IPC10_LVDIP2_POSITION                   0x0000000A
#define _IPC10_LVDIP2_MASK                       0x00000400
#define _IPC10_LVDIP2_LENGTH                     0x00000001

#define _INTTREG_VECNUM_POSITION                 0x00000000
#define _INTTREG_VECNUM_MASK                     0x0000003F
#define _INTTREG_VECNUM_LENGTH                   0x00000006

#define _INTTREG_ILR_POSITION                    0x00000008
#define _INTTREG_ILR_MASK                        0x00000F00
#define _INTTREG_ILR_LENGTH                      0x00000004

#define _INTTREG_VHOLD_POSITION                  0x0000000D
#define _INTTREG_VHOLD_MASK                      0x00002000
#define _INTTREG_VHOLD_LENGTH                    0x00000001

#define _INTTREG_TMODE_POSITION                  0x0000000E
#define _INTTREG_TMODE_MASK                      0x00004000
#define _INTTREG_TMODE_LENGTH                    0x00000001

#define _INTTREG_IRQTOCPU_POSITION               0x0000000F
#define _INTTREG_IRQTOCPU_MASK                   0x00008000
#define _INTTREG_IRQTOCPU_LENGTH                 0x00000001

#define _INTTREG_VECNUM0_POSITION                0x00000000
#define _INTTREG_VECNUM0_MASK                    0x00000001
#define _INTTREG_VECNUM0_LENGTH                  0x00000001

#define _INTTREG_VECNUM1_POSITION                0x00000001
#define _INTTREG_VECNUM1_MASK                    0x00000002
#define _INTTREG_VECNUM1_LENGTH                  0x00000001

#define _INTTREG_VECNUM2_POSITION                0x00000002
#define _INTTREG_VECNUM2_MASK                    0x00000004
#define _INTTREG_VECNUM2_LENGTH                  0x00000001

#define _INTTREG_VECNUM3_POSITION                0x00000003
#define _INTTREG_VECNUM3_MASK                    0x00000008
#define _INTTREG_VECNUM3_LENGTH                  0x00000001

#define _INTTREG_VECNUM4_POSITION                0x00000004
#define _INTTREG_VECNUM4_MASK                    0x00000010
#define _INTTREG_VECNUM4_LENGTH                  0x00000001

#define _INTTREG_VECNUM5_POSITION                0x00000005
#define _INTTREG_VECNUM5_MASK                    0x00000020
#define _INTTREG_VECNUM5_LENGTH                  0x00000001

#define _INTTREG_ILR0_POSITION                   0x00000008
#define _INTTREG_ILR0_MASK                       0x00000100
#define _INTTREG_ILR0_LENGTH                     0x00000001

#define _INTTREG_ILR1_POSITION                   0x00000009
#define _INTTREG_ILR1_MASK                       0x00000200
#define _INTTREG_ILR1_LENGTH                     0x00000001

#define _INTTREG_ILR2_POSITION                   0x0000000A
#define _INTTREG_ILR2_MASK                       0x00000400
#define _INTTREG_ILR2_LENGTH                     0x00000001

#define _INTTREG_ILR3_POSITION                   0x0000000B
#define _INTTREG_ILR3_MASK                       0x00000800
#define _INTTREG_ILR3_LENGTH                     0x00000001

#define _CNEN1_CN0IE_POSITION                    0x00000000
#define _CNEN1_CN0IE_MASK                        0x00000001
#define _CNEN1_CN0IE_LENGTH                      0x00000001

#define _CNEN1_CN1IE_POSITION                    0x00000001
#define _CNEN1_CN1IE_MASK                        0x00000002
#define _CNEN1_CN1IE_LENGTH                      0x00000001

#define _CNEN1_CN2IE_POSITION                    0x00000002
#define _CNEN1_CN2IE_MASK                        0x00000004
#define _CNEN1_CN2IE_LENGTH                      0x00000001

#define _CNEN1_CN3IE_POSITION                    0x00000003
#define _CNEN1_CN3IE_MASK                        0x00000008
#define _CNEN1_CN3IE_LENGTH                      0x00000001

#define _CNEN1_CN4IE_POSITION                    0x00000004
#define _CNEN1_CN4IE_MASK                        0x00000010
#define _CNEN1_CN4IE_LENGTH                      0x00000001

#define _CNEN1_CN5IE_POSITION                    0x00000005
#define _CNEN1_CN5IE_MASK                        0x00000020
#define _CNEN1_CN5IE_LENGTH                      0x00000001

#define _CNEN1_CN6IE_POSITION                    0x00000006
#define _CNEN1_CN6IE_MASK                        0x00000040
#define _CNEN1_CN6IE_LENGTH                      0x00000001

#define _CNEN1_CN7IE_POSITION                    0x00000007
#define _CNEN1_CN7IE_MASK                        0x00000080
#define _CNEN1_CN7IE_LENGTH                      0x00000001

#define _CNEN2_CN17IE_POSITION                   0x00000001
#define _CNEN2_CN17IE_MASK                       0x00000002
#define _CNEN2_CN17IE_LENGTH                     0x00000001

#define _CNEN2_CN18IE_POSITION                   0x00000002
#define _CNEN2_CN18IE_MASK                       0x00000004
#define _CNEN2_CN18IE_LENGTH                     0x00000001

#define _CNPU1_CN0PUE_POSITION                   0x00000000
#define _CNPU1_CN0PUE_MASK                       0x00000001
#define _CNPU1_CN0PUE_LENGTH                     0x00000001

#define _CNPU1_CN1PUE_POSITION                   0x00000001
#define _CNPU1_CN1PUE_MASK                       0x00000002
#define _CNPU1_CN1PUE_LENGTH                     0x00000001

#define _CNPU1_CN2PUE_POSITION                   0x00000002
#define _CNPU1_CN2PUE_MASK                       0x00000004
#define _CNPU1_CN2PUE_LENGTH                     0x00000001

#define _CNPU1_CN3PUE_POSITION                   0x00000003
#define _CNPU1_CN3PUE_MASK                       0x00000008
#define _CNPU1_CN3PUE_LENGTH                     0x00000001

#define _CNPU1_CN4PUE_POSITION                   0x00000004
#define _CNPU1_CN4PUE_MASK                       0x00000010
#define _CNPU1_CN4PUE_LENGTH                     0x00000001

#define _CNPU1_CN5PUE_POSITION                   0x00000005
#define _CNPU1_CN5PUE_MASK                       0x00000020
#define _CNPU1_CN5PUE_LENGTH                     0x00000001

#define _CNPU1_CN6PUE_POSITION                   0x00000006
#define _CNPU1_CN6PUE_MASK                       0x00000040
#define _CNPU1_CN6PUE_LENGTH                     0x00000001

#define _CNPU1_CN7PUE_POSITION                   0x00000007
#define _CNPU1_CN7PUE_MASK                       0x00000080
#define _CNPU1_CN7PUE_LENGTH                     0x00000001

#define _CNPU2_CN17PUE_POSITION                  0x00000001
#define _CNPU2_CN17PUE_MASK                      0x00000002
#define _CNPU2_CN17PUE_LENGTH                    0x00000001

#define _CNPU2_CN18PUE_POSITION                  0x00000002
#define _CNPU2_CN18PUE_MASK                      0x00000004
#define _CNPU2_CN18PUE_LENGTH                    0x00000001

#define _T1CON_TCS_POSITION                      0x00000001
#define _T1CON_TCS_MASK                          0x00000002
#define _T1CON_TCS_LENGTH                        0x00000001

#define _T1CON_TSYNC_POSITION                    0x00000002
#define _T1CON_TSYNC_MASK                        0x00000004
#define _T1CON_TSYNC_LENGTH                      0x00000001

#define _T1CON_TCKPS_POSITION                    0x00000004
#define _T1CON_TCKPS_MASK                        0x00000030
#define _T1CON_TCKPS_LENGTH                      0x00000002

#define _T1CON_TGATE_POSITION                    0x00000006
#define _T1CON_TGATE_MASK                        0x00000040
#define _T1CON_TGATE_LENGTH                      0x00000001

#define _T1CON_TSIDL_POSITION                    0x0000000D
#define _T1CON_TSIDL_MASK                        0x00002000
#define _T1CON_TSIDL_LENGTH                      0x00000001

#define _T1CON_TON_POSITION                      0x0000000F
#define _T1CON_TON_MASK                          0x00008000
#define _T1CON_TON_LENGTH                        0x00000001

#define _T1CON_TCKPS0_POSITION                   0x00000004
#define _T1CON_TCKPS0_MASK                       0x00000010
#define _T1CON_TCKPS0_LENGTH                     0x00000001

#define _T1CON_TCKPS1_POSITION                   0x00000005
#define _T1CON_TCKPS1_MASK                       0x00000020
#define _T1CON_TCKPS1_LENGTH                     0x00000001

#define _T2CON_TCS_POSITION                      0x00000001
#define _T2CON_TCS_MASK                          0x00000002
#define _T2CON_TCS_LENGTH                        0x00000001

#define _T2CON_T32_POSITION                      0x00000003
#define _T2CON_T32_MASK                          0x00000008
#define _T2CON_T32_LENGTH                        0x00000001

#define _T2CON_TCKPS_POSITION                    0x00000004
#define _T2CON_TCKPS_MASK                        0x00000030
#define _T2CON_TCKPS_LENGTH                      0x00000002

#define _T2CON_TGATE_POSITION                    0x00000006
#define _T2CON_TGATE_MASK                        0x00000040
#define _T2CON_TGATE_LENGTH                      0x00000001

#define _T2CON_TSIDL_POSITION                    0x0000000D
#define _T2CON_TSIDL_MASK                        0x00002000
#define _T2CON_TSIDL_LENGTH                      0x00000001

#define _T2CON_TON_POSITION                      0x0000000F
#define _T2CON_TON_MASK                          0x00008000
#define _T2CON_TON_LENGTH                        0x00000001

#define _T2CON_TCKPS0_POSITION                   0x00000004
#define _T2CON_TCKPS0_MASK                       0x00000010
#define _T2CON_TCKPS0_LENGTH                     0x00000001

#define _T2CON_TCKPS1_POSITION                   0x00000005
#define _T2CON_TCKPS1_MASK                       0x00000020
#define _T2CON_TCKPS1_LENGTH                     0x00000001

#define _T3CON_TCS_POSITION                      0x00000001
#define _T3CON_TCS_MASK                          0x00000002
#define _T3CON_TCS_LENGTH                        0x00000001

#define _T3CON_TCKPS_POSITION                    0x00000004
#define _T3CON_TCKPS_MASK                        0x00000030
#define _T3CON_TCKPS_LENGTH                      0x00000002

#define _T3CON_TGATE_POSITION                    0x00000006
#define _T3CON_TGATE_MASK                        0x00000040
#define _T3CON_TGATE_LENGTH                      0x00000001

#define _T3CON_TSIDL_POSITION                    0x0000000D
#define _T3CON_TSIDL_MASK                        0x00002000
#define _T3CON_TSIDL_LENGTH                      0x00000001

#define _T3CON_TON_POSITION                      0x0000000F
#define _T3CON_TON_MASK                          0x00008000
#define _T3CON_TON_LENGTH                        0x00000001

#define _T3CON_TCKPS0_POSITION                   0x00000004
#define _T3CON_TCKPS0_MASK                       0x00000010
#define _T3CON_TCKPS0_LENGTH                     0x00000001

#define _T3CON_TCKPS1_POSITION                   0x00000005
#define _T3CON_TCKPS1_MASK                       0x00000020
#define _T3CON_TCKPS1_LENGTH                     0x00000001

#define _IC1CON_ICM_POSITION                     0x00000000
#define _IC1CON_ICM_MASK                         0x00000007
#define _IC1CON_ICM_LENGTH                       0x00000003

#define _IC1CON_ICBNE_POSITION                   0x00000003
#define _IC1CON_ICBNE_MASK                       0x00000008
#define _IC1CON_ICBNE_LENGTH                     0x00000001

#define _IC1CON_ICOV_POSITION                    0x00000004
#define _IC1CON_ICOV_MASK                        0x00000010
#define _IC1CON_ICOV_LENGTH                      0x00000001

#define _IC1CON_ICI_POSITION                     0x00000005
#define _IC1CON_ICI_MASK                         0x00000060
#define _IC1CON_ICI_LENGTH                       0x00000002

#define _IC1CON_ICTMR_POSITION                   0x00000007
#define _IC1CON_ICTMR_MASK                       0x00000080
#define _IC1CON_ICTMR_LENGTH                     0x00000001

#define _IC1CON_ICSIDL_POSITION                  0x0000000D
#define _IC1CON_ICSIDL_MASK                      0x00002000
#define _IC1CON_ICSIDL_LENGTH                    0x00000001

#define _IC1CON_ICM0_POSITION                    0x00000000
#define _IC1CON_ICM0_MASK                        0x00000001
#define _IC1CON_ICM0_LENGTH                      0x00000001

#define _IC1CON_ICM1_POSITION                    0x00000001
#define _IC1CON_ICM1_MASK                        0x00000002
#define _IC1CON_ICM1_LENGTH                      0x00000001

#define _IC1CON_ICM2_POSITION                    0x00000002
#define _IC1CON_ICM2_MASK                        0x00000004
#define _IC1CON_ICM2_LENGTH                      0x00000001

#define _IC1CON_ICI0_POSITION                    0x00000005
#define _IC1CON_ICI0_MASK                        0x00000020
#define _IC1CON_ICI0_LENGTH                      0x00000001

#define _IC1CON_ICI1_POSITION                    0x00000006
#define _IC1CON_ICI1_MASK                        0x00000040
#define _IC1CON_ICI1_LENGTH                      0x00000001

#define _IC2CON_ICM_POSITION                     0x00000000
#define _IC2CON_ICM_MASK                         0x00000007
#define _IC2CON_ICM_LENGTH                       0x00000003

#define _IC2CON_ICBNE_POSITION                   0x00000003
#define _IC2CON_ICBNE_MASK                       0x00000008
#define _IC2CON_ICBNE_LENGTH                     0x00000001

#define _IC2CON_ICOV_POSITION                    0x00000004
#define _IC2CON_ICOV_MASK                        0x00000010
#define _IC2CON_ICOV_LENGTH                      0x00000001

#define _IC2CON_ICI_POSITION                     0x00000005
#define _IC2CON_ICI_MASK                         0x00000060
#define _IC2CON_ICI_LENGTH                       0x00000002

#define _IC2CON_ICTMR_POSITION                   0x00000007
#define _IC2CON_ICTMR_MASK                       0x00000080
#define _IC2CON_ICTMR_LENGTH                     0x00000001

#define _IC2CON_ICSIDL_POSITION                  0x0000000D
#define _IC2CON_ICSIDL_MASK                      0x00002000
#define _IC2CON_ICSIDL_LENGTH                    0x00000001

#define _IC2CON_ICM0_POSITION                    0x00000000
#define _IC2CON_ICM0_MASK                        0x00000001
#define _IC2CON_ICM0_LENGTH                      0x00000001

#define _IC2CON_ICM1_POSITION                    0x00000001
#define _IC2CON_ICM1_MASK                        0x00000002
#define _IC2CON_ICM1_LENGTH                      0x00000001

#define _IC2CON_ICM2_POSITION                    0x00000002
#define _IC2CON_ICM2_MASK                        0x00000004
#define _IC2CON_ICM2_LENGTH                      0x00000001

#define _IC2CON_ICI0_POSITION                    0x00000005
#define _IC2CON_ICI0_MASK                        0x00000020
#define _IC2CON_ICI0_LENGTH                      0x00000001

#define _IC2CON_ICI1_POSITION                    0x00000006
#define _IC2CON_ICI1_MASK                        0x00000040
#define _IC2CON_ICI1_LENGTH                      0x00000001

#define _OC1CON_OCM_POSITION                     0x00000000
#define _OC1CON_OCM_MASK                         0x00000007
#define _OC1CON_OCM_LENGTH                       0x00000003

#define _OC1CON_OCTSEL_POSITION                  0x00000003
#define _OC1CON_OCTSEL_MASK                      0x00000008
#define _OC1CON_OCTSEL_LENGTH                    0x00000001

#define _OC1CON_OCFLT_POSITION                   0x00000004
#define _OC1CON_OCFLT_MASK                       0x00000010
#define _OC1CON_OCFLT_LENGTH                     0x00000001

#define _OC1CON_OCSIDL_POSITION                  0x0000000D
#define _OC1CON_OCSIDL_MASK                      0x00002000
#define _OC1CON_OCSIDL_LENGTH                    0x00000001

#define _OC1CON_OCM0_POSITION                    0x00000000
#define _OC1CON_OCM0_MASK                        0x00000001
#define _OC1CON_OCM0_LENGTH                      0x00000001

#define _OC1CON_OCM1_POSITION                    0x00000001
#define _OC1CON_OCM1_MASK                        0x00000002
#define _OC1CON_OCM1_LENGTH                      0x00000001

#define _OC1CON_OCM2_POSITION                    0x00000002
#define _OC1CON_OCM2_MASK                        0x00000004
#define _OC1CON_OCM2_LENGTH                      0x00000001

#define _OC2CON_OCM_POSITION                     0x00000000
#define _OC2CON_OCM_MASK                         0x00000007
#define _OC2CON_OCM_LENGTH                       0x00000003

#define _OC2CON_OCTSEL_POSITION                  0x00000003
#define _OC2CON_OCTSEL_MASK                      0x00000008
#define _OC2CON_OCTSEL_LENGTH                    0x00000001

#define _OC2CON_OCFLT_POSITION                   0x00000004
#define _OC2CON_OCFLT_MASK                       0x00000010
#define _OC2CON_OCFLT_LENGTH                     0x00000001

#define _OC2CON_OCSIDL_POSITION                  0x0000000D
#define _OC2CON_OCSIDL_MASK                      0x00002000
#define _OC2CON_OCSIDL_LENGTH                    0x00000001

#define _OC2CON_OCM0_POSITION                    0x00000000
#define _OC2CON_OCM0_MASK                        0x00000001
#define _OC2CON_OCM0_LENGTH                      0x00000001

#define _OC2CON_OCM1_POSITION                    0x00000001
#define _OC2CON_OCM1_MASK                        0x00000002
#define _OC2CON_OCM1_LENGTH                      0x00000001

#define _OC2CON_OCM2_POSITION                    0x00000002
#define _OC2CON_OCM2_MASK                        0x00000004
#define _OC2CON_OCM2_LENGTH                      0x00000001

#define _I2CRCV_I2CRCV_POSITION                  0x00000000
#define _I2CRCV_I2CRCV_MASK                      0x000000FF
#define _I2CRCV_I2CRCV_LENGTH                    0x00000008

#define _I2CRCV_I2CRCV0_POSITION                 0x00000000
#define _I2CRCV_I2CRCV0_MASK                     0x00000001
#define _I2CRCV_I2CRCV0_LENGTH                   0x00000001

#define _I2CRCV_I2CRCV1_POSITION                 0x00000001
#define _I2CRCV_I2CRCV1_MASK                     0x00000002
#define _I2CRCV_I2CRCV1_LENGTH                   0x00000001

#define _I2CRCV_I2CRCV2_POSITION                 0x00000002
#define _I2CRCV_I2CRCV2_MASK                     0x00000004
#define _I2CRCV_I2CRCV2_LENGTH                   0x00000001

#define _I2CRCV_I2CRCV3_POSITION                 0x00000003
#define _I2CRCV_I2CRCV3_MASK                     0x00000008
#define _I2CRCV_I2CRCV3_LENGTH                   0x00000001

#define _I2CRCV_I2CRCV4_POSITION                 0x00000004
#define _I2CRCV_I2CRCV4_MASK                     0x00000010
#define _I2CRCV_I2CRCV4_LENGTH                   0x00000001

#define _I2CRCV_I2CRCV5_POSITION                 0x00000005
#define _I2CRCV_I2CRCV5_MASK                     0x00000020
#define _I2CRCV_I2CRCV5_LENGTH                   0x00000001

#define _I2CRCV_I2CRCV6_POSITION                 0x00000006
#define _I2CRCV_I2CRCV6_MASK                     0x00000040
#define _I2CRCV_I2CRCV6_LENGTH                   0x00000001

#define _I2CRCV_I2CRCV7_POSITION                 0x00000007
#define _I2CRCV_I2CRCV7_MASK                     0x00000080
#define _I2CRCV_I2CRCV7_LENGTH                   0x00000001

#define _I2CTRN_I2CTRN_POSITION                  0x00000000
#define _I2CTRN_I2CTRN_MASK                      0x000000FF
#define _I2CTRN_I2CTRN_LENGTH                    0x00000008

#define _I2CTRN_I2CTRN0_POSITION                 0x00000000
#define _I2CTRN_I2CTRN0_MASK                     0x00000001
#define _I2CTRN_I2CTRN0_LENGTH                   0x00000001

#define _I2CTRN_I2CTRN1_POSITION                 0x00000001
#define _I2CTRN_I2CTRN1_MASK                     0x00000002
#define _I2CTRN_I2CTRN1_LENGTH                   0x00000001

#define _I2CTRN_I2CTRN2_POSITION                 0x00000002
#define _I2CTRN_I2CTRN2_MASK                     0x00000004
#define _I2CTRN_I2CTRN2_LENGTH                   0x00000001

#define _I2CTRN_I2CTRN3_POSITION                 0x00000003
#define _I2CTRN_I2CTRN3_MASK                     0x00000008
#define _I2CTRN_I2CTRN3_LENGTH                   0x00000001

#define _I2CTRN_I2CTRN4_POSITION                 0x00000004
#define _I2CTRN_I2CTRN4_MASK                     0x00000010
#define _I2CTRN_I2CTRN4_LENGTH                   0x00000001

#define _I2CTRN_I2CTRN5_POSITION                 0x00000005
#define _I2CTRN_I2CTRN5_MASK                     0x00000020
#define _I2CTRN_I2CTRN5_LENGTH                   0x00000001

#define _I2CTRN_I2CTRN6_POSITION                 0x00000006
#define _I2CTRN_I2CTRN6_MASK                     0x00000040
#define _I2CTRN_I2CTRN6_LENGTH                   0x00000001

#define _I2CTRN_I2CTRN7_POSITION                 0x00000007
#define _I2CTRN_I2CTRN7_MASK                     0x00000080
#define _I2CTRN_I2CTRN7_LENGTH                   0x00000001

#define _I2CBRG_I2CBRG_POSITION                  0x00000000
#define _I2CBRG_I2CBRG_MASK                      0x000001FF
#define _I2CBRG_I2CBRG_LENGTH                    0x00000009

#define _I2CCON_SEN_POSITION                     0x00000000
#define _I2CCON_SEN_MASK                         0x00000001
#define _I2CCON_SEN_LENGTH                       0x00000001

#define _I2CCON_RSEN_POSITION                    0x00000001
#define _I2CCON_RSEN_MASK                        0x00000002
#define _I2CCON_RSEN_LENGTH                      0x00000001

#define _I2CCON_PEN_POSITION                     0x00000002
#define _I2CCON_PEN_MASK                         0x00000004
#define _I2CCON_PEN_LENGTH                       0x00000001

#define _I2CCON_RCEN_POSITION                    0x00000003
#define _I2CCON_RCEN_MASK                        0x00000008
#define _I2CCON_RCEN_LENGTH                      0x00000001

#define _I2CCON_ACKEN_POSITION                   0x00000004
#define _I2CCON_ACKEN_MASK                       0x00000010
#define _I2CCON_ACKEN_LENGTH                     0x00000001

#define _I2CCON_ACKDT_POSITION                   0x00000005
#define _I2CCON_ACKDT_MASK                       0x00000020
#define _I2CCON_ACKDT_LENGTH                     0x00000001

#define _I2CCON_STREN_POSITION                   0x00000006
#define _I2CCON_STREN_MASK                       0x00000040
#define _I2CCON_STREN_LENGTH                     0x00000001

#define _I2CCON_GCEN_POSITION                    0x00000007
#define _I2CCON_GCEN_MASK                        0x00000080
#define _I2CCON_GCEN_LENGTH                      0x00000001

#define _I2CCON_SMEN_POSITION                    0x00000008
#define _I2CCON_SMEN_MASK                        0x00000100
#define _I2CCON_SMEN_LENGTH                      0x00000001

#define _I2CCON_DISSLW_POSITION                  0x00000009
#define _I2CCON_DISSLW_MASK                      0x00000200
#define _I2CCON_DISSLW_LENGTH                    0x00000001

#define _I2CCON_A10M_POSITION                    0x0000000A
#define _I2CCON_A10M_MASK                        0x00000400
#define _I2CCON_A10M_LENGTH                      0x00000001

#define _I2CCON_IPMIEN_POSITION                  0x0000000B
#define _I2CCON_IPMIEN_MASK                      0x00000800
#define _I2CCON_IPMIEN_LENGTH                    0x00000001

#define _I2CCON_SCLREL_POSITION                  0x0000000C
#define _I2CCON_SCLREL_MASK                      0x00001000
#define _I2CCON_SCLREL_LENGTH                    0x00000001

#define _I2CCON_I2CSIDL_POSITION                 0x0000000D
#define _I2CCON_I2CSIDL_MASK                     0x00002000
#define _I2CCON_I2CSIDL_LENGTH                   0x00000001

#define _I2CCON_I2CEN_POSITION                   0x0000000F
#define _I2CCON_I2CEN_MASK                       0x00008000
#define _I2CCON_I2CEN_LENGTH                     0x00000001

#define _I2CSTAT_TBF_POSITION                    0x00000000
#define _I2CSTAT_TBF_MASK                        0x00000001
#define _I2CSTAT_TBF_LENGTH                      0x00000001

#define _I2CSTAT_RBF_POSITION                    0x00000001
#define _I2CSTAT_RBF_MASK                        0x00000002
#define _I2CSTAT_RBF_LENGTH                      0x00000001

#define _I2CSTAT_R_NOT_W_POSITION                0x00000002
#define _I2CSTAT_R_NOT_W_MASK                    0x00000004
#define _I2CSTAT_R_NOT_W_LENGTH                  0x00000001

#define _I2CSTAT_S_POSITION                      0x00000003
#define _I2CSTAT_S_MASK                          0x00000008
#define _I2CSTAT_S_LENGTH                        0x00000001

#define _I2CSTAT_P_POSITION                      0x00000004
#define _I2CSTAT_P_MASK                          0x00000010
#define _I2CSTAT_P_LENGTH                        0x00000001

#define _I2CSTAT_D_NOT_A_POSITION                0x00000005
#define _I2CSTAT_D_NOT_A_MASK                    0x00000020
#define _I2CSTAT_D_NOT_A_LENGTH                  0x00000001

#define _I2CSTAT_I2COV_POSITION                  0x00000006
#define _I2CSTAT_I2COV_MASK                      0x00000040
#define _I2CSTAT_I2COV_LENGTH                    0x00000001

#define _I2CSTAT_IWCOL_POSITION                  0x00000007
#define _I2CSTAT_IWCOL_MASK                      0x00000080
#define _I2CSTAT_IWCOL_LENGTH                    0x00000001

#define _I2CSTAT_ADD10_POSITION                  0x00000008
#define _I2CSTAT_ADD10_MASK                      0x00000100
#define _I2CSTAT_ADD10_LENGTH                    0x00000001

#define _I2CSTAT_GCSTAT_POSITION                 0x00000009
#define _I2CSTAT_GCSTAT_MASK                     0x00000200
#define _I2CSTAT_GCSTAT_LENGTH                   0x00000001

#define _I2CSTAT_BCL_POSITION                    0x0000000A
#define _I2CSTAT_BCL_MASK                        0x00000400
#define _I2CSTAT_BCL_LENGTH                      0x00000001

#define _I2CSTAT_TRSTAT_POSITION                 0x0000000E
#define _I2CSTAT_TRSTAT_MASK                     0x00004000
#define _I2CSTAT_TRSTAT_LENGTH                   0x00000001

#define _I2CSTAT_ACKSTAT_POSITION                0x0000000F
#define _I2CSTAT_ACKSTAT_MASK                    0x00008000
#define _I2CSTAT_ACKSTAT_LENGTH                  0x00000001

#define _I2CSTAT_R_W_POSITION                    0x00000002
#define _I2CSTAT_R_W_MASK                        0x00000004
#define _I2CSTAT_R_W_LENGTH                      0x00000001

#define _I2CSTAT_D_A_POSITION                    0x00000005
#define _I2CSTAT_D_A_MASK                        0x00000020
#define _I2CSTAT_D_A_LENGTH                      0x00000001

#define _I2CADD_I2CADD_POSITION                  0x00000000
#define _I2CADD_I2CADD_MASK                      0x000003FF
#define _I2CADD_I2CADD_LENGTH                    0x0000000A

#define _U1MODE_STSEL_POSITION                   0x00000000
#define _U1MODE_STSEL_MASK                       0x00000001
#define _U1MODE_STSEL_LENGTH                     0x00000001

#define _U1MODE_PDSEL_POSITION                   0x00000001
#define _U1MODE_PDSEL_MASK                       0x00000006
#define _U1MODE_PDSEL_LENGTH                     0x00000002

#define _U1MODE_ABAUD_POSITION                   0x00000005
#define _U1MODE_ABAUD_MASK                       0x00000020
#define _U1MODE_ABAUD_LENGTH                     0x00000001

#define _U1MODE_LPBACK_POSITION                  0x00000006
#define _U1MODE_LPBACK_MASK                      0x00000040
#define _U1MODE_LPBACK_LENGTH                    0x00000001

#define _U1MODE_WAKE_POSITION                    0x00000007
#define _U1MODE_WAKE_MASK                        0x00000080
#define _U1MODE_WAKE_LENGTH                      0x00000001

#define _U1MODE_ALTIO_POSITION                   0x0000000A
#define _U1MODE_ALTIO_MASK                       0x00000400
#define _U1MODE_ALTIO_LENGTH                     0x00000001

#define _U1MODE_USIDL_POSITION                   0x0000000D
#define _U1MODE_USIDL_MASK                       0x00002000
#define _U1MODE_USIDL_LENGTH                     0x00000001

#define _U1MODE_UARTEN_POSITION                  0x0000000F
#define _U1MODE_UARTEN_MASK                      0x00008000
#define _U1MODE_UARTEN_LENGTH                    0x00000001

#define _U1MODE_PDSEL0_POSITION                  0x00000001
#define _U1MODE_PDSEL0_MASK                      0x00000002
#define _U1MODE_PDSEL0_LENGTH                    0x00000001

#define _U1MODE_PDSEL1_POSITION                  0x00000002
#define _U1MODE_PDSEL1_MASK                      0x00000004
#define _U1MODE_PDSEL1_LENGTH                    0x00000001

#define _U1STA_URXDA_POSITION                    0x00000000
#define _U1STA_URXDA_MASK                        0x00000001
#define _U1STA_URXDA_LENGTH                      0x00000001

#define _U1STA_OERR_POSITION                     0x00000001
#define _U1STA_OERR_MASK                         0x00000002
#define _U1STA_OERR_LENGTH                       0x00000001

#define _U1STA_FERR_POSITION                     0x00000002
#define _U1STA_FERR_MASK                         0x00000004
#define _U1STA_FERR_LENGTH                       0x00000001

#define _U1STA_PERR_POSITION                     0x00000003
#define _U1STA_PERR_MASK                         0x00000008
#define _U1STA_PERR_LENGTH                       0x00000001

#define _U1STA_RIDLE_POSITION                    0x00000004
#define _U1STA_RIDLE_MASK                        0x00000010
#define _U1STA_RIDLE_LENGTH                      0x00000001

#define _U1STA_ADDEN_POSITION                    0x00000005
#define _U1STA_ADDEN_MASK                        0x00000020
#define _U1STA_ADDEN_LENGTH                      0x00000001

#define _U1STA_URXISEL_POSITION                  0x00000006
#define _U1STA_URXISEL_MASK                      0x000000C0
#define _U1STA_URXISEL_LENGTH                    0x00000002

#define _U1STA_TRMT_POSITION                     0x00000008
#define _U1STA_TRMT_MASK                         0x00000100
#define _U1STA_TRMT_LENGTH                       0x00000001

#define _U1STA_UTXBF_POSITION                    0x00000009
#define _U1STA_UTXBF_MASK                        0x00000200
#define _U1STA_UTXBF_LENGTH                      0x00000001

#define _U1STA_UTXEN_POSITION                    0x0000000A
#define _U1STA_UTXEN_MASK                        0x00000400
#define _U1STA_UTXEN_LENGTH                      0x00000001

#define _U1STA_UTXBRK_POSITION                   0x0000000B
#define _U1STA_UTXBRK_MASK                       0x00000800
#define _U1STA_UTXBRK_LENGTH                     0x00000001

#define _U1STA_UTXISEL_POSITION                  0x0000000F
#define _U1STA_UTXISEL_MASK                      0x00008000
#define _U1STA_UTXISEL_LENGTH                    0x00000001

#define _U1STA_URXISEL0_POSITION                 0x00000006
#define _U1STA_URXISEL0_MASK                     0x00000040
#define _U1STA_URXISEL0_LENGTH                   0x00000001

#define _U1STA_URXISEL1_POSITION                 0x00000007
#define _U1STA_URXISEL1_MASK                     0x00000080
#define _U1STA_URXISEL1_LENGTH                   0x00000001

#define _U1TXREG_UTXREG0_POSITION                0x00000000
#define _U1TXREG_UTXREG0_MASK                    0x00000001
#define _U1TXREG_UTXREG0_LENGTH                  0x00000001

#define _U1TXREG_UTXREG1_POSITION                0x00000001
#define _U1TXREG_UTXREG1_MASK                    0x00000002
#define _U1TXREG_UTXREG1_LENGTH                  0x00000001

#define _U1TXREG_UTXREG2_POSITION                0x00000002
#define _U1TXREG_UTXREG2_MASK                    0x00000004
#define _U1TXREG_UTXREG2_LENGTH                  0x00000001

#define _U1TXREG_UTXREG3_POSITION                0x00000003
#define _U1TXREG_UTXREG3_MASK                    0x00000008
#define _U1TXREG_UTXREG3_LENGTH                  0x00000001

#define _U1TXREG_UTXREG4_POSITION                0x00000004
#define _U1TXREG_UTXREG4_MASK                    0x00000010
#define _U1TXREG_UTXREG4_LENGTH                  0x00000001

#define _U1TXREG_UTXREG5_POSITION                0x00000005
#define _U1TXREG_UTXREG5_MASK                    0x00000020
#define _U1TXREG_UTXREG5_LENGTH                  0x00000001

#define _U1TXREG_UTXREG6_POSITION                0x00000006
#define _U1TXREG_UTXREG6_MASK                    0x00000040
#define _U1TXREG_UTXREG6_LENGTH                  0x00000001

#define _U1TXREG_UTXREG7_POSITION                0x00000007
#define _U1TXREG_UTXREG7_MASK                    0x00000080
#define _U1TXREG_UTXREG7_LENGTH                  0x00000001

#define _U1TXREG_UTXREG8_POSITION                0x00000008
#define _U1TXREG_UTXREG8_MASK                    0x00000100
#define _U1TXREG_UTXREG8_LENGTH                  0x00000001

#define _U1TXREG_UTX8_POSITION                   0x00000008
#define _U1TXREG_UTX8_MASK                       0x00000100
#define _U1TXREG_UTX8_LENGTH                     0x00000001

#define _U1RXREG_URXREG0_POSITION                0x00000000
#define _U1RXREG_URXREG0_MASK                    0x00000001
#define _U1RXREG_URXREG0_LENGTH                  0x00000001

#define _U1RXREG_URXREG1_POSITION                0x00000001
#define _U1RXREG_URXREG1_MASK                    0x00000002
#define _U1RXREG_URXREG1_LENGTH                  0x00000001

#define _U1RXREG_URXREG2_POSITION                0x00000002
#define _U1RXREG_URXREG2_MASK                    0x00000004
#define _U1RXREG_URXREG2_LENGTH                  0x00000001

#define _U1RXREG_URXREG3_POSITION                0x00000003
#define _U1RXREG_URXREG3_MASK                    0x00000008
#define _U1RXREG_URXREG3_LENGTH                  0x00000001

#define _U1RXREG_URXREG4_POSITION                0x00000004
#define _U1RXREG_URXREG4_MASK                    0x00000010
#define _U1RXREG_URXREG4_LENGTH                  0x00000001

#define _U1RXREG_URXREG5_POSITION                0x00000005
#define _U1RXREG_URXREG5_MASK                    0x00000020
#define _U1RXREG_URXREG5_LENGTH                  0x00000001

#define _U1RXREG_URXREG6_POSITION                0x00000006
#define _U1RXREG_URXREG6_MASK                    0x00000040
#define _U1RXREG_URXREG6_LENGTH                  0x00000001

#define _U1RXREG_URXREG7_POSITION                0x00000007
#define _U1RXREG_URXREG7_MASK                    0x00000080
#define _U1RXREG_URXREG7_LENGTH                  0x00000001

#define _U1RXREG_URXREG8_POSITION                0x00000008
#define _U1RXREG_URXREG8_MASK                    0x00000100
#define _U1RXREG_URXREG8_LENGTH                  0x00000001

#define _U1RXREG_URX8_POSITION                   0x00000008
#define _U1RXREG_URX8_MASK                       0x00000100
#define _U1RXREG_URX8_LENGTH                     0x00000001

#define _U2MODE_STSEL_POSITION                   0x00000000
#define _U2MODE_STSEL_MASK                       0x00000001
#define _U2MODE_STSEL_LENGTH                     0x00000001

#define _U2MODE_PDSEL_POSITION                   0x00000001
#define _U2MODE_PDSEL_MASK                       0x00000006
#define _U2MODE_PDSEL_LENGTH                     0x00000002

#define _U2MODE_ABAUD_POSITION                   0x00000005
#define _U2MODE_ABAUD_MASK                       0x00000020
#define _U2MODE_ABAUD_LENGTH                     0x00000001

#define _U2MODE_LPBACK_POSITION                  0x00000006
#define _U2MODE_LPBACK_MASK                      0x00000040
#define _U2MODE_LPBACK_LENGTH                    0x00000001

#define _U2MODE_WAKE_POSITION                    0x00000007
#define _U2MODE_WAKE_MASK                        0x00000080
#define _U2MODE_WAKE_LENGTH                      0x00000001

#define _U2MODE_USIDL_POSITION                   0x0000000D
#define _U2MODE_USIDL_MASK                       0x00002000
#define _U2MODE_USIDL_LENGTH                     0x00000001

#define _U2MODE_UARTEN_POSITION                  0x0000000F
#define _U2MODE_UARTEN_MASK                      0x00008000
#define _U2MODE_UARTEN_LENGTH                    0x00000001

#define _U2MODE_PDSEL0_POSITION                  0x00000001
#define _U2MODE_PDSEL0_MASK                      0x00000002
#define _U2MODE_PDSEL0_LENGTH                    0x00000001

#define _U2MODE_PDSEL1_POSITION                  0x00000002
#define _U2MODE_PDSEL1_MASK                      0x00000004
#define _U2MODE_PDSEL1_LENGTH                    0x00000001

#define _U2STA_URXDA_POSITION                    0x00000000
#define _U2STA_URXDA_MASK                        0x00000001
#define _U2STA_URXDA_LENGTH                      0x00000001

#define _U2STA_OERR_POSITION                     0x00000001
#define _U2STA_OERR_MASK                         0x00000002
#define _U2STA_OERR_LENGTH                       0x00000001

#define _U2STA_FERR_POSITION                     0x00000002
#define _U2STA_FERR_MASK                         0x00000004
#define _U2STA_FERR_LENGTH                       0x00000001

#define _U2STA_PERR_POSITION                     0x00000003
#define _U2STA_PERR_MASK                         0x00000008
#define _U2STA_PERR_LENGTH                       0x00000001

#define _U2STA_RIDLE_POSITION                    0x00000004
#define _U2STA_RIDLE_MASK                        0x00000010
#define _U2STA_RIDLE_LENGTH                      0x00000001

#define _U2STA_ADDEN_POSITION                    0x00000005
#define _U2STA_ADDEN_MASK                        0x00000020
#define _U2STA_ADDEN_LENGTH                      0x00000001

#define _U2STA_URXISEL_POSITION                  0x00000006
#define _U2STA_URXISEL_MASK                      0x000000C0
#define _U2STA_URXISEL_LENGTH                    0x00000002

#define _U2STA_TRMT_POSITION                     0x00000008
#define _U2STA_TRMT_MASK                         0x00000100
#define _U2STA_TRMT_LENGTH                       0x00000001

#define _U2STA_UTXBF_POSITION                    0x00000009
#define _U2STA_UTXBF_MASK                        0x00000200
#define _U2STA_UTXBF_LENGTH                      0x00000001

#define _U2STA_UTXEN_POSITION                    0x0000000A
#define _U2STA_UTXEN_MASK                        0x00000400
#define _U2STA_UTXEN_LENGTH                      0x00000001

#define _U2STA_UTXBRK_POSITION                   0x0000000B
#define _U2STA_UTXBRK_MASK                       0x00000800
#define _U2STA_UTXBRK_LENGTH                     0x00000001

#define _U2STA_UTXISEL_POSITION                  0x0000000F
#define _U2STA_UTXISEL_MASK                      0x00008000
#define _U2STA_UTXISEL_LENGTH                    0x00000001

#define _U2STA_URXISEL0_POSITION                 0x00000006
#define _U2STA_URXISEL0_MASK                     0x00000040
#define _U2STA_URXISEL0_LENGTH                   0x00000001

#define _U2STA_URXISEL1_POSITION                 0x00000007
#define _U2STA_URXISEL1_MASK                     0x00000080
#define _U2STA_URXISEL1_LENGTH                   0x00000001

#define _U2TXREG_UTXREG0_POSITION                0x00000000
#define _U2TXREG_UTXREG0_MASK                    0x00000001
#define _U2TXREG_UTXREG0_LENGTH                  0x00000001

#define _U2TXREG_UTXREG1_POSITION                0x00000001
#define _U2TXREG_UTXREG1_MASK                    0x00000002
#define _U2TXREG_UTXREG1_LENGTH                  0x00000001

#define _U2TXREG_UTXREG2_POSITION                0x00000002
#define _U2TXREG_UTXREG2_MASK                    0x00000004
#define _U2TXREG_UTXREG2_LENGTH                  0x00000001

#define _U2TXREG_UTXREG3_POSITION                0x00000003
#define _U2TXREG_UTXREG3_MASK                    0x00000008
#define _U2TXREG_UTXREG3_LENGTH                  0x00000001

#define _U2TXREG_UTXREG4_POSITION                0x00000004
#define _U2TXREG_UTXREG4_MASK                    0x00000010
#define _U2TXREG_UTXREG4_LENGTH                  0x00000001

#define _U2TXREG_UTXREG5_POSITION                0x00000005
#define _U2TXREG_UTXREG5_MASK                    0x00000020
#define _U2TXREG_UTXREG5_LENGTH                  0x00000001

#define _U2TXREG_UTXREG6_POSITION                0x00000006
#define _U2TXREG_UTXREG6_MASK                    0x00000040
#define _U2TXREG_UTXREG6_LENGTH                  0x00000001

#define _U2TXREG_UTXREG7_POSITION                0x00000007
#define _U2TXREG_UTXREG7_MASK                    0x00000080
#define _U2TXREG_UTXREG7_LENGTH                  0x00000001

#define _U2TXREG_UTXREG8_POSITION                0x00000008
#define _U2TXREG_UTXREG8_MASK                    0x00000100
#define _U2TXREG_UTXREG8_LENGTH                  0x00000001

#define _U2TXREG_UTX8_POSITION                   0x00000008
#define _U2TXREG_UTX8_MASK                       0x00000100
#define _U2TXREG_UTX8_LENGTH                     0x00000001

#define _U2RXREG_URXREG0_POSITION                0x00000000
#define _U2RXREG_URXREG0_MASK                    0x00000001
#define _U2RXREG_URXREG0_LENGTH                  0x00000001

#define _U2RXREG_URXREG1_POSITION                0x00000001
#define _U2RXREG_URXREG1_MASK                    0x00000002
#define _U2RXREG_URXREG1_LENGTH                  0x00000001

#define _U2RXREG_URXREG2_POSITION                0x00000002
#define _U2RXREG_URXREG2_MASK                    0x00000004
#define _U2RXREG_URXREG2_LENGTH                  0x00000001

#define _U2RXREG_URXREG3_POSITION                0x00000003
#define _U2RXREG_URXREG3_MASK                    0x00000008
#define _U2RXREG_URXREG3_LENGTH                  0x00000001

#define _U2RXREG_URXREG4_POSITION                0x00000004
#define _U2RXREG_URXREG4_MASK                    0x00000010
#define _U2RXREG_URXREG4_LENGTH                  0x00000001

#define _U2RXREG_URXREG5_POSITION                0x00000005
#define _U2RXREG_URXREG5_MASK                    0x00000020
#define _U2RXREG_URXREG5_LENGTH                  0x00000001

#define _U2RXREG_URXREG6_POSITION                0x00000006
#define _U2RXREG_URXREG6_MASK                    0x00000040
#define _U2RXREG_URXREG6_LENGTH                  0x00000001

#define _U2RXREG_URXREG7_POSITION                0x00000007
#define _U2RXREG_URXREG7_MASK                    0x00000080
#define _U2RXREG_URXREG7_LENGTH                  0x00000001

#define _U2RXREG_URXREG8_POSITION                0x00000008
#define _U2RXREG_URXREG8_MASK                    0x00000100
#define _U2RXREG_URXREG8_LENGTH                  0x00000001

#define _U2RXREG_URX8_POSITION                   0x00000008
#define _U2RXREG_URX8_MASK                       0x00000100
#define _U2RXREG_URX8_LENGTH                     0x00000001

#define _SPI1STAT_SPIRBF_POSITION                0x00000000
#define _SPI1STAT_SPIRBF_MASK                    0x00000001
#define _SPI1STAT_SPIRBF_LENGTH                  0x00000001

#define _SPI1STAT_SPITBF_POSITION                0x00000001
#define _SPI1STAT_SPITBF_MASK                    0x00000002
#define _SPI1STAT_SPITBF_LENGTH                  0x00000001

#define _SPI1STAT_SPIROV_POSITION                0x00000006
#define _SPI1STAT_SPIROV_MASK                    0x00000040
#define _SPI1STAT_SPIROV_LENGTH                  0x00000001

#define _SPI1STAT_SPISIDL_POSITION               0x0000000D
#define _SPI1STAT_SPISIDL_MASK                   0x00002000
#define _SPI1STAT_SPISIDL_LENGTH                 0x00000001

#define _SPI1STAT_SPIEN_POSITION                 0x0000000F
#define _SPI1STAT_SPIEN_MASK                     0x00008000
#define _SPI1STAT_SPIEN_LENGTH                   0x00000001

#define _SPI1CON_PPRE0_POSITION                  0x00000000
#define _SPI1CON_PPRE0_MASK                      0x00000001
#define _SPI1CON_PPRE0_LENGTH                    0x00000001

#define _SPI1CON_PPRE1_POSITION                  0x00000001
#define _SPI1CON_PPRE1_MASK                      0x00000002
#define _SPI1CON_PPRE1_LENGTH                    0x00000001

#define _SPI1CON_SPRE0_POSITION                  0x00000002
#define _SPI1CON_SPRE0_MASK                      0x00000004
#define _SPI1CON_SPRE0_LENGTH                    0x00000001

#define _SPI1CON_SPRE1_POSITION                  0x00000003
#define _SPI1CON_SPRE1_MASK                      0x00000008
#define _SPI1CON_SPRE1_LENGTH                    0x00000001

#define _SPI1CON_SPRE2_POSITION                  0x00000004
#define _SPI1CON_SPRE2_MASK                      0x00000010
#define _SPI1CON_SPRE2_LENGTH                    0x00000001

#define _SPI1CON_MSTEN_POSITION                  0x00000005
#define _SPI1CON_MSTEN_MASK                      0x00000020
#define _SPI1CON_MSTEN_LENGTH                    0x00000001

#define _SPI1CON_CKP_POSITION                    0x00000006
#define _SPI1CON_CKP_MASK                        0x00000040
#define _SPI1CON_CKP_LENGTH                      0x00000001

#define _SPI1CON_SSEN_POSITION                   0x00000007
#define _SPI1CON_SSEN_MASK                       0x00000080
#define _SPI1CON_SSEN_LENGTH                     0x00000001

#define _SPI1CON_CKE_POSITION                    0x00000008
#define _SPI1CON_CKE_MASK                        0x00000100
#define _SPI1CON_CKE_LENGTH                      0x00000001

#define _SPI1CON_SMP_POSITION                    0x00000009
#define _SPI1CON_SMP_MASK                        0x00000200
#define _SPI1CON_SMP_LENGTH                      0x00000001

#define _SPI1CON_MODE16_POSITION                 0x0000000A
#define _SPI1CON_MODE16_MASK                     0x00000400
#define _SPI1CON_MODE16_LENGTH                   0x00000001

#define _SPI1CON_DISSDO_POSITION                 0x0000000B
#define _SPI1CON_DISSDO_MASK                     0x00000800
#define _SPI1CON_DISSDO_LENGTH                   0x00000001

#define _SPI1CON_SPIFSD_POSITION                 0x0000000D
#define _SPI1CON_SPIFSD_MASK                     0x00002000
#define _SPI1CON_SPIFSD_LENGTH                   0x00000001

#define _SPI1CON_FRMEN_POSITION                  0x0000000E
#define _SPI1CON_FRMEN_MASK                      0x00004000
#define _SPI1CON_FRMEN_LENGTH                    0x00000001

#define _SPI1CON_PPRE_POSITION                   0x00000000
#define _SPI1CON_PPRE_MASK                       0x00000003
#define _SPI1CON_PPRE_LENGTH                     0x00000002

#define _SPI1CON_SPRE_POSITION                   0x00000002
#define _SPI1CON_SPRE_MASK                       0x0000001C
#define _SPI1CON_SPRE_LENGTH                     0x00000003

#define _ADCON1_DONE_POSITION                    0x00000000
#define _ADCON1_DONE_MASK                        0x00000001
#define _ADCON1_DONE_LENGTH                      0x00000001

#define _ADCON1_SAMP_POSITION                    0x00000001
#define _ADCON1_SAMP_MASK                        0x00000002
#define _ADCON1_SAMP_LENGTH                      0x00000001

#define _ADCON1_ASAM_POSITION                    0x00000002
#define _ADCON1_ASAM_MASK                        0x00000004
#define _ADCON1_ASAM_LENGTH                      0x00000001

#define _ADCON1_SSRC_POSITION                    0x00000005
#define _ADCON1_SSRC_MASK                        0x000000E0
#define _ADCON1_SSRC_LENGTH                      0x00000003

#define _ADCON1_FORM_POSITION                    0x00000008
#define _ADCON1_FORM_MASK                        0x00000300
#define _ADCON1_FORM_LENGTH                      0x00000002

#define _ADCON1_ADSIDL_POSITION                  0x0000000D
#define _ADCON1_ADSIDL_MASK                      0x00002000
#define _ADCON1_ADSIDL_LENGTH                    0x00000001

#define _ADCON1_ADON_POSITION                    0x0000000F
#define _ADCON1_ADON_MASK                        0x00008000
#define _ADCON1_ADON_LENGTH                      0x00000001

#define _ADCON1_SSRC0_POSITION                   0x00000005
#define _ADCON1_SSRC0_MASK                       0x00000020
#define _ADCON1_SSRC0_LENGTH                     0x00000001

#define _ADCON1_SSRC1_POSITION                   0x00000006
#define _ADCON1_SSRC1_MASK                       0x00000040
#define _ADCON1_SSRC1_LENGTH                     0x00000001

#define _ADCON1_SSRC2_POSITION                   0x00000007
#define _ADCON1_SSRC2_MASK                       0x00000080
#define _ADCON1_SSRC2_LENGTH                     0x00000001

#define _ADCON1_FORM0_POSITION                   0x00000008
#define _ADCON1_FORM0_MASK                       0x00000100
#define _ADCON1_FORM0_LENGTH                     0x00000001

#define _ADCON1_FORM1_POSITION                   0x00000009
#define _ADCON1_FORM1_MASK                       0x00000200
#define _ADCON1_FORM1_LENGTH                     0x00000001

#define _ADCON2_ALTS_POSITION                    0x00000000
#define _ADCON2_ALTS_MASK                        0x00000001
#define _ADCON2_ALTS_LENGTH                      0x00000001

#define _ADCON2_BUFM_POSITION                    0x00000001
#define _ADCON2_BUFM_MASK                        0x00000002
#define _ADCON2_BUFM_LENGTH                      0x00000001

#define _ADCON2_SMPI_POSITION                    0x00000002
#define _ADCON2_SMPI_MASK                        0x0000003C
#define _ADCON2_SMPI_LENGTH                      0x00000004

#define _ADCON2_BUFS_POSITION                    0x00000007
#define _ADCON2_BUFS_MASK                        0x00000080
#define _ADCON2_BUFS_LENGTH                      0x00000001

#define _ADCON2_CSCNA_POSITION                   0x0000000A
#define _ADCON2_CSCNA_MASK                       0x00000400
#define _ADCON2_CSCNA_LENGTH                     0x00000001

#define _ADCON2_VCFG_POSITION                    0x0000000D
#define _ADCON2_VCFG_MASK                        0x0000E000
#define _ADCON2_VCFG_LENGTH                      0x00000003

#define _ADCON2_SMPI0_POSITION                   0x00000002
#define _ADCON2_SMPI0_MASK                       0x00000004
#define _ADCON2_SMPI0_LENGTH                     0x00000001

#define _ADCON2_SMPI1_POSITION                   0x00000003
#define _ADCON2_SMPI1_MASK                       0x00000008
#define _ADCON2_SMPI1_LENGTH                     0x00000001

#define _ADCON2_SMPI2_POSITION                   0x00000004
#define _ADCON2_SMPI2_MASK                       0x00000010
#define _ADCON2_SMPI2_LENGTH                     0x00000001

#define _ADCON2_SMPI3_POSITION                   0x00000005
#define _ADCON2_SMPI3_MASK                       0x00000020
#define _ADCON2_SMPI3_LENGTH                     0x00000001

#define _ADCON2_VCFG0_POSITION                   0x0000000D
#define _ADCON2_VCFG0_MASK                       0x00002000
#define _ADCON2_VCFG0_LENGTH                     0x00000001

#define _ADCON2_VCFG1_POSITION                   0x0000000E
#define _ADCON2_VCFG1_MASK                       0x00004000
#define _ADCON2_VCFG1_LENGTH                     0x00000001

#define _ADCON2_VCFG2_POSITION                   0x0000000F
#define _ADCON2_VCFG2_MASK                       0x00008000
#define _ADCON2_VCFG2_LENGTH                     0x00000001

#define _ADCON3_ADCS_POSITION                    0x00000000
#define _ADCON3_ADCS_MASK                        0x0000003F
#define _ADCON3_ADCS_LENGTH                      0x00000006

#define _ADCON3_ADRC_POSITION                    0x00000007
#define _ADCON3_ADRC_MASK                        0x00000080
#define _ADCON3_ADRC_LENGTH                      0x00000001

#define _ADCON3_SAMC_POSITION                    0x00000008
#define _ADCON3_SAMC_MASK                        0x00001F00
#define _ADCON3_SAMC_LENGTH                      0x00000005

#define _ADCON3_ADCS0_POSITION                   0x00000000
#define _ADCON3_ADCS0_MASK                       0x00000001
#define _ADCON3_ADCS0_LENGTH                     0x00000001

#define _ADCON3_ADCS1_POSITION                   0x00000001
#define _ADCON3_ADCS1_MASK                       0x00000002
#define _ADCON3_ADCS1_LENGTH                     0x00000001

#define _ADCON3_ADCS2_POSITION                   0x00000002
#define _ADCON3_ADCS2_MASK                       0x00000004
#define _ADCON3_ADCS2_LENGTH                     0x00000001

#define _ADCON3_ADCS3_POSITION                   0x00000003
#define _ADCON3_ADCS3_MASK                       0x00000008
#define _ADCON3_ADCS3_LENGTH                     0x00000001

#define _ADCON3_ADCS4_POSITION                   0x00000004
#define _ADCON3_ADCS4_MASK                       0x00000010
#define _ADCON3_ADCS4_LENGTH                     0x00000001

#define _ADCON3_ADCS5_POSITION                   0x00000005
#define _ADCON3_ADCS5_MASK                       0x00000020
#define _ADCON3_ADCS5_LENGTH                     0x00000001

#define _ADCON3_SAMC0_POSITION                   0x00000008
#define _ADCON3_SAMC0_MASK                       0x00000100
#define _ADCON3_SAMC0_LENGTH                     0x00000001

#define _ADCON3_SAMC1_POSITION                   0x00000009
#define _ADCON3_SAMC1_MASK                       0x00000200
#define _ADCON3_SAMC1_LENGTH                     0x00000001

#define _ADCON3_SAMC2_POSITION                   0x0000000A
#define _ADCON3_SAMC2_MASK                       0x00000400
#define _ADCON3_SAMC2_LENGTH                     0x00000001

#define _ADCON3_SAMC3_POSITION                   0x0000000B
#define _ADCON3_SAMC3_MASK                       0x00000800
#define _ADCON3_SAMC3_LENGTH                     0x00000001

#define _ADCON3_SAMC4_POSITION                   0x0000000C
#define _ADCON3_SAMC4_MASK                       0x00001000
#define _ADCON3_SAMC4_LENGTH                     0x00000001

#define _ADCHS_CH0SA_POSITION                    0x00000000
#define _ADCHS_CH0SA_MASK                        0x0000000F
#define _ADCHS_CH0SA_LENGTH                      0x00000004

#define _ADCHS_CH0NA_POSITION                    0x00000004
#define _ADCHS_CH0NA_MASK                        0x00000010
#define _ADCHS_CH0NA_LENGTH                      0x00000001

#define _ADCHS_CH0SB_POSITION                    0x00000008
#define _ADCHS_CH0SB_MASK                        0x00000F00
#define _ADCHS_CH0SB_LENGTH                      0x00000004

#define _ADCHS_CH0NB_POSITION                    0x0000000C
#define _ADCHS_CH0NB_MASK                        0x00001000
#define _ADCHS_CH0NB_LENGTH                      0x00000001

#define _ADCHS_CH0SA0_POSITION                   0x00000000
#define _ADCHS_CH0SA0_MASK                       0x00000001
#define _ADCHS_CH0SA0_LENGTH                     0x00000001

#define _ADCHS_CH0SA1_POSITION                   0x00000001
#define _ADCHS_CH0SA1_MASK                       0x00000002
#define _ADCHS_CH0SA1_LENGTH                     0x00000001

#define _ADCHS_CH0SA2_POSITION                   0x00000002
#define _ADCHS_CH0SA2_MASK                       0x00000004
#define _ADCHS_CH0SA2_LENGTH                     0x00000001

#define _ADCHS_CH0SA3_POSITION                   0x00000003
#define _ADCHS_CH0SA3_MASK                       0x00000008
#define _ADCHS_CH0SA3_LENGTH                     0x00000001

#define _ADCHS_CH0SB0_POSITION                   0x00000008
#define _ADCHS_CH0SB0_MASK                       0x00000100
#define _ADCHS_CH0SB0_LENGTH                     0x00000001

#define _ADCHS_CH0SB1_POSITION                   0x00000009
#define _ADCHS_CH0SB1_MASK                       0x00000200
#define _ADCHS_CH0SB1_LENGTH                     0x00000001

#define _ADCHS_CH0SB2_POSITION                   0x0000000A
#define _ADCHS_CH0SB2_MASK                       0x00000400
#define _ADCHS_CH0SB2_LENGTH                     0x00000001

#define _ADCHS_CH0SB3_POSITION                   0x0000000B
#define _ADCHS_CH0SB3_MASK                       0x00000800
#define _ADCHS_CH0SB3_LENGTH                     0x00000001

#define _ADPCFG_PCFG0_POSITION                   0x00000000
#define _ADPCFG_PCFG0_MASK                       0x00000001
#define _ADPCFG_PCFG0_LENGTH                     0x00000001

#define _ADPCFG_PCFG1_POSITION                   0x00000001
#define _ADPCFG_PCFG1_MASK                       0x00000002
#define _ADPCFG_PCFG1_LENGTH                     0x00000001

#define _ADPCFG_PCFG2_POSITION                   0x00000002
#define _ADPCFG_PCFG2_MASK                       0x00000004
#define _ADPCFG_PCFG2_LENGTH                     0x00000001

#define _ADPCFG_PCFG3_POSITION                   0x00000003
#define _ADPCFG_PCFG3_MASK                       0x00000008
#define _ADPCFG_PCFG3_LENGTH                     0x00000001

#define _ADPCFG_PCFG4_POSITION                   0x00000004
#define _ADPCFG_PCFG4_MASK                       0x00000010
#define _ADPCFG_PCFG4_LENGTH                     0x00000001

#define _ADPCFG_PCFG5_POSITION                   0x00000005
#define _ADPCFG_PCFG5_MASK                       0x00000020
#define _ADPCFG_PCFG5_LENGTH                     0x00000001

#define _ADPCFG_PCFG6_POSITION                   0x00000006
#define _ADPCFG_PCFG6_MASK                       0x00000040
#define _ADPCFG_PCFG6_LENGTH                     0x00000001

#define _ADPCFG_PCFG7_POSITION                   0x00000007
#define _ADPCFG_PCFG7_MASK                       0x00000080
#define _ADPCFG_PCFG7_LENGTH                     0x00000001

#define _ADPCFG_PCFG8_POSITION                   0x00000008
#define _ADPCFG_PCFG8_MASK                       0x00000100
#define _ADPCFG_PCFG8_LENGTH                     0x00000001

#define _ADPCFG_PCFG9_POSITION                   0x00000009
#define _ADPCFG_PCFG9_MASK                       0x00000200
#define _ADPCFG_PCFG9_LENGTH                     0x00000001

#define _ADCSSL_CSSL0_POSITION                   0x00000000
#define _ADCSSL_CSSL0_MASK                       0x00000001
#define _ADCSSL_CSSL0_LENGTH                     0x00000001

#define _ADCSSL_CSSL1_POSITION                   0x00000001
#define _ADCSSL_CSSL1_MASK                       0x00000002
#define _ADCSSL_CSSL1_LENGTH                     0x00000001

#define _ADCSSL_CSSL2_POSITION                   0x00000002
#define _ADCSSL_CSSL2_MASK                       0x00000004
#define _ADCSSL_CSSL2_LENGTH                     0x00000001

#define _ADCSSL_CSSL3_POSITION                   0x00000003
#define _ADCSSL_CSSL3_MASK                       0x00000008
#define _ADCSSL_CSSL3_LENGTH                     0x00000001

#define _ADCSSL_CSSL4_POSITION                   0x00000004
#define _ADCSSL_CSSL4_MASK                       0x00000010
#define _ADCSSL_CSSL4_LENGTH                     0x00000001

#define _ADCSSL_CSSL5_POSITION                   0x00000005
#define _ADCSSL_CSSL5_MASK                       0x00000020
#define _ADCSSL_CSSL5_LENGTH                     0x00000001

#define _ADCSSL_CSSL6_POSITION                   0x00000006
#define _ADCSSL_CSSL6_MASK                       0x00000040
#define _ADCSSL_CSSL6_LENGTH                     0x00000001

#define _ADCSSL_CSSL7_POSITION                   0x00000007
#define _ADCSSL_CSSL7_MASK                       0x00000080
#define _ADCSSL_CSSL7_LENGTH                     0x00000001

#define _ADCSSL_CSSL8_POSITION                   0x00000008
#define _ADCSSL_CSSL8_MASK                       0x00000100
#define _ADCSSL_CSSL8_LENGTH                     0x00000001

#define _ADCSSL_CSSL9_POSITION                   0x00000009
#define _ADCSSL_CSSL9_MASK                       0x00000200
#define _ADCSSL_CSSL9_LENGTH                     0x00000001

#define _TRISB_TRISB0_POSITION                   0x00000000
#define _TRISB_TRISB0_MASK                       0x00000001
#define _TRISB_TRISB0_LENGTH                     0x00000001

#define _TRISB_TRISB1_POSITION                   0x00000001
#define _TRISB_TRISB1_MASK                       0x00000002
#define _TRISB_TRISB1_LENGTH                     0x00000001

#define _TRISB_TRISB2_POSITION                   0x00000002
#define _TRISB_TRISB2_MASK                       0x00000004
#define _TRISB_TRISB2_LENGTH                     0x00000001

#define _TRISB_TRISB3_POSITION                   0x00000003
#define _TRISB_TRISB3_MASK                       0x00000008
#define _TRISB_TRISB3_LENGTH                     0x00000001

#define _TRISB_TRISB4_POSITION                   0x00000004
#define _TRISB_TRISB4_MASK                       0x00000010
#define _TRISB_TRISB4_LENGTH                     0x00000001

#define _TRISB_TRISB5_POSITION                   0x00000005
#define _TRISB_TRISB5_MASK                       0x00000020
#define _TRISB_TRISB5_LENGTH                     0x00000001

#define _TRISB_TRISB6_POSITION                   0x00000006
#define _TRISB_TRISB6_MASK                       0x00000040
#define _TRISB_TRISB6_LENGTH                     0x00000001

#define _TRISB_TRISB7_POSITION                   0x00000007
#define _TRISB_TRISB7_MASK                       0x00000080
#define _TRISB_TRISB7_LENGTH                     0x00000001

#define _TRISB_TRISB8_POSITION                   0x00000008
#define _TRISB_TRISB8_MASK                       0x00000100
#define _TRISB_TRISB8_LENGTH                     0x00000001

#define _TRISB_TRISB9_POSITION                   0x00000009
#define _TRISB_TRISB9_MASK                       0x00000200
#define _TRISB_TRISB9_LENGTH                     0x00000001

#define _PORTB_RB0_POSITION                      0x00000000
#define _PORTB_RB0_MASK                          0x00000001
#define _PORTB_RB0_LENGTH                        0x00000001

#define _PORTB_RB1_POSITION                      0x00000001
#define _PORTB_RB1_MASK                          0x00000002
#define _PORTB_RB1_LENGTH                        0x00000001

#define _PORTB_RB2_POSITION                      0x00000002
#define _PORTB_RB2_MASK                          0x00000004
#define _PORTB_RB2_LENGTH                        0x00000001

#define _PORTB_RB3_POSITION                      0x00000003
#define _PORTB_RB3_MASK                          0x00000008
#define _PORTB_RB3_LENGTH                        0x00000001

#define _PORTB_RB4_POSITION                      0x00000004
#define _PORTB_RB4_MASK                          0x00000010
#define _PORTB_RB4_LENGTH                        0x00000001

#define _PORTB_RB5_POSITION                      0x00000005
#define _PORTB_RB5_MASK                          0x00000020
#define _PORTB_RB5_LENGTH                        0x00000001

#define _PORTB_RB6_POSITION                      0x00000006
#define _PORTB_RB6_MASK                          0x00000040
#define _PORTB_RB6_LENGTH                        0x00000001

#define _PORTB_RB7_POSITION                      0x00000007
#define _PORTB_RB7_MASK                          0x00000080
#define _PORTB_RB7_LENGTH                        0x00000001

#define _PORTB_RB8_POSITION                      0x00000008
#define _PORTB_RB8_MASK                          0x00000100
#define _PORTB_RB8_LENGTH                        0x00000001

#define _PORTB_RB9_POSITION                      0x00000009
#define _PORTB_RB9_MASK                          0x00000200
#define _PORTB_RB9_LENGTH                        0x00000001

#define _LATB_LATB0_POSITION                     0x00000000
#define _LATB_LATB0_MASK                         0x00000001
#define _LATB_LATB0_LENGTH                       0x00000001

#define _LATB_LATB1_POSITION                     0x00000001
#define _LATB_LATB1_MASK                         0x00000002
#define _LATB_LATB1_LENGTH                       0x00000001

#define _LATB_LATB2_POSITION                     0x00000002
#define _LATB_LATB2_MASK                         0x00000004
#define _LATB_LATB2_LENGTH                       0x00000001

#define _LATB_LATB3_POSITION                     0x00000003
#define _LATB_LATB3_MASK                         0x00000008
#define _LATB_LATB3_LENGTH                       0x00000001

#define _LATB_LATB4_POSITION                     0x00000004
#define _LATB_LATB4_MASK                         0x00000010
#define _LATB_LATB4_LENGTH                       0x00000001

#define _LATB_LATB5_POSITION                     0x00000005
#define _LATB_LATB5_MASK                         0x00000020
#define _LATB_LATB5_LENGTH                       0x00000001

#define _LATB_LATB6_POSITION                     0x00000006
#define _LATB_LATB6_MASK                         0x00000040
#define _LATB_LATB6_LENGTH                       0x00000001

#define _LATB_LATB7_POSITION                     0x00000007
#define _LATB_LATB7_MASK                         0x00000080
#define _LATB_LATB7_LENGTH                       0x00000001

#define _LATB_LATB8_POSITION                     0x00000008
#define _LATB_LATB8_MASK                         0x00000100
#define _LATB_LATB8_LENGTH                       0x00000001

#define _LATB_LATB9_POSITION                     0x00000009
#define _LATB_LATB9_MASK                         0x00000200
#define _LATB_LATB9_LENGTH                       0x00000001

#define _TRISC_TRISC13_POSITION                  0x0000000D
#define _TRISC_TRISC13_MASK                      0x00002000
#define _TRISC_TRISC13_LENGTH                    0x00000001

#define _TRISC_TRISC14_POSITION                  0x0000000E
#define _TRISC_TRISC14_MASK                      0x00004000
#define _TRISC_TRISC14_LENGTH                    0x00000001

#define _TRISC_TRISC15_POSITION                  0x0000000F
#define _TRISC_TRISC15_MASK                      0x00008000
#define _TRISC_TRISC15_LENGTH                    0x00000001

#define _PORTC_RC13_POSITION                     0x0000000D
#define _PORTC_RC13_MASK                         0x00002000
#define _PORTC_RC13_LENGTH                       0x00000001

#define _PORTC_RC14_POSITION                     0x0000000E
#define _PORTC_RC14_MASK                         0x00004000
#define _PORTC_RC14_LENGTH                       0x00000001

#define _PORTC_RC15_POSITION                     0x0000000F
#define _PORTC_RC15_MASK                         0x00008000
#define _PORTC_RC15_LENGTH                       0x00000001

#define _LATC_LATC13_POSITION                    0x0000000D
#define _LATC_LATC13_MASK                        0x00002000
#define _LATC_LATC13_LENGTH                      0x00000001

#define _LATC_LATC14_POSITION                    0x0000000E
#define _LATC_LATC14_MASK                        0x00004000
#define _LATC_LATC14_LENGTH                      0x00000001

#define _LATC_LATC15_POSITION                    0x0000000F
#define _LATC_LATC15_MASK                        0x00008000
#define _LATC_LATC15_LENGTH                      0x00000001

#define _TRISD_TRISD8_POSITION                   0x00000008
#define _TRISD_TRISD8_MASK                       0x00000100
#define _TRISD_TRISD8_LENGTH                     0x00000001

#define _TRISD_TRISD9_POSITION                   0x00000009
#define _TRISD_TRISD9_MASK                       0x00000200
#define _TRISD_TRISD9_LENGTH                     0x00000001

#define _PORTD_RD8_POSITION                      0x00000008
#define _PORTD_RD8_MASK                          0x00000100
#define _PORTD_RD8_LENGTH                        0x00000001

#define _PORTD_RD9_POSITION                      0x00000009
#define _PORTD_RD9_MASK                          0x00000200
#define _PORTD_RD9_LENGTH                        0x00000001

#define _LATD_LATD8_POSITION                     0x00000008
#define _LATD_LATD8_MASK                         0x00000100
#define _LATD_LATD8_LENGTH                       0x00000001

#define _LATD_LATD9_POSITION                     0x00000009
#define _LATD_LATD9_MASK                         0x00000200
#define _LATD_LATD9_LENGTH                       0x00000001

#define _TRISF_TRISF2_POSITION                   0x00000002
#define _TRISF_TRISF2_MASK                       0x00000004
#define _TRISF_TRISF2_LENGTH                     0x00000001

#define _TRISF_TRISF3_POSITION                   0x00000003
#define _TRISF_TRISF3_MASK                       0x00000008
#define _TRISF_TRISF3_LENGTH                     0x00000001

#define _TRISF_TRISF4_POSITION                   0x00000004
#define _TRISF_TRISF4_MASK                       0x00000010
#define _TRISF_TRISF4_LENGTH                     0x00000001

#define _TRISF_TRISF5_POSITION                   0x00000005
#define _TRISF_TRISF5_MASK                       0x00000020
#define _TRISF_TRISF5_LENGTH                     0x00000001

#define _TRISF_TRISF6_POSITION                   0x00000006
#define _TRISF_TRISF6_MASK                       0x00000040
#define _TRISF_TRISF6_LENGTH                     0x00000001

#define _PORTF_RF2_POSITION                      0x00000002
#define _PORTF_RF2_MASK                          0x00000004
#define _PORTF_RF2_LENGTH                        0x00000001

#define _PORTF_RF3_POSITION                      0x00000003
#define _PORTF_RF3_MASK                          0x00000008
#define _PORTF_RF3_LENGTH                        0x00000001

#define _PORTF_RF4_POSITION                      0x00000004
#define _PORTF_RF4_MASK                          0x00000010
#define _PORTF_RF4_LENGTH                        0x00000001

#define _PORTF_RF5_POSITION                      0x00000005
#define _PORTF_RF5_MASK                          0x00000020
#define _PORTF_RF5_LENGTH                        0x00000001

#define _PORTF_RF6_POSITION                      0x00000006
#define _PORTF_RF6_MASK                          0x00000040
#define _PORTF_RF6_LENGTH                        0x00000001

#define _LATF_LATF2_POSITION                     0x00000002
#define _LATF_LATF2_MASK                         0x00000004
#define _LATF_LATF2_LENGTH                       0x00000001

#define _LATF_LATF3_POSITION                     0x00000003
#define _LATF_LATF3_MASK                         0x00000008
#define _LATF_LATF3_LENGTH                       0x00000001

#define _LATF_LATF4_POSITION                     0x00000004
#define _LATF_LATF4_MASK                         0x00000010
#define _LATF_LATF4_LENGTH                       0x00000001

#define _LATF_LATF5_POSITION                     0x00000005
#define _LATF_LATF5_MASK                         0x00000020
#define _LATF_LATF5_LENGTH                       0x00000001

#define _LATF_LATF6_POSITION                     0x00000006
#define _LATF_LATF6_MASK                         0x00000040
#define _LATF_LATF6_LENGTH                       0x00000001

#define _RCON_POR_POSITION                       0x00000000
#define _RCON_POR_MASK                           0x00000001
#define _RCON_POR_LENGTH                         0x00000001

#define _RCON_BOR_POSITION                       0x00000001
#define _RCON_BOR_MASK                           0x00000002
#define _RCON_BOR_LENGTH                         0x00000001

#define _RCON_IDLE_POSITION                      0x00000002
#define _RCON_IDLE_MASK                          0x00000004
#define _RCON_IDLE_LENGTH                        0x00000001

#define _RCON_SLEEP_POSITION                     0x00000003
#define _RCON_SLEEP_MASK                         0x00000008
#define _RCON_SLEEP_LENGTH                       0x00000001

#define _RCON_WDTO_POSITION                      0x00000004
#define _RCON_WDTO_MASK                          0x00000010
#define _RCON_WDTO_LENGTH                        0x00000001

#define _RCON_SWDTEN_POSITION                    0x00000005
#define _RCON_SWDTEN_MASK                        0x00000020
#define _RCON_SWDTEN_LENGTH                      0x00000001

#define _RCON_SWR_POSITION                       0x00000006
#define _RCON_SWR_MASK                           0x00000040
#define _RCON_SWR_LENGTH                         0x00000001

#define _RCON_EXTR_POSITION                      0x00000007
#define _RCON_EXTR_MASK                          0x00000080
#define _RCON_EXTR_LENGTH                        0x00000001

#define _RCON_LVDL_POSITION                      0x00000008
#define _RCON_LVDL_MASK                          0x00000F00
#define _RCON_LVDL_LENGTH                        0x00000004

#define _RCON_LVDEN_POSITION                     0x0000000C
#define _RCON_LVDEN_MASK                         0x00001000
#define _RCON_LVDEN_LENGTH                       0x00000001

#define _RCON_BGST_POSITION                      0x0000000D
#define _RCON_BGST_MASK                          0x00002000
#define _RCON_BGST_LENGTH                        0x00000001

#define _RCON_IOPUWR_POSITION                    0x0000000E
#define _RCON_IOPUWR_MASK                        0x00004000
#define _RCON_IOPUWR_LENGTH                      0x00000001

#define _RCON_TRAPR_POSITION                     0x0000000F
#define _RCON_TRAPR_MASK                         0x00008000
#define _RCON_TRAPR_LENGTH                       0x00000001

#define _RCON_LVDL0_POSITION                     0x00000008
#define _RCON_LVDL0_MASK                         0x00000100
#define _RCON_LVDL0_LENGTH                       0x00000001

#define _RCON_LVDL1_POSITION                     0x00000009
#define _RCON_LVDL1_MASK                         0x00000200
#define _RCON_LVDL1_LENGTH                       0x00000001

#define _RCON_LVDL2_POSITION                     0x0000000A
#define _RCON_LVDL2_MASK                         0x00000400
#define _RCON_LVDL2_LENGTH                       0x00000001

#define _RCON_LVDL3_POSITION                     0x0000000B
#define _RCON_LVDL3_MASK                         0x00000800
#define _RCON_LVDL3_LENGTH                       0x00000001

#define _OSCCON_OSWEN_POSITION                   0x00000000
#define _OSCCON_OSWEN_MASK                       0x00000001
#define _OSCCON_OSWEN_LENGTH                     0x00000001

#define _OSCCON_LPOSCEN_POSITION                 0x00000001
#define _OSCCON_LPOSCEN_MASK                     0x00000002
#define _OSCCON_LPOSCEN_LENGTH                   0x00000001

#define _OSCCON_CF_POSITION                      0x00000003
#define _OSCCON_CF_MASK                          0x00000008
#define _OSCCON_CF_LENGTH                        0x00000001

#define _OSCCON_LOCK_POSITION                    0x00000005
#define _OSCCON_LOCK_MASK                        0x00000020
#define _OSCCON_LOCK_LENGTH                      0x00000001

#define _OSCCON_POST_POSITION                    0x00000006
#define _OSCCON_POST_MASK                        0x000000C0
#define _OSCCON_POST_LENGTH                      0x00000002

#define _OSCCON_NOSC_POSITION                    0x00000008
#define _OSCCON_NOSC_MASK                        0x00000700
#define _OSCCON_NOSC_LENGTH                      0x00000003

#define _OSCCON_COSC_POSITION                    0x0000000C
#define _OSCCON_COSC_MASK                        0x00007000
#define _OSCCON_COSC_LENGTH                      0x00000003

#define _OSCCON_POST0_POSITION                   0x00000006
#define _OSCCON_POST0_MASK                       0x00000040
#define _OSCCON_POST0_LENGTH                     0x00000001

#define _OSCCON_POST1_POSITION                   0x00000007
#define _OSCCON_POST1_MASK                       0x00000080
#define _OSCCON_POST1_LENGTH                     0x00000001

#define _OSCCON_NOSC0_POSITION                   0x00000008
#define _OSCCON_NOSC0_MASK                       0x00000100
#define _OSCCON_NOSC0_LENGTH                     0x00000001

#define _OSCCON_NOSC1_POSITION                   0x00000009
#define _OSCCON_NOSC1_MASK                       0x00000200
#define _OSCCON_NOSC1_LENGTH                     0x00000001

#define _OSCCON_NOSC2_POSITION                   0x0000000A
#define _OSCCON_NOSC2_MASK                       0x00000400
#define _OSCCON_NOSC2_LENGTH                     0x00000001

#define _OSCCON_COSC0_POSITION                   0x0000000C
#define _OSCCON_COSC0_MASK                       0x00001000
#define _OSCCON_COSC0_LENGTH                     0x00000001

#define _OSCCON_COSC1_POSITION                   0x0000000D
#define _OSCCON_COSC1_MASK                       0x00002000
#define _OSCCON_COSC1_LENGTH                     0x00000001

#define _OSCCON_COSC2_POSITION                   0x0000000E
#define _OSCCON_COSC2_MASK                       0x00004000
#define _OSCCON_COSC2_LENGTH                     0x00000001

#define _OSCTUN_TUN0_POSITION                    0x00000000
#define _OSCTUN_TUN0_MASK                        0x00000001
#define _OSCTUN_TUN0_LENGTH                      0x00000001

#define _OSCTUN_TUN1_POSITION                    0x00000001
#define _OSCTUN_TUN1_MASK                        0x00000002
#define _OSCTUN_TUN1_LENGTH                      0x00000001

#define _OSCTUN_TUN2_POSITION                    0x00000002
#define _OSCTUN_TUN2_MASK                        0x00000004
#define _OSCTUN_TUN2_LENGTH                      0x00000001

#define _OSCTUN_TUN3_POSITION                    0x00000003
#define _OSCTUN_TUN3_MASK                        0x00000008
#define _OSCTUN_TUN3_LENGTH                      0x00000001

#define _NVMCON_PROGOP_POSITION                  0x00000000
#define _NVMCON_PROGOP_MASK                      0x0000007F
#define _NVMCON_PROGOP_LENGTH                    0x00000007

#define _NVMCON_TWRI_POSITION                    0x00000008
#define _NVMCON_TWRI_MASK                        0x00000100
#define _NVMCON_TWRI_LENGTH                      0x00000001

#define _NVMCON_WRERR_POSITION                   0x0000000D
#define _NVMCON_WRERR_MASK                       0x00002000
#define _NVMCON_WRERR_LENGTH                     0x00000001

#define _NVMCON_WREN_POSITION                    0x0000000E
#define _NVMCON_WREN_MASK                        0x00004000
#define _NVMCON_WREN_LENGTH                      0x00000001

#define _NVMCON_WR_POSITION                      0x0000000F
#define _NVMCON_WR_MASK                          0x00008000
#define _NVMCON_WR_LENGTH                        0x00000001

#define _NVMCON_PROGOP0_POSITION                 0x00000000
#define _NVMCON_PROGOP0_MASK                     0x00000001
#define _NVMCON_PROGOP0_LENGTH                   0x00000001

#define _NVMCON_PROGOP1_POSITION                 0x00000001
#define _NVMCON_PROGOP1_MASK                     0x00000002
#define _NVMCON_PROGOP1_LENGTH                   0x00000001

#define _NVMCON_PROGOP2_POSITION                 0x00000002
#define _NVMCON_PROGOP2_MASK                     0x00000004
#define _NVMCON_PROGOP2_LENGTH                   0x00000001

#define _NVMCON_PROGOP3_POSITION                 0x00000003
#define _NVMCON_PROGOP3_MASK                     0x00000008
#define _NVMCON_PROGOP3_LENGTH                   0x00000001

#define _NVMCON_PROGOP4_POSITION                 0x00000004
#define _NVMCON_PROGOP4_MASK                     0x00000010
#define _NVMCON_PROGOP4_LENGTH                   0x00000001

#define _NVMCON_PROGOP5_POSITION                 0x00000005
#define _NVMCON_PROGOP5_MASK                     0x00000020
#define _NVMCON_PROGOP5_LENGTH                   0x00000001

#define _NVMCON_PROGOP6_POSITION                 0x00000006
#define _NVMCON_PROGOP6_MASK                     0x00000040
#define _NVMCON_PROGOP6_LENGTH                   0x00000001

#define _NVMADRU_NVMADR_POSITION                 0x00000000
#define _NVMADRU_NVMADR_MASK                     0x000000FF
#define _NVMADRU_NVMADR_LENGTH                   0x00000008

#define _PMD1_ADCMD_POSITION                     0x00000000
#define _PMD1_ADCMD_MASK                         0x00000001
#define _PMD1_ADCMD_LENGTH                       0x00000001

#define _PMD1_SPI1MD_POSITION                    0x00000003
#define _PMD1_SPI1MD_MASK                        0x00000008
#define _PMD1_SPI1MD_LENGTH                      0x00000001

#define _PMD1_U1MD_POSITION                      0x00000005
#define _PMD1_U1MD_MASK                          0x00000020
#define _PMD1_U1MD_LENGTH                        0x00000001

#define _PMD1_U2MD_POSITION                      0x00000006
#define _PMD1_U2MD_MASK                          0x00000040
#define _PMD1_U2MD_LENGTH                        0x00000001

#define _PMD1_I2CMD_POSITION                     0x00000007
#define _PMD1_I2CMD_MASK                         0x00000080
#define _PMD1_I2CMD_LENGTH                       0x00000001

#define _PMD1_T1MD_POSITION                      0x0000000B
#define _PMD1_T1MD_MASK                          0x00000800
#define _PMD1_T1MD_LENGTH                        0x00000001

#define _PMD1_T2MD_POSITION                      0x0000000C
#define _PMD1_T2MD_MASK                          0x00001000
#define _PMD1_T2MD_LENGTH                        0x00000001

#define _PMD1_T3MD_POSITION                      0x0000000D
#define _PMD1_T3MD_MASK                          0x00002000
#define _PMD1_T3MD_LENGTH                        0x00000001

#define _PMD2_OC1MD_POSITION                     0x00000000
#define _PMD2_OC1MD_MASK                         0x00000001
#define _PMD2_OC1MD_LENGTH                       0x00000001

#define _PMD2_OC2MD_POSITION                     0x00000001
#define _PMD2_OC2MD_MASK                         0x00000002
#define _PMD2_OC2MD_LENGTH                       0x00000001

#define _PMD2_IC1MD_POSITION                     0x00000008
#define _PMD2_IC1MD_MASK                         0x00000100
#define _PMD2_IC1MD_LENGTH                       0x00000001

#define _PMD2_IC2MD_POSITION                     0x00000009
#define _PMD2_IC2MD_MASK                         0x00000200
#define _PMD2_IC2MD_LENGTH                       0x00000001



/* -------------------------------------------------------- */
/* Macros for setting device configuration registers        */
/* -------------------------------------------------------- */

/* Register FUID0 (0x8005c0)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FUID0;
#define _FUID0(x) __attribute__((address(0x8005c0),deprecated_definition("consider migrating to #pragma config"),section("__FUID0.sec"),space(prog))) __prog__ uint16_t _FUID0 = (x);

/*
** Only one invocation of FUID0 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID0.
** Multiple options may be combined, as shown:
**
** _FUID0( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   :
**
*/


/* Register FUID1 (0x8005c2)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FUID1;
#define _FUID1(x) __attribute__((address(0x8005c2),deprecated_definition("consider migrating to #pragma config"),section("__FUID1.sec"),space(prog))) __prog__ uint16_t _FUID1 = (x);

/*
** Only one invocation of FUID1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID1.
** Multiple options may be combined, as shown:
**
** _FUID1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   :
**
*/


/* Register FUID2 (0x8005c4)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FUID2;
#define _FUID2(x) __attribute__((address(0x8005c4),deprecated_definition("consider migrating to #pragma config"),section("__FUID2.sec"),space(prog))) __prog__ uint16_t _FUID2 = (x);

/*
** Only one invocation of FUID2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID2.
** Multiple options may be combined, as shown:
**
** _FUID2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   :
**
*/


/* Register FUID3 (0x8005c6)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FUID3;
#define _FUID3(x) __attribute__((address(0x8005c6),deprecated_definition("consider migrating to #pragma config"),section("__FUID3.sec"),space(prog))) __prog__ uint16_t _FUID3 = (x);

/*
** Only one invocation of FUID3 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FUID3.
** Multiple options may be combined, as shown:
**
** _FUID3( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   :
**
*/


/* Register FOSC (0xf80000)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FOSC;
#define _FOSC(x) __attribute__((address(0xf80000),deprecated_definition("consider migrating to #pragma config"),section("__FOSC.sec"),space(prog))) __prog__ uint16_t _FOSC = (x);

/*
** Only one invocation of FOSC should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FOSC.
** Multiple options may be combined, as shown:
**
** _FOSC( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Oscillator:
**     LP                   Low-Power 32KHz Osc (No change to Primary Osc Mode bits)
**     FRC                  Internal Fast RC (No change to Primary Osc Mode bits)
**     LPRC                 Internal Low-Power RC (No change to Primary Osc Mode bits)
**     XTL                  XTL
**     HS                   HS
**     XT                   XT
**     ERCIO                ERCIO
**     ERC                  ERC
**     EC                   EC
**     ECIO                 ECIO
**     FRC_PLL4             FRC w/PLL 4x
**     FRC_PLL16            FRC w/PLL 16x
**     XT_PLL4              XT w/PLL 4x
**     XT_PLL8              XT w/PLL 8x
**     XT_PLL16             XT w/PLL 16x
**     FRC_PLL8             FRC w/PLL 8x
**     ECIO_PLL4            ECIO w/PLL 4x
**     ECIO_PLL8            ECIO w/PLL 8x
**     ECIO_PLL16           ECIO w/PLL 16x
**     HS2_PLL4             HS2 w/PLL 4x
**     HS2_PLL8             HS2 w/PLL 8x
**     HS2_PLL16            HS2 w/PLL 16x
**     HS3_PLL4             HS3 w/PLL 4x
**     HS3_PLL8             HS3 w/PLL 8x
**     HS3_PLL16            HS3 w/PLL 16x
**
**   Clock Switching and Monitor:
**     CSW_FSCM_ON          Sw Enabled, Mon Enabled
**     CSW_ON_FSCM_OFF      Sw Enabled, Mon Disabled
**     CSW_FSCM_OFF         Sw Disabled, Mon Disabled
**
*/

#define LP                   0xC000
#define FRC                  0xC100
#define LPRC                 0xC200
#define XTL                  0xC300
#define HS                   0xC302
#define XT                   0xC304
#define ERCIO                0xC308
#define ERC                  0xC309
#define EC                   0xC30B
#define ECIO                 0xC30C
#define FRC_PLL4             0xC701
#define FRC_PLL16            0xC703
#define XT_PLL4              0xC705
#define XT_PLL8              0xC706
#define XT_PLL16             0xC707
#define FRC_PLL8             0xC70A
#define ECIO_PLL4            0xC70D
#define ECIO_PLL8            0xC70E
#define ECIO_PLL16           0xC70F
#define HS2_PLL4             0xC711
#define HS2_PLL8             0xC712
#define HS2_PLL16            0xC713
#define HS3_PLL4             0xC715
#define HS3_PLL8             0xC716
#define HS3_PLL16            0xC717

#define CSW_FSCM_ON          0x071F
#define CSW_ON_FSCM_OFF      0x471F
#define CSW_FSCM_OFF         0x871F

/* Register FWDT (0xf80002)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FWDT;
#define _FWDT(x) __attribute__((address(0xf80002),deprecated_definition("consider migrating to #pragma config"),section("__FWDT.sec"),space(prog))) __prog__ uint16_t _FWDT = (x);

/*
** Only one invocation of FWDT should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FWDT.
** Multiple options may be combined, as shown:
**
** _FWDT( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   WDT Prescaler B:
**     WDTPSB_1             1:1
**     WDTPSB_2             1:2
**     WDTPSB_3             1:3
**     WDTPSB_4             1:4
**     WDTPSB_5             1:5
**     WDTPSB_6             1:6
**     WDTPSB_7             1:7
**     WDTPSB_8             1:8
**     WDTPSB_9             1:9
**     WDTPSB_10            1:10
**     WDTPSB_11            1:11
**     WDTPSB_12            1:12
**     WDTPSB_13            1:13
**     WDTPSB_14            1:14
**     WDTPSB_15            1:15
**     WDTPSB_16            1:16
**
**   WDT Prescaler A:
**     WDTPSA_1             1:1
**     WDTPSA_8             1:8
**     WDTPSA_64            1:64
**     WDTPSA_512           1:512
**
**   Watchdog Timer:
**     WDT_OFF              Disabled
**     WDT_ON               Enabled
**
*/

#define WDTPSB_1             0x8030
#define WDTPSB_2             0x8031
#define WDTPSB_3             0x8032
#define WDTPSB_4             0x8033
#define WDTPSB_5             0x8034
#define WDTPSB_6             0x8035
#define WDTPSB_7             0x8036
#define WDTPSB_8             0x8037
#define WDTPSB_9             0x8038
#define WDTPSB_10            0x8039
#define WDTPSB_11            0x803A
#define WDTPSB_12            0x803B
#define WDTPSB_13            0x803C
#define WDTPSB_14            0x803D
#define WDTPSB_15            0x803E
#define WDTPSB_16            0x803F

#define WDTPSA_1             0x800F
#define WDTPSA_8             0x801F
#define WDTPSA_64            0x802F
#define WDTPSA_512           0x803F

#define WDT_OFF              0x003F
#define WDT_ON               0x803F

/* Register FBORPOR (0xf80004)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FBORPOR;
#define _FBORPOR(x) __attribute__((address(0xf80004),deprecated_definition("consider migrating to #pragma config"),section("__FBORPOR.sec"),space(prog))) __prog__ uint16_t _FBORPOR = (x);

/*
** Only one invocation of FBORPOR should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FBORPOR.
** Multiple options may be combined, as shown:
**
** _FBORPOR( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   POR Timer Value:
**     PWRT_OFF             Timer Disabled
**     PWRT_4               4ms
**     PWRT_16              16ms
**     PWRT_64              64ms
**
**   Brown Out Voltage:
**     BORV45               4.5V
**     BORV42               4.2V
**     BORV27               2.7V
**     BORV20               Reserved
**
**   PBOR Enable:
**     PBOR_OFF             Disabled
**     PBOR_ON              Enabled
**
**   Master Clear Enable:
**     MCLR_DIS             Disabled
**     MCLR_EN              Enabled
**
*/

#define PWRT_OFF             0x87B0
#define PWRT_4               0x87B1
#define PWRT_16              0x87B2
#define PWRT_64              0x87B3

#define BORV45               0x8783
#define BORV42               0x8793
#define BORV27               0x87A3
#define BORV20               0x87B3

#define PBOR_OFF             0x8733
#define PBOR_ON              0x87B3

#define MCLR_DIS             0x07B3
#define MCLR_EN              0x87B3

/* Register RESERVED1 (0xf80006)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _RESERVED1;
#define _RESERVED1(x) __attribute__((address(0xf80006),deprecated_definition("consider migrating to #pragma config"),section("__RESERVED1.sec"),space(prog))) __prog__ uint16_t _RESERVED1 = (x);

/*
** Only one invocation of RESERVED1 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set RESERVED1.
** Multiple options may be combined, as shown:
**
** _RESERVED1( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register RESERVED2 (0xf80008)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _RESERVED2;
#define _RESERVED2(x) __attribute__((address(0xf80008),deprecated_definition("consider migrating to #pragma config"),section("__RESERVED2.sec"),space(prog))) __prog__ uint16_t _RESERVED2 = (x);

/*
** Only one invocation of RESERVED2 should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set RESERVED2.
** Multiple options may be combined, as shown:
**
** _RESERVED2( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
*/

/* Register FGS (0xf8000a)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FGS;
#define _FGS(x) __attribute__((address(0xf8000a),deprecated_definition("consider migrating to #pragma config"),section("__FGS.sec"),space(prog))) __prog__ uint16_t _FGS = (x);

/*
** Only one invocation of FGS should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FGS.
** Multiple options may be combined, as shown:
**
** _FGS( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   General Code Segment Write Protect:
**     GWRP_ON              Enabled
**     GWRP_OFF             Disabled
**
**   General Segment Code Protection:
**     CODE_PROT_ON         Enabled
**     CODE_PROT_OFF        Disabled
**
*/

#define GWRP_ON              0x0006
#define GWRP_OFF             0x0007

#define CODE_PROT_ON         0x0001
#define CODE_PROT_OFF        0x0007

/* Register FICD (0xf8000c)                               */

extern __attribute__((space(prog))) __prog__ uint16_t _FICD;
#define _FICD(x) __attribute__((address(0xf8000c),deprecated_definition("consider migrating to #pragma config"),section("__FICD.sec"),space(prog))) __prog__ uint16_t _FICD = (x);

/*
** Only one invocation of FICD should appear in a project,
** at the top of a C source file (outside of any function).
**
** The following constants can be used to set FICD.
** Multiple options may be combined, as shown:
**
** _FICD( OPT1_ON & OPT2_OFF & OPT3_PLL )
**
**   Comm Channel Select:
**     ICS_PGD3             Use EMUC3 and EMUD3
**     PGD3                 Use EMUC3 and EMUD3
**     ICS_PGD2             Use EMUC2 and EMUD2
**     PGD2                 Use EMUC2 and EMUD2
**     ICS_PGD1             Use EMUC1 and EMUD1
**     PGD1                 Use EMUC1 and EMUD1
**     ICS_PGD              Use PGC/EMUC and PGD/EMUD
**     PGD                  Use PGC/EMUC and PGD/EMUD
**
*/

#define ICS_PGD3             0xC000
#define PGD3                 0xC000
#define ICS_PGD2             0xC001
#define PGD2                 0xC001
#define ICS_PGD1             0xC002
#define PGD1                 0xC002
#define ICS_PGD              0xC003
#define PGD                  0xC003



/*
 * Memory Segments Sizes
 */

#define __RESET_BASE 0x0
#define __RESET_LENGTH 0x4

#define __IVT_BASE 0x4
#define __IVT_LENGTH 0x7c

#define ___RESERVED_BASE 0x80
#define ___RESERVED_LENGTH 0x4

#define __AIVT_BASE 0x84
#define __AIVT_LENGTH 0x7c

#define __PROGRAM_BASE 0x100
#define __PROGRAM_LENGTH 0x3f00

#define __EEDATA_BASE 0x7ffc00
#define __EEDATA_LENGTH 0x400

#define __FUID0_BASE 0x8005c0
#define __FUID0_LENGTH 0x2

#define __FUID1_BASE 0x8005c2
#define __FUID1_LENGTH 0x2

#define __FUID2_BASE 0x8005c4
#define __FUID2_LENGTH 0x2

#define __FUID3_BASE 0x8005c6
#define __FUID3_LENGTH 0x2

#define __FOSC_BASE 0xf80000
#define __FOSC_LENGTH 0x2

#define __FWDT_BASE 0xf80002
#define __FWDT_LENGTH 0x2

#define __FBORPOR_BASE 0xf80004
#define __FBORPOR_LENGTH 0x2

#define __RESERVED1_BASE 0xf80006
#define __RESERVED1_LENGTH 0x2

#define __RESERVED2_BASE 0xf80008
#define __RESERVED2_LENGTH 0x2

#define __FGS_BASE 0xf8000a
#define __FGS_LENGTH 0x2

#define __FICD_BASE 0xf8000c
#define __FICD_LENGTH 0x2

#define __DEVID_BASE 0xff0000
#define __DEVID_LENGTH 0x4

#define __SFRS_BASE 0x0
#define __SFRS_LENGTH 0x800

#define __DATA_BASE 0x800
#define __DATA_LENGTH 0x800

#define __YDATA_BASE 0xc00
#define __YDATA_LENGTH 0xc00
#define __SFRS_BASE 0x0
#define __SFRS_LENGTH 0x800

#define __DATA_BASE 0x800
#define __DATA_LENGTH 0x800

#define __YDATA_BASE 0xc00
#define __YDATA_LENGTH 0xc00
#define __SFRS_BASE 0x0
#define __SFRS_LENGTH 0x800

#define __DATA_BASE 0x800
#define __DATA_LENGTH 0x800

#define __YDATA_BASE 0xc00
#define __YDATA_LENGTH 0xc00


#endif
