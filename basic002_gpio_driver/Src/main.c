#include <stdint.h>
#include "stm32f407xx.h"
#include "stm32f407xx_driver.h"

void delay(void)
{
	for(uint32_t i = 0; i <= 500000; i++); //for loop for delay
}
int main(void)
{
	GPIO_Handle GPIOLed;
	PERICLKCONTROL(GPIOD, GPIO_ENABLE);
	GPIOLed.GPIOx = GPIOD;
	GPIOLed.GPIO_Config.PinNumber = GPIO_PIN_NO12;
	GPIOLed.GPIO_Config.PinMode = OUTPUT_MODE;
	GPIOLed.GPIO_Config.PinSpeed = GPIO_OUTPUT_SPEED_MEDIUM;
	GPIOLed.GPIO_Config.OutputType = OUTPUT_PUSHPULL;
	GPIOLed.GPIO_Config.PuPdMode = NO_PUPD;

	GPIO_Init(&GPIOLed);

	while(1)
	{
		GPIO_TogglePin(GPIOD , GPIO_PIN_NO12);
		delay();
	}
	return 0;
}
