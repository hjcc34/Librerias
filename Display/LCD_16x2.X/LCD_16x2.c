/*
 * File:   LCD_16x2.c
 * Author: Familia CS
 *
 * Created on 4 de junio de 2025, 22:15
 */

#include "CFG_LCD_16x2.h"

//------------------------------------------------------------------------------
//------------------------------decodificaodor----------------------------------
//--------------------------Nible alto y nible bajo-----------------------------
//------------------------------------------------------------------------------
void Lcd_cmd_data(unsigned char datos,unsigned char cmd_data,unsigned char bits)
{
    if (bits == 0)
    {
        PORTD = datos;
    }
    if (bits == 1)
    {
        nhigh = datos;
        nlow  = datos;
        nhigh = nhigh>>4;
        nlow  = nlow<<4;
        nlow  = nlow>>4;
//******************************************************************************
        Dato_D4 = Dato_D5 = Dato_D6 = Dato_D7 = 0;
        Dato_D4 = (nhigh >> 0) & 0x01; 
        Dato_D5 = (nhigh >> 1) & 0x01;
        Dato_D6 = (nhigh >> 2) & 0x01;
        Dato_D7 = (nhigh >> 3) & 0x01;
        }
    Dato_RS = cmd_data;
    __delay_us(100);
    Dato_E = 1;
    __delay_ms(1);
    Dato_E = 0;
    __delay_ms(1);
    if (bits == 1)
    {
        Dato_D4 = Dato_D5 = Dato_D6 = Dato_D7 = 0;
        Dato_D4 = (nlow >> 0) & 0x01; 
        Dato_D5 = (nlow >> 1) & 0x01;
        Dato_D6 = (nlow >> 2) & 0x01;
        Dato_D7 = (nlow >> 3) & 0x01;
        Dato_RS = cmd_data;
        __delay_us(100);
        Dato_E = 1;
        __delay_ms(1);
        Dato_E = 0;
        __delay_ms(1);
        Dato_D4 = Dato_D5 = Dato_D6 = Dato_D7 = 0;
    }
}
//------------------------------------------------------------------------------
//--------------------------INICIALIZACION 4 BITS-------------------------------
//------------------------------------------------------------------------------
void Lcd_inicio_4bits(void)
{
    __delay_ms(50);
    Lcd_cmd_data(_mode_8bits_0x30,cmd,_4bits);__delay_ms(5);
    Lcd_cmd_data(_mode_8bits_0x30,cmd,_4bits);__delay_us(150);
    Lcd_cmd_data(_mode_8bits_0x30,cmd,_4bits);__delay_us(150);
    Lcd_cmd_data(_mode_4bits_0x20,cmd,_4bits);__delay_us(150);
    Lcd_cmd_data(_4b_2lin_5x8_,cmd,_4bits);
    Lcd_cmd_data(_ON_LCD,cmd,_4bits);
    Lcd_cmd_data(_CFG_in,cmd,_4bits);
    Lcd_cmd_data(_LCD_CLEAR,cmd,_4bits);

}
//******************************************************************************
void Lcd_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	Lcd_Write_Char(a[i]);
}
//******************************************************************************
void Lcd_Write_Char(unsigned char a)
{
    Lcd_cmd_data(a,dat,_4bits);
}
//******************************************************************************
void Lcd_pos_x(unsigned char POSx)
{
    unsigned char a;
    a = 0x80 + POSx - 1;
    Lcd_cmd_data(a,cmd,_4bits);
}    
//******************************************************************************
void Lcd_pos_y(unsigned char POSy)
{
    unsigned char a;    
    a = 0xC0 + POSy - 1;
    Lcd_cmd_data(a,cmd,_4bits);    
}
//******************************************************************************
void Caracter_0(void) 
{
    for (contador2=0;contador2<9;contador2++)
    {
        Envio_control(caracter0_direccion[contador2]);
        Envio_data(caracter0_datos[contador2]);
    }
}
//******************************************************************************
void Caracter_1(void) 
{
    for (contador2=0;contador2<9;contador2++)
    {
        Envio_control(caracter1_direccion[contador2]);
        Envio_data(caracter1_datos[contador2]);
    }
}
//******************************************************************************
void Caracter_2(void) 
{
    for (contador2=0;contador2<9;contador2++)
    {
        Envio_control(caracter2_direccion[contador2]);
        Envio_data(caracter2_datos[contador2]);
    }
}
//**************************ENVIO CONTROL***************************************
void Envio_control(unsigned char q)
{
    Dato_RS = 0;
    __delay_us(100);
    PORTD = q;
    __delay_us(100);
    Dato_E = 1;
    __delay_ms(1);
    Dato_E = 0;
    __delay_ms(1);
}
//*************************ENVIO DATA*******************************************
void Envio_data(unsigned char t)
{
    Dato_RS = 1;
    PORTD = t;
    Dato_E = 1;
    __delay_ms(1);
    Dato_E = 0;
    __delay_ms(1);
}
