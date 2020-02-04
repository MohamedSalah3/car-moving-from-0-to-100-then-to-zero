/*
 * dcMotor.c
 *
 * Created: 03/02/2020 08:23:24 م
 *  Author: mo
 */ 
#include "dcMotor.h"
#include "dcMotorConfig.h"
#include "gpio.h"
void MotorDC_Init(En_motorType_t en_motor_number)
{
	switch(en_motor_number){
		case MOT_1 :{
	/*Enable PWM Bit...output*/
	gpioPinDirection(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,OUTPUT);
	/*IN1*/
	gpioPinDirection(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,OUTPUT);
	/*IN2*/
	gpioPinDirection(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,OUTPUT);
			break;
		}					
	case MOT_2:{
	/*ENABLE PWM BIT FOR MOTOR 2*/
	gpioPinDirection(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,OUTPUT);
	/*IN3*/
	gpioPinDirection(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,OUTPUT);
	/*IN4*/
	gpioPinDirection(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,OUTPUT);
			break;
			}
			case ALLMOT:
			{
				/*Enable PWM Bit...output*/
				gpioPinDirection(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,OUTPUT);
				/*IN1*/
				gpioPinDirection(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,OUTPUT);
				/*IN2*/
				gpioPinDirection(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,OUTPUT);

				/*ENABLE PWM BIT FOR MOTOR 2*/
				gpioPinDirection(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,OUTPUT);
				/*IN3*/
				gpioPinDirection(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,OUTPUT);
				/*IN4*/
				gpioPinDirection(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,OUTPUT);
				break;
				
			}	
		}

}
void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir)
{
switch(en_motor_number)
{
	case MOT_1:{
	switch(en_motor_dir)
	{
		case FORWARD:
		{
			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
			
			break;
		}
		case BACKWARD:
		{
			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
			
			break;
		}
		case STOP:{gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
		gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
		break;}
	
	}
		break;
	}
	case MOT_2:
	{
		switch(en_motor_dir)
		{
			case FORWARD:
			{
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);
				
				break;
			}
			case BACKWARD:
			{
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
				break;
			}
			case STOP:
			{
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
				break;
			}
			
		}

		break;
	}
	case ALLMOT:
	{
switch(en_motor_dir)
{
	case FORWARD:
	{
		gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
		gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
		
		gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
		gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);
		
		break;
	}
	case BACKWARD:
	{
		
		gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
		gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
		
		gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
		gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
		
		break;	}
	case STOP:
	{
			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
			gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
			
			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
			gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
			
		break;
	}		
	}
	
}
	break;
	}

	}		
	

void MotorDC_Speed_HwPWM(uint8_t u8_motor_speed)
{
HwPWMSetDuty(u8_motor_speed,1);
}