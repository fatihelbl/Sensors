#include "TripleSensor.h"
void TripleSensor ::sensorRead()
{

    while (Serial1.available() >= 0)
    {
        Serial1.readBytes(array, SIZE); // 16 byte diziye gelen data atıldı.
        firstData = array[0];

        if (firstData == 255) //Seri haberleşmeden gelen ilk bit 0xff olduğu için.
        {

            temperatureRead();
            c02Read();
            humidityRead();

            //Serial.println(serial_buffer[serial_count],HEX);
        }
    }

    void TripleSensor::temperatureRead()
    {
        double result = (((array[10] * 256) + array[11]) * 0.1); //Gelen 16 byte'lık verinin 10-11. byteleri sıcaklık için
        Serial.print("sicaklik :");
        Serial.println(result);
    }
    void TripleSensor ::humidityRead()
    {
        double result1 = (((array[12] * 256) + array[13]) * 0.1); //Gelen 16 byte'lık verinin 11-12. byteleri nem için
        Serial.print("nem :");
        Serial.println(result1);
    }

    void TripleSensor ::c02Read()
    {
        double result3 = (((array[8] * 256) + array[9])); //Gelen 16 byte'lık verinin 8-9. byteleri CO2 için
        Serial.print("co2 :");
        Serial.println(result3);
    }
}
