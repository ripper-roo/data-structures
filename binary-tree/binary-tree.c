#include <stdlib.h>
#include "binary-tree.h"

p_node createTree()
{
    p_node root = malloc(sizeof(struct node));
    if(!root)
        exit(1);

    root->left = NULL;
    root->right = NULL;
    root->up = NULL;

    return root;
}

p_node insert(p_node root, int value)
{
    if(root == NULL) // reached tree bottom
    {
        p_node new = malloc(sizeof(struct node));
        if(!new)
            exit(1);

        new->left = new->right = NULL;
        new->value = value;
        
        return new;
    }

    if(value < root->value)
    {
        root->left = insert(root->left, value);
        root->left->up = root;
    }
    else
    {
        root->right = insert(root->right, value);
        root->right->up = root;
    }

    return root;
}

p_node getMin(p_node root)
{
    // return node with minimum value, which will be the further left node

    if(root == NULL || root->left == NULL)
        return root;
    return getMin(root->left);
}

p_node nextNode(p_node node)
{
    /*
        given a node, find the node with next greater value, which will be:

        1. minimum node from the right subtree;

        2. if there is no right subtree, then the first ancestral node to the right
    */

    if(node->right != NULL)
        return getMin(node->right);
    else
        return rightAncestral(node);
}

p_node rightAncestral(p_node node)
{
    if(node == NULL)
        return NULL;
    if(node->up == NULL || node->up->left == node)
        return node->up;
    else
        return rightAncestral(node->up);
}

p_node remove(p_node root, int value)
{
    if(root == NULL)
        return NULL;
    if(value < root->value)
        root->left = remove(root->left, value);
    else if(value > root->value)
        root->right = remove(root->right, value);
    else if(root->left == NULL)
        return root->right;
    else if(root->right == NULL)
        return root->left;
    else
        removeNextNode(root);
    return root;
}

void removeNextNode(p_node node)
{
    p_node min = node->right;
    p_node up = node;

    while(min->left != NULL)
    {
        up = min;
        min = min->left;
    }
    if(up->left == min)
        up->left = min->right;
    else
        up->right = min->right;

    node->value = min->value;
}

p_node searchNode(p_node node, int value)
{
    if(node == NULL)
        return node;
    if(value < node->value)
        return searchNode(node->left, value);
    if(value > node->value)
        return searchNode(node->right, value);

    return node;
}

int numberOfNodes(p_node root)
{
    if(root == NULL)
        return 0;

    return numberOfNodes(root->left) + numberOfNodes(root->right) + 1;
}

int height(p_node root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}