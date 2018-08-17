/**
@file ADS7828.ino
@brief a short example of ADS7828 library usage

@mainpage

 *  @author    Major Lee
 *  @version   if needed git controlled version
 *  @date      08/2018
 *  @copyright GNU Public License.
 <https://github.com/MajorLee95/ads7828lib>
*/

/**
@file ADS7828.h
@brief include all other include needed
*/

#include <ADS7828.h>

ADS7828 adc;

void setup(){
    adc.begin();
    Serial.begin(115200);
    Serial.println("ADS7828 ADC lib Test...");
}

void loop(){
    adc.writeCmd8( CMD_CH0SEL_SD | POWERDOWN );
    int value = adc.read16();
    Serial.println( "CH0 val = " + value);
}