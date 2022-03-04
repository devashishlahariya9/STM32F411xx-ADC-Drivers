#include <stdio.h>
#include "STM32F411xx_ADC.h"

int main(void)
{
	ADC_Init();

	ADC_EnableChannel(ADC_CHANNEL0);

	while(1)
	{
		uint16_t val  = ADC_GetValue(ADC_CHANNEL0);

		float voltage = ADC_GetVoltage(ADC_CHANNEL0);

		printf("VALUE: %d\tVOLTAGE: %.2fV\n", val, voltage);

		Sys_Delay_ms(500);
	}
	return 0;
}
