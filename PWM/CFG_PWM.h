/* 
 * File:   CFG_PWM.h
 * Author: Familia CS
 *
 * Created on 20 de diciembre de 2024, 18:54
 */

#ifndef CFG_PWM_H
#define	CFG_PWM_H

#include "CFG_16F877A.h"

unsigned int DATOADC_PWM_AN_T,DATOADC_PWM_AN_T2;

#define     PWMCCP1     PORTCbits.RC2;
#define     PWMCCP2     PORTCbits.RC1;

void PWM_Inicializar(void);
void PWM_IN_AN1();
void PWM_IN_AN3();

#endif	/* CFG_PWM_H */