/* 
 * File:   CFG_BMP280.h
 * Author: Familia CS
 *
 * Created on 22 de noviembre de 2024, 21:15
 */

#ifndef CFG_BMP280_H
#define	CFG_BMP280_H

#include "CFG_16F877A.h"

long SSPBUFmsb,SSPBUFlsb,dig_T1,dig_T2,dig_T3,dig_P1,dig_P2,dig_P3,dig_P4,dig_P5,dig_P6,dig_P7,dig_P8,dig_P9,adc_T,var1,var2,t_fine,T,BMP280_S32_t,SSPBUFxsb;

long registro [13];

#define _bmp280_w           0xEE
#define _bmp280_r           0xEF
#define _habilta_SPI        0x01
#define _bmp280_reset       0xB6
#define _bmp280_CFG         0xF5
#define _bmp280_ctrl_mes    0xF4
#define _bmp280_status      0xF3
#define _bmp280_reg_reset   0xE0
#define _bmp280_ID          0xD0

void READ_BMP280_T(void);
void CALCULO_BMP280_T(void);
void READ_BMP280_P(void);
void CALCULO_BMP280_P(void);
void CALIBRATION_BMP280(void);
void CALCULO_BMP280(void);
void READ_BMP280(void); 
void ini_bmp280 (void);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CFG_BMP280_H */

