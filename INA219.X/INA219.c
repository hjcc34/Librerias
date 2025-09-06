#include "CFG_INA219.h"
//---------------------------CFG INA219-----------------------------------------
void CFG_INA219_32V_3A(void)
{
    I2C_CFG_REG(0x80,0x00,0xB9,0x9F);                                           
    I2C_Stop();
    I2C_CFG_REG(0x80,0x05,0x10,0x62);                                           
    I2C_Stop();
    Lcd_pos_x(5);
    Lcd_Write_String("INA219");
    Lcd_pos_y(3);
    Lcd_Write_String("Configurado");
    __delay_ms(1000);
    Lcd_cmd_data(_LCD_CLEAR,cmd,_4bits);
}
//-------------------------Lectura BUS voltaje----------------------------------
void Lectura_Bus_VDC_INA219(void)
{
    I2C_PUNTERO(0x80,0x02);
    I2C_Stop();
    I2C_Lectura(0x81);
    I2C_Stop();
    __delay_us(10);
    
}
//-------------------------Lectura Corriente------------------------------------
void Lectura_corriente_INA219(void)
{
    I2C_PUNTERO(0x80,0x04);
    I2C_Stop();
    I2C_Lectura(0x81);
    I2C_Stop();
    __delay_us(10);
}
//-------------------------Lectura Potencia-------------------------------------
void Lectura_potencia_INA219(void)
{
    I2C_PUNTERO(0x80,0x03);
    I2C_Stop();
    I2C_Lectura(0x81);
    I2C_Stop();
    __delay_us(10);
}