#include "MTR_GPIO.h"

//ɲ��
void MTR_CarBrakeAll(void){
	MTR1_BRAKE;

	MTR3_BRAKE;

}

//ǰ��
void MTR_CarGo(void){
	MTR1_CW;

	MTR3_CW;

}

//����
void MTR_CarBackGo(void){
	MTR1_CCW;

	MTR3_CCW;

}

//��ת
void MTR_CarCW(void){
	
  MTR1_CCW;
	MTR3_CW;

}

//��ת
void MTR_CarCCW(void){
	
	
	MTR1_CW;
  MTR3_CCW;
	

}

void MTR_GPIOInit(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(MTR1_GPIO_CLK|MTR3_GPIO_CLK|pwm_1_GPIO_CLK|pwm_3_GPIO_CLK,ENABLE);//ʱ��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
	//���1PF_0_2
	GPIO_InitStructure.GPIO_Pin = MTR1_GPIO_PIN;
	GPIO_Init(MTR1_GPIO_PORT, &GPIO_InitStructure);

	//���3PF_4_6
	GPIO_InitStructure.GPIO_Pin = MTR3_GPIO_PIN;
	GPIO_Init(MTR3_GPIO_PORT, &GPIO_InitStructure);
	
	//pwm_PF_13_15
	GPIO_InitStructure.GPIO_Pin = pwm_1_GPIO_PIN;
	GPIO_Init(pwm_1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = pwm_3_GPIO_PIN;
	GPIO_Init(pwm_3_GPIO_PORT, &GPIO_InitStructure);
	
	
	//С��ɲ��
	MTR_CarBrakeAll();
}
