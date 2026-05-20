
#include <OneWire.h>
#include <DallasTemperature.h>

#define one_wire 5

OneWire wire(one_wire);

DallasTemperature sensor(&wire);

void sensor_begin()
{
    sensor.begin();
}

float temp_fromsensor()
{
    sensor.requestTemperatures();

    return sensor.getTempCByIndex(0);
}//sensor_ds18b20.cpp

