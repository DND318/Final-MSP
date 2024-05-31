/*
 * button.h
 *
 *  Created on: May 27, 2024
 *      Author: Dell
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int RESET_flag;
extern int INC_flag;
extern int DEC_flag;

void getkeyInput();


#endif /* INC_BUTTON_H_ */
