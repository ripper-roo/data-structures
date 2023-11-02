#include <stdlib.h>
#include <string.h>

#include "circular_queue.h"

#define SIZE 4

int main()
{
    p_queue queue = createQueue(SIZE);
    int value;
    char choice[50];

    printf("- enq <value>\n- deq <value>\n- print\n- first\n- last\n- quit\n");
    do
    {
        scanf(" %s", choice);

        if(!strcmp(choice, "enq"))
        {
            if(!isFull(queue))
            {
                scanf(" %d", &value);
                enqueue(queue, value);
            }
            else
                printf("Queue is full.\n");
        }
        else if(!strcmp(choice, "deq"))
        {
            if(!isEmpty(queue))
            {
                dequeue(queue);
            }
            else
                printf("Queue is empty.\n");
        }
        else if(!strcmp(choice, "print"))
        {
            if(!isEmpty(queue))
            {
                print(queue);
            }
            else
                printf("Queue is empty.\n");
        }
        else if(!strcmp(choice, "first"))
        {
            if(!isEmpty(queue))
            {
                printf("%d\n", firstItem(queue));
            }
            else
                printf("Queue is empty.\n");
        }
        else if(!strcmp(choice, "last"))
        {
            if(!isEmpty(queue))
            {
                printf("%d\n", lastItem(queue));
            }
            else
                printf("Queue is empty.\n");
        }
        else
            printf("Invalid Option.\n");

    } while (strcmp(choice, "quit"));

    eraseQueue(queue);

    return 0;
}