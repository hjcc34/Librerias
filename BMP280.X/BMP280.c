#include "CFG_BMP280.h"
//------------------------------------------------------------------------------
void ini_bmp280 (void)
{
    I2C_Write(_bmp280_w,_bmp280_ID,_bmp280_r);
    I2C_Read_8bits();
    if (I2C_Read_8bits() == 0x58)
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
    for (w = 0; w <6; w++)
    {
        unsigned char a = 0x88 + w;
        I2C_Write(_bmp280_w, a, _bmp280_r);
        cal_data[w] = I2C_Read_8bits();
    }

    dig_T1 = (uint16_t)(cal_data[0] | (cal_data[1] << 8));
    dig_T2 = (int16_t)(cal_data[2] | (cal_data[3] << 8));
    dig_T3 = (int16_t)(cal_data[4] | (cal_data[5] << 8));

}
//------------------------------------------------------------------------------
int32_t CALCULO_BMP280(void)
{
    I2C_Write(_bmp280_w,_bmp280_temp_msb,_bmp280_r);
    I2C_Read_8bits_3bytes();     
//------------------------------------------------------------------------------
    adc_T = (((DATO_READ_8b_3 = DATO_READ_8b_3 << 12) | (DATO_READ_8b_2 = DATO_READ_8b_2 << 4)  | (DATO_READ_8b_1 = DATO_READ_8b_1 >> 4)));
    
    var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
    var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;

    t_fine = var1 + var2;
    temp = (t_fine * 5 + 128);
    temp = temp >> 8;                                                           // Temperatura en °C x 100
    return temp;                                                                // Devuelve entero: 2534 representa 25.34°C 
}

