#ifndef TRIPLESENSOR_H
#define TRIPLESENSOR_H
#include <Arduino.h>
#define SIZE 16

class TripleSensor
{
private:
    //int c = 0;
    // char serial_buffer[SIZE] = {};
    //byte serial_count = 0;
    byte array[SIZE] = {};
    int firstData;
    unsigned long startMillis, standByTime;

    // tx:18, rx:19;

public:
    bool waitTime;
    void sensorRead();
    void temperatureRead();
    void co2Read();
    void humidityRead();
    void updateCo2();
    void resetTimer();
    void checkTimer();
};

#endif