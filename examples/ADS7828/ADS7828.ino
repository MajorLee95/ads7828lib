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

/**
\var adc
\brief an instance of the class under test
Default address is 0x48
*/
ADS7828 adc;

void setup(){
    adc.begin();
    Serial.begin(115200);
    Serial.println("ADS7828 ADC lib Test...");
    Serial.println( CMD_CH0SEL_SD | POWERDOWN_ALLON, HEX);
}

void loop(){
    
    adc.writeCmd8( CMD_CH0SEL_SD | POWERDOWN_ALLON  );
    delay(5);
    int value = adc.read16();
    Serial.println( "CH0 val = " + (String)value);
    delay(500);
}