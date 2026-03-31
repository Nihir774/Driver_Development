/*
 * stm32f407xx_driver.c
 *
 *  Created on: Mar 27, 2026
 *      Author: unaca
 */

#include <stdint.h>

#include "stm32f407xx_driver.h"
#include "stm32f407xx.h"
#define GPIO_ENABLE        1

void PERICLKCONTROL(GPIOx_RegDef *GPIOx, uint16_t EnorDi)
{
	if(EnorDi == GPIO_ENABLE)
	{
		if(GPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(GPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(GPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(GPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(GPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(GPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(GPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if(GPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if(GPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}else                  // if GPIOx == GPIO_DISABLE
	{
		if(GPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}else if(GPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}else if(GPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}else if(GPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}else if(GPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}else if(GPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}else if(GPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}else if(GPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}else if(GPIOx == GPIOI)
		{
			GPIOI_PCLK_DI();
		}
	}
}


void GPIO_Init(GPIO_Handle *pGPIO_Handle)
{
	uint32_t temp = 0;
	if(pGPIO_Handle->GPIO_Config.PinMode <= ANALOG_MODE)
	{

		//moder
		temp = pGPIO_Handle->GPIO_Config.PinMode << (2 * pGPIO_Handle->GPIO_Config.PinNumber);
		pGPIO_Handle->GPIOx->MODER &= ~(0x3 << 2 * pGPIO_Handle->GPIO_Config.PinNumber);
		pGPIO_Handle->GPIOx->MODER |= temp;
	}else
	{
		//interrupt part
	}
	//gpio_pin speed
	temp = 0;
	temp = pGPIO_Handle->GPIO_Config.PinSpeed<< (2 * pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->GPIOx->OSPEEDR &= ~(0x3 << 2 * pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->GPIOx->OSPEEDR |= temp;

	//pull up pull down
	temp = 0;
	temp = pGPIO_Handle->GPIO_Config.PuPdMode << (2 * pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->GPIOx->PUPDR &= ~(0x3 << 2 * pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->GPIOx->PUPDR |= temp;

	//outputype

	temp = 0;
	temp = pGPIO_Handle->GPIO_Config.OutputType << (pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->GPIOx->OTYPER &= ~(0x1 << pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->GPIOx->OTYPER |= temp;

	if(pGPIO_Handle->GPIO_Config.PinMode== ALT_FUNMODE)
	{
		uint8_t temp1 , temp2;
		temp1= pGPIO_Handle->GPIO_Config.PinNumber/8;
		temp2=  pGPIO_Handle->GPIO_Config.PinNumber%8;
		pGPIO_Handle->GPIOx->AFR[temp1] &= ~(pGPIO_Handle->GPIO_Config.AltFunMode << (4 * temp2));

		pGPIO_Handle->GPIOx->AFR[temp1] |= (pGPIO_Handle->GPIO_Config.AltFunMode << (4 * temp2));
	}

}


void GPIO_DeInit(	GPIOx_RegDef *GPIOx, uint8_t EnorDi)
{
	if(EnorDi == GPIO_ENABLE)
	{
		if(GPIOx == GPIOA)
		{
			GPIOA_REG_RESET();
		}else if(GPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}else if(GPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}else if(GPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}else if(GPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}else if(GPIOx == GPIOF)
		{
			GPIOF_REG_RESET();
		}else if(GPIOx == GPIOG)
		{
			GPIOG_REG_RESET();
		}else if(GPIOx == GPIOH)
		{
			GPIOH_REG_RESET();
		}else if(GPIOx == GPIOI)
		{
			GPIOI_REG_RESET();
		}
    }
}



uint16_t GPIO_Write_to_OutputPort(GPIOx_RegDef *GPIOx, uint16_t value)
{
	GPIOx->ODR = value;
}
uint8_t GPIO_Write_to_OutputPin(GPIOx_RegDef *GPIOx, uint8_t PinNumber,uint8_t value)
{
	if(value == SET)
	{
		//write 1 to enable
		GPIOx->ODR |= (1<<PinNumber);
	}else
	{
		//write 0 to disable
		GPIOx->ODR &= ~(1<<PinNumber);

	}
}

uint16_t GPIO_Readfrom_InputPort(GPIOx_RegDef *GPIOx)
{
	uint16_t value;
	value = (uint16_t)GPIOx->IDR ;
	return value;
}
uint8_t GPIO_Readfrom_InputPin(GPIOx_RegDef *GPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t) (GPIOx->IDR >> PinNumber) & 0x00000001;
	return value;
}
void GPIO_TogglePin(GPIOx_RegDef *GPIOx, uint8_t PinNumber)
{
    GPIOx->ODR ^= (1 << PinNumber);
}
void GPIO_IRQConfig(GPIOx_RegDef IRQPriority , uint8_t PinNumber, uint8_t value)
{

}
void GPIO_IRQHandling(uint8_t PinNumber)
{

}

