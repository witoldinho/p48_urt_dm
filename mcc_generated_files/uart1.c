#include <xc.h>
#include "uart1.h"

/**
  Section: UART1 APIs
*/

void UART1_Initialize(void)
{
    // Set the UART1 module to the options selected in the user interface.

    // STSEL 2; PDSEL 8N; RTSMD disabled; OVFDIS disabled; ACTIVE disabled; RXINV disabled; WAKE disabled; BRGH enabled; IREN disabled; ON enabled; SLPEN disabled; SIDL disabled; ABAUD disabled; LPBACK disabled; UEN TX_RX; CLKSEL PBCLK; 
    U1MODE = (0x8001 & ~(1<<15)); // disabling UART ON bit  
    // UTXISEL TX_ONE_CHAR; UTXINV disabled; ADDR 0; MASK 0; URXEN disabled; OERR disabled; URXISEL RX_ONE_CHAR; UTXBRK disabled; UTXEN disabled; ADDEN disabled; 
    U1STA = 0x0;
    // BaudRate = 250000; Frequency = 12000000 Hz; BRG 11; 
    U1BRG = 0x2;
     
    //Make sure to set LAT bit corresponding to TxPin as high before UART initialization
    U1STASET = _U1STA_UTXEN_MASK;
    U1MODESET = _U1MODE_ON_MASK;  // enabling UART ON bit
    U1STASET = _U1STA_URXEN_MASK; 
}

uint8_t UART1_Read(void)
{
    while(!(U1STAbits.URXDA == 1))
    {
    }

    if ((U1STAbits.OERR == 1))
    {
        U1STACLR = _U1STA_OERR_MASK;
    }

    return U1RXREG;
}

void UART1_Write(uint8_t txData)
{
    while(U1STAbits.UTXBF == 1)
    {
    }

    U1TXREG = txData;    // Write the data byte to the USART.
}

bool UART1_IsRxReady(void)
{
    return U1STAbits.URXDA;
}

bool UART1_IsTxReady(void)
{
    return (U1STAbits.TRMT && U1STAbits.UTXEN );
}

bool UART1_IsTxDone(void)
{
    return U1STAbits.TRMT;
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
UART1_STATUS __attribute__((deprecated)) UART1_StatusGet (void)
{
    return U1STA;
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
bool __attribute__((deprecated)) UART1_DataReady(void)
{
    return UART1_IsRxReady();
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
bool __attribute__((deprecated)) UART1_is_tx_ready(void)
{
    return UART1_IsTxReady();
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
bool __attribute__((deprecated)) UART1_is_rx_ready(void)
{
    return UART1_IsRxReady();
}

/* !!! Deprecated API - This function may not be supported in a future release !!! */
bool __attribute__((deprecated)) UART1_is_tx_done(void)
{
    return UART1_IsTxDone();
}

