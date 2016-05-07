#ifndef _BUTTON_SENSOR
  #define _BUTTON_SENSOR
  
#include <Arduino.h>

#include <Button.h>

#include <Sensor.h>
#include <TouchableSensor.h>
#include <Value.h>


class ButtonSensor : public Sensor<bool>, public TouchableSensor {
  protected:
    Button* _button; 

  public:
    ButtonSensor(byte pin) : Sensor<bool>() {
      _button = new Button(pin);
      _button->begin();
    }
    
    ~ButtonSensor() {
      delete _button;
    }
    
    virtual unsigned long requestValue() { return 0; }
    
    virtual void refreshValue() {
      value->setValue(_button->read());
    }
    
    bool isTouched() {
      refreshValue();
      
      return value->getValue();
    }
};
  
#endif //_BUTTON_SENSOR
