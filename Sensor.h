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
  protected:
    T _minValue;
    T _maxValue;
    
  public:
    Value<T>* value;  /**< public variable  value  The value of the last sensor reading  */
    
   /**
    * Constructor
    *
    * @param maxValue The maximum reasonable value (used in inBounds() check)
    * @param minValue The minimum reasonable value (used in inBounds() check)
    * @param displayLength The total width of the output string.
    * @param displayDecimals The number of decimal places.
    * @param divideBy Divide the value by this amount, eg; 60000 to convert milliseconds to minutes.
    */
    Sensor(T maxValue=0, T minValue=0, byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : _maxValue(maxValue), _minValue(minValue), SensorBase() {
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
    
  protected:
   /**
    * check if the candidate value is within bounds
    *
    * Note: maxValue is not considered if maxValue & minValue have at default values
    *
    * @param candidateValue The candidate value
    * @return true if candidateValue is between minValue & maxValue
    */
    bool _inBounds(T candidateValue) {
      return ((candidateValue >= _minValue) && ( ((_minValue == 0) && (_maxValue == 0)) || (candidateValue <= _maxValue) ));
    }
    
   /**
    * update the sensor value
    *
    * Note: if the value is not inBounds, it will be ignored
    *
    * @param val The candidate value
    */
    void _updateValue(T val) {
      if (_inBounds(val)) {
        value->setValue(val);
      }
    }

};
  
#endif //_SENSOR_H
