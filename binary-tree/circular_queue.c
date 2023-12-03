#include <stdlib.h>
#include <stdio.h>

#include "circular_queue.h"

p_queue createQueue(int size)
{
    p_queue new;
    new = malloc(sizeof(struct queue));
    if(!new)
        exit(1);

    p_tree *array = malloc(size * sizeof(p_tree));
    if(!array)
        exit(1);
    new->array = array;

    new->front = 0;
    new->rear = 0;
    new->size = size;
    new->numberOfElements = 0;

    return new;
}

void eraseQueue(p_queue queue)
{
    free(queue->array);
    free(queue);
}

int isFull(p_queue queue)
{
    return queue->numberOfElements == queue->size ? 1 : 0;
}

int isEmpty(p_queue queue)
{
    return !queue->numberOfElements ? 1 : 0;
}

void enqueue(p_queue queue, p_tree value)
{
    queue->array[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->size;
    queue->numberOfElements++;
}

p_tree dequeue(p_queue queue)
{
    p_tree value = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    queue->numberOfElements--;
    
    return value;
}

p_tree firstItem(p_queue queue)
{
    return queue->array[queue->front];
}

p_tree lastItem(p_queue queue)
{
    int lastElement = ((queue->rear -1) + queue->size) % queue->size;
    return queue->array[lastElement];
}
