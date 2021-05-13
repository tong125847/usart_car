#include "BIZHANG.H"
#include "MTR_GPIO.h"
#include "delay.h"
#include "stm32f10x_it.h" 
#include "stm32f10x.h"
#include "usart3.h"
#include "LED.h"
#include "PWM_GeneralTim.h"
#include "beep.h"

void bizhang_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(BIZHANG1_GPIO_CLK|BIZHANG2_GPIO_CLK,ENABLE);//时钟
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//弱下拉
	//左通道
	GPIO_InitStructure.GPIO_Pin = BIZHANG1_GPIO_PIN;
	GPIO_Init(BIZHANG1_GPIO_PORT, &GPIO_InitStructure);

	//右通道
	GPIO_InitStructure.GPIO_Pin = BIZHANG2_GPIO_PIN;
	GPIO_Init(BIZHANG2_GPIO_PORT, &GPIO_InitStructure);


}



void bizhang(void)
{
	while(1)
	{      
							
					
					       //有信号为1  没有信号为0
                if(BIZHANG1_STATE==1&&BIZHANG2_STATE==1)
                {
                
                   MTR_CarGo();;   //调用前进函数    
										
                }          
//                if(BIZHANG1_STATE==0&&BIZHANG2_STATE==1)            //右边检测到障碍物
//                {
//                        
//                        
//                        MTR_CarBackGo();
//                        delay_ms(200);
//                        MTR_CarCCW();                    //调用小车左转函数
//                        delay_ms(200);
//												
//                
//                }                           
                if(BIZHANG1_STATE==1 &&BIZHANG2_STATE==0)                //左边检测到障碍物  
                {          
                        
                        
                        MTR_CarBackGo();
                        delay_ms(200);
                        MTR_CarCW();                     //调用小车右转函数
                        delay_ms(200);
												
                        
                }
                if (BIZHANG1_STATE==0&&BIZHANG2_STATE==0)                //左边检测到障碍物  &&BIZHANG2_STATE==1 
                {          
                        MTR_CarBackGo();                //调用小车右转函数
												
								}
					 if(USART_ReceiveData(USART3)=='9')  
							break;
						
			} 
	MTR_CarBrakeAll();
}
