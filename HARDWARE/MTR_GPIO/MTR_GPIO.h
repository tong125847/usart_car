#ifndef __MTR_GPIO_H
#define __MTR_GPIO_H

#include "stm32f10x.h"

/*
	小车四轮驱动
	电机1：右上
	电机2：右下
	电机3：左上
	电机4：左下
*/
#define MTR1_GPIO_PORT		GPIOF
#define MTR1_GPIO_CLK 	    RCC_APB2Periph_GPIOF
#define MTR1_GPIO_PIN		GPIO_Pin_0|GPIO_Pin_2
#define MTR1_CW				{GPIO_ResetBits(MTR1_GPIO_PORT,GPIO_Pin_0);GPIO_SetBits(MTR1_GPIO_PORT,GPIO_Pin_2);}//顺时针
#define MTR1_CCW			{GPIO_SetBits(MTR1_GPIO_PORT,GPIO_Pin_0);GPIO_ResetBits(MTR1_GPIO_PORT,GPIO_Pin_2);}//逆时针
#define MTR1_BRAKE			GPIO_ResetBits(MTR1_GPIO_PORT,MTR1_GPIO_PIN);

//#define MTR2_GPIO_PORT    	GPIOB
//#define MTR2_GPIO_CLK 	    RCC_APB2Periph_GPIOB
//#define MTR2_GPIO_PIN		GPIO_Pin_8|GPIO_Pin_9
//#define MTR2_CW				{GPIO_ResetBits(MTR2_GPIO_PORT,GPIO_Pin_8);GPIO_SetBits(MTR2_GPIO_PORT,GPIO_Pin_9);}//顺时针
//#define MTR2_CCW			{GPIO_SetBits(MTR2_GPIO_PORT,GPIO_Pin_8);GPIO_ResetBits(MTR2_GPIO_PORT,GPIO_Pin_9);}//逆时针
//#define MTR2_BRAKE			GPIO_ResetBits(MTR2_GPIO_PORT,MTR2_GPIO_PIN);

#define MTR3_GPIO_PORT    	GPIOF
#define MTR3_GPIO_CLK 	    RCC_APB2Periph_GPIOF
#define MTR3_GPIO_PIN		GPIO_Pin_4|GPIO_Pin_6
#define MTR3_CW				{GPIO_ResetBits(MTR3_GPIO_PORT,GPIO_Pin_4);GPIO_SetBits(MTR3_GPIO_PORT,GPIO_Pin_6);}//顺时针
#define MTR3_CCW			{GPIO_SetBits(MTR3_GPIO_PORT,GPIO_Pin_4);GPIO_ResetBits(MTR3_GPIO_PORT,GPIO_Pin_6);}//逆时针
#define MTR3_BRAKE			GPIO_ResetBits(MTR3_GPIO_PORT,MTR3_GPIO_PIN);


#define pwm_1_GPIO_PORT   GPIOF
#define pwm_1_GPIO_CLK    RCC_APB2Periph_GPIOF
#define pwm_1_GPIO_PIN    GPIO_Pin_13
#define pwm_1_CW          {GPIO_ResetBits(pwm_1_GPIO_PORT,pwm_1_GPIO_PIN);}
#define pwm_1_CCW         {GPIO_SetBits(pwm_1_GPIO_PORT,pwm_1_GPIO_PIN);}
//#define pwm_1_BRAKE       GPIO_ResetBits(pwm_1_GPIO_PORT,MTR3_GPIO_PIN);

#define pwm_3_GPIO_PORT   GPIOF
#define pwm_3_GPIO_CLK    RCC_APB2Periph_GPIOF
#define pwm_3_GPIO_PIN    GPIO_Pin_15
#define pwm_3_CW          {GPIO_ResetBits(pwm_3_GPIO_PORT,pwm_3_GPIO_PIN);}
#define pwm_3_CCW         {GPIO_SetBits(pwm_3_GPIO_PORT,pwm_3_GPIO_PIN);}
//#define pwm_3_BRAKE       GPIO_ResetBits(pwm_3_GPIO_PORT,MTR3_GPIO_PIN);

//#define MTR4_GPIO_PORT    	GPIOB
//#define MTR4_GPIO_CLK 	    RCC_APB2Periph_GPIOB
//#define MTR4_GPIO_PIN		GPIO_Pin_14|GPIO_Pin_15
//#define MTR4_CW				{GPIO_ResetBits(MTR4_GPIO_PORT,GPIO_Pin_14);GPIO_SetBits(MTR4_GPIO_PORT,GPIO_Pin_15);}//顺时针
//#define MTR4_CCW			{GPIO_SetBits(MTR4_GPIO_PORT,GPIO_Pin_14);GPIO_ResetBits(MTR4_GPIO_PORT,GPIO_Pin_15);}//逆时针
//#define MTR4_BRAKE			GPIO_ResetBits(MTR4_GPIO_PORT,MTR4_GPIO_PIN);

void MTR_CarBrakeAll(void);		//小车刹车
void MTR_CarGo(void);			//小车前进
void MTR_CarBackGo(void);		//小车后退
void MTR_CarCW(void);			//右转
void MTR_CarCCW(void);			//左转
void MTR_GPIOInit(void);

#endif
