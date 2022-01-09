#ifndef DRIVERS_IMU_H__
#define DRIVERS_IMU_H__

#include <stdint.h>

#define IMU_ADDR_SELF_TEST_X_GYRO           (0x00)
#define IMU_ADDR_SELF_TEST_Y_GYRO           (0x01)
#define IMU_ADDR_SELF_TEST_Z_GYRO           (0x02)
#define IMU_ADDR_SELF_TEST_X_ACCEL          (0x0D)
#define IMU_ADDR_SELF_TEST_Y_ACCEL          (0x0E)
#define IMU_ADDR_SELF_TEST_Z_ACCEL          (0x0F)
#define IMU_ADDR_XG_OFFS_USRH               (0x13)
#define IMU_ADDR_XG_OFFS_USRL               (0x14)
#define IMU_ADDR_YG_OFFS_USRH               (0x15)
#define IMU_ADDR_YG_OFFS_USRL               (0x16)
#define IMU_ADDR_ZG_OFFS_USRH               (0x17)
#define IMU_ADDR_ZG_OFFS_USRL               (0x18)
#define IMU_ADDR_SMPLRT_DIV                 (0x19)
#define IMU_ADDR_CONFIG                     (0x1A)
#define IMU_ADDR_GYRO_CONFIG                (0x1B)
#define IMU_ADDR_ACCEL_CONFIG               (0x1C)
#define IMU_ADDR_ACCEL_CONFIG_2             (0x1D)

#define IMU_ADDR_USER_CTRL                  (0x6A)
#define IMU_ADDR_PWR_MGMT_1                 (0x6B)
#define IMU_ADDR_PWR_MGMT_2                 (0x6C)

#define IMU_ADDR_WHO_AM_I                   (0x75)

#define IMU_BIT_USER_CTRL_I2C_IF_DIS        (0x10)
#define IMU_BIT_PWR_MGMT_1_DEVICE_RESET     (0x80)
#define IMU_BIT_PWR_MGMT_1_CLK_SEL_PLL      (0x01)
#define IMU_BIT_PWR_MGMT_1_CLK_SEL_PLL_Z    (0x03)
#define IMU_BIT_PWR_MGMT_1_SLEEP            (0x40)


#define IMU_READ                            (0x80)
#define IMU_WRITE                           (0x00)

int8_t Imu_Init(void);
int8_t Imu_Write(uint8_t address, uint8_t data);
int8_t Imu_Read(uint8_t address);

#endif