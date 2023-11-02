#include <stdio.h>
#include <stdlib.h>

#include "linked_list_impl.h"

p_stack createStack()
{
    p_stack new = malloc(sizeof(struct stack));
    if(!new)
        exit(1);

    new->top = NULL;
    return new;
}

int isEmpty(p_stack stack)
{
    return !stack->top ? 1 : 0;
}

void push(p_stack stack, int value)
{
    p_node new = malloc(sizeof(struct node));
    if(!new)
        exit(1);

    new->data = value;
    new->next = stack->top;
    stack->top = new;
}

int pop(p_stack stack)
{
    p_node top = stack->top;
    int value = top->data;

    stack->top = top->next;
    free(top);

    return value;
}

int top(p_stack stack)
{
    return stack->top->data;
}

void print(p_stack stack)
{
    p_node node = stack->top;
    while(node)
    {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
}

void eraseStack(p_stack stack)
{
    p_node alt;
    while(stack->top)
    {
        alt = stack->top;
        stack->top = stack->top->next;
        free(alt);
    }

    free(stack);
}