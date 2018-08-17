


#ifndef ADS7828_H
#define ADS7828_H

#include <Arduino.h>
#include <Wire.h>

#define ADS7828_DEFAULT_AD 0x48

class ADS7828{
    public:
        ADS7828();
        ADS7828( uint8_t addr );
        bool begin();
        void writeCmd8(uint8_t value);
        uint16_t read16(void);


    private:
        TwoWire *_i2cBus; 
        uint8_t _addr;

};

#endif
