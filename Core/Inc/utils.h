#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_flash.h"
#include "stm32f3xx_hal_adc_ex.h"

#include "control.h"
#include "flash.h"
#include "fsm.h"

#define DELAY 20

void init_bios();
void init_hw();

void on_pc13();
void off_pc13();
void on_pc15();
void off_pc15();
void blink(uint8_t count);
uint8_t feedback();
float get_sense_12V_normalized();
void set_adc_timer();

void set_on_pc13();
void set_off_pc13();
void set_on_pc15();
void set_off_pc15();
void set_on_blink();
void set_off_blink();
void set_cdc_feedback();
void set_off_feedback();
void set_on_adc();
void set_off_adc();

void write_config();
void read_config(ControlTypeDef *p);
uint8_t validate_config(ControlTypeDef *p);

#endif /* INC_UTILS_H_ */
