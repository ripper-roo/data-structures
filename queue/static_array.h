#ifndef STATIC_ARRAY
#define STATIC_ARRAY

#include <stdio.h>

#define SIZE 4

int isFull();

int isEmpty();

void enqueue(int *queue, int value);

void dequeue(int *queue);

int firstItem(int *queue);

int lastItem(int *queue);

void print(int *queue);

#endif