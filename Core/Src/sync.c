#include "sync.h"
#include "control.h"

extern ControlTypeDef control;

void us_delay(unsigned us_nr)
{
  unsigned int i;

  for (i = 0; i < us_nr * control.cfg_sync.us_delay_a_div_b; i++)
    (void)HAL_GetDEVID();
}

void us_delay_calibrate()
{
	unsigned long k = 0;
	uint32_t stamp = HAL_GetTick();

	while (stamp == HAL_GetTick()) ;

	stamp = HAL_GetTick();

	while (stamp + 5 > HAL_GetTick()) {
		us_delay(1);
		k++;
	}

	control.cfg_sync.us_delay_a = k;
	control.cfg_sync.us_delay_b = 5;
	control.cfg_sync.us_delay_a_div_b = k / 5;
}
