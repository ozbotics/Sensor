/** @file TempDepSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _TEMP_DEP_SENSOR_H
  #define _TEMP_DEP_SENSOR_H

#include <AsyncSensor.h>

/**
 * The base of all Finite State Machines (FSM)
 *
 * Requires that subclasses implement setTemperatureAsync() & setTemperatureSync()
 * Provides ability to inform temperature dependant sensors of the current temperture
 */
class TempDepSensor {
  public:
  
   /**
    * set the temperature
    *
    * @param value The temperature in deg C
    *
    * @return the number of milliseconds to wait before confirming the operation suceeded
    */
    virtual unsigned long setTemperatureAsync(float value)=0;
    
   /**
    * set the temperature, and block while waiting for the process to complete
    *
    * @param temperature The temperature in deg C
    *
    * @return true if the operation suceeded
    */
    virtual bool setTemperatureSync(float temperature)=0;
    
   /**
    * set the temperature
    *
    * @param value The temperature in deg C (expressed in fixed-point)
    *
    * @return the number of milliseconds to wait before confirming the operation suceeded
    */
    unsigned long setTemperatureAsync(unsigned int value) {
      return setTemperatureAsync((float)value / 100);
    }
    
   /**
    * set the temperature, and block while waiting for the process to complete
    *
    * @param temperature The temperature in deg C (expressed in fixed-point)
    *
    * @return true if the operation suceeded
    */
    bool setTemperatureSync(unsigned int temperature) {
      return setTemperatureSync((float)temperature / 100);
    }
};

#endif //_TEMP_DEP_SENSOR_H
