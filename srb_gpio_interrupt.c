#include "srb_gpio_interrupt.h"

// gpioInterruptMode
void gpioInterruptMode(char pin, char mode) {
	char port;
	mapPin(&pin, &port);

	switch (mode) {
		case DISABLED:
			if (port == 1)
				P1IE &= ~pin;
			else
				P2IE &= ~pin;
		break;
		case FALLING:
			if (port == 1) {
				P1IES |= pin;
				P1IFG &= ~pin;
				P1IE |= pin;
			} else {
				P2IES |= pin;
				P2IFG &= ~pin;
				P2IE |= pin;
			}
		break;
		case RISING:
			if (port == 1) {
				P1IES &= ~pin;
				P1IFG &= ~pin;
				P1IE |= pin;
			} else {
				P2IES &= ~pin;
				P2IFG &= ~pin;
				P2IE |= pin;
			}
		break;
	}
}

// gpioFlagCheck
char gpioFlagCheck(char pin) {
	char pin2, port;
	pin2 = pinNum(pin);
	mapPin(&pin, &port);

	switch (port) {
		case 1:
			return (P1IFG & pin) >> pin2;
		case 2:
			return (P2IFG & pin) >> pin2;
		default:
			return 0;
	} 
}

// gpioFlagClear
void gpioFlagClear(char pin) {
	char port;
	mapPin(&pin, &port);

	switch (port) {
		case 1:
			P1IFG &= ~pin;
		break;
		case 2:
			P2IFG &= ~pin;
		break;
  }
}
