/*
 * STM32F411xx_Interrupt.c
 *
 * Created on: 03-Nov-2021
 * Author: Devashish Lahariya
*/

#include "STM32F411xx_Interrupt.h"

void NVIC_Enable_IRQ(uint8_t _IRQ)
{
	if(_IRQ > 32)
	{
		NVIC_ISER -> ISER[(_IRQ / 32)] |= (1 << (_IRQ - 32));
	}

	else if(_IRQ > 64)
	{
		NVIC_ISER -> ISER[(_IRQ / 32)] |= (1 << (_IRQ - 64));
	}

	else
	{
		NVIC_ISER -> ISER[(_IRQ / 32)] |= (1 << _IRQ);
	}
}

void NVIC_Disable_IRQ(uint8_t _IRQ)
{
	if(_IRQ > 32)
	{
		NVIC_ICER -> ICER[(_IRQ / 32)] |= (1 << (_IRQ - 32));
	}

	else if(_IRQ > 64)
	{
		NVIC_ICER -> ICER[(_IRQ / 32)] |= (1 << (_IRQ - 64));
	}

	else
	{
		NVIC_ICER -> ICER[(_IRQ / 32)] |= (1 << _IRQ);
	}
}

void GPIO_Enable_IRQ(uint8_t _port, uint8_t _pin, uint8_t _trigger)
{
	RCC -> APB2ENR |= (1 << SYSCFGEN);
	EXTI -> IMR    |= (1 << _pin);

	uint8_t syscfg_reg = (_pin / 4);
	uint8_t bit_pos[16] = {EXTI0, EXTI1, EXTI2, EXTI3, EXTI4, EXTI5, EXTI6, EXTI7, EXTI8, EXTI9, EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15};

	switch(_port)
	{
		case PORTA:
			RCC -> AHB1ENR |= (1 << GPIOAEN);
			SYSCFG -> EXTICR[syscfg_reg] &= ~(0xf << bit_pos[_pin]);
			break;

		case PORTB:
			RCC -> AHB1ENR |= (1 << GPIOBEN);
			SYSCFG -> EXTICR[syscfg_reg] |=  (1 << bit_pos[_pin]);
			break;

		case PORTC:
			RCC -> AHB1ENR |= (1 << GPIOCEN);
			SYSCFG -> EXTICR[syscfg_reg] |=  (2 << bit_pos[_pin]);
			break;

		case PORTD:
			RCC -> AHB1ENR |= (1 << GPIODEN);
			SYSCFG -> EXTICR[syscfg_reg] |=  (3 << bit_pos[_pin]);
			break;

		case PORTE:
			RCC -> AHB1ENR |= (1 << GPIOEEN);
			SYSCFG -> EXTICR[syscfg_reg] |=  (4 << bit_pos[_pin]);
			break;
	}

	switch(_trigger)
	{
		case GPIO_FALLING:
			EXTI -> RTSR &= ~(1 << _pin);
			EXTI -> FTSR |=  (1 << _pin);
			break;

		case GPIO_RISING:
			EXTI -> RTSR |=  (1 << _pin);
			EXTI -> FTSR &= ~(1 << _pin);
			break;

		case GPIO_CHANGE:
			EXTI -> RTSR |=  (1 << _pin);
			EXTI -> FTSR |=  (1 << _pin);
			break;
	}
}
