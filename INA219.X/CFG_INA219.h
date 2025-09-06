/* 
 * File:   CFG_INA219.h
 * Author: Familia CS
 *
 * Created on 11 de enero de 2025, 19:15
 */

#ifndef CFG_INA219_H
#define	CFG_INA219_H

#include "../../FVV_V1.0/FV.X/CFG_16F877A.h"

void CFG_INA219_32V_3A(void);
void Lectura_Bus_VDC_INA219(void);
void Lectura_corriente_INA219(void);
void Lectura_potencia_INA219(void);

#endif	/* CFG_INA219_H */

