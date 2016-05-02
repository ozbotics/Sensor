#ifndef _TEMP_DEP_SENSOR_H
  #define _TEMP_DEP_SENSOR_H

#include <AsyncSensor.h>

class TempDepSensor {
  public:
    virtual unsigned long setTemperatureAsync(float value)=0;
    virtual bool setTemperatureSync(float temperature)=0;
    
    unsigned long setTemperatureAsync(unsigned int value) {
      return setTemperatureAsync((float)value / 100);
    }
    
    bool setTemperatureSync(unsigned int temperature) {
      return setTemperatureSync((float)temperature / 100);
    }
};

#endif //_TEMP_DEP_SENSOR_H
