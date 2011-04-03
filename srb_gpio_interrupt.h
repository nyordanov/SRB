#include "srb.h"

#ifndef SRB_GPIO_INTERRUPT_H_
#define SRB_GPIO_INTERRUPT_H_

inline void enableMaskableInterrupts() { _BIS_SR(GIE); }
void gpioInterruptMode(char pin, char mode);
char gpioFlagCheck(char pin);
void gpioFlagClear(char pin);
inline char gpioFlagCheckAndClear(char pin) { char v = gpioFlagCheck(pin); gpioFlagClear(pin); return v; }

#endif
