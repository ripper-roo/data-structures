#ifndef LINKED_LIST_IMPL
#define LINKED_LIST_IMPL

typedef struct node* p_node;
	
struct node
{
  int data;
  p_node next;
};

typedef struct stack* p_stack;

struct stack
{
    p_node top;
};

p_stack createStack();

int isEmpty(p_stack stack);

void push(p_stack stack, int value);

int pop(p_stack stack);

int top(p_stack stack);

void print(p_stack stack);

void eraseStack(p_stack stack);

#endif