#include <stdlib.h>

typedef struct treeNode* p_tree;

struct treeNode
{
    int value;
    p_tree left, right, up;
};

p_tree createTree();

void eraseTree(p_tree root);

p_tree insert(p_tree root, int value);

p_tree getMin(p_tree root);

p_tree nextNode(p_tree node);

p_tree rightAncestral(p_tree node);

p_tree remove(p_tree root, int value);

void removeNextNode(p_tree root);

p_tree searchNode(p_tree node, int value);

int numberOfNodes(p_tree root);

int height(p_tree root);