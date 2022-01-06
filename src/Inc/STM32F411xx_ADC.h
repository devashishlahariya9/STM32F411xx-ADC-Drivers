/*
 * STM32F411xx_ADC.h
 *
 * Created on: 04-Jan-2022
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_ADC_H_
#define STM32F411XX_ADC_H_

#include "STM32F411xx_GPIO.h"

//ADC -> SR
#define ADC_OVR			5U
#define ADC_STRT		4U
#define ADC_JSTRT		3U
#define ADC_JEOC		2U
#define ADC_EOC			1U
#define ADC_AWD			0U

//ADC -> CR1
#define ADC_OVRIE		26U
#define ADC_RES			24U
#define ADC_AWDEN		23U
#define ADC_JAWDEN		22U
#define ADC_DISCNUM		13U
#define ADC_JDISCEN		12U
#define ADC_DISCEN		11U
#define ADC_JAUTO		10U
#define ADC_AWDSGL		9U
#define ADC_SCAN		8U
#define ADC_JEOCIE		7U
#define ADC_AWDIE		6U
#define ADC_EOCIE		5U
#define ADC_AWDCH		0U

//ADC -> CR2
#define ADC_SWSTART		30U
#define ADC_EXTEN		28U
#define ADC_EXTSEL		24U
#define ADC_JSWSTART	22U
#define ADC_JEXTEN		20U
#define ADC_JEXTSEL		16U
#define ADC_ALIGN		11U
#define ADC_EOCS		10U
#define ADC_DDS			9U
#define ADC_DMA			8U
#define ADC_CONT		1U
#define ADC_ADON		0U

//ADC -> SMPR1
#define ADC_SMPR18		24U
#define ADC_SMPR17		21U
#define ADC_SMPR16		18U
#define ADC_SMPR15		15U
#define ADC_SMPR14		12U
#define ADC_SMPR13		9U
#define ADC_SMPR12		6U
#define ADC_SMPR11		3U
#define ADC_SMPR10		0U

//ADC -> SMPR2
#define ADC_SMPR9		27U
#define ADC_SMPR8		24U
#define ADC_SMPR7		21U
#define ADC_SMPR6		18U
#define ADC_SMPR5		15U
#define ADC_SMPR4		12U
#define ADC_SMPR3		9U
#define ADC_SMPR2		6U
#define ADC_SMPR1		3U
#define ADC_SMPR0		0U

#define ADC_JOFFSET1	0U
#define ADC_JOFFSET2	0U
#define ADC_JOFFSET3	0U
#define ADC_JOFFSET4	0U

#define ADC_HT			0U
#define ADC_LT			0U

//ADC -> SQR1
#define ADC_L			20U
#define ADC_SQ16		15U
#define ADC_SQ15		10U
#define ADC_SQ14		5U
#define ADC_SQ13		0U

//ADC -> SQR2
#define ADC_SQ12		25U
#define ADC_SQ11		20U
#define ADC_SQ10		15U
#define ADC_SQ9			10U
#define ADC_SQ8			5U
#define ADC_SQ7			0U

//ADC -> SQR3
#define ADC_SQ6			25U
#define ADC_SQ5			20U
#define ADC_SQ4			15U
#define ADC_SQ3			10U
#define ADC_SQ2			5U
#define ADC_SQ1			0U

//ADC -> JSQR
#define ADC_JL			20U
#define ADC_JSQ4		15U
#define ADC_JSQ3		10U
#define ADC_JSQ2		5U
#define ADC_JSQ1		0U

//ADC_CCR
#define ADC_TSVREFE		23U
#define ADC_VBATE		22U
#define ADC_ADCPRE		16U

enum ADC_CHANNELS
{
	ADC_CHANNEL0,	//PA0
	ADC_CHANNEL1,	//PA1
	ADC_CHANNEL2,	//PA2
	ADC_CHANNEL3,   //PA3
	ADC_CHANNEL4,   //PA4
	ADC_CHANNEL5,   //PA5
	ADC_CHANNEL6,   //PA6
	ADC_CHANNEL7,   //PA7

	ADC_CHANNEL8,	//PB0
	ADC_CHANNEL9,	//PB1

	ADC_CHANNEL10,	//PC0
	ADC_CHANNEL11,	//PC1
	ADC_CHANNEL12,	//PC2
	ADC_CHANNEL13,	//PC3
	ADC_CHANNEL14,	//PC4
	ADC_CHANNEL15,	//PC5
};

#define ADC_RESOL	4096
#define ADC_REF_VOL 3.3

void FPU_Init(void);
void ADC_Init(void);
void ADC_EnableChannel(uint8_t _channel);
uint16_t ADC_getValue(uint8_t _channel);
float ADC_getVoltage(uint8_t _channel);

#endif /* STM32F411XX_ADC_H_ */
