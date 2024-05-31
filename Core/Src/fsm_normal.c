/*
 * fsm_normal.c
 *
 *  Created on: May 28, 2024
 *      Author: Dell
 */

#include "fsm_normal.h"
int n=0;
void Counter(){
	if(n>9) n = 0;
	if(n<0) n = 9;
}
void fsm_simple_buttons_run(){
	if(isRESETPressed() == 1){
		n = 0;
	}

	if(isINCPressed() ==1){
		Counter(n++);

	}

	if(isDECPressed() == 1){
		Counter(n--);

	}
	if (timer0_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			setTimer0(100);
		}
		if (timer1_flag == 1){
			display7SEG(n);
			setTimer1(10);
		}
}
