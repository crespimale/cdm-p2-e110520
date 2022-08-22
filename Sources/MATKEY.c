#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PORT.h"
#include "MEF.h"

static unsigned char n_pin;

void MATKEY_Init(){
	n_pin = 0;
}

void MATKEY_Shift(){
	  /* Corrimiento de PTBD[3:0] a izquierda */
	  switch(n_pin){
	  case 0:
		  MATKEY_pin0 = 1;
		  MATKEY_pin1 = 0;
		  n_pin++;
		  break;
	  case 1:
		  MATKEY_pin1 = 1;
		  MATKEY_pin2 = 0;
		  n_pin++;
		  break;
	  case 2:
		  MATKEY_pin2 = 1;
		  MATKEY_pin3 = 0;
		  n_pin++;
		  break;
	  case 3:
		  MATKEY_pin3 = 1;
		  MATKEY_pin0 = 0;
		  n_pin = 0;
		  break;
	  }
}

unsigned char MATKEY_Check(){
	/* Compruebo si se presion� A, B, C, D o Asterisco */
	switch(MATKEY_data){
	/* Se presion� ASTERISCO */
	case 0b11100111:
		if (MEF_state == START){
			MEF_state = NORMAL;
		}
		return 0x63;
	/* Se presion� A */
	case 0b01111110:
		if (MEF_state == NORMAL){
			MEF_state = MOD_HRS;
		} else if (MEF_state == MOD_HRS && hour_check == 1){
			hour_confirm = 1;
		} 
		return 0x63;
	/* Se presion� B */
	case 0b01111101:
		if (MEF_state == NORMAL){
			MEF_state = MOD_MIN;
		} else if (MEF_state == MOD_MIN && minute_check == 1){
			minute_confirm = 1;
		}
		return 0x63;
	/* Se presion� C */
	case 0b01111011: 
		if (MEF_state == NORMAL){
			MEF_state = MOD_SEC;
		} else if (MEF_state == MOD_SEC && second_check == 1){
			second_confirm = 1;
		}
		return 0x63;
	/* Se presion� D */
	case 0b01110111:
		MEF_Init();
		return 0x63;
	/* Se presion� 1 */
	case 0b11101110:
		return 0x1;
	/* Se presion� 2 */	
	case 0b11011110:
		return 0x2;
	/* Se presion� 3 */	
	case 0b10111110:
		return 0x3;
	/* Se presion� 4 */	
	case 0b11101101:
		return 0x4;
	/* Se presion� 5 */	
	case 0b11011101:
		return 0x5;
	/* Se presion� 6 */	
	case 0b10111101:
		return 0x6;
	/* Se presion� 7 */
	case 0b11101011:
		return 0x7;
	/* Se presion� 8 */	
	case 0b11011011:
		return 0x8;
	/* Se presion� 9 */	
	case 0b10111011:
		return 0x9;
	/* Se presion� 0 */	
	case 0b11010111:
		return 0x0;
}
	
}



