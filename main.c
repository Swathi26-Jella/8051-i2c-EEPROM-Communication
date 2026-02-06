#include <reg51.h>
#include "i2c.h"

void main()
{
    while(1)
    {
        I2C_Start();
        I2C_Write(0xA0);   // EEPROM address
        I2C_Write(0x55);   // sample data
        I2C_Stop();

        for(int i=0;i<50000;i++);
    }
}
