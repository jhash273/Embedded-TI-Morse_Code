/*
 * State3.h
 *
 *  Created on: Jul 10, 2019
 *      Author: Justin
 */

#ifndef STATE3_H_
#define STATE3_H_

#include <msp430.h>
#include "SLL.h"
#include "ConfigureControl.h"
#include "myGpio.h" // Required for the LCD
#include "myClocks.h" // Required for the LCD
#include "myLcd.h" // Required for the LCD


void displayMorseMessage(struct SLL*);
//char convertToChar(int);


#endif /* STATE3_H_ */
