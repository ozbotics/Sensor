/** @file TouchableSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _TOUCHABLE_SENSOR_H
  #define _TOUCHABLE_SENSOR_H

/**
 * The TouchableSensor Interface
 *
 * Requires that subclasses implement isTouched()
 */
class TouchableSensor {
  public:
  
   /**
    * implement this to identify if the sensor is touched
    */  
    virtual bool isTouched()=0;
};

#endif //_TOUCHABLE_SENSOR_H
