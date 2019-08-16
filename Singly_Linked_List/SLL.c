/*
 * SLL.c
 *
 *  Created on: Jul 9, 2019
 *      Author: justi
 */

#include "SLL.h"

node createNode()
{
    node temp;
    temp = (node)malloc(sizeof(struct SLL));
    temp->next = NULL;

    return temp;
}

node pushEnd(node head, short int value)
{
    node temp, current;
    temp = createNode();
    temp->data = value;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        current = head;

        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = temp;
    }

    return head;
}

node nextNode(node current)
{
    if(current->next != NULL)
    {
        return current->next;
    }

    return current;
}

short int getListSize(node head)
{
    short int listSize = 0;
    node current;
    current = head;

    while(current != NULL)
    {
        listSize++;
        current = current->next;
    }

    return listSize;
}

void destroyList(node head)
{
    node temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

node popFirst(node head)
{
    node current = head;

    current = pushEnd(current, (short int)current->data);
    current = current->next;

    free(head);

    return current;
}


