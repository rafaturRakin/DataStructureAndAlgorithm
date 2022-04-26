#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

/*
    Author: Rakin
    Date:  26-04-2022
    Language: C
    Content: Tree (Counting different types of node)
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

int countTotalNodes(struct Node *node)
{
    if(node)
        return countTotalNodes(node->leftChild) + countTotalNodes(node->rightChild) + 1;
    return 0;
}

int countLeafNodes(struct Node *node)
{
    if(node)
    {
        if(node->leftChild==NULL && node->rightChild==NULL)
            return countLeafNodes(node->leftChild) + countLeafNodes(node->rightChild) + 1;
        return countLeafNodes(node->leftChild) + countLeafNodes(node->rightChild);
    }
    return 0;
}


int countInternalNodes(struct Node *node)
{
    if(node)
    {
        if(node->leftChild!=NULL || node->rightChild!=NULL)
            return countInternalNodes(node->leftChild) + countInternalNodes(node->rightChild) + 1;
        return countInternalNodes(node->leftChild) + countInternalNodes(node->rightChild);
    }
    return 0;
}


int countDegreeTwoNodes(struct Node *node)
{
    if(node)
    {
        if(node->leftChild!=NULL && node->rightChild!=NULL)
            return countDegreeTwoNodes(node->leftChild) + countDegreeTwoNodes(node->rightChild) + 1;
        return countDegreeTwoNodes(node->leftChild) + countDegreeTwoNodes(node->rightChild);
    }
    return 0;
}

int countDegreeOneNodes(struct Node *node)
{
    if(node)
    {
        if(node->leftChild!=NULL ^ node->rightChild!=NULL)
            return countDegreeOneNodes(node->leftChild) + countDegreeOneNodes(node->rightChild) + 1;
        return countDegreeOneNodes(node->leftChild) + countDegreeOneNodes(node->rightChild);
    }
    return 0;
}

int main()
{
    printf("\t***** An Example of Counting different types of node in c *****\n\n");

    createTree();

    printf("Total node in the tree is : %d\n", countTotalNodes(root));
    printf("Total Internal nodes : %d\n", countInternalNodes(root));
    printf("Total Leaf/Terminal/External node : %d\n", countLeafNodes(root));
    printf("Total Degree->2 nodes : %d\n", countDegreeTwoNodes(root));
    printf("Total Degree->1 nodes : %d\n", countDegreeOneNodes(root));

    return 0;
}

