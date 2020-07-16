/*
 * PWM.h
 *
 * Created: 06/07/2020 18:39:26
 *  Author: ADHM
 */ 


#ifndef PWM_H_
#define PWM_H_
#include <avr/io.h>

#define F_CPU 16000000UL
//PWM MODES
#define FAST_PWM 0
#define PHASE_CORRECT 1
//FAST PWM MODES 
#define NON_INVERTED 0
#define INVERTED 1
//PHASE CORRECT MODES 
#define CLR_UP_SET_DOWN 2
#define SET_UP_CLR_DOWN 3
//calculating PRESCALE
#define  _1 0
#define  _8 1
#define  _64 2
#define  _256 3
#define _1024 4


#define SET_BIT(REG,INDX) ((REG)|=(1<<(INDX)))
#define CLR_BIT(REG,INDX) ((REG)&=~(1<<(INDX)))


void PWM_INI(uint8_t MODE,uint8_t COMPARE_MODE,uint8_t prescale );
void GENERATE_WAVE(float DUTY_CYLCE);





#endif /* PWM_H_ */