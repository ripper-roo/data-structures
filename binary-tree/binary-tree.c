#include <stdlib.h>
#include <stdio.h>

#include "binary-tree.h"
#include "circular_queue.h"

#define TREE_SIZE 100

p_tree createTree(char value, p_tree left, p_tree right)
{
    p_tree new = malloc(sizeof(struct treeNode));
    if(!new)
        exit(1);

    new->value = value;
    new->left = left;
    new->right = right;

    return new;
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

void preOrder(p_tree root)
{
    if(root != NULL)    // root == NULL means that a leaf has been reached
    {
        printf("%d ", root->value);  // process root
        preOrder(root->left);
        preOrder(root->right);
    }
    printf("\n");

}

void postOrder(p_tree root)
{
    if(root != NULL)    // root == NULL means that a leaf has been reached
    {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ", root->value);  // process root
    }
    
    printf("\n");
}

void inorder(p_tree root)
{
    if(root != NULL)    // root == NULL means that a leaf has been reached
    {
        preOrder(root->left);
        printf("%d ", root->value);  // process root
        preOrder(root->right);
    }

    printf("\n");
}

void breadthTraversal(p_tree root)
{
    p_queue queue = createQueue(TREE_SIZE);
    enqueue(queue, root);

    while(!isEmpty(queue))
    {
        root = dequeue(queue);
        if(root != NULL)
        {
            enqueue(queue, root->left);
            enqueue(queue, root->right);
            printf("%d ", root->value); // process root
        }
    }

    printf("\n");

    eraseQueue(queue);
}