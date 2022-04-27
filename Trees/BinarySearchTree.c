#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  27-04-2022
    Language: C
    Content: Binary Search Tree
*/

struct Node
{
    struct Node *leftChild;
    int data;
    struct Node *rightChild;
} *root = NULL;

void insertNode(int data)
{
    struct Node *previous=NULL, *current=root, *temp;
    if(current==NULL)
    {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = data;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        root = temp;
        printf("\t--<%d Insert as root node>--\n", root->data);
        return;
    }

    while(current)
    {
        previous = current;
        if(current->data == data)
        {
            printf("\t--<%d : Duplicate Value Found>--\n", data);
            return;
        }
        else if(data>current->data)
            current = current->rightChild;
        else
            current = current->leftChild;
    }

    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    if(temp->data > previous->data)
    {
        printf("\t--<%d Insert as right child of %d>--\n", data, previous->data);
        previous->rightChild = temp;
    }
    else
    {
        printf("\t--<%d Insert as left child of %d>--\n", data, previous->data);
        previous->leftChild = temp;
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

struct Node * searchNode(int key)
{
    struct Node *node = root;
    while(node)
    {
        if(node->data == key)
            return node;
        else if(node->data < key)
            node = node->rightChild;
        else
            node = node->leftChild;
    }
    return NULL;
}

int main()
{
    printf("\t***** An Example of Binary Search Tree in c *****\n\n");
    insertNode(10);
    insertNode(10);
    insertNode(20);
    insertNode(5);
    insertNode(7);
    insertNode(27);

    inorderTraversal(root);
    printf("\n");

    int data = 5;
    struct Node *node = searchNode(data);
    if(node)
        printf("%d Found\n", data);
    else
        printf("%d Not found\n", data);

    return 0;
}
