//#include <stdio.h>
#include "STM32F411xx_ADC.h"

int main(void)
{
	ADC_Init();

	ADC_EnableChannel(ADC_CHANNEL0);

	while(1)
	{
		uint16_t val  = ADC_getValue(ADC_CHANNEL0);
		float voltage = ADC_getVoltage(ADC_CHANNEL0);
//		printf("VALUE 0: %d\tVOLTAGE 0: %.2fV\n", val, voltage);
		for(int i=0; i<800000; i++);
	}
	return 0;
}
