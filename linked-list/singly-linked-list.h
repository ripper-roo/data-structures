#ifndef SINGLY_LINKED
#define SINGLY_LINKED

typedef struct node *p_node;
	
struct node
{
  int data;
  struct node *next;
};

p_node createList(void);

void eraseList(p_node head);

void printList(p_node head);

int isEmpty(p_node head);

p_node searchValue(p_node head, int value);

void insertAtFront(p_node head, int value);

void insertAtBack(p_node head, int value);

void insertAfter(p_node head, int specifiedValue, int valueToBeAdded);

void deleteAtFront(p_node head);

void deleteAtBack(p_node head);

void deleteValue(p_node head, int value);

#endif