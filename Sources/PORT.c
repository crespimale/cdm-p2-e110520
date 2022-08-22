#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "mc9s08sh8.h"
#include "PORT.h"

void PORT_Init(){
	MATKEY_ctrl = 0b00001111;
	MATKEY_pullup = 0b11110000;
	MATKEY_data = 0b11111110;
}

