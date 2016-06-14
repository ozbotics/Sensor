/** @file AsyncSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef ASYNC_SENSOR_H
  #define ASYNC_SENSOR_H

#include <Arduino.h>
#include "Sensor.h"

/**
 * The base of all AsyncSensor(s)
 *
 * Intended to provide a base for all Sensors that can be triggered then be queried for their value later
 * (Although it doesn't seem to be doing too much at the moment)
 */
template <typename T>
class AsyncSensor : public Sensor<T> {
  public:
   /**
    * Constructor
    *
    * @param maxValue The maximum reasonable value
    * @param minValue The minimum reasonable value
   */  
    AsyncSensor(T maxValue, T minValue) : Sensor<T>(maxValue, minValue) {}
};
  
#endif // ASYNC_SENSOR_H
