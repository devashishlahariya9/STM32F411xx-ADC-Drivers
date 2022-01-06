/*
 * STM32F411xx_Interrupt.h
 *
 * Created on: 16-Oct-2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_INTERRUPT_H_
#define STM32F411XX_INTERRUPT_H_

#include "STM32F411xx.h"
#include "STM32F411xx_GPIO.h"

#define GPIO_FALLING 	 0U
#define GPIO_RISING  	 1U
#define GPIO_CHANGE  	 2U

enum IRQ_Positions
{
	WWDG_IRQ,
	EXTI16_IRQ,
	PVD_IRQ = EXTI16_IRQ,
	EXTI21_IRQ,
	TIME_STAMP_IRQ = EXTI21_IRQ,
	EXTI22_IRQ,
	RTC_WKUP_IRQ = EXTI22_IRQ,
	FLASH_IRQ,
	RCC_IRQ,
	EXTI0_IRQ,
	EXTI1_IRQ,
	EXTI2_IRQ,
	EXTI3_IRQ,
	EXTI4_IRQ,
	DMA1_Stream0_IRQ,
	DMA1_Stream1_IRQ,
	DMA1_Stream2_IRQ,
	DMA1_Stream3_IRQ,
	DMA1_Stream4_IRQ,
	DMA1_Stream5_IRQ,
	DMA1_Stream6_IRQ,
	ADC_IRQ,
	EXTI5_IRQ = 23,
	EXTI6_IRQ = EXTI5_IRQ,
	EXTI7_IRQ = EXTI5_IRQ,
	EXTI8_IRQ = EXTI5_IRQ,
	EXTI9_IRQ = EXTI5_IRQ,
	TIM1_BRK_IRQ,
	TIM9_IRQ = TIM1_BRK_IRQ,
	TIM1_UP_IRQ,
	TIM10_IRQ = TIM1_UP_IRQ,
	TIM1_TRG_IRQ,
	COM_IRQ = TIM1_TRG_IRQ,
	TIM11_IRQ = TIM1_TRG_IRQ,
	TIM1_CC_IRQ,
	TIM2_IRQ,
    TIM3_IRQ,
    TIM4_IRQ,
    I2C1_EV_IRQ,
    I2C1_ER_IRQ,
    I2C2_EV_IRQ,
    I2C2_ER_IRQ,
    SPI1_IRQ,
    SPI2_IRQ,
    USART1_IRQ,
    USART2_IRQ,
    EXTI15_IRQ = 40,
    EXTI14_IRQ = EXTI15_IRQ,
    EXTI13_IRQ = EXTI15_IRQ,
    EXTI12_IRQ = EXTI15_IRQ,
    EXTI11_IRQ = EXTI15_IRQ,
    EXTI10_IRQ = EXTI15_IRQ,
    EXTI17_IRQ,
    RTC_Alarm_IRQ = EXTI17_IRQ,
    EXTI18_IRQ,
    OTG_FS_WKUP_IRQ = EXTI18_IRQ,
    DMA1_Stream7 = 47,
    SDIO_IRQ = 49,
    TIM5_IRQ,
    SPI3_IRQ,
    DMA2_Stream0_IRQ = 56,
    DMA2_Stream1_IRQ,
    DMA2_Stream2_IRQ,
    DMA2_Stream3_IRQ,
    DMA2_Stream4_IRQ,
    OTG_FS_IRQ = 67,
    DMA2_Stream5_IRQ,
    DMA2_Stream6_IRQ,
    DMA2_Stream7_IRQ,
    USART6_IRQ,
    I2C3_EV_IRQ,
    I2C3_ER_IRQ,
    FPU_IRQ = 81,
    SPI4_IRQ = 84,
    SPI5_IRQ
};

void NVIC_Enable_IRQ(uint8_t _IRQ);
void NVIC_Disable_IRQ(uint8_t _IRQ);
void GPIO_Enable_IRQ(uint8_t _port, uint8_t _pin, uint8_t _trigger);

#endif /* STM32F411XX_INTERRUPT_H_ */
