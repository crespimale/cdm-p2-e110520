#ifndef _DISPLAY_H
#define _DISPLAY_H

void DISPLAY_Init(void);
void DISPLAY_UpdateHour(unsigned char);
void DISPLAY_UpdateMinute(unsigned char);
void DISPLAY_UpdateSecond(unsigned char);
void DISPLAY_ShowTime(unsigned char, unsigned char, unsigned char);

#endif
