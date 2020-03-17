#include "stm32f10x.h"
#include "./led/bsp_led.h"   
#include "./systick/bsp_systick.h"
#include "./usart/bsp_usart.h"
#include "./time/bsp_time.h"
#include "./adc/bsp_adc.h"

extern __IO uint16_t ADC_ConvertedValue;

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal;        

// 软件延时
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 


int main(void)
{
	LED_GPIO_Config();
	SysTick_Init();
	USART_Config();	

	// ADC 初始化
	ADCx_Init();
	printf("\r\n ----这是一个ADC单通道中断读取实验----\r\n");
	
	while (1)
	{
		ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; 
	
		printf("\r\n The current AD value = 0x%04X \r\n",ADC_ConvertedValue); 
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal); 
		printf("\r\n\r\n");

//		Delay_us(500);
 
	}
}
