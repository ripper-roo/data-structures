#include <stdlib.h>
#include <string.h>

#include "static_array.h"

int main()
{
    int queue[SIZE];
    int value;
    char choice[50];

    printf("- enq <value>\n- deq <value>\n- print\n- first\n- last\n- quit\n");
    do
    {
        scanf(" %s", choice);

        int empty = isEmpty();

        if(!strcmp(choice, "enq"))
        {
            scanf(" %d", &value);
            enqueue(queue, value);
        }
        else if(!strcmp(choice, "deq"))
            dequeue(queue);
        else if(!strcmp(choice, "print") && !empty)
            print(queue);
        else if(!strcmp(choice, "first") && !empty)
            printf("%d\n", firstItem(queue));
        else if(!strcmp(choice, "last") && !empty)
            printf("%d\n", lastItem(queue));

    } while (strcmp(choice, "quit"));

    return 0;
}