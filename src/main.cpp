#include <Arduino.h>
#include "NTC Sensor/NtcSensor.h"
#include "SerialController/SerialController.h"
#include"Triple Sensor/TripleSensor.h"

NtcSensor iNtcSensor;
TripleSensor iTripleSensor;
SerialController iController(iNtcSensor,iTripleSensor); 

void setup() {
 Serial.begin(9600);
 Serial1.begin(9600,SERIAL_8N1);

 while (!Serial1 || !Serial)
 {
   Serial.println(SERIAL_COMMUNATION_ERROR);
 }
 
}

void loop() {
  iController.serialRead();
}