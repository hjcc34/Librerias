/* 
 * File:   CFG_LCD.h
 * Author: Familia CS
 *
 * Created on 11 de enero de 2025, 18:59
 */

#ifndef CFG_LCD_H
#define	CFG_LCD_H

#include "../../../Reloj_V1/RELOJ_LCD_16x2.X/CFG_16F877A.h"

#define RS  TRISEbits.TRISE0                                                    //Rs del LCD
#define E   TRISEbits.TRISE2                                                    //Enable del LCD
#define D0  TRISDbits.TRISD0                                                    //D0
#define D1  TRISDbits.TRISD1                                                    //D1
#define D2  TRISDbits.TRISD2                                                    //D2
#define D3  TRISDbits.TRISD3                                                    //D3
#define D4  TRISDbits.TRISD4                                                    //D4
#define D5  TRISDbits.TRISD5                                                    //D5
#define D6  TRISDbits.TRISD6                                                    //D6
#define D7  TRISDbits.TRISD7                                                    //D7

#define Dato_RS PORTEbits.RE0                                                   //RS del LCD
#define Dato_E  PORTEbits.RE2                                                   //Enable de la LCD
#define Dato_D0 PORTDbits.RD0                                                   //D0
#define Dato_D1 PORTDbits.RD1                                                   //D1
#define Dato_D2 PORTDbits.RD2                                                   //D2
#define Dato_D3 PORTDbits.RD3                                                   //D3
#define Dato_D4 PORTDbits.RD4                                                   //D4
#define Dato_D5 PORTDbits.RD5                                                   //D5
#define Dato_D6 PORTDbits.RD6                                                   //D6
#define Dato_D7 PORTDbits.RD7                                                   //D7
//****************************Comandos LCD**************************************
#define     _LCD_FIRST_ROW          128
#define     _LCD_SECOND_ROW         192
#define     _LCD_THIRD_ROW          148
#define     _LCD_FOURTH_ROW         212
#define     _LCD_CLEAR              1
#define     _LCD_RETURN_HOME        2
#define     _LCD_CURSOR_OFF         12
#define     _LCD_UNDERLINE_ON       14
#define     _LCD_BLINK_CURSOR_ON    15
#define     _LCD_MOVE_CURSOR_LEFT   16
#define     _LCD_MOVE_CURSOR_RIGHT  20
#define     _LCD_TURN_OFF           0
#define     _dis_OFF_cur_OFF_bl_OFF 8
#define     _LCD_SHIFT_LEFT         24
#define     _LCD_SHIFT_RIGHT        28
#define     _mode_8bits_0x30        0x03
#define     _mode_4bits_0x20        0x02
#define     _8bit_2lines_58         0x38
#define     _ON_LCD                 0x0C
#define     _4b_2lin_5x8_           0x28
#define     _CFG_in                 0x06
#define     cmd                     0x00
#define     dat                     0x01
#define     _4bits                  0x01
#define     _8bits                  0x00

unsigned char contador2,nhigh,nlow;

//-------------------------------caracter de bocina-----------------------------
unsigned char caracter0_direccion[9]={0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x80};
unsigned char caracter0_datos[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

unsigned char caracter1_direccion[9]={0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,0x81};
unsigned char caracter1_datos[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01};

unsigned char caracter2_direccion[9]={0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x81};
unsigned char caracter2_datos[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02};
//*********************************Funciones************************************   
void Lcd_inicio_4bits(void);                                                    //Funcion de incializar la pantalla LCD 4 bits
void Lcd_cmd_data(unsigned char datos,unsigned char cmd_data,unsigned char bits);               //Decodificador de nible alto y bajo.
void Lcd_print_string(unsigned char POSx,char *String_x,unsigned char POSy,char *String_y);    //Imprimir en x,y un string
void Lcd_Write_String(char *a);                                                 //Envio de cadena de caracteres
void Lcd_Write_Char(unsigned char a);                                           //Envio de caracter
void Lcd_pos_x (unsigned char POSx);
void Lcd_pos_y (unsigned char POSy);

void Caracter_0(void);
void Caracter_1(void);
void Caracter_2(void);
void Envio_control(unsigned char q);
void Envio_data(unsigned char t);

#endif	/* CFG_LCD_H */
