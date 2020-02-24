
/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/uart1.h"
#include <stdio.h>
#include <proc/p32mm0256gpm048.h>
#include "pliki/dma.h"
#include "mcc_generated_files/dma.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/crc.h"

#define  SYSTEMCLOCK 24000000 


 uint8_t tab1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255}; 
 uint8_t tab2[] = {2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 100, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 20, 251, 252, 15, 254, 2}; 
 
 uint16_t x,bt;
 
 void __attribute__((used)) delayUs(unsigned int usec);
 void __attribute__((used)) delayMs(unsigned int usec);
 void wyslij(uint8_t *tb);
 void DMA_Init(void);
 
 
/*
                         Main application
 */
int main(void)
{
    delayMs(1500);
    
    // initialize the device
    SYSTEM_Initialize();
  //  DMA0_Initialize();
    //TRISB.RB6=0;
    //LATB.RB6=1;
    
    /*
      DMA_Initialize();
        DMA_ChannelEnable(DMA_CHANNEL_1);
        DMA_TransferCountSet(DMA_CHANNEL_1, 100);
        DMA_SourceAddressSet(DMA_CHANNEL_1,(uint32_t)& srcArray);
        DMA_DestinationAddressSet(DMA_CHANNEL_1,(uint32_t)& dstArray);
        
        DMA_TransferStartEnable(DMA_CHANNEL_1);

        while(!(DMA_Status(DMA_CHANNEL_1) & DMA_BLOCK_TX_COMPLETE));
        //Check for transfer results after transfer completes
        DMA_ChannelDisable(DMA_CHANNEL_1);
     */
       // printf("\n\r stan dma przy starcie 0 [dh0int-%08X] \n\r",DCH0INT);
      printf("------------------------system start---------------------------------  \n\r "); 
        printf("\n\r stan dma przed  init [dh0int-%08X,SSA-%08X, DSA %08X , ] \n\r",DCH0INT,DCH0SSA,DCH0DSA);
         IO_RD0_SetLow();
      //  DMA_Initialize();
         DMA_Init();
         printf("\n\r stan dma po init [dh0int-%08X,SSA-%08X, DSA %08X , ] \n\r",DCH0INT,DCH0SSA,DCH0DSA);
     //   printf("\n\r stan dma przy starcie [dh0int-%08X] \n\r",DCH0INT);

    /*DMA_TransferCountSet(DMA_CHANNEL_0 ,1 ); // sizeof(tab1)
    DMA_SourceAddressSet(DMA_CHANNEL_0, (uint32_t)& tab1 );
    DMA_SourceSizeSet(DMA_CHANNEL_0,  sizeof(tab1 ));
    DMA_DestinationAddressSet(DMA_CHANNEL_0, (uint32_t)& U1TXREG);
    DMA_DestinationSizeSet(DMA_CHANNEL_0, 1); */ 
       printf("system start  \n\r "); 
        printf(" %i \n\r ",sizeof(tab1));
    IO_RD0_SetHigh();
    DMACONbits.ON = 1;
    //DMACONbits.CHEN=1;
    DCH0CONbits.CHEN=1;
    
     printf("\n\r stan dma po wyslaniu [dh0int-%08X] \n\r",DCH0INT);
    while(!(DMA_StatusGet(DMA_CHANNEL_0) & DMA_BLOCK_TX_COMPLETE));
    //;
    printf("/bt=%i/",bt);
    printf("\n\r stan dma po wyslaniu [dh0int-%08X] \n\r",DCH0INT);
    
    //while(bt=IO_RA0_GetValue())
    //{
    // }
    DMACONbits.ON=0;
    DCH0CONbits.CHEN=0;
   printf("\n\r stan dma po off[dh0int-%08X,SSA-%08X, DSA %08X , ] \n\r",DCH0INT,DCH0SSA,DCH0DSA);
   
       
       printf("/bt=%i/",bt);
    //DMA_TransferStartEnable(DMA_CHANNEL_0);
   
    //   DMA_TransferStartEnable(DMA_CHANNEL_0);
    printf(".");
    
     
    
    while (1)
    {
        // Add your application code
        
        delayMs(500);
        DCH0INTCLR=0xff;
        DMACONbits.ON=1;
    DCH0CONbits.CHEN=1;
        while(!(DMA_StatusGet(DMA_CHANNEL_0) & DMA_BLOCK_TX_COMPLETE));
         bt=IO_RA0_GetValue();
        printf("/bt=%i/",bt);
        if(!bt)
        {
           // wyslij(tab1);
            
        }
        else
        {
          //  wyslij(tab2);
        }
       // delayMs(1000);
     /*   delayMs(500);
        printf(".");
        U1STAbits.UTXINV=1;
        delayUs(90);
        U1STAbits.UTXINV=0;
        delayUs(16);
        UART1_Write(0);
        while(x<sizeof(tab1))
        {
         UART1_Write(tab1[x++]);   
        }
        x=0;*/ 
    }
    return 1;   
}
/**
 End of File
*/
void __attribute__((used)) delayUs(unsigned int usec)
{
    unsigned int tWait, tStart;

    tWait=(SYSTEMCLOCK/2000000)*usec; 
    tStart=_mfc0(9,0);
    while((_mfc0(9,0)-tStart)<tWait);        // wait for the time to pass
}

  void __attribute__((used)) delayMs(unsigned int usec)
{
    unsigned int tWait, tStart;

    tWait=(SYSTEMCLOCK/2000)*usec; 
    tStart=_mfc0(9,0);
    while((_mfc0(9,0)-tStart)<tWait);        // wait for the time to pass
}
 void wyslij(uint8_t *tb)
 {
     //delayMs(500);
     DMA_SourceAddressSet(DMA_CHANNEL_0, (uint32_t)& tb );
    DMA_SourceSizeSet(DMA_CHANNEL_0,  sizeof(tb ));
     DMA_TransferStartIRQEnable(DMA_CHANNEL_0);
     DMA_ChannelEnable(DMA_CHANNEL_0);
     printf(" stan dma [dh0int-%08X] \n\r ",DCH0INT);
     while(!(DMA_StatusGet(DMA_CHANNEL_0) & DMA_BLOCK_TX_COMPLETE));
     DMA_ChannelDisable(DMA_CHANNEL_0);
     DMA_TransferAbortIRQEnable(DMA_CHANNEL_0);
     DMA_TransferAbortEnable(DMA_CHANNEL_0);
        //Check for transfer results after transfer completes
     printf(" stan dma po disabled [dh0int-%08X] \n\r",DCH0INT);
 }
 
  void DMA_Init(void)
  {
      DMACONbits.ON=0;
      DCH0CON=0;
      DCH0ECON= 0x1110 ;  //0; // 0x1110; timer1
  DCH0INTCLR = 0xFF;
      DCH0SSA= ((uint32_t)& tab1) &  0x1FFFFFFF ; //0x00; // (address & 0x1FFFFFFF);
    // CHDSA 0; 
    DCH0DSA= ((uint32_t)& U1TXREG) &  0x1FFFFFFF;//0x00;
    // CHSSIZ 0; 
    DCH0SSIZ= sizeof(tab1);
    // CHDSIZ 0; 
    DCH0DSIZ= 1;
    // CHCSIZ 1; 
    DCH0CSIZ= 0x01;
    // DCHPDAT 0; 
    DCH0DAT= 0x00;
    // Clearing Channel 0 Interrupt Flag;
    IFS3CLR= 1 << _IFS3_DMA0IF_POSITION;
    // Enabling Channel 0 Interrupt
    IEC3bits.DMA0IE = 1;
     //  DMACON = (0x8000 | 0x01) & 0x7FFF; //Enable DMA later

    // CHCHNS Chain to channel higher; CHAEN disabled; CHEN enabled; CHCHN disabled; CHBUSY disabled; CHAED disabled; CHPRI Priority 0; 
     //0x80 & 0xFF7F; //Enable DMA Channel later;
    // AIRQEN disabled; CABORT disabled; CHAIRQ 0; SIRQEN enabled; CHSIRQ 17; PATEN disabled; CFORCE disabled; 
    // CHSDIE enabled; CHSDIF No interrupt; CHERIF No interrupt; CHSHIE disabled; CHSHIF No interrupt; CHERIE enabled; CHCCIF No interrupt; CHBCIE disabled; CHBCIF No interrupt; CHDDIF No interrupt; CHDDIE enabled; CHCCIE disabled; CHDHIF No interrupt; CHDHIE disabled; CHTAIE disabled; CHTAIF No interrupt; 
  //  DCH0INT= 0xA10000;
    
 //  DCH0INTbits.CHDDIE=1;
   // DCH0INTbits.CHCCIE=1;
    // CHSSA 0; 
    
      
  }