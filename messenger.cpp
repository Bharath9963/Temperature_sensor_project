#include "messenger.h"

void messenger_begin(unsigned long baud)
{
    Serial.begin(baud);
}

void send_temp(float temp)
{
    Serial.print("temperature : ");
    Serial.print(temp);
    Serial.println(" C");
}

void send_alert()
{
    Serial.println("error : exceeded threshold");
}

void send_log(const char *msg)
{
    Serial.println(msg);
}
