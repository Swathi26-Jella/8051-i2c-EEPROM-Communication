#include <reg51.h>
#include "i2c.h"

sbit SDA = P2^0;
sbit SCL = P2^1;

void I2C_Delay()
{
    int i;
    for(i=0;i<50;i++);
}

void I2C_Start()
{
    SDA = 1; SCL = 1;
    I2C_Delay();
    SDA = 0;
    I2C_Delay();
    SCL = 0;
}

void I2C_Stop()
{
    SDA = 0; SCL = 1;
    I2C_Delay();
    SDA = 1;
}

void I2C_Write(unsigned char data)
{
    int i;
    for(i=0;i<8;i++)
    {
        SDA = (data & 0x80);
        SCL = 1;
        I2C_Delay();
        SCL = 0;
        data <<= 1;
    }
}
