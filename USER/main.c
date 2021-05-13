#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "rtc.h"
#include "lcd.h"
#include "string.h" 
#include "BIZHANG.H"
#include "usart3.h"
#include "stm32f10x.h"                  // Device header
#include "MTR_GPIO.h"
#include "LED.h"
#include "blueTooth.h"
#include "PWM_GeneralTim.h"


/************************************************

 STM32F103ZET6新建工程模板
 项目名称：基于STM32ZET6平台的rtc时钟,时间串口可调整
 作者：TONG
************************************************/


 int main(void)
 {	
//	 u8 reclen=0;
	 
	 
	 delay_init();
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	

	 LED_Init();
	 BEEP_Init();

	//KEY_Init();//后期调速
	//LCD_Init();		 
 
	 MTR_GPIOInit();//电机引脚
	//GENERAL_TIM_Init();//定时器PWM初始化，用于小车转向
   	pwm_1_CCW;
    pwm_3_CCW;
	
	 delay_ms(1000);
	 usart3_init(9600);//串口
	 
	 delay_ms(1000);
	 u3_printf("Usart3_init is ok!");
	 delay_ms(1000);
   USART3_RX_STA=0;	
	 LED1=1;
	 BUZZER_BEEP2();
	 bizhang_init();
	 while(1)
		{ 
        LED0=0;
			  delay_ms(500);
			  LED0=1;
			  delay_ms(500);
		}
 }




