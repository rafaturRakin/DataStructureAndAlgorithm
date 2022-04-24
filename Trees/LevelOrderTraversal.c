#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

/*
    Author: Rakin
    Date:  24-04-2022
    Language: C
    Content: Tree (Level order traversal)
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

void levelOrderTraversal(struct Node *node)
{
    struct Queue q;
    createQueue(&q, 100);

    printf("\t%d", node->data);
    enqueueElement(&q, node);

    while(!isEmpty(&q))
    {
        node = dequeueElement(&q);
        if(node->leftChild)
        {
            printf("\t%d", node->leftChild->data);
            enqueueElement(&q, node->leftChild);
        }
        if(node->rightChild)
        {
            printf("\t%d", node->rightChild->data);
            enqueueElement(&q, node->rightChild);
        }
    }
}

int main()
{
    printf("\t***** An Example of Tree in c *****\n\n");

    createTree();

    printf("Pre-order Traversal : \n");
    preorderTraversal(root);
    printf("\n\n");

    printf("In-order Traversal : \n");
    inorderTraversal(root);
    printf("\n\n");

    printf("Post-order Traversal : \n");
    postorderTraversal(root);
    printf("\n\n");

    printf("Level-order Traversal : \n");
    levelOrderTraversal(root);
    printf("\n\n");

    return 0;
}

