#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "min-heap.h"

#define HEAP_SIZE 2

int main()
{
    p_minHeap heap = createHeap(HEAP_SIZE);
    int elementPriority;
    char choice[50], elementValue[50];

    printf("- push <string> <priority>\n- pop\n- quit\n");
    do
    {
        scanf(" %s", choice);

        if(!strcmp(choice, "push"))
        {
            if(!isHeapFull(heap))
            {
                scanf(" %s", elementValue);
                scanf(" %d", &elementPriority);
                push(heap, elementValue, elementPriority);
            }
            else
                printf("Heap is full.\n");
        }
        else if(!strcmp(choice, "pop"))
        {
            if(!isHeapEmpty(heap))
            {
                struct Element element = pop(heap);
                printf("|| string: %s\n|| priority: %d\n", element.value, element.priority);
            }
            else
                printf("Heap is empty.\n");
        }
        else
            printf("Invalid Option.\n");

    } while (strcmp(choice, "quit"));

    freeHeap(heap);

    return 0;
}