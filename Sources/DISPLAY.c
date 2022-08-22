#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "DISPLAY.h"
#include "MEF.h"

char time[] = "HH:MM:SS";
static unsigned char change;

void DISPLAY_Init(){
	change = 0;
}

void DISPLAY_UpdateHour(unsigned char hour){
	time[0] = (hour / 10) + '0';
	time[1] = (hour % 10) + '0';
}

void DISPLAY_UpdateMinute(unsigned char minute){
	time[3] = (minute / 10) + '0';
	time[4] = (minute % 10) + '0';
}

void DISPLAY_UpdateSecond(unsigned char second){
	time[6] = (second / 10) + '0';
	time[7] = (second % 10) + '0';
}

void DISPLAY_ShowTime(unsigned char hour, unsigned char minute, unsigned char second){
	switch (MEF_state){
		case START:
		case NORMAL:
			DISPLAY_UpdateHour(hour);
			DISPLAY_UpdateMinute(minute);
			DISPLAY_UpdateSecond(second);
			break;
		case MOD_HRS:
			if (hrs_dig1 == 99){
				if (change == 0){
					time[0] = '0';
					time[1] = '0';
					DISPLAY_UpdateMinute(minute);
					DISPLAY_UpdateSecond(second);
				} else {
					time[0] = ' ';
					time[1] = ' ';
					DISPLAY_UpdateMinute(minute);
					DISPLAY_UpdateSecond(second);
				}
			} else if (hrs_dig1 != 99 && hrs_dig2 == 99){
				time[0] = hrs_dig1 + '0';
				if (change == 0){
					time[1] = '0';
					DISPLAY_UpdateMinute(minute);
					DISPLAY_UpdateSecond(second);
				} else {
					time[1] = ' ';
					DISPLAY_UpdateMinute(minute);
					DISPLAY_UpdateSecond(second);
				}
			} else {
				time[0] = hrs_dig1 + '0';
				time[1] = hrs_dig2 + '0';
				DISPLAY_UpdateMinute(minute);
				DISPLAY_UpdateSecond(second);
			}
			change = change ^ 0x1;
			break;
		case MOD_MIN:
			if (min_dig1 == 99){
				if (change == 0){
					DISPLAY_UpdateHour(hour);
					time[3] = '0';
					time[4] = '0';
					DISPLAY_UpdateSecond(second);
				} else {
					DISPLAY_UpdateHour(hour);
					time[3] = ' ';
					time[4] = ' ';
					DISPLAY_UpdateSecond(second);
				}
			} else if (min_dig1 != 99 && min_dig2 == 99){
				time[3] = min_dig1 + '0';
				if (change == 0){
					DISPLAY_UpdateHour(hour);
					time[4] = '0';
					DISPLAY_UpdateSecond(second);
				} else {
					DISPLAY_UpdateHour(hour);
					time[4] = ' ';
					DISPLAY_UpdateSecond(second);
				}
			} else {
				DISPLAY_UpdateHour(hour);
				time[3] = min_dig1 + '0';
				time[4] = min_dig2 + '0';
				DISPLAY_UpdateSecond(second);
			}
			change = change ^ 0x1;
			break;	
		case MOD_SEC:
			if (sec_dig1 == 99){
				if (change == 0){
					DISPLAY_UpdateHour(hour);
					DISPLAY_UpdateMinute(minute);
					time[6] = '0';
					time[7] = '0';
				} else {
					DISPLAY_UpdateHour(hour);
					DISPLAY_UpdateMinute(minute);
					time[6] = ' ';
					time[7] = ' ';
				}
			} else if (sec_dig1 != 99 && sec_dig2 == 99){
				time[6] = sec_dig1 + '0';
				if (change == 0){
					DISPLAY_UpdateHour(hour);
					DISPLAY_UpdateMinute(minute);
					time[7] = '0';
				} else {
					DISPLAY_UpdateHour(hour);
					DISPLAY_UpdateMinute(minute);
					time[7] = ' ';
				}
			} else {
				DISPLAY_UpdateHour(hour);
				DISPLAY_UpdateMinute(minute);
				time[6] = sec_dig1 + '0';
				time[7] = sec_dig2 + '0';
			}
			change = change ^ 0x1;
			break;
	} 
}
