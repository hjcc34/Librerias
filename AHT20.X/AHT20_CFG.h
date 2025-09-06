/* 
 * File:   AHT20_CFG.h
 * Author: Familia CS
 *
 * Created on 23 de noviembre de 2024, 21:11
 */

#ifndef AHT20_CFG_H
#define	AHT20_CFG_H

#include "../../../../Mis Proyectos/Reloj_V1/RELOJ_LCD_16x2.X/CFG_PIC16F877A.h"


#define AHT20_W     0x70
#define AHT20_R     0x71
#define AHT20_ini   0xBE
#define AHT20_Mes   0xAC
#define AHT20_P1    0x08
#define AHT20_P2    0x00
#define AHT20_P3    0x33
#define AHT20_reg   0x38

#ifdef	__cplusplus
extern "C" {
#endif
    
uint8_t b_0,b_1,b_2,b_3,b_4,b_5;

uint32_t RH,H1,H2,H3,raw,humedad;
    
uint8_t ver_cal_AHT20(void);
void mes_AHT20(void);
void med_AHT20(void);
void cal_AHT20(void);

#ifdef	__cplusplus
}
#endif

#endif	/* AHT20_CFG_H */

