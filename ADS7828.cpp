
#include "ADS7828.h"


ADS7828::ADS7828(){
    _addr = ADS7828_DEFAULT_AD;
}

bool ADS7828::begin(){
    _i2cBus = &Wire;
    _i2cBus->begin();
    
    return true;
}

void ADS7828::writeCmd8(uint8_t value) {
    _i2cBus->beginTransmission(_addr);
    _i2cBus->write((uint8_t)value);
    _i2cBus->endTransmission();
}
/*
uint8_t ADS7828::read8() {
    uint8_t value;
    _i2cBus->beginTransmission(_addr);
    _i2cBus->endTransmission(false);

    _i2cBus->requestFrom(_addr, 1);
    value = _i2cBus->read();

    return value;
}
*/

uint16_t ADS7828::read16(){
    uint16_t value;

    _i2cBus->beginTransmission((uint8_t)_addr);
    _i2cBus->endTransmission();
    _i2cBus->requestFrom((uint8_t)_addr, (byte)2);
    value = (_i2cBus->read() << 8) | _i2cBus->read();

    return value;
}
