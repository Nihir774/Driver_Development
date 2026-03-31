/*
 *Header file: stm32f407xx.h
 */

#ifndef STM32F407XX_H_
#define STM32F407XX_H_

#define __vo volatile

#define PERIPHERAL_BASEADDR             (0x40000000U)
#define APB1_BASEADDR                   (PERIPHERAL_BASEADDR)
#define APB2_BASEADDR                   (PERIPHERAL_BASEADDR+0x10000U)
#define AHB1_BASEADDR                   (PERIPHERAL_BASEADDR+0x20000U)
#define FLASH_BASEADDR                  (PERIPHERAL_BASEADDR+0x23C00U)
#define GPIOA_BASEADDR                  (AHB1_BASEADDR)
#define GPIOB_BASEADDR                  (AHB1_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR                  (AHB1_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR                  (AHB1_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR                  (AHB1_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR                  (AHB1_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR                  (AHB1_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR                  (AHB1_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR                  (AHB1_BASEADDR + 0x2000U)

#define RCC_BASEADDR                    (AHB1_BASEADDR + 0x3800U)

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIOx_RegDef;

typedef struct {
    __vo uint32_t CR;                   // 0x00: Clock control register
    __vo uint32_t PLLCFGR;              // 0x04: PLL configuration register
    __vo uint32_t CFGR;                 // 0x08: Clock configuration register
    __vo uint32_t CIR;                  // 0x0C: Clock interrupt register
    __vo uint32_t AHB1RSTR;             // 0x10: AHB1 peripheral reset register
    __vo uint32_t AHB2RSTR;             // 0x14: AHB2 peripheral reset register
    __vo uint32_t AHB3RSTR;             // 0x18: AHB3 peripheral reset register
    uint32_t          Reserved0;        // 0x1C: Reserved
    __vo uint32_t APB1RSTR;             // 0x20: APB1 peripheral reset register
    __vo uint32_t APB2RSTR;             // 0x24: APB2 peripheral reset register
    uint32_t          Reserved1[2];     // 0x28-0x2C: Reserved
    __vo uint32_t AHB1ENR;              // 0x30: AHB1 peripheral clock enable register
   __vo uint32_t AHB2ENR;               // 0x34: AHB2 peripheral clock enable register
    __vo uint32_t AHB3ENR;              // 0x38: AHB3 peripheral clock enable register
    uint32_t          Reserved2;        // 0x3C: Reserved
    __vo uint32_t APB1ENR;              // 0x40: APB1 peripheral clock enable register
    __vo uint32_t APB2ENR;              // 0x44: APB2 peripheral clock enable register
    uint32_t          Reserved3[2];     // 0x48-0x4c
    __vo uint32_t AHB1LPENR;            // 0x50
    __vo uint32_t AHB2LPENR;            // 0x54
    __vo uint32_t AHB3LPENR;            // 0x58
    uint32_t          Reserved4;        // 0x5c
    __vo uint32_t APB1LPENR;            // 0x60
    __vo uint32_t APB2LPENR;            // 0x64
    uint32_t          Reserved5[2];     // 0x68-0x6c
    __vo uint32_t BDCR;                 // 0x70
    __vo uint32_t CSR;                  // 0x74
    uint32_t          Reserved6[2];     // 0x78-0x7c
    __vo uint32_t SSCGR;                // 0x80
    __vo uint32_t PLLI2SCFGR;           // 0x84
    __vo uint32_t PLLSAICFGR;           // 0x88
    __vo uint32_t DCKCFGR;              // 0x8c

} RCC_RegDef;

#define RCC                     ((RCC_RegDef*)RCC_BASEADDR)          //6.3 RCC registers reference manual of stm32f407

#define GPIOA                   ((GPIOx_RegDef*)GPIOA_BASEADDR)
#define GPIOB                   ((GPIOx_RegDef*)GPIOB_BASEADDR)
#define GPIOC                   ((GPIOx_RegDef*)GPIOC_BASEADDR)
#define GPIOD                   ((GPIOx_RegDef*)GPIOD_BASEADDR)
#define GPIOE                   ((GPIOx_RegDef*)GPIOE_BASEADDR)
#define GPIOF                   ((GPIOx_RegDef*)GPIOF_BASEADDR)
#define GPIOG                   ((GPIOx_RegDef*)GPIOG_BASEADDR)
#define GPIOH                   ((GPIOx_RegDef*)GPIOH_BASEADDR)
#define GPIOI                   ((GPIOx_RegDef*)GPIOI_BASEADDR)

//clock enable macros
#define GPIOA_PCLK_EN()   (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()   (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()   (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()   (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()   (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()   (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()   (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()   (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()   (RCC->AHB1ENR |= (1 << 8))
//clock disable macros
#define GPIOA_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 8))



#define GPIOA_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 0));  (RCC->AHB1RSTR &= ~(1 << 0));}while(0)
#define GPIOB_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 1));  (RCC->AHB1RSTR &= ~(1 << 1));}while(0)
#define GPIOC_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 2));  (RCC->AHB1RSTR &= ~(1 << 2));}while(0)
#define GPIOD_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 3));  (RCC->AHB1RSTR &= ~(1 << 3));}while(0)
#define GPIOE_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 4));  (RCC->AHB1RSTR &= ~(1 << 4));}while(0)
#define GPIOF_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 5));  (RCC->AHB1RSTR &= ~(1 << 5));}while(0)
#define GPIOG_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 6));  (RCC->AHB1RSTR &= ~(1 << 6));}while(0)
#define GPIOH_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 7));  (RCC->AHB1RSTR &= ~(1 << 7));}while(0)
#define GPIOI_REG_RESET()              do {(RCC->AHB1RSTR |= (1 << 8));  (RCC->AHB1RSTR &= ~(1 << 8));}while(0)

#define GPIO_ENABLE 1
#define GPIO_DISABLE 0
#define SET      GPIO_ENABLE
#define RESET    gpio_DISABLE


#endif /* STM32F407XX_H_ */
