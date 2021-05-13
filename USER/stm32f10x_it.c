/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h" 
#include "stm32f10x.h"
#include "usart3.h"
#include "LED.h"
#include "MTR_GPIO.h"
#include "PWM_GeneralTim.h"
#include "beep.h"
#include "BIZHANG.H"
void NMI_Handler(void)
{
}
 
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
 
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

 
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
 
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
 
void SVC_Handler(void)
{
}
 
void DebugMon_Handler(void)
{
}
 
void PendSV_Handler(void)
{
}
 
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
void USART3_IRQHandler(void)         
{
uint8_t CMD = 0;//接收的命令
	if(USART_GetITStatus(USART3, USART_IT_RXNE)!=RESET){
//		BUZZER_BEEP1();
		
		CMD = USART_ReceiveData(USART3);//读取一个
		switch(CMD){
			case '5':
				//电机停止
  			MTR_CarBrakeAll();
				u3_printf("STOP");
				break;
			case '6':
				//小车向左
				MTR_CarCW();
				u3_printf("LEFT");
				break;
			case '4':
				//小车向右
				MTR_CarCCW();
				u3_printf("RIGHT");
				break;
			case '2':
				//小车前进
				MTR_CarGo();
				u3_printf("FORWARD");
				break;
			case '8':
				//小车后退
				MTR_CarBackGo();
				u3_printf("BACK");
				break;
			case '0':
				//小车开灯
			  LED1=1;
			  BUZZER_BEEP1();
				u3_printf("LED ON");
				break;
			case '1':
				//小车关灯
			  LED1=0;
			  BUZZER_BEEP2();
				u3_printf("LED OFF");
				break;
			case '7':
				//避障
			  //BUZZER_BEEP2();
        bizhang();
				u3_printf("SAFEMODE_Close");
				break;
			case '3':
				MIDI_PLAY();
				break;
		}
		
	}
			
//		USART3_RX_STA=0;	 
	USART_ClearFlag(USART3,USART_FLAG_RXNE);

}   

