/* 
 * File:   CFG_I2C.h
 * Author: Familia CS
 *
 * Created on 10 de noviembre de 2024, 0:14
 */

#ifndef CFG_I2C_H
#define	CFG_I2C_H

#include "../../../Reloj_V1/RELOJ_LCD_16x2.X/CFG_16F877A.h"

uint8_t DATO_I2C_8bits,re,byte_6,byte_5,byte_4,byte_3,byte_2,byte_1,byte_0;

uint32_t DATO_READ_8b_3,DATO_READ_8b_2,DATO_READ_8b_1;

void I2C_Check(void);                                                           
void I2C_Write(unsigned char DirW,unsigned char CmdW,unsigned char DirW2);
void I2C_Write_AHT20(uint8_t DirW,uint8_t CmdW,uint8_t Par1);
int8_t I2C_Read_8bits(void);
void I2C_Read_8bits_3bytes(void);
void I2C_Read_8bits_6bytes(void);
void I2C_Cmd(unsigned char Dir,unsigned char Cfg,unsigned char Cmd);
void I2C_Initialize(void);

#endif	/* CFG_I2C_H */

