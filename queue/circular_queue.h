#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include <stdio.h>

typedef struct queue *p_queue;

struct queue
{
    int *array;
    int front, rear, size, numberOfElements;
};

p_queue createQueue(int size);

int isFull(p_queue queue);

int isEmpty(p_queue queue);

void enqueue(p_queue queue, int value);

int dequeue(p_queue queue);

int firstItem(p_queue queue);

int lastItem(p_queue queue);

void print(p_queue queue);

#endif