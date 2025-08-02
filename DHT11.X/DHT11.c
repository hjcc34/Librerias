#include "CFG_DHT11.h"

//------------------------------------------------------------------------------
void DHT11_Inicio(void)
{
    DHT11 = 0;
    __delay_ms(20);                                                             //20 ms de bajo del micro para que lo detecte el DHT11
    DHT11 = 1;    
    while (DHT11 == 1)                                                          //El micro espera que el sensor coloque en pin en alto
    {
    }
//---------------------------Respuesta DHT11------------------------------------
    while (DHT11 == 0)                                                          // verificar la respuesta baja del sensor 80us
    {
    }
    while (DHT11 == 1)                                                          // verificar la respuesta alta del sensor 80us
    {
    }
}
//------------------------------------------------------------------------------
void DHT11_READ_BITS(unsigned char variable_DHT11)
{
    unsigned char u;
    for (u=0;u<8;++u)
    {
        while (DHT11 == 0)                                                           // verifico los 50us del bit de inicio transmision
        {
        }
    __delay_us(40);
        if (DHT11 == 1)
        {
            variable_DHT11 = variable_DHT11 <<1;
            variable_DHT11 += 1;
        }
        if (DHT11 == 0)
        {
            variable_DHT11 = variable_DHT11 <<1;
            variable_DHT11 += 0;
        }
        while (DHT11 == 1)
        {
        }
    }
    variable2 = variable_DHT11;
}
//******************************************************************************
void DHT11_READ(void)
{ 
   DHT11_Inicio();
//*****************************Humedad 1***************************************   
   DHT11_READ_BITS(H1);
   H1 = variable2;
//*****************************Humedad 2***************************************   
   DHT11_READ_BITS(H2);
   H2 = variable2;
//***************************Temperatura 1*************************************   
   DHT11_READ_BITS(T1);
   T1 = variable2;
//***************************Temperatura 2*************************************   
   DHT11_READ_BITS(T2);
   T2 = variable2;
}
//-----------------------Conversor binario to BCD-------------------------------
unsigned char Decodificador_BIN_ASCII(unsigned char m)
{
    unsigned char p;
    datouni = m;
    unidad_DHT11 = m;
    decena_DHT11 = m;
    decena_DHT11 /= 0x0A;
    x = decena_DHT11;
    q = x *10;
    decena_DHT11 += 0x30;
//******************************************************************************    
    if (datouni <=9)
        {
        unidad_DHT11 = datouni;          
        }
//******************************************************************************
    if (datouni >=10)
    {
        if (datouni <=254)
        {
            unidad_DHT11 -= q;
        }
    }
//******************************************************************************     
    unidad_DHT11 += 0x30;
    return unidad_DHT11,decena_DHT11;
}
//------------------------Medicion del DHT11------------------------------------
//------------------------Medicion de Humedad-----------------------------------
//------------------------------------------------------------------------------
void DHT11_medicion (void)
{
    DHT11_READ();
    Decodificador_BIN_ASCII(H1);
    Lcd_pos_y(3);
    Lcd_Write_Char(unidad_DHT11);
    Lcd_pos_y(2);
    Lcd_Write_Char(decena_DHT11);
    Lcd_pos_y(4);
    Lcd_Write_Char('.');
    Decodificador_BIN_ASCII(H2);
    Lcd_pos_y(6);
    Lcd_Write_Char(unidad_DHT11);
    Lcd_pos_y(5);
    Lcd_Write_Char(decena_DHT11);
    Lcd_pos_y(7);
    Lcd_Write_Char('%');    
//------------------------Medicion de Temperatura-------------------------------
    Decodificador_BIN_ASCII(T1);
    Lcd_pos_y(12);
    Lcd_Write_Char(unidad_DHT11);
    Lcd_pos_y(11);
    Lcd_Write_Char(decena_DHT11);
    Lcd_pos_y(13);
    Lcd_Write_Char('.');
    Decodificador_BIN_ASCII(T2);
    Lcd_pos_y(15);
    Lcd_Write_Char(unidad_DHT11);
    Lcd_pos_y(14);
    Lcd_Write_Char(decena_DHT11);
    Lcd_pos_y(16);
    Lcd_Write_Char('c');    
}
//------------------------------------------------------------------------------
void DHT11_medicion_rs232 (void)
{
    DHT11_READ();
    DEC_TO_LCD(H1);
    Uart_Send_Char(decenas);
    Uart_Send_Char(unidades);
    Uart_Send_Char('.');
    DEC_TO_LCD(H2);
    Uart_Send_Char(decenas);
    Uart_Send_Char(unidades);
    Uart_Send_String("\r\n");
//******************************************************************************        
    DEC_TO_LCD(T1);
    Uart_Send_Char(decenas);
    Uart_Send_Char(unidades);
    Uart_Send_Char('.');
    DEC_TO_LCD(T2);
    Uart_Send_Char(decenas);
    Uart_Send_Char(unidades);    
    Uart_Send_String("\r\n");
    p = 1;
}