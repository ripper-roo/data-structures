#include <stdlib.h>
#include "binary-search-tree.h"

p_tree createTree()
{
    p_tree root = malloc(sizeof(struct treeNode));
    if(!root)
        exit(1);

    root->left = NULL;
    root->right = NULL;
    root->up = NULL;

    return root;
}

void eraseTree(p_tree root)
{
    // post order traversal to free tree's memory

    if(root == NULL)
        return;

    eraseTree(root->left);
    eraseTree(root->right);

    free(root);
}

p_tree insert(p_tree root, int value)
{
    if(root == NULL) // reached tree bottom
    {
        p_tree new = malloc(sizeof(struct treeNode));
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

p_tree getMin(p_tree root)
{
    // return node with minimum value, which will be the further left node

    if(root == NULL || root->left == NULL)
        return root;
    return getMin(root->left);
}

p_tree nextNode(p_tree node)
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

p_tree rightAncestral(p_tree node)
{
    if(node == NULL)
        return NULL;
    if(node->up == NULL || node->up->left == node)
        return node->up;
    else
        return rightAncestral(node->up);
}

p_tree remove(p_tree root, int value)
{
    /* 
    function to remove a tree element, where two situations can occur:
    
    1. the element has child in only one side, in which case the function returns it to the element's father node and frees the element

    2. the element has childs in both sides, then, its value gets replaced by its next node's value, which gets removed following the first situation.

    */

    if(root == NULL)
        return NULL;

    // find the element to be removed

    if(value < root->value)
        root->left = remove(root->left, value);
    else if(value > root->value)
        root->right = remove(root->right, value);

    // return the element's child to father node (first situation)
    
    else if(root->left == NULL)
    {
        p_tree right = root->right;
        free(root);
        return right;
    }
    else if(root->right == NULL)
    {
        p_tree left = root->left;
        free(root);
        return left;
    }

    // both sides have child trees (situation 2)

    else
        removeNextNode(root);

    return root;
}

void removeNextNode(p_tree root)
{
    p_tree next = nextNode(root); // will call getMin()
    root->value = next->value;

    p_tree up = next->up;

    // remove next node's original place
    
    if(up->left == next)
    {
        up->left = next->right;
        free(next);
    }
    else // if up == root
    {
        up->right = next->right;
        free(next);
    }
}

p_tree searchNode(p_tree node, int value)
{
    if(node == NULL)
        return node;
    if(value < node->value)
        return searchNode(node->left, value);
    if(value > node->value)
        return searchNode(node->right, value);

    return node;
}

int numberOfNodes(p_tree root)
{
    if(root == NULL)
        return 0;

    return numberOfNodes(root->left) + numberOfNodes(root->right) + 1;
}

int height(p_tree root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}