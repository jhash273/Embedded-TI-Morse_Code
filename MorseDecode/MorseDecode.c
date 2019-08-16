/*
 * MorseDecode.c
 *
 *  Created on: Jul 12, 2019
 *      Author: Justin
 */

#include "MorseDecode.h"

char findChar(struct SLL* morseList)
{
    short int listSize = getListSize(morseList);

    struct SLL* current = morseList;

    short int j = 0;
    short int k = 1;

    while (current->next != 0)
    {
        j *= k;
        j += current->data;
        current = current->next;
        k = 10;
    }

    j *= k;
    j += current->data;

    switch(j)
    {
    case 1:
        return 'E';
    case 2:
        return 'T';
    case 11:
        return 'I';
    case 12:
        return 'A';
    case 21:
        return 'N';
    case 22:
        return 'M';
    case 111:
        return 'S';
    case 112:
        return 'U';
    case 121:
        return 'R';
    case 122:
        return 'W';
    case 211:
        return 'D';
    case 212:
        return 'K';
    case 221:
        return 'G';
    case 222:
        return 'O';
    case 1111:
        return 'H';
    case 1112:
        return 'V';
    case 1121:
        return 'F';
    case 1211:
        return 'L';
    case 1221:
        return 'P';
    case 1222:
        return 'J';
    case 2111:
        return 'B';
    case 2112:
        return 'X';
    case 2121:
        return 'C';
    case 2122:
        return 'Y';
    case 2211:
        return 'Z';
    case 2212:
        return 'Q';
    default:
        return '8';
    }
}

