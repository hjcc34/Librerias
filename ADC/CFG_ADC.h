/* 
 * File:   CFG_ADC.h
 * Author: Familia CS
 *
 * Created on 24 de enero de 2025, 22:04
 */

#ifndef CFG_ADC_H
#define	CFG_ADC_H

#include "CFG_16F877A.h"

unsigned long  DATOADCH,DATOADC_PWM_AN1,DATOADC_PWM_AN3;
unsigned int DATOADCL_PWM_AN1,DATOADCL_PWM2_AN1,DATOADCL_PWM3_AN1,DATOADCH_PWM_AN1,DATOADCL_PWM_AN3,DATOADCL_PWM2_AN3,DATOADCL_PWM3_AN3,DATOADCH_PWM_AN3;

long datoadc;

void ConversorAD(void);
void ADC_Configuracion(void);
void ConversorAD_PWM_AN1(void);
void ConversorAD_PWM_AN3(void);

#endif	/* CFG_ADC_H */

