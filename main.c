#include <stdint.h>
#include "headers/stm32f745xx.h"
#include "timers/systick/systick.h"

void main(void)
{
    uint64_t i = 0;
    while (1)
    {
        i++;
        i++;
        i--;
    }
}