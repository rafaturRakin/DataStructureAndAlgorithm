#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  01-05-2022
    Language: C
    Content: AVL Tree
*/

struct Node
{
    struct Node * leftChild;
    int data;
    int height;
    struct Node * rightChild;
} * ROOT = NULL;


int nodeHeight(struct Node * node)
{
    int leftHeight, rightHeight;
    leftHeight = node && node->leftChild ? node->leftChild->height : 0;
    rightHeight = node && node->rightChild ? node->rightChild->height : 0;

    return leftHeight > rightHeight ? leftHeight+1 : rightHeight + 1;
}


int balanceFactor(struct Node *node)
{
    int leftHeight, rightHeight;
    leftHeight = node && node->leftChild ? node->leftChild->height : 0;
    rightHeight = node && node->rightChild ? node->rightChild->height : 0;

    return leftHeight-rightHeight;
}

struct Node * LLRotation(struct Node * node)
{
    struct Node * nodeLeftChild = node->leftChild;
    struct Node *nodeLeftRightChild = nodeLeftChild->rightChild;

    nodeLeftChild->rightChild = node;
    node->leftChild = nodeLeftRightChild;
    node->height = nodeHeight(node);
    nodeLeftChild->height = nodeHeight(nodeLeftChild);

    if(ROOT==node)
        ROOT = nodeLeftChild;

    return nodeLeftChild;
}


struct Node * recursiveInsert(struct Node * node, int data)
{
    struct Node *newNode = NULL;

    if(node == NULL)
    {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->leftChild = NULL;
        newNode->data = data;
        newNode->height = 1; // assuming height is 1 in leaf
        newNode->rightChild = NULL;
        return newNode;
    }

    if(data < node->data)
       node->leftChild = recursiveInsert(node->leftChild, data);
    else if(data > node->data)
        node->rightChild = recursiveInsert(node->rightChild, data);

    node->height = nodeHeight(node);

    if(balanceFactor(node)==2 && balanceFactor(node->leftChild)==1)
        return LLRotation(node);
    //else if(balanceFactor(node)==2 && balanceFactor(node->leftChild)==-1)
        //return LRRotaion(node);
    /*
    else if(balanceFactor(node)==-2 && balanceFactor(node->leftChild)==-1)
        return RRRotation(node);
    else if(balanceFactor(node)==-2 && balanceFactor(node->leftChild)==1)
        return RLRotaion(node);
    */

    return node;
}




int main()
{
    printf("\t***** An Example of AVL Tree in c *****\n\n");
    ROOT = recursiveInsert(ROOT, 10);
    printf("After first Value : %d\n", ROOT->data);
    recursiveInsert(ROOT, 5);
    recursiveInsert(ROOT, 2);

    printf("Current Root : %d\n", ROOT->data);
    return 0;
}

