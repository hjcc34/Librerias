/*
 * File:   RS-232.c
 * Author: Familia CS
 *
 * Created on 1 de mayo de 2025, 23:19
 */

#include "CFG_RS232.h"

//------------------------------------------------------------------------------
void Uart_Init(void)
{
        TRISCbits.TRISC7 = 1;                                                   // Pin RX como una entrada digital
        TRISCbits.TRISC6 = 0;                                                   // Pin TX como una salida digital
        TXSTA = 0x24;                                                           // 8bits, transmisión habilitada, asíncrono, alta velocidad
        RCSTA = 0x90;                                                           // Habilitado el USART PIC, recepción 8 bits,  habilitada, asíncrono
        SPBRG = 25;
        __delay_ms(1);
}
//------------------------------------------------------------------------------
short Uart_Available(void)                                                      // Funcion de verificacion si ha recibido datos
{
    return PIR1bits.RCIF ? 1 : 0;
}
//------------------------------------------------------------------------------
void Uart_Send_Char(char txData)                                                // Funcion para transmitir caracteres
{
    while(TXSTAbits.TRMT == 0);
    TXREG = txData;
}
//------------------------------------------------------------------------------
void Uart_Send_String(char *info)                                               // Funcion para transmitir una cadena de caracteres
{
    while(*info)
    {
        Uart_Send_Char(*info++);
    }
}
//------------------------------------------------------------------------------
char Uart_Read(void)                                                            // Funcion para recibir caracteres
{
    while(PIR1bits.RCIF == 0);
    if(RCSTAbits.OERR == 1)
    {
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
    }
    PIR1bits.RCIF = 0;
    return RCREG;
}
//------------------------------------------------------------------------------
void Uart_Read_String(char* Buf, unsigned int s_buf)                            // Funcion para recibir cadenas de caracteres
{
    unsigned int cont_buf = 0;
    char c;
    do
    {
        c = Uart_Read();
        Buf[cont_buf++] = c;
        if(cont_buf >= s_buf) break;
    }while(c != '\n');
    Buf[cont_buf-2] = '\0';
    cont_buf = 0;
}
//------------------------------------------------------------------------------ 
void Uart_Read_Substring(char* cp, char* vc, unsigned int inc, unsigned int fn)                   // Funcion para descomponer cadenas de caracteres con incio y fin.
{
    int pt = 0;
    for(int lt=inc; lt<=fn; lt++)
    {
        vc[pt] = cp[lt];
        pt++;
    }
    vc[pt] = '\0';
}
//------------------------------------------------------------------------------
void Uart_Read_StringUntil(char stop_c, char* buf, unsigned int st_size)        // Funcion para descomponer cadenas de caracteres y se detiene con un caracter
{
    unsigned int rx_cont = 0;
    while(*(buf-1) != stop_c)
    {
        rx_cont++;
        *buf++ = Uart_Read();
        if(rx_cont >= st_size) break;
    }
    *--buf = 0;
}
//------------------------------------------------------------------------------
