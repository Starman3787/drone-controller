#ifndef SYSTICK_H__
#define SYSTICK_H__

#include <stdint.h>
#include <time.h>

void SysTick_Handler(void);

extern volatile uint64_t ticks;
// extern volatile time_t unix;

void SysTick_Init(void);

#endif