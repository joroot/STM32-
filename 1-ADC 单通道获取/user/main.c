#include "stm32f10x.h"
#include "./led/bsp_led.h"   
#include "./systick/bsp_systick.h"
#include "./usart/bsp_usart.h"
#include "./time/bsp_time.h"
#include "./adc/bsp_adc.h"

extern __IO uint16_t ADC_ConvertedValue;

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal;        

// �����ʱ
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 


int main(void)
{
	LED_GPIO_Config();
	SysTick_Init();
	USART_Config();	

	// ADC ��ʼ��
	ADCx_Init();
	printf("\r\n ----����һ��ADC��ͨ���ж϶�ȡʵ��----\r\n");
	
	while (1)
	{
		ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; 
	
		printf("\r\n The current AD value = 0x%04X \r\n",ADC_ConvertedValue); 
		printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal); 
		printf("\r\n\r\n");

//		Delay_us(500);
 
	}
}
