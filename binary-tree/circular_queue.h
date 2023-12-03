#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include <stdio.h>

#include "binary-tree.h"

typedef struct queue *p_queue;

struct queue
{
    p_tree *array;
    int front, rear, size, numberOfElements;
};

p_queue createQueue(int size);

void eraseQueue(p_queue queue);

int isFull(p_queue queue);

int isEmpty(p_queue queue);

void enqueue(p_queue queue, p_tree value);

p_tree dequeue(p_queue queue);

p_tree firstItem(p_queue queue);

p_tree lastItem(p_queue queue);

#endif