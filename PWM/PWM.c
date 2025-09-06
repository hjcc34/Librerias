#include "CFG_PWM.h"

void PWM_Inicializar(void)
{
    CCP1CONbits.CCP1M3 = 1; CCP1CONbits.CCP1M2 = 1;                             //Modo PWM
    CCP2CONbits.CCP2M3 = 1; CCP2CONbits.CCP2M2 = 1;                             //Modo PWM
    PR2 = 254;                                                                  //PR2 a 1khz
}
//------------------------------------------------------------------------------
void PWM_IN_AN1()
{
    T2CONbits.TMR2ON = 1;                                                       //Enciende PWM
//******************************************************************************
    if (DATOADCL_PWM2_AN1 == 0x80)
    {
        CCP1CONbits.CCP1Y = 1;
    }
    if (DATOADCL_PWM2_AN1 == 0)
    {
        CCP1CONbits.CCP1Y = 0;
    }
//******************************************************************************
    if (DATOADCL_PWM3_AN1 == 1)
    {
        CCP1CONbits.CCP1X = 1;
    }
    if (DATOADCL_PWM3_AN1 == 0)
    {
        CCP1CONbits.CCP1X = 0;
    }
    CCPR1L = DATOADC_PWM_AN1;
}
//------------------------------------------------------------------------------
void PWM_IN_AN3()
{
    T2CONbits.TMR2ON = 1;                                                       //Enciende PWM
//******************************************************************************
    if (DATOADCL_PWM2_AN3 == 0x80)
    {
        CCP1CONbits.CCP1Y = 1;
    }
    if (DATOADCL_PWM2_AN3 == 0)
    {
        CCP1CONbits.CCP1Y = 0;
    }
//******************************************************************************
    if (DATOADCL_PWM3_AN3 == 1)
    {
        CCP1CONbits.CCP1X = 1;
    }
    if (DATOADCL_PWM3_AN3 == 0)
    {
        CCP1CONbits.CCP1X = 0;
    }
    DATOADC_PWM_AN3 = ~DATOADC_PWM_AN3;
DATOADC_PWM_AN3 -= 120;
    CCPR2L = DATOADC_PWM_AN3;
}