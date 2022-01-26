#ifndef NTCSENSOR_H
#define NTCSENSOR_H

#include "Arduino.h"
//config

class NtcSensor
{
private:
    /* data */
public:
    float thermistorReadValue();
    float thermistorWriteValue(float);
};

#endif
