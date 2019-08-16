/*
 * State3.c
 *
 *  Created on: Jul 10, 2019
 *      Author: Justin
 */

#include "State3.h"

void displayMorseMessage(struct SLL* charList)
{
    initGPIO(); // Initializes General Purpose
                // Inputs and Outputs for LCD
    initClocks(); // Initialize clocks for LCD
    myLCD_init(); // Prepares LCD to receive commands

    short int charListSize = getListSize(charList);
    short int i = 0;
    //short int pbThreeUp = 0;
    struct SLL* current = 0;
    struct SLL* front = 0;

    front = charList;
    current = charList;

    if (charListSize <= 6)
    {
        for(i = 1; i <= charListSize; i++)
        {
            myLCD_showChar(current->data,i);
            current = current->next;
        }
    }
    else
    {
        establishTimer2();
        charList = pushEnd(current, 32);
        charList = pushEnd(current, 32);
        charList = pushEnd(current, 32);
    }

    while(1)
    {
        if((TA1CTL & TAIFG) && charListSize > 6)
        {
            current = front;

            for(i = 1; i <= 6; i++)
            {
                myLCD_showChar(current->data,i);

                if(current->next != 0)
                {
                    current = current->next;
                }
                else
                {
                    current = charList;
                }
            }

            if(front->next != 0)
            {
                front = front->next;
            }
            else
            {
                front = charList;
            }

            TA1CTL = TA1CTL & (~TAIFG);
        }



        /*if((PB3 & P2IN) != 0)
        {
            pbThreeUp = 1;
        }

        if(((PB3 & P2IN) == 0) && pbThreeUp == 1)
        {

            myLCD_showChar( ' ', 1 );
            myLCD_showChar( ' ', 2 );
            myLCD_showChar( ' ', 3 );
            myLCD_showChar( ' ', 4 );
            myLCD_showChar( ' ', 5 );
            myLCD_showChar( ' ', 6 );

            destroyList(charList);

            break;
        }*/
    }
}



