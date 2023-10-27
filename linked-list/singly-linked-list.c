#include <stdio.h>
#include <stdlib.h>

#include "singly-linked-list.h"

p_node createList(void)
{
    /* Create head */
    
    p_node new = malloc(sizeof(struct node));
    if(!new)
        exit(1);

    new->next = NULL;

    return new;
}

void eraseList(p_node head)
{
    while(head)
    {
        p_node alt = head->next;
        free(head);
        head = alt;
    }
}

void printList(p_node head)
{
    p_node alt = head->next;

    while(alt)
    {
        printf("%d ", alt->data);
        alt = alt->next;
    }

    printf("\n");
}

int isEmpty(p_node head)
{
    return head->next ? 1 : 0;
}

p_node searchValue(p_node head, int value)
{
    p_node alt = head;
    while(alt)
    {
        if(alt->data == value)
            return alt;

        alt = alt->next;
    }

    return NULL;
}

void insertAtFront(p_node head, int value)
{
    /* Insert the given value at the front of the list */

    p_node new = malloc(sizeof(struct node));
    if(!new)
        exit(1);

    new->data = value;

    new->next = head->next;
    head->next = new;
}

void insertAtBack(p_node head, int value)
{
    /* Insert the given value at the back of the list */

    p_node new = malloc(sizeof(struct node));
    if(!new)
        exit(1);

    new->data = value;

    p_node lastValue = head;
    while(lastValue->next)
    {
        lastValue = lastValue->next;
    }

    lastValue->next = new;
}

void insertAfter(p_node head, int specifiedValue, int valueToBeAdded)
{
    /* Insert the given value right after the specified item */

    p_node searchResult = searchValue(head, specifiedValue);
    if(searchResult)
    {
        p_node new = malloc(sizeof(struct node));
        if(!new)
            exit(1);

        new->data = valueToBeAdded;
        
        new->next = searchResult->next;
        searchResult->next = new;
    }
    else
        printf("Value not found.\n");
}

void deleteAtFront(p_node head)
{
    /* Delete the first item */

    p_node firstValue = head->next;
    head->next = firstValue->next;

    free(firstValue);
}

void deleteAtBack(p_node head)
{
    /* Delete the last item */

    p_node newLastValue = head, lastValue = head->next;

    while(lastValue->next)
    {
        newLastValue = lastValue;
        lastValue = lastValue->next;
    }
    
    free(lastValue);
    newLastValue->next = NULL;
}

void deleteValue(p_node head, int value)
{
    /* Delete the specified value */

    p_node previousNode = head, nodeToBeDeleted = head->next;

    while(nodeToBeDeleted->data != value && nodeToBeDeleted->next)
    {
        previousNode = nodeToBeDeleted;
        nodeToBeDeleted = nodeToBeDeleted->next;
    }

    if(nodeToBeDeleted->data != value)
        printf("Value not found.\n");
    else
    {
        previousNode->next = nodeToBeDeleted->next;
        free(nodeToBeDeleted);
    }
}