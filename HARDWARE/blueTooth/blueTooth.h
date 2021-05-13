#ifndef __BLUE_TOOTH_H
#define	__BLUE_TOOTH_H

#include "stm32f10x.h"

#define BLUE_TOOTH_GPIO_PORT		GPIOA
#define BLUE_TOOTH_GPIO_CLK 	    RCC_APB2Periph_GPIOA
#define BLUE_TOOTH_GPIO_PIN			GPIO_Pin_1
#define BLUE_TOOTH_STATE			GPIO_ReadInputDataBit(BLUE_TOOTH_GPIO_PORT,BLUE_TOOTH_GPIO_PIN)

void blueToothInit(void);

#endif /* __BLUE_TOOTH_H */
