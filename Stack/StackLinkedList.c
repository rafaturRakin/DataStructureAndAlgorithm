#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  06-04-2022
    Language: C
    Content: Stack using Linked List
*/

struct Node
{
    int data;
    struct Node *next;
} *Top = NULL;


int isFull()
{
    struct Node *current = (struct Node *) malloc(sizeof(struct Node));
    if(current)
    {
        free(current);
        return 0;
    }
    return 1;
}

int isEmpty(struct Node *current)
{
    if(current)
        return 0;
    return 1;
}

void pushElement(int element)
{
    struct Node *current = (struct Node*) malloc(sizeof(struct Node));
    if(current)
    {
        printf("\t-<%d is pushed>-\n", element);
        current->data = element;
        current->next = Top;
        Top = current;
    }
    else
        printf("\t-<Stack Overflow!!>-\n");
}

void popElement()
{
    if(Top)
    {
        struct Node *current = Top;
        Top = Top->next;
        printf("\t-<%d is popped from stack>-\n", current->data);
        free(current);
    }
    else
        printf("\t-<Stack Underflow\n>-\n");
}


void peekElement(int index)
{
    if(index<1)
    {
        printf("\t-<Invalid Index!!>-\n");
        return;
    }

    struct Node *current = Top;
    for(int i=0; current && i<index-1; i++)
        current = current->next;
    if(current)
        printf("\t%d is in position %d\n", current->data, index);
    else
        printf("\t-<Invalid Index!!\n>-");
}

void stackTop()
{
    if(Top)
        printf("\t%d is stack top\n", Top->data);
    else
        printf("\t-<Stack is Empty>-\n");
}


void displayStack()
{
    struct Node *current = Top;
    printf("\nDisplaying stack...\n");
    while(current)
    {
        printf("\t%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    printf("\t***** An Example of Stack using Array in c *****\n\n");

    if(isEmpty(Top))
        printf("Stack is Empty\n");

    pushElement(1);
    pushElement(2);
    pushElement(3);
    pushElement(4);

    displayStack();

    popElement(Top);
    popElement(Top);

    displayStack();

    if(!isFull())
        printf("Stack is not full\n");
    stackTop();
    peekElement(2);

    return 0;
}
