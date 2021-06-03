#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_

#include "stm32f3xx_hal.h"
#include "i2c.h"
#include "sync.h"

#define ON 1
#define OFF 0
#define PC13_ON ON
#define PC13_OFF OFF
#define PC15_ON ON
#define PC15_OFF OFF
#define BLINK_ON ON
#define BLINK_OFF OFF
#define ADC_ON ON
#define ADC_OFF OFF
#define SENSE_12V_RESET 0
#define SENSE_12V_BASE 12

#define CONFIG_BEGIN 0x55
#define CONFIG_END 0xAA

#define DEFAULT_CONFIG {  	\
	CONFIG_BEGIN, 			\
	PC13_ON, 				\
	PC15_ON,				\
	BLINK_ON, 				\
	BLINK_ON, 				\
	FEEDBACK_CDC, 			\
	SENSE_12V_BASE, 		\
	SENSE_12V_RESET, 		\
	DEFAULT_I2C,			\
	DEFAULT_SYNC,			\
	CONFIG_END 				\
}


typedef struct __tControlTypeDef {
	uint8_t config_begin;			//начало конфига
	uint8_t pc13;   				//вкл/выкл pin13
	uint8_t pc15;   				//вкл/выкл pin13
	uint8_t blink;					//вкл/выкл мигания
	uint8_t adc;					//вкл/выкл adc
	uint8_t feedback;				//терминал отправляет ответы на USB CDC
	uint8_t sense_12V_base;			//базовое напряжение 12V
	uint16_t sense_12V_normalized;  //текущее измерение напряжение на входе sense_12V_normalized
	I2CTypeDef cfg_i2c;				//кофигурация I2C
	SyncTypeDef cfg_sync;			//кофигурация SYNC
	uint8_t config_end;				//конец конфига
} ControlTypeDef;

#endif /* INC_CONTROL_H_ */
