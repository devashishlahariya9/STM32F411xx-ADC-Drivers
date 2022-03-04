/*
 * STM32F411xx_ADC.c
 *
 * Created on: 04-Jan-2022
 * Author: Devashish Lahariya
*/

#include "STM32F411xx_ADC.h"

void ADC_Init(void)
{
	FPU_Init();

	RCC -> AHB1ENR |= (1 << GPIOAEN) | (1 << GPIOBEN) | (1 << GPIOCEN);
	RCC -> APB2ENR |= (1 << ADC1EN);

	ADC -> CR1 |= (1 << ADC_SCAN);							//Set To SCAN Mode
	ADC -> CR1 &= ~(3 << ADC_RES);							//Set To 12-BIT Resolution

	ADC -> CR2 |= (1 << ADC_EOCS);							//Enable End Of Conversion Flag
	ADC -> CR2 |= (1 << ADC_CONT);							//Continuous Conversion Mode

	ADC -> SR = 0;											//Clear The Status Register

	ADC -> CR2 |= (1 << ADC_ADON);							//ADC ON
}

void ADC_EnableChannel(uint8_t _channel)
{
	if(_channel <= ADC_CHANNEL7)
	{
		GPIO_SetMode(GPIOA, _channel, GPIO_LOW_SPEED, GPIO_MODE_PUSH_PULL, GPIO_MODE_ANALOG);
	}

	else if((_channel == ADC_CHANNEL8) || (_channel == ADC_CHANNEL9))
	{
		GPIO_SetMode(GPIOB, (_channel - 8), GPIO_LOW_SPEED, GPIO_MODE_PUSH_PULL, GPIO_MODE_ANALOG);
	}

	else
	{
		GPIO_SetMode(GPIOC, (_channel - 10), GPIO_LOW_SPEED, GPIO_MODE_PUSH_PULL, GPIO_MODE_ANALOG);
	}
}

uint16_t ADC_GetValue(uint8_t _channel)
{
	uint16_t value = 0;

	ADC -> CR2 &= ~(1 << ADC_SWSTART);

	if(ADC -> SR & (1 << ADC_OVR))
	{
		ADC -> SR &= ~(1 << ADC_OVR);
	}
	ADC -> SQR1 &= ~(0xF << ADC_L);
	ADC -> SQR1 |=  (1 << ADC_L);

	ADC -> SQR3 &= ~(0x1F << ADC_SQ1);
	ADC -> SQR3 |=  (_channel << ADC_SQ1);

	ADC -> CR2 |=   (1 << ADC_SWSTART);

	while(!(ADC -> SR & (1 << ADC_EOC)));
	value = (uint16_t)(ADC -> DR);

	return value;
}

float ADC_GetVoltage(uint8_t _channel)
{
	float voltage = 0;
	uint16_t ADC_val = ADC_GetValue(_channel);
	voltage = ((float)(ADC_REF_VOL * ADC_val) / (float)ADC_RESOL);
	return voltage;
}
