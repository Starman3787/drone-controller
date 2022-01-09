#include <stdint.h>
#include "drivers/spi/spi.h"
#include "headers/stm32f745xx.h"
#include "util/delay/delay.h"
#include "drivers/imu/imu.h"

int8_t Spi_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;

    RCC->APB2ENR |= RCC_APB2ENR_SPI4EN;

    // set alternate function
    GPIOE->AFR[0] |= (0b0101 << (PIN_SPI4_IMU_SCK * 4)) |
                     (0b0101 << (PIN_SPI4_IMU_MISO * 4)) |
                     (0b0101 << (PIN_SPI4_IMU_MOSI * 4));

    // alternate function mode
    GPIOE->MODER |= (0b10 << (PIN_SPI4_IMU_SCK * 2)) |
                    (0b01 << (PIN_SPI4_IMU_SS * 2)) |
                    (0b10 << (PIN_SPI4_IMU_MISO * 2)) |
                    (0b10 << (PIN_SPI4_IMU_MOSI * 2));

    GPIOE->BSRR = (0b1 << PIN_SPI4_IMU_SS);

    // CPOL = 1, CPHA = 1
    // freq = CLK / 4
    // master mode
    SPI4->CR1 |= (0b1 << SPI_CR1_CPHA_Pos) |
                 (0b1 << SPI_CR1_CPOL_Pos) |
                 SPI_CR1_BR |
                 SPI_CR1_MSTR;

    // enable SS output
    // set data size
    SPI4->CR2 |= SPI_CR2_SSOE |
                 (0b0111 << 8);

    // enable SPI
    SPI4->CR1 |= (0b1 << SPI_CR1_SPE_Pos);

    uint8_t spiWhoAmI = Spi_Read(IMU_ADDR_WHO_AM_I);

    uint8_t spiPwr = Spi_Read(IMU_ADDR_PWR_MGMT_1);
    // Spi_Write(IMU_ADDR_PWR_MGMT_1, 0);
    // Spi_Write(IMU_ADDR_PWR_MGMT_1, IMU_BIT_PWR_MGMT_1_DEVICE_RESET/* & ~(IMU_BIT_PWR_MGMT_1_SLEEP)*/);
    delay_ms(500);
    uint8_t spiPwr2 = Spi_Read(IMU_ADDR_PWR_MGMT_1);
    uint8_t spiWhoAmI2 = Spi_Read(IMU_ADDR_WHO_AM_I);
    // Spi_Write(IMU_ADDR_USER_CTRL, IMU_BIT_USER_CTRL_I2C_IF_DIS);

    uint8_t spiUserCtrl = Spi_Read(IMU_ADDR_USER_CTRL);

    return 0;
}

uint8_t Spi_Read(uint8_t address)
{
    return Spi_Transmit(address | IMU_READ) >> 8;
}

int8_t Spi_Write(uint8_t address, uint8_t data)
{
    Spi_Transmit(address | IMU_WRITE | (data << 8));
    return 0;
}

uint16_t Spi_Transmit(uint16_t data)
{
    GPIOE->BSRR = (0b1 << (PIN_SPI4_IMU_SS + 16));
    SPI4->DR = data;

    uint16_t sr;

    do
    {
        sr = SPI4->SR;
    } while (!(sr & (SPI_SR_TXE)));

    do
    {
        sr = SPI4->SR;
    } while (!(sr & (SPI_SR_RXNE)));

    do
    {
        sr = SPI4->SR;
    } while (sr & (SPI_SR_BSY));

    GPIOE->BSRR = (0b1 << PIN_SPI4_IMU_SS);

    return SPI4->DR;
}