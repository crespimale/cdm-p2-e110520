#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PORT.h"
#include "MATKEY.h"
#include "DISPLAY.h"
#include "MEF.h"

typeMEF_state MEF_state; 			// Estado actual del sistema
unsigned char hour_confirm, minute_confirm, second_confirm;
unsigned char hour_check, minute_check, second_check;
unsigned char hrs_dig1, hrs_dig2, min_dig1, min_dig2, sec_dig1, sec_dig2;

static unsigned char hour, minute, second;

void MEF_DigitInit(){
	hrs_dig1 = 99;
	hrs_dig2 = 99;
	min_dig1 = 99;
	min_dig2 = 99;
	sec_dig1 = 99;
	sec_dig2 = 99;
	hour_confirm = 0;
	hour_check = 0;
	minute_confirm = 0;
	minute_check = 0;
	second_confirm = 0;
	second_check = 0;
}

void MEF_Init(){
	MEF_state = START;
	MEF_DigitInit();
}

void MEF_TimeInit(){
	hour = 12;
	minute = 0;
	second = 0;
}

void MEF_TimeUpdate(){
	second++;
	if (second > SEC_DUR){
		second = 0;
		minute++;
	}
	if (minute > MIN_DUR){
		minute = 0;
		hour++;
	}
	if (hour > HRS_DUR){
		hour = 0;
	}
}

void MEF_Update(unsigned char key){
    switch (MEF_state){
    case START:
    	MEF_TimeInit();
    	DISPLAY_ShowTime(hour,minute,second);
    break;
    case NORMAL:
    	MEF_TimeUpdate();
    	DISPLAY_ShowTime(hour,minute,second);
    break;
/* Si el estado actual es MOD_HRS... */
    case MOD_HRS:
/* Obtengo el valor del primer dígito a modificar utilizando el valor de ‘key’ que se recibió por parámetro. */
    	if (hrs_dig1 == 99) {
	/* Si el el dígito ingresado es válido, lo guardo. */
		if (key <= 2){
			hrs_dig1 = key;
			break;
		} 
/* Si ya se ingresó el primer dígito y este es válido, obtengo el valor del segundo dígito a modificar utilizando el valor de ‘key’ que se recibió por parámetro. */
    	} else if (hrs_dig1 != 99 && hrs_dig2 == 99){
		if (key != 99){
			hrs_dig2 = key;
		/* Confirmo que ya se han ingresado dos dígitos válidos */
			hour_check = 1;
			break;
		} 
    	/* Si se confirmó la operación */

    	} else if (hour_confirm == 1){
    		/* Modifico hora (si fue confirmado) */
    		hour = 0;
    		while (hrs_dig1 > 0){
    			hour += 10;
    			hrs_dig1--;
    		}
    		hour += hrs_dig2;
    		hrs_dig1 = 99;
    		hrs_dig2 = 99;
    		hour_confirm = 0;
    		hour_check = 0;
    		MEF_state = NORMAL;
    	}
    	MEF_TimeUpdate();
    	DISPLAY_ShowTime(hour,minute,second);
    break;
    case MOD_MIN:
    	if (min_dig1 == 99) {
			if (key <= 5){
				min_dig1 = key;
				break;
			} 
    	} else if (min_dig1 != 99 && min_dig2 == 99){
		if (key != 99){
			min_dig2 = key;
			minute_check = 1;
			break;
		} 
    	} else if (minute_confirm == 1){
    		minute = 0;
    		while (min_dig1 > 0){
    			minute += 10;
    			min_dig1--;
    		}
    		minute += min_dig2;
    		min_dig1 = 99;
    		min_dig2 = 99;
    		minute_confirm = 0;
    		minute_check = 0;
    		MEF_state = NORMAL;
    	}
    	MEF_TimeUpdate();
    	DISPLAY_ShowTime(hour,minute,second);
    break;
    case MOD_SEC:
    	if (sec_dig1 == 99) {
			if (key <= 5){
				sec_dig1 = key;
				break;
			} 
    	} else if (sec_dig1 != 99 && sec_dig2 == 99){
		if (key != 99){
			sec_dig2 = key;
			second_check = 1;
			break;
		} 
    	} else if (second_confirm == 1){
    		second = 0;
    		while (sec_dig1 > 0){
    			second += 10;
    			sec_dig1--;
    		}
    		second += sec_dig2;
    		sec_dig1 = 99;
    		sec_dig2 = 99;
    		second_confirm = 0;
    		second_check = 0;
    		MEF_state = NORMAL;
    	}
    	MEF_TimeUpdate();
    	DISPLAY_ShowTime(hour,minute,second);
    break;
    }
}
