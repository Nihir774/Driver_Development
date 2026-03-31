/*
 * stm32f407xx_driver.h
 *
 *  Created on: Mar 25, 2026
 *      Author: unaca
 */

#ifndef STM32F407XX_DRIVER_H_
#define STM32F407XX_DRIVER_H_

#include <stdint.h>

#include "stm32f407xx.h"


typedef struct
{
	uint16_t PinNumber;
	uint8_t PinMode;
	uint8_t PinSpeed;
	uint8_t OutputType;
	uint8_t PuPdMode;
	uint8_t AltFunMode;
}GPIO_Config_strct;

typedef struct
{
	GPIOx_RegDef *GPIOx;
	GPIO_Config_strct GPIO_Config;
}GPIO_Handle;



//GPIO port mode register

#define INPUT_MODE     0x00                 //00: Input (reset state)
#define OUTPUT_MODE    0x01                 //01: General purpose output mode
#define ALT_FUNMODE    0x02                 //10: Alternate function mode
#define ANALOG_MODE    0x03                 //11: Analog mode


//GPIO port output type register

#define OUTPUT_PUSHPULL               0x00         //0: Output push-pull (reset state)
#define OUTPUT_OPENDRAIN              0x01         //1: Output open-drain

//GPIO port output speed register
#define GPIO_OUTPUT_SPEED_LOW         0x00         //00: Low speed
#define GPIO_OUTPUT_SPEED_MEDIUM      0x01         //01: Medium speed
#define GPIO_OUTPUT_SPEED_HIGH        0x02       //10: High speed
#define GPIO_OUTPUT_SPEED_VERYHIGH    0x03         //11: Very high speed

//GPIO port pull-up/pull-down register

#define NO_PUPD    0x00             //00: No pull-up, pull-down
#define PULL_UP    0x01             //01: Pull-up
#define PULL_DOWN  0x02             //10: Pull-down


//gpio Pin Numbers

#define GPIO_PIN_NO0       0
#define GPIO_PIN_NO1       1
#define GPIO_PIN_NO2       2
#define GPIO_PIN_NO3       3
#define GPIO_PIN_NO4       4
#define GPIO_PIN_NO5       5
#define GPIO_PIN_NO6       6
#define GPIO_PIN_NO7       7
#define GPIO_PIN_NO8       8
#define GPIO_PIN_NO9       9
#define GPIO_PIN_NO10       10
#define GPIO_PIN_NO11       11
#define GPIO_PIN_NO12       12
#define GPIO_PIN_NO13       13
#define GPIO_PIN_NO14       14
#define GPIO_PIN_NO15       15




void GPIO_Init(GPIO_Handle *GPIO_Handle);
void GPIO_DeInit(	GPIOx_RegDef *GPIOx, uint8_t EnorDi);
void PERICLKCONTROL(GPIOx_RegDef *GPIOx, uint16_t EnorDi);
uint16_t GPIO_Write_to_OutputPort(GPIOx_RegDef *GPIOx, uint16_t value);
uint8_t GPIO_Write_to_OutputPin(GPIOx_RegDef *GPIOx, uint8_t PinNumber, uint8_t value);
uint16_t GPIO_Readfrom_InputPort(GPIOx_RegDef *GPIOx);
uint8_t GPIO_Readfrom_InputPin(GPIOx_RegDef *GPIOx, uint8_t PinNumber);
void GPIO_TogglePin(GPIOx_RegDef *GPIOx, uint8_t PinNumber);
void GPIO_IRQConfig(GPIOx_RegDef IRQPriority , uint8_t PinNumber, uint8_t value);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* STM32F407XX_DRIVER_H_ */
