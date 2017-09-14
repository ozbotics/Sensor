/** @file SensorValue.h 
  *  Copyright (c) 2017 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */
#ifndef _SENSOR_VALUE_H
  #define _SENSOR_VALUE_H

#include <Value.h>
#include <Sensor.h>

template <typename T>
class Sensor;

/**
  *  SensorValue class template. 
  *  Value that is able to initialize a Sensor
*/
template <class T>
class SensorValue : public Value<T> {
  protected:
    Sensor<T>* _sensor;
    
  public:
  /**
    * constructor
    * @param displayLength The total width of the output string.
    * @param displayDecimals The number of decimal places.
    * @param divideBy Divide the value by this amount, eg; 60000 to convert milliseconds to minutes.
    */  
    SensorValue(Sensor<T>* sensor, byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : _sensor(sensor), Value<T>(displayLength, displayDecimals, divideBy) { }
    
   /**
    * persist the value to the Sensor (set the Sensor's initial value)
    * @return nothing
    */  
    virtual void persistValue() {
      Value<T>::persistValue();

      //Serial.println("SensorValue::persistValue()");
      _sensor->initValue(Value<T>::getValue());
    }
    
};
#endif // _SENSOR_VALUE_H
