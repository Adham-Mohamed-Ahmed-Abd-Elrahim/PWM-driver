/*
 * PWM.c
 *
 * Created: 06/07/2020 04:36:04
 * Author : ADHM
 */ 

#include "PWM.h"
#include <util/delay.h>


int main(void)
{PWM_INI(FAST_PWM,NON_INVERTED,_8);
	
    /* Replace with your application code */
    while (1) 
    {GENERATE_WAVE(75);
		_delay_ms(8);
		GENERATE_WAVE(30);
		_delay_ms(8);
    }
}

