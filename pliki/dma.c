/*
    File Name:        :  dma.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/

#include "../mcc_generated_files/mcc.h"
#include "dma.h"

char myWriteBuffer[] = "Witaj DMA"; /*bufor nadawczy*/

void DMA0_Initialize(void){

IEC3bits.DMA0IE = 0 ; /*disable DMA0 interrupt, datasheet page 66*/
IFS3bits.DMA0IF = 0 ; /*clear any existing DMA channel 0 interrupt flag, datasheet page 66*/

DMACONbits.ON = 1; /*enable the DMA controller*/
DCH0CONbits.CHEN = 0; /* channel off*/
DCH0CONbits.CHPRI = 3; /*channel priority 3*/

DCH0ECON=0; /*no start or stop IRQs, no pattern match*/

DCH0SSA = ((uint32_t)myWriteBuffer & 0x1FFFFFFF); // Convert virtual address to physical address
DCH0DSA = ((uint32_t)&SPI2BUF & 0x1FFFFFFF); // Convert virtual address to physical address

DCH0SSIZ = sizeof(myWriteBuffer); /*source size*/
DCH0DSIZ = 1; /*desination size, one byte per SPI transfer */
DCH0CSIZ = sizeof(myWriteBuffer); /*cell size*/

DCH0INTCLR = 0xFF;      /*clear existing all Interrupt flag*/
DCH0INTbits.CHCCIE = 1; /*Channel Cell Transfer Complete Interrupt Enable bit*/

IPC24bits.DMA0IP = 1 ; /*set interrupt priority*/
IPC24bits.DMA0IS = 0 ; /*set interrupt subpriority*/

 DCH0CONbits.CHEN = 1; /*channel on*/
 IEC3bits.DMA0IE = 1; /*enable DMA0 interrupt, datasheet page 66*/
 IFS3bits.DMA0IF = 0;

}
void swiatlo_go(void)
{
    printf(" sw  IN "); 
    IO_RD0_SetHigh();
    while(!(DMA_StatusGet(DMA_CHANNEL_0) & DMA_BLOCK_TX_COMPLETE));
      printf("\n\r stan dma po sw in [dh0int-%08X,SSA-%08X, DSA %08X , ] \n\r",DCH0INT,DCH0SSA,DCH0DSA);
     
      //DMACONbits.ON = 0;
    //DMACONbits.CHEN=1;
    DCH0CONbits.CHEN=0;
      
       U1STAbits.UTXINV=1;
        delayUs(90);
        U1STAbits.UTXINV=0;
        delayUs(16);
       // UART1_Write(0);
        
     DCH0INTCLR=0xff;
    // DMACONbits.ON = 1;
     DCH0CONbits.CHEN=1;
     printf(" sw OUT "); 
    //DMACONbits.ON=0;
    //DCH0CONbits.CHEN=0;
}

void light_go(uint8_t *ramka)
{
    printf(" sw light  IN "); 
    IO_RD0_SetHigh();
    while(!(DMA_StatusGet(DMA_CHANNEL_0) & DMA_BLOCK_TX_COMPLETE));
      printf("\n\r stan dma po sw in [dh0int-%08X,SSA-%08X, DSA %08X , ] \n\r",DCH0INT,DCH0SSA,DCH0DSA);
     
      DMACONbits.ON = 0;
    //DMACONbits.CHEN=1;
    DCH0CONbits.CHEN=0;
    DCH0SSA=0;
    DCH0SSA=((uint32_t)& ramka) &  0x1FFFFFFF ; 
    DCH0SSA=513;
       U1STAbits.UTXINV=1;
        delayUs(90);
        U1STAbits.UTXINV=0;
        delayUs(16);
       // UART1_Write(0);
        
     DCH0INTCLR=0xff;
     DMACONbits.ON = 1;
     DCH0CONbits.CHEN=1;
     printf(" sw light OUT "); 
}

/* 
void __ISR(_DMA0_VECTOR) __DMA0Interrupt(void)
{
PORTBbits.RB6 = 1 ;     /*set LED ON*/
//DCH0INTCLR = 0xFF;      /*clear existing all DMA0 Interrupt flag*/
//IFS3bits.DMA0IF = 0 ;   /*clear existing DMA0 channel 0 interrupt flag, datasheet page 66*/
//}

//*/
        



