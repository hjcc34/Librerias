#include "CFG_16F877A.h"

//--------------------------Configuracion ADC-----------------------------------
void ADC_Configuracion(void)
{
    ADCON1bits.PCFG = 4;                                                        //Activa AN0 y AN1 Entrada analogica
    ADCON1bits.ADCS2 = 0; ADCON0bits.ADCS1 = 0; ADCON0bits.ADCS0 = 1;           //Clock conversion FOSC/8
    ADCON1bits.ADFM = 1;                                                        //Justificacion a la derecha
    ADCON0bits.ADON = 1;                                                        //Enciendo modulo de ADC 
}
//---------------------------Conversor para AN1---------------------------------
void ConversorAD_PWM_AN1(void)
{
    ADCON0bits.CHS = 1;                                                         //Seleciona el canal 1 del ADC.
    __delay_us(50);
    ADCON0bits.GO_DONE = 1;
    while (ADCON0bits.GO_DONE == 1)
    {
        
    }
    DATOADCL_PWM_AN1 = ADRESL;
    DATOADCL_PWM2_AN1 = ADRESL;
    DATOADCL_PWM3_AN1 = ADRESL;
    DATOADCH_PWM_AN1 = ADRESH;
//********************************Valor total***********************************
    DATOADCL_PWM_AN1 = DATOADCL_PWM_AN1>>2;
    DATOADCH_PWM_AN1 = DATOADCH_PWM_AN1<<6;
    DATOADC_PWM_AN1 = DATOADCL_PWM_AN1 + DATOADCH_PWM_AN1;
//******************************CCP1CON Y***************************************
    DATOADCL_PWM2_AN1 = DATOADCL_PWM2_AN1<<7;
//****************************CCP1CON X*****************************************
    DATOADCL_PWM3_AN1 = DATOADCL_PWM3_AN1<<7;
    DATOADCL_PWM3_AN1 /= 10000000;
}
//---------------------------Conversor para AN3---------------------------------
void ConversorAD_PWM_AN3(void)
{
    ADCON0bits.CHS = 3;                                                         //Seleciona el canal 3 del ADC.
    __delay_us(50);
    ADCON0bits.GO_DONE = 1;
    while (ADCON0bits.GO_DONE == 1)
    {
        
    }
    DATOADCL_PWM_AN3 = ADRESL;
    DATOADCL_PWM2_AN3 = ADRESL;
    DATOADCL_PWM3_AN3 = ADRESL;
    DATOADCH_PWM_AN3 = ADRESH;
//********************************Valor total***********************************
    DATOADCL_PWM_AN3 = DATOADCL_PWM_AN3>>2;
    DATOADCH_PWM_AN3 = DATOADCH_PWM_AN3<<6;
    DATOADC_PWM_AN3 = DATOADCL_PWM_AN3 + DATOADCH_PWM_AN3;
//******************************CCP1CON Y***************************************
    DATOADCL_PWM2_AN3 = DATOADCL_PWM2_AN3<<7;
//****************************CCP1CON X*****************************************
    DATOADCL_PWM3_AN3 = DATOADCL_PWM3_AN3<<7;
    DATOADCL_PWM3_AN3 /= 10000000;
}