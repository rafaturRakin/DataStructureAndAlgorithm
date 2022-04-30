#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

/*
    Author: Rakin
    Date:  27-04-2022
    Language: C
    Content: Binary Search Tree
*/

struct Node *root = NULL;

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


struct Node * insertNodeRecursive(struct Node *node, int data)
{
    struct Node *newNode;
    if(node == NULL)
    {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }

    if(node->data > data)
        node->leftChild = insertNodeRecursive(node->leftChild, data);
    else if(node->data < data)
        node->rightChild = insertNodeRecursive(node->rightChild, data);

    return node;
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

struct Node * searchNodeRecursive(struct Node *node, int key)
{
    if(node==NULL)
        return NULL;
    if(node->data == key)
        return node;
    else if(node->data < key)
        return searchNodeRecursive(node->rightChild, key);
    else
        return searchNodeRecursive(node->leftChild, key);
}

int treeHeight(struct Node *node)
{
    int left, right;
    if(node==NULL)
        return 0;
    left = treeHeight(node->leftChild);
    right = treeHeight(node->rightChild);
    if(left>=right)
        return left + 1;
    else
        return right + 1;
}

struct Node * inorderPredessor(struct Node *node)
{
    while(node && node->rightChild)
        node = node->rightChild;
    return node;
}

struct Node * inorderSuccessor(struct Node *node)
{
    while(node && node->leftChild)
        node = node->leftChild;
    return  node;
}

struct Node * deleteNode(struct Node *node, int key)
{
    struct Node *newNode;

    if(node==NULL)
        return NULL;
    if(node->leftChild==NULL && node->rightChild==NULL)
    {
        if(node==root)
            root = NULL;
        free(node);
        return NULL;
    }

    if(key < node->data)
        node->leftChild = deleteNode(node->leftChild, key);
    else if(key > node->data)
        node->rightChild = deleteNode(node->rightChild, key);
    else
    {
        if(treeHeight(node->leftChild) >= treeHeight(node->rightChild))
        {
            newNode = inorderPredessor(node->leftChild);
            node->data = newNode->data;
            node->leftChild = deleteNode(node->leftChild, newNode->data);
        }
        else
        {
            newNode = inorderSuccessor(node->rightChild);
            node->data = newNode->data;
            node->rightChild = deleteNode(node->rightChild, newNode->data);
        }
    }
    return node;
}

void createFromPreorder(int elements[], int length)
{
    struct Stack st;
    createStack(&st, 100);
    struct Node *current, *newNode;
    int i = 0;

    root = (struct Node *) malloc(sizeof(struct Node));
    root->leftChild = NULL;
    root->data = elements[i++];
    root->rightChild = NULL;
    current = root;

    while(i<length)
    {
        if(elements[i]<current->data)
        {
            newNode = (struct Node *) malloc(sizeof(struct Node));
            newNode->data = elements[i++];
            newNode->leftChild = NULL;
            newNode->rightChild = NULL;
            current->leftChild = newNode;
            pushElement(&st, current);
            current = newNode;
        }
        else
        {
            int data;
            if(stackTopPointer(st)==NULL)
                data = INT_MAX;
            else
                data = stackTopPointer(st)->data;
            if(elements[i]>current->data && elements[i]<data)
            {
                newNode = (struct Node *) malloc(sizeof(struct Node));
                newNode->data = elements[i++];
                newNode->leftChild = NULL;
                newNode->rightChild = NULL;
                current->rightChild = newNode;
                current = newNode;
            }
            else
                current = popElement(&st);
        }
    }
}

int main()
{
    printf("\t***** An Example of Binary Search Tree in c *****\n\n");
    int preorder [] = {30, 20, 10, 15, 25, 40, 50, 45};

    createFromPreorder(preorder, 8);

    inorderTraversal(root);
    printf("\n");


    return 0;
}
