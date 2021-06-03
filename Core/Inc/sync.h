#ifndef INC_SYNC_H_
#define INC_SYNC_H_

#include "stm32f3xx_hal.h"

#define DEFAULT_SYN_A 1
#define DEFAULT_SYN_B 1
#define DEFAULT_SYN_A_DIV_B 1

#define DEFAULT_SYNC { 				\
	DEFAULT_SYN_A,					\
	DEFAULT_SYN_B,					\
	DEFAULT_SYN_A_DIV_B				\
}

typedef struct __tSyncTypeDef {
	uint32_t us_delay_a;
	uint32_t us_delay_b;
	uint32_t us_delay_a_div_b;
} SyncTypeDef;

void us_delay(unsigned us_nr);
void us_delay_calibrate();

#endif /* INC_SYNC_H_ */
