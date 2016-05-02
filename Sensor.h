#ifndef _SENSOR_H
  #define _SENSOR_H
  
#include <Arduino.h>
#include <Value.h>

class SensorBase {
  public:
    virtual unsigned long requestValue();
    virtual void refreshValue();
};

template <typename T>
class Sensor : public SensorBase {
  public:
    Value<T>* value; 
    Sensor(byte displayLength=1, byte displayDecimals=0, unsigned int divideBy=1) : SensorBase() {
      value = new Value<T>();
    
      value->setDisplayLength(displayLength);
      value->setDisplayDecimals(displayDecimals);
      value->setDivideBy(divideBy);
    }
    
    ~Sensor() {
      delete value;
    }

    virtual unsigned long requestValue()=0;

    virtual void refreshValue()=0;

    
    T getRefreshedValue() { 
      refreshValue();
      
      return value->getValue();
    }
};
  
#endif //_SENSOR_H
