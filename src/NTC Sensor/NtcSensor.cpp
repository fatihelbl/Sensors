#include "NtcSensor.h"
#include "config.h"

float NtcSensor::thermistorReadValue()
{
    float average = 0;
    for (byte i = 0; i < THERMISTOR_READ_SAMPLE; i++)
    {
        average += analogRead(THERMISTORPIN); //Daha stabil değer okumak için 5 kere okuyup bölmemiz gerek.
    }
    average /= THERMISTOR_READ_SAMPLE;
    average = 1023 / average - 1;
    average = THERMISTOR_RESISTOR / average;

    float steinhart;
    steinhart = average / THERMISTOR_NOMINAL;
    steinhart = log(steinhart);
    steinhart /= BCO_EFFICIENT;
    steinhart += 1.0 / (TEMPERATURE_NOMINAL + 273.15);
    steinhart = 1.0 / steinhart;
    steinhart -= 273.15;
    thermistorWriteValue(steinhart);

    return steinhart;
}

float NtcSensor ::thermistorWriteValue(float arg_read_value)
{

    return Serial.println(arg_read_value);
}