#include "srb_advanced_io.h"

// shiftOut
void shiftOut(char dataPin, char clockPin, char bitOrder, unsigned char value) {
	char dataPort, clockPort;
	char i, bitToSend;

	mapPin(&dataPin, &dataPort);
	mapPin(&clockPin, &clockPort);
	
	// stream out bytes
	for (i = 0; i < 8; i++) {
		if (bitOrder == MSBFIRST)
			bitToSend = 128 & value;
		else
			bitToSend = 1 & value;
		
		switch (clockPort) {
			case 1:
				switch (dataPort) {
					case 1:
						if(bitToSend == 0) {
							P1OUT &= ~dataPin;
						} else {
							P1OUT |= dataPin;
						}
					break;
					case 2:
						if (bitToSend == 0) {
							P2OUT &= ~dataPin;
						} else {
							P2OUT |= dataPin;
						}
						break;
					default:
						return;
					}

				// toggle clock
				P1OUT |= clockPin;
				P1OUT &= ~clockPin;
			break;
			case 2:
				switch (dataPort) {
					case 1:
						if(bitToSend == 0) {
							P1OUT &= ~dataPin;
						} else {
							P1OUT |= dataPin;
						}
					break;
					case 2:
						if (bitToSend == 0) {
							P2OUT &= ~dataPin;
						} else {
							P2OUT |= dataPin;
						}
						break;
					default:
						return;
				}
				
				// toggle clock
				P2OUT |= clockPin;
				P2OUT &= ~clockPin;
			break;
			default:
				return;
		}

		if (bitOrder == MSBFIRST)
			value = value << 1;
		else
			value = value >> 1;
	}
}
