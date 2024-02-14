#include <stdlib.h>
#include <string.h>

#include "min-heap.h"

p_minHeap createHeap(int size)
{
    p_minHeap heap = malloc(sizeof(struct minHeap));
    if(!heap)
        exit(1);

    heap->elements = malloc(size * sizeof(struct Element));
    if(!heap->elements)
        exit(1);

    heap->numberOfElements = 0;
    heap->size = size;

    return heap;
}

void freeHeap(p_minHeap heap)
{
    free(heap->elements);
    free(heap);
}

int isHeapEmpty(p_minHeap heap)
{
    return heap->numberOfElements ? 0 : 1;
}

int isHeapFull(p_minHeap heap)
{
    return heap->numberOfElements >= heap->size ? 1 : 0;
}

void swap(struct Element *a, struct Element *b)
{
    /* Swaps two elements in the heap's array of elements */

    struct Element t = *a;
    *a = *b;
    *b = t;
}

#define fatherNode(i) ((i-1)/2)

void upHeap(p_minHeap heap, int index)
{
    /* Given an element index, moves it up the min-heap if necessary */ 

    // checks if father node has bigger priority value and, if so, swaps its place in the array with the child node, calling the function recursively

    if(index > 0 && heap->elements[fatherNode(index)].priority > heap->elements[index].priority)
    {
        swap(&heap->elements[index], &heap->elements[fatherNode(index)]);
        upHeap(heap, fatherNode(index));
    }
}

void push(p_minHeap heap, char *value, int priority)
{
    /* Creates an element and adds it into the heap's array */

    struct Element element;
    element.priority = priority;
    strcpy(element.value, value);

    heap->elements[heap->numberOfElements] = element;
    heap->numberOfElements++;

    // adjusts the heap tree

    upHeap(heap, heap->numberOfElements-1);
}

#define leftChild(index) (2*index+1)
#define rightChild(index) (2*index+2)

int findSmallestChild(p_minHeap heap, int index)
{
    int smallestChildIndex = index;;

    if(leftChild(index) < heap->numberOfElements) // check array bounds
    {
        smallestChildIndex = leftChild(index);

        if(rightChild(index) < heap->numberOfElements && 
           heap->elements[rightChild(index)].priority < heap->elements[leftChild(index)].priority)
            smallestChildIndex = rightChild(index);
    }

    return smallestChildIndex;
}

void downHeap(p_minHeap heap, int index)
{
    /* Given an element index, moves it down the min-heap if necessary */ 

    // checks if child with less priority value has it lower than father's and, if so, swaps its places in the array, calling the function recursively

    int smallestChildIndex = findSmallestChild(heap, index);

    if(heap->elements[index].priority > heap->elements[smallestChildIndex].priority)
    {
        swap(&heap->elements[index], &heap->elements[smallestChildIndex]);
        downHeap(heap, smallestChildIndex);
    }
}

void removeTopElement(p_minHeap heap)
{
    /* Swaps the top element with the bottom one and then decreases the array bound, removing it */

    swap(&heap->elements[0], &heap->elements[heap->numberOfElements-1]);
    heap->numberOfElements--;

    // adjusts the heap tree

    downHeap(heap, 0);
}

struct Element pop(p_minHeap heap)
{
    /* Remove element with higher priority from heap and returns it */

    struct Element topNode = heap->elements[0];

    removeTopElement(heap);

    return topNode;
}