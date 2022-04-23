#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#include "Stack.h"

/*
    Author: Rakin
    Date:  23-04-2022
    Language: C
    Content: Tree Traversal
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
    struct Stack st;
    createStack(&st, 100);
    while(node || !isStackEmpty(st))
    {
        if(node)
        {
            printf("\t%d", node->data);
            pushElement(&st, node);
            node = node->leftChild;
        }
        else
        {
            node = popElement(&st);
            node = node->rightChild;
        }
    }
}

void inorderTraversal(struct Node *node)
{
    struct Stack st;
    createStack(&st, 100);
    while(node || !isStackEmpty(st))
    {
        if(node)
        {
            pushElement(&st, node);
            node = node->leftChild;
        }
        else
        {
            node = popElement(&st);
            printf("\t%d", node->data);
            node = node->rightChild;
        }
    }
}

void postorderTraversal(struct Node *node)
{
    struct Stack st;
    struct Node *current;
    createStack(&st, 100);
    while(node || !isStackEmpty(st))
    {
        if(node)
        {
            pushElement(&st, node);
            node = node->leftChild;
        }
        else
        {
            current = popElement(&st);
            long long int value = (long long int) current;
            if(value < 0)
            {
                value = value * -1;
                current = (struct Node *) value;
                printf("\t%d", current->data);
                node = NULL;
            }
            else
            {
                value = -1 * (long long int) current;
                struct Node *temp = (struct Node *) value;
                pushElement(&st, temp);
                node = ((struct Node *)current)->rightChild;
            }
        }
    }
}

int main()
{
    printf("\t***** An Example of Iterative Tree Traversal in c *****\n\n");

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

