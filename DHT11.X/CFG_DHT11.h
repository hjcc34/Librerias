/* 
 * File:   CFG_DHT11.h
 * Author: Familia CS
 *
 * Created on 8 de diciembre de 2024, 19:25
 */

#ifndef CFG_DHT11_H
#define	CFG_DHT11_H

#include "../../Librerias/../Reloj_V1/RELOJ_LCD_16x2.X/CFG_16F877A.h"

#define DHT11          PORTCbits.RC0                                            //Tecla OK 

unsigned char x,q,p,datouni,variable2,H1,H2,T1,T2,unidad_DHT11,decena_DHT11,centena_DHT11,unidadM,variable_DHT11;

uint32_t RH,H1,H2,H3,raw,humedad;

void DHT11_Inicio(void);
void DHT11_READ_BITS(unsigned char variable);
void DHT11_READ(void);
unsigned char Decodificador_BIN_ASCII(unsigned char m);
void DHT11_medicion (void);
void DHT11_medicion_rs232 (void);

#endif	/* CFG_DHT11_H */

