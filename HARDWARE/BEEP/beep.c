#include "beep.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK 精英STM32开发板
//蜂鸣器驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB8为输出口.并使能这个口的时钟		    
//蜂鸣器初始化
void BEEP_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能GPIOB端口时钟
 
 GPIO_InitStructure.GPIO_Pin = BUZZER ;				 //BEEP-->PB.8 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);	 //根据参数初始化GPIOB.8
 
 GPIO_WriteBit(BUZZERPORT,BUZZER,(BitAction)(0));
}
void BUZZER_BEEP1(void)
{
   u16 i;
	for(i=0;i<200;i++)
	{
		GPIO_WriteBit(BUZZERPORT,BUZZER,(BitAction)(1));
	  delay_us(500);
		GPIO_WriteBit(BUZZERPORT,BUZZER,(BitAction)(0));
		delay_us(500);
	}
}

void BUZZER_BEEP2(void)
{
   u16 i;
	for(i=0;i<200;i++)
	{
		GPIO_WriteBit(BUZZERPORT,BUZZER,(BitAction)(1));
	  delay_us(200);
		GPIO_WriteBit(BUZZERPORT,BUZZER,(BitAction)(0));
		delay_us(200);
	}
}


uc16 music1[52]={ 
659,750,
0  ,750,
659,350,
587,350,
523,350,
523,750,
0  ,750,
523,750,
587,375,
523,350,
494,350,
440,750,
0  ,750,
523,350,
587,375,
523,375,
494,350,
440,750,
0  ,750, 
494,750,
523,750,
587,750,
0  ,350,
523,750,
494,350,
523,1000,
};

void MIDI_PLAY(void){ 
	u16 i,e;
	for(i=0;i<26;i++){
		for(e=0;e<music1[i*2]*music1[i*2+1]/1000;e++){
			GPIO_WriteBit(BUZZERPORT,BUZZER,(BitAction)(1));
			delay_us(500000/music1[i*2]); 	
			GPIO_WriteBit(BUZZERPORT,BUZZER,(BitAction)(0));
			delay_us(500000/music1[i*2]); 	
		}	
	}
}

