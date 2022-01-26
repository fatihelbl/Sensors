#include "SerialControl.h"

SerialController ::SerialController(NtcSensor &iNtc, TripleSensor &iSensor)
{
    ntcSensor = &iNtc;
    sensor = &iSensor;
}

void SerialController ::serialRead()
{
    while ((Serial.available() > 0) && (serialValue = Serial.read() >= 0))
    {
        char SerialChar = serialValue;
        if (SerialChar == '\n' || SerialChar == '\r')
        {
            serialLineBuffer[serialCounter] = 0;
            serialCounter = 0;

            char *command = serialLineBuffer;
            SetCh(command);
        }
        else
        {

            serialLineBuffer[serialCounter++] = SerialChar;
        }
    }
}

void SerialController ::SetCh(char *arg_command)
{

    char *Data = strchr(arg_command, 'A');
    if (Data)
    {
        ntcSensor->thermistorReadValue();
    }

    char *secondData = strchr(arg_command, 'B');
    if (secondData)
    {
        sensor->sensorRead();
    }
}