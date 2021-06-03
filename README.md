#builing

Для сборки добавить флаг -u_printf_float в /Project/Properties/C/C++ Build/Setings/Miscellaneous

#hw setting 

используемое оборудование
	1. GPIO
		GPIOC - GPIO_PIN_13
		GPIOA - GPIO_PIN_15
	2. TIM3
	3. ADC2

выставить предделитель системной частоты таймера 

	htim3.Init.Prescaler = 720;
	
выставить кол-во преобразований в максимум

	sConfig.SamplingTime = ADC_SAMPLETIME_601CYCLES_5;

