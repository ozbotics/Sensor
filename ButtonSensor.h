/** @file ButtonSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _BUTTON_SENSOR
  #define _BUTTON_SENSOR
  
#include <Arduino.h>

#include <Button.h>

#include <Sensor.h>
#include <TouchableSensor.h>
#include <Value.h>

/**
 * ButtonSensor
 *
 * Provides standard Sensor interface to Button
 */
class ButtonSensor : public Sensor<bool>, public TouchableSensor {
  protected:
    Button* _button; /**< protected variable  _button Pointer to Button */

  public:
   /**
    * Constructor
    *
    * @param pin The pin that the button  is connected to
    */
    ButtonSensor(byte pin) : Sensor<bool>() {
      _button = new Button(pin);
      _button->begin();
    }
    
   /**
    * Destructor
    */
    ~ButtonSensor() {
      delete _button;
    }
    
   /**
    * over-ride requestValue to always return 0
    *  (takes no time to prepare)
    */
    virtual unsigned long requestValue() { return 0; }
    
   /**
    * over-ride requestValue to read value from Button
    */
    virtual void refreshValue() {
      value->setValue(_button->read());
    }
    
   /**
    * implement isTouched interface
    *
    * @return bool
    */
    bool isTouched() {
      refreshValue();
      
      return value->getValue();
    }
};
  
#endif //_BUTTON_SENSOR
