#ifndef DRIVERS_LED_H__
#define DRIVERS_LED_H__

#include <stdint.h>

#define PIN_ST_LED      (2)

int8_t Led_Init(void);
void Led_On(void);
void Led_Off(void);

#endif