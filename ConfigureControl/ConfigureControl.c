/*
 * LightControl.c
 *
 *  Created on: Jul 10, 2019
 *      Author: Justin
 */

#include <ConfigureControl.h>

void greenOn()
{
    P9OUT = P9OUT | GREEN_LED;
}

void greenOff()
{
    P9OUT = OFF; //Turn off Green LED
}

void redOn()
{
    P1OUT = P1OUT | RED_LED;
}

void redOff()
{
    P1OUT = PB2; //Turn off Red LED but keep Push Up Resistor on Port 1 for PB2
}

void establishIO()
{
    PM5CTL0 = ENABLE_PINS; //Enable Pins

    P9DIR = GREEN_LED; //Enable port 9 output green LED
    P1DIR = RED_LED; //Enable port 1 output red LED

    P4REN = PB1; //Enable pull up resistor for PB1
    P4OUT = PB1; //Enable PB1 as a port 4 input

    P1REN = PB2; //Enable pull up resistor for PB2
    P1OUT = PB2; //Enable PB2 as a port 1 input

    P2REN = PB3; //Enable pull up resistor for PB3
    P2OUT = PB3; //Enable PB3 as a port 2 input

}

void establishTimer1()
{
    TA0CCR0 = 8000; // We will count up from 0 to 20000
    TA0CTL = ACLK | UP; // Use ACLK, for UP mode
}

void establishTimer2()
{
    TA1CCR0 = 8000; // We will count up from 0 to 20000
    TA1CTL = ACLK | UP; // Use ACLK, for UP mode
}
