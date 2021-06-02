#include "i2c.h"
#include "control.h"

extern ControlTypeDef control;
extern I2C_HandleTypeDef *hi2c2;

void init_i2c2() {
	hi2c2->Init.Timing = control.cfg_i2c.i2c2_timing;
	hi2c2->Init.OwnAddress1 = control.cfg_i2c.i2c1_slave_addr;
	if (HAL_I2C_Init(&hi2c2) != HAL_OK) {
		Error_Handler();
	}
	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE)
			!= HAL_OK) {
		Error_Handler();
	}
	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK) {
		Error_Handler();
	}
}
