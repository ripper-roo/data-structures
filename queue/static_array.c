#include <stdio.h>

#include "static_array.h"

int front = -1;
int rear = -1;

int isFull()
{
    return rear == SIZE-1 ? 1 : 0;
}

int isEmpty()
{
    return (front > rear || front == -1) ? 1 : 0;
}

void moveItemsToStart(int *queue)
{
    int temp = 0;
    for(int k = front; k <= rear; k++)
    {
        queue[temp] = queue[k];
        temp++;
    }

    front = 0;
    rear = temp-1;
}

void enqueue(int *queue, int value)
{
    if(isFull() && front > 0) // there is free spaces at front's left
        moveItemsToStart(queue);

    if(!isFull())
    {
        rear++;
        queue[rear] = value;

        if(front == -1) // it's the first value being added
            front++;
    }
}

void dequeue(int *queue)
{
    if(!isEmpty())
    {
        front++;
        if(isEmpty())   // if the queue got empty, restart "front" and "rear" variables to avoid the O(n) displacement done by moveItemsToStart()
        {
            front = -1;
            rear = -1;
        }
    }
}

int firstItem(int *queue)
{
    return queue[front];
}

int lastItem(int *queue)
{
    return queue[rear];
}

void print(int *queue)
{
    for(int k = front; k <= rear; k++)
    {
        printf("%d ", queue[k]);
    }

    printf("\n");
}