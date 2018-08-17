


#ifndef ADS7828_H
#define ADS7828_H

#include <Arduino.h>
#include <Wire.h>

#define ADS7828_DEFAULT_AD 0x48

// #define CMD_DIFFINPUTS 0
// #define CMD_SINGLEENDED 0x80
#define CMD_CH0SEL_SD (0x8 | 0x0)<<4
#define CMD_CH1SEL_SD (0x8 | 0x4)<<4
#define CMD_CH2SEL_SD (0x8 | 0x1)<<4
#define CMD_CH3SEL_SD (0x8 | 0x5)<<4
#define CMD_CH4SEL_SD (0x8 | 0x2)<<4
#define CMD_CH5SEL_SD (0x8 | 0x6)<<4
#define CMD_CH6SEL_SD (0x8 | 0x3)<<4
#define CMD_CH7SEL_SD (0x8 | 0x7)<<4

#define CMD_CH0CH1_DIFF 0x0<<4
#define CMD_CH2CH3_DIFF 0x1<<4
#define CMD_CH4CH5_DIFF 0x2<<4
#define CMD_CH6CH7_DIFF 0x3<<4
#define CMD_CH1CH0_DIFF 0x4<<4
#define CMD_CH3CH2_DIFF 0x5<<4
#define CMD_CH5CH4_DIFF 0x6<<4
#define CMD_CH7CH6_DIFF 0x7<<4

#define POWERDOWN 0<<2
#define POWERDOWN_IREFOFF_ADON 1<<2
#define POWERDOAN_IREFON_ADOFF 2<<2
#define POWERDOWN_ALLON 3<<2


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
