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
#define OFFSET 0.03 //I noticed 30mV offset in my circuit 

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
    
    // adc.writeCmd8( CMD_CH0SEL_SD | POWERDOWN_ALLON  ); // to turn on internal ref
    // delay(2);
    
    // adc.writeCmd8( CMD_CH0SEL_SD | POWERDOWN_ALLON  );
    adc.writeCmd8( CMD_CH2SEL_SD | POWERDOWN_IREFOFF_ADON  ); //external ref
    int value = adc.read16();
    Serial.println( "CH2 val = " + (String)value + " en Volt (ref2.5V) : " + (String)((value*2.5/4086.0)+OFFSET));
    // Serial.println( "CH1 sans correction : val = " + (String)value + " en Volt (ref2.5V) : " + (String)((value*2.5/4086.0)));
    delay(500);
}