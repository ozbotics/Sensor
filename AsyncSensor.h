#ifndef ASYNC_SENSOR_H
  #define ASYNC_SENSOR_H

#include <Arduino.h>
#include "Sensor.h"

template <typename T>
class AsyncSensor : public Sensor<T> {
  public:
    AsyncSensor() : Sensor<T>() {}
};
  
#endif // ASYNC_SENSOR_H
