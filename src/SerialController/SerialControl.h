#ifndef SERIALCONTROL_H
#define SERIALCONTROL_H
#include "Arduino.h"
#include "Triple Sensor/TripleSensor.h"
#include "NTC Sensor/NtcSensor.h"
#include "config.h"

class SerialController
{
private:
    char serialValue = 0;
    byte serialCounter = 0;
    char serialLineBuffer[MAX_CMD_SIZE];

    NtcSensor *ntcSensor;
    TripleSensor *sensor;

public:
    SerialController(NtcSensor &, TripleSensor &);
    void serialRead();
    void SetCh(char *);
};

#endif
