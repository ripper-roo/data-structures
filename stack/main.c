#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list_impl.h"

int main()
{
    p_stack stack = createStack();
    int value;
    char choice[50];

    printf("- push <value>\n- pop <value>\n- print\n- top\n- quit\n");
    do
    {
        scanf(" %s", choice);

        if(!strcmp(choice, "push"))
        {
            scanf(" %d", &value);
            push(stack, value);
        }
        else if(!strcmp(choice, "pop"))
        {
            if(!isEmpty(stack))
            {
                pop(stack);
            }
            else
                printf("Stack is empty.\n");
        }
        else if(!strcmp(choice, "print"))
        {
            if(!isEmpty(stack))
            {
                print(stack);
            }
            else
                printf("Stack is empty.\n");
        }
        else if(!strcmp(choice, "top"))
        {
            if(!isEmpty(stack))
            {
                printf("%d\n", top(stack));
            }
            else
                printf("Stack is empty.\n");
        }
        else
            printf("Invalid Option.\n");

    } while (strcmp(choice, "quit"));

    eraseStack(stack);

    return 0;
}