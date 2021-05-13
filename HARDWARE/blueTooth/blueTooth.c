#include "blueTooth.h"

void blueToothInit(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(BLUE_TOOTH_GPIO_CLK,ENABLE);//时钟
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//下拉输入
	//蓝牙状态引脚
	GPIO_InitStructure.GPIO_Pin = BLUE_TOOTH_GPIO_PIN;
	GPIO_Init(BLUE_TOOTH_GPIO_PORT, &GPIO_InitStructure);
}
