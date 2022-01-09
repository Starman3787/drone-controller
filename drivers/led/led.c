#include <stdint.h>
#include "drivers/led/led.h"
#include "headers/stm32f745xx.h"

int8_t Led_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER |= (0b01 << (PIN_ST_LED * 2));

    return 0;
}

void Led_On(void)
{
    GPIOA->ODR &= ~(0b1 << PIN_ST_LED);
}

void Led_Off(void)
{
    GPIOA->ODR |= (0b1 << PIN_ST_LED);
}