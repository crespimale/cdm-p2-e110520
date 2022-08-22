#ifndef _MEF_H
#define _MEF_H

#define HRS_DUR 23
#define MIN_DUR 59
#define SEC_DUR 59

typedef enum {START, NORMAL, MOD_HRS, MOD_MIN, MOD_SEC} typeMEF_state;

extern typeMEF_state MEF_state;
extern unsigned char hour_confirm, minute_confirm, second_confirm;
extern unsigned char hour_check, minute_check, second_check;
extern unsigned char hrs_dig1, hrs_dig2, min_dig1, min_dig2, sec_dig1, sec_dig2;

void MEF_DigitInit(void);
void MEF_Init(void);
void MEF_TimeInit(void);
void MEF_TimeUpdate(void);
void MEF_Update(unsigned char);

#endif
