/*
 * State2.h
 *
 *  Created on: Jul 10, 2019
 *      Author: Justin
 */

#ifndef STATE2_H_
#define STATE2_H_

#include <msp430.h>
#include "SLL.h"
#include "ConfigureControl.h"

char readMorseChar();
char addCharCode(struct SLL*);
void resetTimer();
short int getMorse();

#endif /* STATES_STATE2_H_ */
