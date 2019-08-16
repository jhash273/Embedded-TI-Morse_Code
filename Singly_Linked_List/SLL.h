/*
 * SLL.h
 *
 *  Created on: Jul 9, 2019
 *      Author: justi
 */

#ifndef SLL_H_
#define SLL_H_

#include <stdio.h>
#include <stdlib.h>


struct SLL
{
    short int data;
    struct SLL *next;
};


typedef struct SLL* node;

node createNode();
node pushEnd(node, short int);
node popFirst(node);
node nextNode(node);
short int getListSize(node);
void destroyList(node);


#endif /* SLL_H_ */
