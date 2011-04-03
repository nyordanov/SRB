#include "srb_digital_io.h"

// sets INPUT/OUTPUT pins
void pinMode(char pin, char mode) {
	char port;
	mapPin(&pin, &port);

	switch (mode) {
		case OUTPUT:
			switch (port) {
				case 1:
					P1DIR |= pin;
				break;
				case 2:
					P2DIR |= pin;
				break;
			}
		break;
		case INPUT:
			switch (port) {
				case 1:
					P1DIR &= ~pin;
				break;
				case 2:
					P2DIR &= ~pin;
				break;
			}
		break;
  }
}

// sets INTERNAL/EXTERNAL ports
void pinFunction(char pin, char mode) {

  char port;
  mapPin(&pin, &port);

  switch (mode) {
    case INTERNAL:
      switch (port) {
        case 1:
          P1SEL |= pin;
        break;
        case 2:
          P2SEL |= pin;
          break;
      }
      break;
    case EXTERNAL:
      switch (port) {
        case 1:
          P1SEL &= ~pin;
          break;
        case 2:
          P2SEL &= ~pin;
          break;
      }
    break;
  }
}


// digitalRead
char digitalRead(char pin) {
	char port, pin_num;
	pin_num = pinNum(pin);
	mapPin(&pin, &port);

	switch (port) {
		case 1:
			return (P1IN & pin) >> pin_num;
		break;
		case 2:
			return (P2IN & pin) >> pin_num;
		break;
	}

	return 0;
}

// digitalWrite
void digitalWrite(char pin, char data) {
	char port;
	mapPin(&pin, &port);

	switch (data) {
		case HIGH:
			switch (port) {
				case 1:
					P1OUT |= pin;
				break;
				
				case 2:
					P2OUT |= pin;
				break;
			}
		break;
		
		case LOW:
			switch (port) {
				case 1:
					P1OUT &= ~pin;
				break;
				case 2:
					P2OUT &= ~pin;
				break;
			}
		break;
  }
}

void digitalToggle(char pin) {
	char port;
	mapPin(&pin, &port);

	switch (port) {
		case 1:
			P1OUT ^= pin;
		break;
		case 2:
			P2OUT ^= pin;
		break;
	}
}

// resistorMode - set internal pullup/pulldown resistors
void resistorMode(char pin, char mode) {
	char port;
	mapPin(&pin, &port);

	switch (mode) {
		case DISABLED:
			switch(port) {
				case 1:
					P1REN &= ~pin;
				break;
				case 2:
					P2REN &= ~pin;
				break;
			}
		break;
		case PULLDOWN:
			switch(port) {
				case 1:
					P1REN |= pin;
					P1OUT &= ~pin;
				break;
				case 2:
					P2REN |= pin;
					P1OUT &= ~pin;
				break;
			}
		break;
		case PULLUP:
			switch(port) {
				case 1:
					P1REN |= pin;
					P1OUT |= pin;
				break;
				case 2:
					P2REN |= pin;
					P1OUT |= pin;
				break;
			}
		break;
	}
}
