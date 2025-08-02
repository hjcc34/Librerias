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
void DHT11_READ_BITS(uint8_t variable_DHT11)
{
    uint8_t u;
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
//-----------------------Conversor binario to BCD-------------------------------
void Decodificador_BIN_ASCII(unsigned char m)
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
}
//------------------------Medicion del DHT11------------------------------------
//------------------------Medicion de Humedad-----------------------------------
//------------------------------------------------------------------------------
void DHT11_medicion (void)
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
//*****************************Humedad 1***************************************   
   DHT11_READ_BITS(H_1);
   H_1 = variable2;
//*****************************Humedad 2***************************************   
   DHT11_READ_BITS(H_2);
   H_2 = variable2;
//***************************Temperatura 1*************************************   
   DHT11_READ_BITS(T_1);
   T_1 = variable2;
//***************************Temperatura 2*************************************   
   DHT11_READ_BITS(T_2);
   T_2 = variable2;
//******************************************************************************    
    Decodificador_BIN_ASCII(H_1);
    Lcd_pos_y(3);
    Lcd_Write_Char(unidad_DHT11);
    Lcd_pos_y(2);
    Lcd_Write_Char(decena_DHT11);
    Lcd_pos_y(4);
    Lcd_Write_Char('.');
    Decodificador_BIN_ASCII(H_2);
    Lcd_pos_y(6);
    Lcd_Write_Char(unidad_DHT11);
    Lcd_pos_y(5);
    Lcd_Write_Char(decena_DHT11);
    Lcd_pos_y(7);
    Lcd_Write_Char('%');    
//------------------------Medicion de Temperatura-------------------------------
    Decodificador_BIN_ASCII(T_1);
    Lcd_pos_y(12);
    Lcd_Write_Char(unidad_DHT11);
    Lcd_pos_y(11);
    Lcd_Write_Char(decena_DHT11);
    Lcd_pos_y(13);
    Lcd_Write_Char('.');
    Decodificador_BIN_ASCII(T_2);
    Lcd_pos_y(15);
    Lcd_Write_Char(unidad_DHT11);
    Lcd_pos_y(14);
    Lcd_Write_Char(decena_DHT11);
    Lcd_pos_y(16);
    Lcd_Write_Char('c');    
}
//------------------------------------------------------------------------------