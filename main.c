#include <msp430.h> 
#include "ConfigureControl.h"
#include "SLL.h"
#include "State2.h"
#include "State3.h"

//void insertSpace(struct SLL*);

/**
 * main.c
 */
int main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    struct SLL* morseCharList = 0;

    char currentChar;
    short int pbTwoUp = 0;

    establishIO();
    establishTimer1();

    while(1)
    {
        greenOn();

        if((PB1 & P4IN) == 0)
        {
            currentChar = readMorseChar();
            morseCharList = pushEnd(morseCharList, (short int)currentChar);

            pbTwoUp = 0;
        }

        if (pbTwoUp == 0 && ((PB2 & P1IN) != 0))
        {
            pbTwoUp = 1;
        }

        if(pbTwoUp == 1 && ((PB2 & P1IN) == 0))
        {
            pbTwoUp = 0;
            morseCharList = pushEnd(morseCharList, 32);
        }

        if((PB3 & P2IN) == 0)
        {
            displayMorseMessage(morseCharList);
        }
    }
}
