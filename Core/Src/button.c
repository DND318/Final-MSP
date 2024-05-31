/*
 * button.c
 *
 *  Created on: May 27, 2024
 *      Author: Dell
 */
#include "button.h"
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  500;
int RESET_flag = 0;
int INC_flag = 0;
int DEC_flag = 0;
int pressDuration;

int isRESETPressed(){
	if(RESET_flag == 1){
		RESET_flag = 0;
		return 1;
	}
	return 0;
}
int isINCPressed(){
	if(INC_flag == 1){
		INC_flag = 0;
		return 1;
	}
	return 0;
}
int isDECPressed(){
	if(DEC_flag == 1){
		DEC_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(){
	//TODO
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	RESET_flag = 1;
	INC_flag = 1;
	DEC_flag = 1;
}

void getkeyInput(){
	//For RESET
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;

      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 500;
        pressDuration = 0;
        subKeyProcess();
      }
    }else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
          KeyReg3 = NORMAL_STATE;
        }
        if (KeyReg3 == PRESSED_STATE){
        	pressDuration ++ ;
        	if(pressDuration >= 300){
        		RESET_flag = 2;
        		pressDuration = 0;
        	}
        }
    }
  }
  // For Button 2
    KeyReg2 = KeyReg1;
    KeyReg1 = KeyReg0;
    KeyReg0 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
    if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
      if (KeyReg2 != KeyReg3){
        KeyReg3 = KeyReg2;

        if (KeyReg3 == PRESSED_STATE){
          TimeOutForKeyPress = 500;
          subKeyProcess();
        }
      }else{
         TimeOutForKeyPress --;
          if (TimeOutForKeyPress == 0){
            KeyReg3 = NORMAL_STATE;
          }
          if (KeyReg3 == PRESSED_STATE){
                  	pressDuration ++ ;
                  	if(pressDuration >= 300){
                  		RESET_flag = 2;
                  		pressDuration = 0;
                  	}
                  }
      }
    }

    // For Button 3
    KeyReg2 = KeyReg1;
    KeyReg1 = KeyReg0;
    KeyReg0 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
    if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
      if (KeyReg2 != KeyReg3){
        KeyReg3 = KeyReg2;

        if (KeyReg3 == PRESSED_STATE){
          TimeOutForKeyPress = 500;
          subKeyProcess();
        }
      }else{
         TimeOutForKeyPress --;
          if (TimeOutForKeyPress == 0){
            KeyReg3 = NORMAL_STATE;
          }
          if (KeyReg3 == PRESSED_STATE){
                  	pressDuration ++ ;
                  	if(pressDuration >= 300){
                  		RESET_flag = 2;
                  		pressDuration = 0;
                  	}
                  }
      }
    }
  }



