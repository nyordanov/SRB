#include "srb.h"

void setup();
void loop();

int main(void) {
	init();
	setup();
	
	for (;;)
		loop();
}

void init() {
	P1DIR = 0xFF; // default to OUTPUT
	P2DIR = 0xFF; // default to OUTPUT
	P1OUT = 0; // defualt to LOW
	P2OUT = 0; // default to LOW
	
	P1REN = 0; // default no resistors
	P2REN = 0; // default no resistors
	P1IE  = 0; // default no interrupts
	P2IE  = 0; // default no interrupts
}

char pinNum(char pin) {
	// assume pin is in [10; 19)
	pin -= 10;
	
	// if we're using P2
	if (pin > 10) {
		pin -= 10;
	}
	
	return pin;
}

void mapPin(char* pin, char* port) {
	// assume it's P1
	*port = 1;
	
	// if we're using P2
	if (*pin > 20) {
		*port = 2;
	}
	
	*pin = (1 << pinNum(*pin));
}