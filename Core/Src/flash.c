#include "flash.h"

void init_flash(){
	  FLASH->KEYR = 0x45670123;
	  FLASH->KEYR = 0xCDEF89AB;
}

void read(ControlTypeDef *p, uint32_t address)
{
   uint32_t *ptr = (uint32_t* ) p;
   memcpy(ptr, address, sizeof(ControlTypeDef));
   p = (ControlTypeDef*)(ptr);
}

void erase(unsigned int pageAddress) {
	while (FLASH->SR & FLASH_SR_BSY);
	if (FLASH->SR & FLASH_SR_EOP) {
		FLASH->SR = FLASH_SR_EOP;
	}

	FLASH->CR |= FLASH_CR_PER;
	FLASH->AR = pageAddress;
	FLASH->CR |= FLASH_CR_STRT;
	while (!(FLASH->SR & FLASH_SR_EOP));
	FLASH->SR = FLASH_SR_EOP;
	FLASH->CR &= ~FLASH_CR_PER;
}

void write(ControlTypeDef *p, uint32_t address)
{
    uint32_t *pRecord = (uint32_t* )p;
    uint32_t flash_address = address;

    for(int i=0; i<sizeof(ControlTypeDef); i+=4, pRecord++, flash_address+=4)
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, flash_address,*pRecord);
}
