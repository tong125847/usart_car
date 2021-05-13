#include "MTR_GPIO.h"

//刹车
void MTR_CarBrakeAll(void){
	MTR1_BRAKE;

	MTR3_BRAKE;

}

//前进
void MTR_CarGo(void){
	MTR1_CW;

	MTR3_CW;

}

//后退
void MTR_CarBackGo(void){
	MTR1_CCW;

	MTR3_CCW;

}

//左转
void MTR_CarCW(void){
	
  MTR1_CCW;
	MTR3_CW;

}

//右转
void MTR_CarCCW(void){
	
	
	MTR1_CW;
  MTR3_CCW;
	

}

void MTR_GPIOInit(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(MTR1_GPIO_CLK|MTR3_GPIO_CLK|pwm_1_GPIO_CLK|pwm_3_GPIO_CLK,ENABLE);//时钟
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	//电机1PF_0_2
	GPIO_InitStructure.GPIO_Pin = MTR1_GPIO_PIN;
	GPIO_Init(MTR1_GPIO_PORT, &GPIO_InitStructure);

	//电机3PF_4_6
	GPIO_InitStructure.GPIO_Pin = MTR3_GPIO_PIN;
	GPIO_Init(MTR3_GPIO_PORT, &GPIO_InitStructure);
	
	//pwm_PF_13_15
	GPIO_InitStructure.GPIO_Pin = pwm_1_GPIO_PIN;
	GPIO_Init(pwm_1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = pwm_3_GPIO_PIN;
	GPIO_Init(pwm_3_GPIO_PORT, &GPIO_InitStructure);
	
	
	//小车刹车
	MTR_CarBrakeAll();
}
