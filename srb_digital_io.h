#include "srb.h"

#ifndef SRB_DIGITAL_IO_H_
#define SRB_DIGITAL_IO_H_

void pinMode(char pin, char mode);
void pinFunction(char pin, char mode);
char digitalRead(char pin);
void digitalWrite(char pin, char data);
void digitalToggle(char pin);
void resistorMode(char pin, char mode);

#endif
