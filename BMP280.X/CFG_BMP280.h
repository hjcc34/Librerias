/* 
 * File:   CFG_BMP280.h
 * Author: Familia CS
 *
 * Created on 22 de noviembre de 2024, 21:15
 */

#ifndef BMP280_H
#define BMP280_H

#include "../../Reloj_V1/RELOJ_LCD_16x2.X/CFG_16F877A.h"

#define _bmp280_w           0xEE
#define _bmp280_r           0xEF
#define _habilta_SPI        0x01
#define _bmp280_reset       0xB6
#define _bmp280_CFG         0xF5
#define _bmp280_ctrl_mes    0xF4
#define _bmp280_status      0xF3
#define _bmp280_reg_reset   0xE0
#define _bmp280_ID          0xD0
#define _mode_sleep         0x00
#define _bmp280_temp_xlsb   0xFC
#define _bmp280_temp_lsb    0xFB
#define _bmp280_temp_msb    0xFA
#define _bmp280_pres_xlsb   0xF9
#define _bmp280_pres_lsb    0xF8
#define _bmp280_pres_msb    0xF7

char xlsb;
unsigned int dig_T1,dig_P1;
int dig_T2,dig_T3,dig_P2,dig_P3,dig_P4,dig_P5,dig_P6,dig_P7,dig_P8,dig_P9,lsb;

long msb;

int32_t adc_T,var1,var2,t_fine,temp;


int cal_data[24];

void CALIBRATION_BMP280(void);
char read_xlsb(void);
int read_lsb(void);
long read_msb(void);
int16_t CALCULO_BMP280(void);
void ini_bmp280 (void);

#endif	/* CFG_BMP280_H */

