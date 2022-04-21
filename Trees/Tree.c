#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

/*
    Author: Rakin
    Date:  21-04-2022
    Language: C
    Content: Tree
*/

struct Node *root = NULL;

void createTree()
{
    struct Node *current, *temp;
    int data;
    struct Queue qt;
    createQueue(&qt, 100);

    // creating root node
    printf("Enter root node value : ");
    scanf("%d", &data);
    root = (struct Node *) malloc(sizeof(struct Node));
    root->data = data;
    root->leftChild = NULL;
    root->rightChild = NULL;

    enqueueElement(&qt, root);

    while(!isEmpty(&qt))
    {
        current = dequeueElement(&qt);

        // For left child
        printf("\nEnter left child of node->%d : ", current->data);
        scanf("%d", &data);
        if(data != -1)
        {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
            current->leftChild = temp;
            enqueueElement(&qt, temp);
        }

        // For Right child
        printf("Enter right child of node->%d : ", current->data);
        scanf("%d", &data);
        if(data != -1)
        {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
            current->rightChild = temp;
            enqueueElement(&qt, temp);
        }
    }
    printf("\n\n");
}

void preorderTraversal(struct Node *node)
{
    if(node)
    {
        printf("\t%d", node->data);
        preorderTraversal(node->leftChild);
        preorderTraversal(node->rightChild);
    }
}

void inorderTraversal(struct Node *node)
{
    if(node)
    {
        inorderTraversal(node->leftChild);
        printf("\t%d", node->data);
        inorderTraversal(node->rightChild);
    }
}

void postorderTraversal(struct Node *node)
{
    if(node)
    {
        postorderTraversal(node->leftChild);
        postorderTraversal(node->rightChild);
        printf("\t%d", node->data);
    }
}

int main()
{
    printf("\t***** An Example of Tree in c *****\n\n");

    createTree();

    printf("Preorder Traversal : \n");
    preorderTraversal(root);
    printf("\n\n");

    printf("Inorder Traversal : \n");
    inorderTraversal(root);
    printf("\n\n");

    printf("Postorder Traversal : \n");
    postorderTraversal(root);
    printf("\n\n");

    return 0;
}
