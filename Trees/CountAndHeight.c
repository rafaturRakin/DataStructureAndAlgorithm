#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

/*
    Author: Rakin
    Date:  25-04-2022
    Language: C
    Content: Tree Nodes counting and Height finding
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

int countNodes(struct Node *node)
{
    if(node)
        return countNodes(node->leftChild) + countNodes(node->rightChild) + 1;
    return 0;
}

int treeHeight(struct Node *node)
{
    int left = 0, right = 0;
    if(node)
    {
        left = treeHeight(node->leftChild);
        right = treeHeight(node->rightChild);
        if(left>right)
            return left + 1;
        else
            return right + 1;
    }

    return 0;
}


int main()
{
    printf("\t***** An Example of Tree (counting node and height) in c *****\n\n");

    createTree();

    printf("Total nodes in the tree is : %d\n", countNodes(root));
    printf("Maximum Height is : %d\n", treeHeight(root));

    return 0;
}

