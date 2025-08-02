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

uint8_t x,q,p,datouni,variable2,H_1,H_2,T_1,T_2,unidad_DHT11,decena_DHT11,centena_DHT11,unidadM,variable_DHT11;

void DHT11_Inicio(void);
void DHT11_READ_BITS(uint8_t variable);
void Decodificador_BIN_ASCII(unsigned char m);
void DHT11_medicion (void);

#endif	/* CFG_DHT11_H */

