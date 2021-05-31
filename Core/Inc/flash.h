#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include "control.h"
#include "utils.h"

#define LAST_PAGE_ADDRESS 0x0801FC00

void init_flash();
void read(tcontrol *p, uint32_t address);
void write(tcontrol *p, uint32_t address);
void erase(unsigned int pageAddress);


#endif /* INC_FLASH_H_ */
