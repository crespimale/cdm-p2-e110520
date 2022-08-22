#ifndef _PORT_H
#define _PORT_H

#define MATKEY_data PTBD
#define MATKEY_ctrl PTBDD
#define MATKEY_pullup PTBPE

// Filas
#define MATKEY_pin0 PTBD_PTBD0
#define MATKEY_pin1 PTBD_PTBD1
#define MATKEY_pin2 PTBD_PTBD2
#define MATKEY_pin3 PTBD_PTBD3

// Columnas
#define MATKEY_pin4 PTBD_PTBD4
#define MATKEY_pin5 PTBD_PTBD5
#define MATKEY_pin6 PTBD_PTBD6
#define MATKEY_pin7 PTBD_PTBD7

void PORT_Init(void);

#endif

