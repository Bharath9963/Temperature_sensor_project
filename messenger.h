#ifndef MESSENGER_H
#define MESSENGER_H

void messenger_begin(unsigned long baud);

void send_temp(float temp);

void send_alert();

void send_log(const char *msg);

#endif
