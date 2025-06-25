#include "CFG_I2C.h"

//------------------------------------------------------------------------------
//-------------------------Inicializar I2C--------------------------------------
//------------------------------------------------------------------------------
void I2C_Initialize(void)                                                       //Begin IIC as master
{
  TRISC3 = 1;                                                                   //Set SDA and SCL pins as input pins
  TRISC4 = 1;                                                                   //Set SDA and SCL pins as input pins
  
  SSPCON  = 0x28;                                                               //pg84/234 
  SSPCON2 = 0x00;                                                               //pg85/234
  
  SSPADD = 0x09;
  SSPSTAT = 0x80;                                                               //pg83/234
}
//------------------------------------------------------------------------------
//---------------------------I2C chequeo----------------------------------------
//------------------------------------------------------------------------------
void I2C_Check(void) 
{
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F))
    {

    }
}
//------------------------------------------------------------------------------
//-----------------------------I2C CFG------------------------------------------
//------------------------------------------------------------------------------
void I2C_Cmd(unsigned char Dir,unsigned char Cfg,unsigned char Cmd)
{
    I2C_Check();
    SSPCON2bits.SEN = 1;                                                        //Activo el start
    while (SSPCON2bits.SEN == 1)                                                //verifico el start
    {
    }
    I2C_Check();
    SSPBUF = Dir;                                                               //ingreso direccion esclavo
    while (SSPSTATbits.BF == 1)                                                 //verifico si termino la transmision
    {
    }
    I2C_Check();
    TMR1L = 0x18;
    TMR1H = 0xFC;
    while (SSPCON2bits.ACKSTAT == 1 && re == 0)                                  //verifico reconocimiento
    {
        T1CONbits.TMR1ON = 1;
        if (PIR1bits.TMR1IF == 1)
        {
            PIR1bits.TMR1IF = 0;
            ++re;
            T1CONbits.TMR1ON = 0;
            TMR1L = 0x18;
            TMR1H = 0xFC;
        }
    }
    T1CONbits.TMR1ON = 0;
    I2C_Check();                                                                //verifico el bus
    SSPBUF = Cfg;                                                               //ingreso configuracion para esclavo
    while (SSPSTATbits.BF == 1)                                                 //verifico si termino la transmision
    {
    }
    I2C_Check();
    TMR1L = 0x18;
    TMR1H = 0xFC;
    while (SSPCON2bits.ACKSTAT == 1 && re == 1)                                  //verifico reconocimiento
    {
        T1CONbits.TMR1ON = 1;
        if (PIR1bits.TMR1IF == 1)
        {
            PIR1bits.TMR1IF = 0;
            ++re;
            T1CONbits.TMR1ON = 0;
            TMR1L = 0x18;
            TMR1H = 0xFC;
        }
    }
    T1CONbits.TMR1ON = 0;
    I2C_Check();                                                               //verifico el bus
    SSPBUF = Cmd;                                                               //ingreso comando para esclavo
    while (SSPSTATbits.BF == 1)                                                 //verifico si termino la transmision
    {
    }
    I2C_Check();
    TMR1L = 0x18;
    TMR1H = 0xFC;
    while (SSPCON2bits.ACKSTAT == 1 && re == 2)                                  //verifico reconocimiento
    {
        T1CONbits.TMR1ON = 1;
        if (PIR1bits.TMR1IF == 1)
        {
            PIR1bits.TMR1IF = 0;
            ++re;
            T1CONbits.TMR1ON = 0;
            TMR1L = 0x18;
            TMR1H = 0xFC;
        }
    }
    T1CONbits.TMR1ON = 0;
//********************************Stop******************************************
    I2C_Check();
    SSPCON2bits.PEN = 1;                                                        //activo stop
    while (SSPSTATbits.P == 0)                                                  //verifico si termino el stop
    {
    }    
}
//------------------------------------------------------------------------------
//-----------------------------I2C WRITE----------------------------------------
//------------------------------------------------------------------------------
void I2C_Write(unsigned char DirW,unsigned char CmdW,unsigned char DirW2)
{
    I2C_Check();
    SSPCON2bits.SEN = 1;                                                        //Activo el start
    __delay_us(5);
    while (SSPCON2bits.SEN == 1)                                                //verifico el start
    {
    }
    I2C_Check();                                                                //verifico el bus
    SSPBUF = DirW;                                                              //ingreso direccion esclavo
    while (SSPSTATbits.BF == 1)                                                 //verifico si termino la transmision
    {
    }
    I2C_Check();
    while (SSPCON2bits.ACKSTAT == 1 && re == 0)                                  //verifico reconocimiento
    {
        T1CONbits.TMR1ON = 1;
        if (PIR1bits.TMR1IF == 1)
        {
            PIR1bits.TMR1IF = 0;
            ++re;
            T1CONbits.TMR1ON = 0;
        }
    }
    T1CONbits.TMR1ON = 0;
//******************************************************************************    
    I2C_Check();                                                                //verifico el bus
    SSPBUF = CmdW;                                                              //ingreso comando para esclavo
    while (SSPSTATbits.BF == 1)                                                 //verifico si termino la transmision
    {
    }
    I2C_Check();
    while (SSPCON2bits.ACKSTAT == 1 && re == 1)                                  //verifico reconocimiento
    {
        T1CONbits.TMR1ON = 1;
        if (PIR1bits.TMR1IF == 1)
        {
            PIR1bits.TMR1IF = 0;
            ++re;
            T1CONbits.TMR1ON = 0;
        }
    }
    T1CONbits.TMR1ON = 0;
//******************************************************************************    
    I2C_Check();                                                                //verifico el bus
    SSPCON2bits.RSEN = 1;                                                       //reinicio start
    while (SSPCON2bits.RSEN == 0)                                               //verifico el start
    {
    }
//******************************************************************************    
    I2C_Check();                                                                //verifico el bus
    SSPBUF = DirW2;                                                             //ingreso direccion esclavo
    while (SSPSTATbits.BF == 1)                                                 //verifico si termino la transmision
    {
    }
    I2C_Check();                                                                //verifico el bus
    while (SSPCON2bits.ACKSTAT == 1 && re == 2)                                  //verifico reconocimiento
    {
        T1CONbits.TMR1ON = 1;
        if (PIR1bits.TMR1IF == 1)
        {
            PIR1bits.TMR1IF = 0;
            ++re;
            T1CONbits.TMR1ON = 0;
        }
    }
    T1CONbits.TMR1ON = 0;    
}
//------------------------------------------------------------------------------
//---------------------------I2C READ 8 BITS------------------------------------
//------------------------------------------------------------------------------
unsigned char I2C_Read_8bits(void)
{ 
    I2C_Check();                                                                //verifico el bus
    SSPCON2bits.RCEN = 1;                                                       //configuro maestro como recepcion
    while (SSPCON2bits.RCEN == 1)                                               //verifico si termino la recepcion
    {
    }
    I2C_Check();                                                                //verifico el bus
    SSPCON2bits.ACKDT = 1;                                                      //acknowledge
    I2C_Check();                                                                //verifico el bus
    SSPCON2bits.ACKEN = 1;                                                      //Acknowledge secuencia
    I2C_Check();                                                                //verifico el bus
    SSPCON2bits.PEN = 1;                                                        //activo stop
    while (SSPSTATbits.P == 0)                                                  //verifico si termino el stop
    {
    }
    DATO_I2C_8bits = SSPBUF;
    return DATO_I2C_8bits;
}
//------------------------------------------------------------------------------