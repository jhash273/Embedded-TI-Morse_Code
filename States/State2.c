/*
 * State2.c
 *
 *  Created on: Jul 10, 2019
 *      Author: Justin
 */

#include "State2.h"

char readMorseChar()
{
    struct SLL* morse = 0;
    short int down = 0;
    char morseChar;

    redOn();
    greenOff();

    while(1)
    {
        if(down == 0 && ((PB1 & P4IN) == 0))
        {
            resetTimer();
            redOn();
            down = 1;
        }

        if(down == 1 && ((PB1 & P4IN) != 0))
        {
            redOff();
            down = 0;
            morse = pushEnd(morse, getMorse());
        }

        if((PB2 & P1IN) == 0)
        {
            redOff();
            morseChar = addCharCode(morse);
            destroyList(morse);
            return morseChar;
        }
    }
}

char addCharCode(struct SLL* morseList)
{
    return findChar(morseList);
}

void resetTimer()
{
    TA0CTL = 0x0110;
    TA0R = 0x0000;
}

short int getMorse()
{
    if(TA0CTL & TAIFG)
    {
        return 2;
    }

    return 1;
}
