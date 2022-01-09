#include <stdint.h>
#include "timers/systick/systick.h"
#include "drivers/led/led.h"
#include "drivers/spi/spi.h"

volatile uint64_t ticks = 0;

void SystemInit(void)
{
    SysTick_Init();
    Led_Init();
    Spi_Init();
}