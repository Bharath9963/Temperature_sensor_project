#include "sensor.h"

float temp_limit = 35.0;

int time_del = 2000;

String cmd = "";

int check_threshold(float temp, float limit)
{
    if(temp > limit)
    {
        return 1;
    }

    return 0;
}

void alert()
{
    Serial.println("error : excceded threshold");
}

void print_config()
{
    Serial.print("threshold : ");
    Serial.println(temp_limit);

    Serial.print("delay : ");
    Serial.println(time_del);
}

void user_can_change(String ch)
{
    ch.trim();

    if(ch.startsWith("SET_THRESHOLD="))
    {
        String val = ch.substring(strlen("SET_THRESHOLD="));

        temp_limit = val.toFloat();

        Serial.print("new val : ");
        Serial.println(temp_limit);
    }

    else if(ch.startsWith("SET_DELAY="))
    {
        String val = ch.substring(strlen("SET_DELAY="));

        time_del = val.toInt();

        Serial.print("new delay : ");
        Serial.println(time_del);
    }

    else if(ch == "GET_CONFIG")
    {
        print_config();
    }

    else
    {
        Serial.println("invalid command");
    }
}

void setup()
{
    Serial.begin(115200);

    sensor_begin();

    Serial.println("temperature monitoring");
}

void loop()
{
    float temp = temp_fromsensor();

    Serial.print("temperature : ");
    Serial.print(temp);
    Serial.println(" C");

    if(check_threshold(temp, temp_limit))
    {
        alert();
    }

    if(Serial.available())
    {
        cmd = Serial.readStringUntil('\n');

        user_can_change(cmd);
    }

    delay(time_del);
}