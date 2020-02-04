#include "HwPWM.h"
void HwPWMInit(void)
{
		timer1Init(T1_PWM_Phase_8,T1_OC1A_OC1B,T1_PRESCALER_64,0,200,200,0,T1_INTERRUPT_All);
}


void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency)
{
	
float dutyReal;
uint16_t pwm_time_on = MAX_HOLD;
	switch(a_u32_frequency)
	{
		case 1:
		{
		u32g_T1_Prescaler=T1_PRESCALER_NO;
			break;
		}		
		case 2:
		{
			u32g_T1_Prescaler=T1_PRESCALER_8;
			break;
		}		
		case 3:
		{
			u32g_T1_Prescaler=T1_PRESCALER_64;
			break;
		}	
		case 4:
		{
			u32g_T1_Prescaler=T1_PRESCALER_256;
			break;
		}
		case 5:
		{
			u32g_T1_Prescaler=T1_PRESCALER_1024;
			break;	
		}			
	}	
timer1Start();
dutyReal=((float)a_u8_duty/(float)FULL_SPEED);
pwm_time_on=(float)pwm_time_on*dutyReal;
OCR1A=pwm_time_on;
OCR1B=pwm_time_on;

}
