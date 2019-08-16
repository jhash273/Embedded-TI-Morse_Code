/*
 * LightControl.h
 *
 *  Created on: Jul 10, 2019
 *      Author: Justin
 */

#ifndef CONFIGURECONTROL_H_
#define CONFIGURECONTROL_H_

#include <msp430.h>

#define ENABLE_PINS 0xFFFE
#define RED_LED BIT0
#define GREEN_LED BIT7
#define OFF 0x0000
#define PB1 BIT7
#define PB2 BIT5
#define PB3 BIT1
#define ACLK 0x0100 //Timer_A ACLK source
#define UP 0x0010 //Timer_A UP mode

void greenOn();
void greenOff();
void redOn();
void redOff();
void flashGreen();

void establishIO();
void establishTimer1();
void establishTimer2();

#endif /* CONFIGURECONTROL_H_ */
