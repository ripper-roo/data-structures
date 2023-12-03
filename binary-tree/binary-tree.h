#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct treeNode* p_tree;

struct treeNode
{
    int value;
    p_tree left, right;
};

p_tree createTree(char value, p_tree left, p_tree right);

void eraseTree(p_tree root);

void preOrder(p_tree root);

void postOrder(p_tree root);

void inorder(p_tree root);

void breadthTraversal(p_tree tree);

#endif