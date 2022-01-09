#ifndef DRIVERS_SPI_H__
#define DRIVERS_SPI_H__

#include <stdint.h>

#define PIN_SPI4_IMU_DRDY       (1)
#define PIN_SPI4_IMU_SCK        (2)
#define PIN_SPI4_IMU_SS         (4)
#define PIN_SPI4_IMU_MISO       (5)
#define PIN_SPI4_IMU_MOSI       (6)

int8_t Spi_Init(void);
uint8_t Spi_Read(uint8_t address);
int8_t Spi_Write(uint8_t address, uint8_t data);
uint16_t Spi_Transmit(uint16_t data);

#endif