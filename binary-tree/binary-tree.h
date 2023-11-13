#include <stdlib.h>

typedef struct node* p_node;

struct node
{
    int value;
    p_node left, right, up;
};

p_node createTree();

p_node insert(p_node root, int value);

p_node getMin(p_node root);

p_node nextNode(p_node node);

p_node rightAncestral(p_node node);

p_node remove(p_node root, int value);

void removeNextNode(p_node node);

p_node searchNode(p_node node, int value);

int numberOfNodes(p_node root);

int height(p_node root);