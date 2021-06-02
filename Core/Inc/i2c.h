#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "stm32f3xx_hal.h"

#define I2C1_SLAVE_ADDR 152
#define I2C1_TIMING 0x0000020B
#define I2C2_TIMING 0x2000090E

#define I2C2_TPS_MAP_0 0x71
#define I2C2_TPS_MAP_1 0x72
#define I2C2_TPS_MAP_2 0x73
#define I2C2_TPS_MAP_3 0x61
#define I2C2_TPS_MAP_4 0x75

#define INIT_PHASES 4
#define INIT_PHASES_0 INIT_PHASES
#define INIT_PHASES_1 INIT_PHASES
#define INIT_PHASES_2 INIT_PHASES
#define INIT_PHASES_3 INIT_PHASES
#define INIT_PHASES_4 INIT_PHASES

#define DEFAULT_I2C { 																						\
	I2C1_SLAVE_ADDR,																						\
	I2C1_TIMING,																							\
	I2C2_TIMING,																							\
	{I2C2_TPS_MAP_0, I2C2_TPS_MAP_1,I2C2_TPS_MAP_2, I2C2_TPS_MAP_3, I2C2_TPS_MAP_4 }, 						\
	{INIT_PHASES_0, INIT_PHASES_1,INIT_PHASES_2, INIT_PHASES_3, INIT_PHASES_4 }								\
}

typedef struct __tI2cTypeDef {
	 uint32_t i2c1_slave_addr;
	 uint32_t i2c1_timing;
	 uint32_t i2c2_timing;
	 uint32_t tps_map[5];
	 uint32_t tps_initial_phases[5];
} I2CTypeDef;


void init_i2c2();

#endif /* INC_I2C_H_ */
