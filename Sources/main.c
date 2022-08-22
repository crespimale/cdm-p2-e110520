#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PORT.h"
#include "DISPLAY.h"
#include "MEF.h"

#ifdef __cplusplus
extern "C"
#endif
void MCU_init(void); /* Device initialization function declaration */

void main(void) {
	
  MCU_init();	/* call Device Initialization */
  PORT_Init();
  MATKEY_Init();
  DISPLAY_Init();
  MEF_Init();	
  
  for(;;) {
    /* __RESET_WATCHDOG(); By default COP is disabled with device init. When enabling, also reset the watchdog. */
  }
}


