#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "singly-linked-list.h"

int main()
{
    p_node head = createList();
    int value, target;

    char choice[50];
    do
    {
        printf("- add\n- del\n- print\n- quit\n");

        scanf(" %s", choice);

        if(!strcmp(choice, "add"))
        {
            printf("- back <value>\n- front <value>\n- after <target> <value>\n");

            scanf(" %s", choice);
            if(!strcmp(choice, "back"))
            {
                scanf(" %d", &value);
                insertAtBack(head, value);
            }
            else if(!strcmp(choice, "front"))
            {
                scanf(" %d", &value);
                insertAtFront(head, value);
            }
            else if(!strcmp(choice, "after"))
            {
                scanf(" %d %d", &target, &value);
                insertAfter(head, target, value);
            }
            else
                printf("Invalid option\n");
        }
        else if(!strcmp(choice, "del"))
        {
            if(!isEmpty(head))
            {
                printf("List is empty.\n");
                continue;
            }

            printf("\n- back\n- front\n- value <value>\n");

            scanf(" %s", choice);
            if(!strcmp(choice, "back"))
            {
                deleteAtBack(head);
            }
            else if(!strcmp(choice, "front"))
            {
                deleteAtFront(head);
            }
            else if(!strcmp(choice, "value"))
            {
                scanf(" %d", &value);
                deleteValue(head, value);
            }
            else
                printf("Invalid option\n");
        }
        else if(!strcmp(choice, "print"))
            printList(head);
        else
            printf("Invalid option\n");

    } while (strcmp(choice, "quit"));

    eraseList(head);
    
    return 0;
}