#include "blueTooth.h"

void blueToothInit(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(BLUE_TOOTH_GPIO_CLK,ENABLE);//ʱ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//��������
	//����״̬����
	GPIO_InitStructure.GPIO_Pin = BLUE_TOOTH_GPIO_PIN;
	GPIO_Init(BLUE_TOOTH_GPIO_PORT, &GPIO_InitStructure);
}
