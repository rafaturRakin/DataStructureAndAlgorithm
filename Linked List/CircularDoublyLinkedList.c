#include<stdio.h>
#include<stdlib.h>

/*
    Author: Rakin
    Date:  29-03-2022
    Language: C
    Content:  Circular Doubly Linked List
*/

struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
}*head=NULL;


void createLinkedList(int arr[], int len)
{
    struct Node *last, *current_node;
    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = arr[0];
    head->previous = head;
    head->next = head;
    last = head;
    for(int i=1; i<len; i++)
    {
        current_node = (struct Node *) malloc(sizeof(struct Node));
        current_node->data = arr[i];
        current_node->previous = last;
        current_node->next = last->next;
        last->next = current_node;
        current_node->next->previous = current_node;
        last = current_node;
    }
}

int countNodes(struct Node *h)
{
    int counter = 0;
    if(h==NULL)
        return counter;
    do
    {
        ++counter;
        h = h->next;
    } while(h!=head);
    return counter;
}


void insertNode(struct Node *h, int index, int value)
{
    if(index<0 || index>countNodes(h))
    {
        printf("\tInvalid Index!!!%d is not inserted\n", value);
        return;
    }

    struct Node *newNode, *currentNode;
    if(index==0)
    {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->previous = head->previous;
        newNode->next = head;
        newNode->previous->next = newNode;
        head->previous = newNode;
        head = newNode;
        printf("\t%d is inserted at head\n", value);
    }
    else
    {
        currentNode = head;
        for(int i=0; i<index-1; i++)
            currentNode = currentNode->next;
        newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = currentNode->next;
        newNode->previous = currentNode;
        currentNode->next->previous = newNode;
        currentNode->next = newNode;
        printf("\t%d is inserted\n", value);
    }
}

void deleteNode(struct Node *h, int index)
{
    if(index<1 || index>countNodes(h))
    {
        printf("Invalid Index!!! Index must be in between [1, %d]\n", countNodes(h));
        return;
    }

    struct Node *currentNode = h;
    if(index==1)
    {
        currentNode = currentNode->next;
        currentNode->previous = h->previous;
        h->previous->next = currentNode;
        head = currentNode;
        printf("\t%d is deleted from the head of the list\n", h->data);
        free(h);
    }
    else
    {
        for(int i=0; i<index-1; i++)
            currentNode = currentNode->next;
        currentNode->previous->next = currentNode->next;
        currentNode->next->previous = currentNode->previous;
        printf("\t%d is delete from the list\n", currentNode->data);
        free(currentNode);
    }
}


void displayList(struct Node *h)
{
    if(h==NULL)
    {
        printf("Empty List\n");
        return;
    }
    printf("Printing %d nodes circular linked list\n", countNodes(h));
    do
    {
        printf("\t%d", h->data);
        h = h->next;
    } while(h!=head);
    printf("\n");
}

int main()
{
    printf("\t***** An Example of Circular Doubly Linked List in C *****\n\n");

    int fixed_array[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    struct Node *temp = NULL;
    createLinkedList(fixed_array, 6);
    deleteNode(head, 1);
    displayList(head);
    return 0;
}
