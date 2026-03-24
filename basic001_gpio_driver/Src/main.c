/*
 * main.c
 *
 */

#include <stdint.h>
#include "stm32f407xx.h"

void delay(void)
{
	for (int i=0 ; i <= 500000 ; i++);
}

int main()
{
	GPIOD_PCLK_EN();

	GPIOD->MODER &= ~(3 << 24); //reset of moder

	GPIOD->MODER |= (1 << 24);

	while(1)
	{
		GPIOD->ODR ^= (1 << 12);     //toglling the bit using XOR

		delay();
	}

}
