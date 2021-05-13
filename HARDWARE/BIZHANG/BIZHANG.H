#ifndef __BIZHANG_H
#define __BIZHANG_H

#include "stm32f10x.h"


#define BIZHANG1_GPIO_PORT   GPIOG
#define BIZHANG1_GPIO_CLK    RCC_APB2Periph_GPIOG
#define BIZHANG1_GPIO_PIN    GPIO_Pin_1
#define BIZHANG1_STATE			 GPIO_ReadInputDataBit(BIZHANG1_GPIO_PORT,BIZHANG1_GPIO_PIN)

#define BIZHANG2_GPIO_PORT   GPIOG
#define BIZHANG2_GPIO_CLK    RCC_APB2Periph_GPIOG
#define BIZHANG2_GPIO_PIN    GPIO_Pin_3
#define BIZHANG2_STATE			 GPIO_ReadInputDataBit(BIZHANG2_GPIO_PORT,BIZHANG2_GPIO_PIN)
void bizhang_init(void);

void bizhang(void);



#endif /*bizhang*/
