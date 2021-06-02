#include "utils.h"

extern ControlTypeDef control;
extern ADC_HandleTypeDef* hadc2;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	control.sense_12V_normalized = HAL_ADC_GetValue(hadc);
}

void blink(uint8_t count) {
	uint8_t i = 0;
	if (control.blink == 1) {
		for (i; i < count; i++) {
			on_pc13();
			HAL_Delay(DELAY);
			off_pc13();
			HAL_Delay(DELAY);
		}
		off_pc13();
		HAL_Delay(count * DELAY);
	}
}

void on_pc13() {
	if (control.pc13)
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
}

void off_pc13()
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}

void on_pc15()
{
	if (control.pc15)
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
}

void off_pc15()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
}

void set_adc_timer()
{
	TIM3->CR1 = ((control.adc) ? TIM_CR1_CEN : TIM_CR1_CEN_Pos) | TIM_CR1_ARPE;

	if (control.adc) {
		while(HAL_ADCEx_Calibration_Start(& hadc2, ADC_SINGLE_ENDED) != HAL_OK);
		HAL_ADC_Start_IT(& hadc2);
	}
}

void set_on_pc13() {
	control.pc13 = 1;
}

void set_off_pc13() {
	off_pc13();
	control.pc13 = 0;
}

void set_on_pc15() {
	control.pc15 = 1;
}

void set_off_pc15() {
	off_pc15();
	control.pc15 = 0;
}

void set_on_blink() {
	control.blink = 1;
}

void set_off_blink() {
	off_pc13();
	control.blink = 0;
}

void set_cdc_feedback() {
	control.feedback = FEEDBACK_CDC;
}

void set_off_feedback() {
	control.feedback = FEEDBACK_DISABLED;
}

uint8_t feedback() {
	return control.feedback;
}

void set_on_adc() {
	control.adc = 1;
	set_adc_timer();
}

void set_off_adc() {
	control.adc = 0;
	set_adc_timer();
}

float get_sense_12V_normalized() {
	control.sense_12V_normalized = HAL_ADC_GetValue (& hadc2);
	return (((float)control.sense_12V_normalized)*control.sense_12V_base)/4096;
}

void init_bios()
{
	init_flash();
}

void init_hw()
{
	set_adc_timer();
	init_i2c2();
}

void read_config(ControlTypeDef *p)
{
	ControlTypeDef config = DEFAULT_CONFIG;
	read(p, LAST_PAGE_ADDRESS);
	if (!validate_config(p)){
		memcpy(p, &config, sizeof(ControlTypeDef));
	}
}

uint8_t validate_config(ControlTypeDef *p)
{
	return ((p->config_begin == CONFIG_BEGIN)&&(p->config_end == CONFIG_END));
}

void write_config()
{
	erase(LAST_PAGE_ADDRESS);
	write(&control, LAST_PAGE_ADDRESS);
}




