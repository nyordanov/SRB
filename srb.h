#ifndef _SRB_H
#define _SRB_H

#include <io.h>
#include <signal.h>

#define LOW       (0)
#define HIGH      (1)

#define INPUT     (0) // for pinMode
#define OUTPUT    (1) // for pinMode

#define MSBFIRST  (0) // for bit ordering
#define MSBLAST   (1) // for bit ordering

#define EXTERNAL  (0) // for pinFunction
#define INTERNAL  (1) // for pinFunction

#define PULLDOWN  (0) // for resistorMode
#define PULLUP    (1) // for resistorMode

#define DISABLED  (2)
#define ENABLED   (3)

#define FALLING   (0)
#define RISING    (1)

// functions
void init();
void setup();
void loop();
void mapPin(char *pin, char *port);
char pinNum(char pin);

inline void wdtHold() {
	WDTCTL = WDTPW + WDTHOLD;
}

#endif