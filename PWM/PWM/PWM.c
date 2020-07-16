/*
 * PWM.c
 *
 * Created: 06/07/2020 18:39:38
 *  Author: ADHM
 */
 #include "PWM.h"
 static uint8_t mode; 
 static uint8_t comp; 
void PWM_INI(uint8_t MODE,uint8_t COMPARE_MODE,uint8_t prescale )
{//Enble force compare match for wave generating
	SET_BIT(TCCR0,FOC0);
	//setting OC0 AS OUTPUT 
	SET_BIT(DDRB,3);
	//CHHOSING MODE 
	switch(MODE)
	{case FAST_PWM : SET_BIT(TCCR0,WGM00);SET_BIT(TCCR0,WGM01);mode=0;break;
		case PHASE_CORRECT : SET_BIT(TCCR0,WGM00);CLR_BIT(TCCR0,WGM01);mode=1;break;
		//default fast pwm
		default:SET_BIT(TCCR0,WGM00);SET_BIT(TCCR0,WGM01);break;
	}
	
	switch(COMPARE_MODE)
	{case NON_INVERTED:CLR_BIT(TCCR0,COM00);SET_BIT(TCCR0,COM01);comp=0;break;
		case INVERTED:SET_BIT(TCCR0,COM00);SET_BIT(TCCR0,COM01);comp=1;break;
		case CLR_UP_SET_DOWN: CLR_BIT(TCCR0,COM00);SET_BIT(TCCR0,COM01);comp=2;break;
		case SET_UP_CLR_DOWN: SET_BIT(TCCR0,COM00);SET_BIT(TCCR0,COM01);comp=3;break;
		
		//default non_inverted in fast pwm or clr up set down in phase correct 
		default:CLR_BIT(TCCR0,COM00);SET_BIT(TCCR0,WGM01);SET_BIT(TCCR0,WGM00);SET_BIT(TCCR0,COM01);break;
	}
	switch (prescale)
	{case _1:SET_BIT(TCCR0,CS00);CLR_BIT(TCCR0,CS01);CLR_BIT(TCCR0,CS02);break;
		
		case _8:CLR_BIT(TCCR0,CS00);SET_BIT(TCCR0,CS01);CLR_BIT(TCCR0,CS02);break;
		case _64:SET_BIT(TCCR0,CS00);SET_BIT(TCCR0,CS01);CLR_BIT(TCCR0,CS02);break;
		case _256:CLR_BIT(TCCR0,CS00);CLR_BIT(TCCR0,CS01);SET_BIT(TCCR0,CS02);break;
		case _1024:SET_BIT(TCCR0,CS00);CLR_BIT(TCCR0,CS01);SET_BIT(TCCR0,CS02);break;
		//default /64
		default:SET_BIT(TCCR0,CS00);SET_BIT(TCCR0,CS01);CLR_BIT(TCCR0,CS02);break;
		
	}
}
void GENERATE_WAVE(float DUTY_CYLCE)
{
switch(mode)
{case FAST_PWM:
	switch(comp)
	{case NON_INVERTED:OCR0=(((256*DUTY_CYLCE)/100)-1);break;
	 case INVERTED:OCR0=(255-(256/100)*DUTY_CYLCE);break;
	 //default NON-INVERTED 
	 default:OCR0=(((256*DUTY_CYLCE)/100)-1);break;}break;
	 case PHASE_CORRECT:
	switch(comp)
	{case CLR_UP_SET_DOWN:OCR0=(((255*DUTY_CYLCE)/100));break;
		case SET_UP_CLR_DOWN:OCR0=(255-((255*DUTY_CYLCE)/100));break;
		//default CLR-UP SET DOWN
	default:OCR0=(((256*DUTY_CYLCE)/100)-1);break;}break;
		
	}
	
}