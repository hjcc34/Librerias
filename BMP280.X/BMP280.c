#include "CFG_BMP280.h"
//------------------------------------------------------------------------------
void ini_bmp280 (void)
{
    I2C_Write(_bmp280_w,_bmp280_ID,_bmp280_r);
    I2C_Read_8bits();
    if (DATO_I2C_8bits == 0x58)
    {
    }
    I2C_Cmd(_bmp280_w,_bmp280_reg_reset,_bmp280_reset);
    I2C_Cmd(_bmp280_w,_bmp280_ctrl_mes,_mode_sleep);
    I2C_Cmd(_bmp280_w,_bmp280_CFG,0x00);
    I2C_Cmd(_bmp280_w,_bmp280_ctrl_mes,0x47);
}
//------------------------------------------------------------------------------
void CALIBRATION_BMP280(void)
{
    unsigned char w;
    for (w=0;w<24;w++)
    {
        unsigned char a = 0x88;
        a += w;
        I2C_Write(_bmp280_w,a,_bmp280_r);
        cal_data[w] = I2C_Read_8bits();
    }
    dig_T1 = cal_data[0]  + (cal_data[1]  = (cal_data[1]<<8));
    dig_T2 = cal_data[2]  + (cal_data[3]  = (cal_data[3]<<8));
    dig_T3 = cal_data[4]  + (cal_data[5]  = (cal_data[5]<<8));
    dig_P1 = cal_data[6]  + (cal_data[7]  = (cal_data[7]<<8));
    dig_P2 = cal_data[8]  + (cal_data[9]  = (cal_data[9]<<8));
    dig_P3 = cal_data[10] + (cal_data[11] = (cal_data[11]<<8));
    dig_P4 = cal_data[12] + (cal_data[13] = (cal_data[13]<<8));
    dig_P5 = cal_data[14] + (cal_data[15] = (cal_data[15]<<8));
    dig_P6 = cal_data[16] + (cal_data[17] = (cal_data[17]<<8));
    dig_P7 = cal_data[18] + (cal_data[19] = (cal_data[19]<<8));
    dig_P8 = cal_data[20] + (cal_data[21] = (cal_data[21]<<8));
    dig_P9 = cal_data[22] + (cal_data[23] = (cal_data[23]<<8));    
}
//------------------------------------------------------------------------------
char read_xlsb(void)
{
    I2C_Write(_bmp280_w,_bmp280_temp_xlsb,_bmp280_r);
    xlsb = I2C_Read_8bits();
    xlsb = xlsb>>4;
    return xlsb;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int read_lsb(void)
{
    I2C_Write(_bmp280_w,_bmp280_temp_lsb,_bmp280_r);
    lsb = I2C_Read_8bits();
    return lsb;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
long read_msb(void)
{
    I2C_Write(_bmp280_w,_bmp280_temp_msb,_bmp280_r);
    msb = I2C_Read_8bits();
    msb = msb<<8;
    return msb;
}
//------------------------------------------------------------------------------
int16_t CALCULO_BMP280(void)
{
    I2C_Write(_bmp280_w,_bmp280_temp_xlsb,_bmp280_r);
    xlsb = I2C_Read_8bits();
//------------------------------------------------------------------------------
    I2C_Write(_bmp280_w,_bmp280_temp_lsb,_bmp280_r);
    lsb = I2C_Read_8bits();
//------------------------------------------------------------------------------
    I2C_Write(_bmp280_w,_bmp280_temp_msb,_bmp280_r);
    msb = I2C_Read_8bits();    
//------------------------------------------------------------------------------    
    int32_t adc_T = ((uint32_t)msb << 12) | ((uint32_t)lsb << 4) | (xlsb >> 4);

    int32_t var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
    int32_t var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;

    t_fine = var1 + var2;

    int32_t temp = (t_fine * 5 + 128) >> 8;  // En décimas de °C
    /*
    return (int16_t)temp; // Devuelve entero: 2534 representa 25.34°C 
     */
    return temp = 54268;
} 

