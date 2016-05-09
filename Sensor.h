/** @file Sensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _SENSOR_H
  #define _SENSOR_H
  
#include <Arduino.h>
#include <Value.h>

/**
 * The base of all Sensors
 *
 * Requires that subclasses implement requestValue() & refreshValue()
 * Provides a uniform interface for sensors to be triggered and the results read
 */
class SensorBase {
  public:
  
   /**
    * implement this to define how the sensor is prompted to take a reading and determine how long the process should take
    * 
    * @return the number of milliseconds until the reading will be available. Note: this may well be 0
    */
    virtual unsigned long requestValue() =0;
    
    
   /**
    * implement this to define how the sensor is queried for the reading
    */
    virtual void refreshValue() =0;
};

/**
 * Sensor class template
 *
 * Provides a uniform interface for sensors to have their sensedValue display formatting configured
 */
template <typename T>
class Sensor : public SensorBase {
  public:
    Value<T>* value;  /**< public variable  value  The value of the last sensor reading  */
    
   /**
    * Constructor
    *
    * @param displayLength The total width of the output string.
    * @param displayDecimals The number of decimal places.
    * @param divideBy Divide the value by this amount, eg; 60000 to convert milliseconds to minutes.
    */
    Sensor(byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : SensorBase() {
      value = new Value<T>();
    
      value->setDisplayLength(displayLength);
      value->setDisplayDecimals(displayDecimals);
      value->setDivideBy(divideBy);
    }
    
   /**
    * Destructor
    */
    ~Sensor() {
      delete value;
    }

   /**
    * implement this to define how the sensor is prompted to take a reading and determine how long the process should take
    * 
    * @return the number of milliseconds until the reading will be available. Note: this may well be 0
    */
    virtual unsigned long requestValue()=0;

   /**
    * implement this to define how the sensor is queried for the reading
    */
    virtual void refreshValue()=0;

    
   /**
    * shortcut to force value to be refreshed then returned
    *
    * @return the sensor value
    */
    T getRefreshedValue() { 
      refreshValue();
      
      return value->getValue();
    }
};
  
#endif //_SENSOR_H
