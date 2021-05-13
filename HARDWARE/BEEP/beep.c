#include "beep.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK ��ӢSTM32������
//��������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PB8Ϊ�����.��ʹ������ڵ�ʱ��		    
//��������ʼ��
void BEEP_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��GPIOB�˿�ʱ��
 
 GPIO_InitStructure.GPIO_Pin = BUZZER ;				 //BEEP-->PB.8 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);	 //���ݲ�����ʼ��GPIOB.8
 
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

