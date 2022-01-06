/*
 * STM32F411xx_ADC.c
 *
 * Created on: 04-Jan-2022
 * Author: Devashish Lahariya
*/

#include "STM32F411xx_ADC.h"

void FPU_Init(void)
{
	FPU -> CPACR = (0xF << 20);

	while(!(FPU -> CPACR & (0xF << 20)));
}

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
		GPIO_setMode(PORTA, _channel, LOW_SPEED, PUSH_PULL, ANALOG);
	}

	else if((_channel == ADC_CHANNEL8) || (_channel == ADC_CHANNEL9))
	{
		GPIO_setMode(PORTB, (_channel - 8), LOW_SPEED, PUSH_PULL, ANALOG);
	}

	else
	{
		GPIO_setMode(PORTC, (_channel - 10), LOW_SPEED, PUSH_PULL, ANALOG);
	}
}

uint16_t ADC_getValue(uint8_t _channel)
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

float ADC_getVoltage(uint8_t _channel)
{
	float voltage = 0;
	uint16_t ADC_val = ADC_getValue(_channel);
	voltage = ((float)(ADC_REF_VOL * ADC_val) / (float)ADC_RESOL);
	return voltage;
}
