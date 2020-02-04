/*
 * HWPWM.c
 *
 * Created: 03/02/2020 12:23:35 ص
 *  Author: mo
 */ 
#include "HwPWM.h"
#include "Interrupts.h"
#include "timers.h"
#include "registers.h"
#include "std_types.h"
#include "dcMotor.h"
#include "dcMotorConfig.h"

int main(void)
{uint8_t speed=0,flag1=1,flag2=0,flag3=1;
	MotorDC_Init(ALLMOT);
	timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_1024,0,0,0,T2_POLLING);
/*
*intialize Timer1 and make OC1B,OC1A output ,start the timer
*/
	HwPWMInit();
	while(1)
    {
		MotorDC_Dir(ALLMOT,FORWARD);
		if (flag1==1 || flag2 < 100 && flag3==1)
		{
			flag1=0;
			flag2++;
			while(speed<100){
			MotorDC_Speed_HwPWM(speed++);
			}
			timer2Start();
			timer2DelayMs(50);
		}else
		{
	MotorDC_Speed_HwPWM(speed--);
	timer2Start();
	timer2DelayMs(50);
	if (speed<10)
	{
		flag3=1;
		flag1=1;
		flag2=0;
	}
		}
		
	}
	
}